//! Noyaux externes pour Fedora.

mod install;
mod repo;
mod sysutil;
#[cfg(feature = "gui")]
mod gui;

use repo::KernelKind;
use std::io::Write;
use std::path::PathBuf;
use std::process;

// ----------------------------------------------------------------------
// Point d'entrée
// ----------------------------------------------------------------------

fn main() {
    let args: Vec<String> = std::env::args().skip(1).collect();

    if args.is_empty() {
        #[cfg(feature = "gui")]
        gui::run_gui();
        #[cfg(not(feature = "gui"))]
        print_usage();
        return;
    }

    match args[0].as_str() {
        "list" | "ls" => cmd_list(),
        "install" | "i" => cmd_install(&args[1..]),
        "remove" | "rm" => cmd_remove(&args[1..]),
        "check" => cmd_check(),
        #[cfg(feature = "gui")]
        "gui" => gui::run_gui(),
        "help" | "--help" | "-h" => print_usage(),
        other => {
            eprintln!("Argument inconnu : {}", other);
            print_usage();
            process::exit(1);
        }
    }
}

// ----------------------------------------------------------------------
// CLI
// ----------------------------------------------------------------------

fn print_usage() {
    println!(
        "Kernel Manager — gestionnaire de noyaux externes pour Fedora"
    );
    println!();
    println!("Usage :");
    println!("  kernel-manager list              Liste des noyaux installés");
    println!("  kernel-manager install <type>    Installe un noyau externe");
    println!("                                  Types : cachyos, zen, liquorix");
    println!("  kernel-manager remove <version>  Supprime un noyau externe");
    println!("  kernel-manager check             Vérifie la configuration boot");
    println!();
    println!(
        "Le mot de passe root sera demandé au moment de l'installation."
    );
}

fn cmd_list() {
    println!("Vérification des noyaux externes installés…");
    flush();

    let installed = install::list_installed();
    let running = sysutil::running_kernel();

    if installed.is_empty() {
        println!("  Aucun noyau externe installé.");
        return;
    }

    println!();
    println!("  Noyaux externes installés :");
    println!();
    for k in &installed {
        let mark = if k.running { "✓" } else { " " };
        let status = if k.running { "* RUNNING" } else { "" };
        println!(
            "  {}  {}  ({})  {}",
            mark, k.display_version, k.kind.label(), status
        );
    }
    println!();
    println!("  Noyau courant : {}", running);
    println!();
}

fn cmd_install(args: &[String]) {
    let kind = parse_kernel_kind(args);

    print!(
        "Récupération des versions disponibles ({})…\n",
        kind.label()
    );
    flush();

    let releases = match repo::fetch_latest_kernels(kind) {
        Ok(r) => r,
        Err(e) => {
            eprintln!("  Erreur : {}", e);
            process::exit(1);
        }
    };

    if releases.is_empty() {
        eprintln!("  Aucun noyau trouvé dans le dépôt.");
        process::exit(1);
    }

    let target = if let Some(v) = args.get(1) {
        releases.iter().find(|r| r.version == *v).unwrap_or(&releases[0])
    } else {
        &releases[0]
    };

    println!("  Version : {}", target.version);
    println!("  Paquet  : {}", target.kernel_version);
    println!();

    print!("  Mot de passe root : ");
    flush();
    let pw = read_password();
    if pw.is_empty() {
        eprintln!("  Annulation : mot de passe non fourni.");
        process::exit(1);
    }
    println!();

    let downloaded = repo::download_kernel(&target, &|written, total| {
        if total > 0 {
            let pct = (written * 100) / total;
            print!(
                "\r  Téléchargement : {}% ({:.1} / {:.1} Mo)",
                pct,
                written as f64 / 1_000_000.0,
                total as f64 / 1_000_000.0
            );
            flush();
        }
    });

    let path = match downloaded {
        Ok(p) => p,
        Err(e) => {
            eprintln!("  Erreur téléchargement : {}", e);
            process::exit(1);
        }
    };
    println!();

    let result = install::install_kernel(
        &pw,
        &path,
        &target.kernel_version,
        kind,
        &|step, text| {
            print!("\r  Étape {}/8 : {}", step, text);
            flush();
        },
    );

    match result {
        Ok(boot_entry) => {
            println!(
                "\n  ✓ Noyau {} installé avec succès.",
                target.kernel_version
            );
            println!("  Entrée boot : {}", boot_entry);
            println!("  Pour booter : choisir ce noyau dans GRUB2");
        }
        Err(e) => {
            eprintln!("\n  Erreur installation : {}", e);
            process::exit(1);
        }
    }
}

fn cmd_remove(args: &[String]) {
    if args.is_empty() {
        eprintln!(
            "  Version requise. Exemple : kernel-manager remove 6.8.6-cachyos"
        );
        process::exit(1);
    }
    let version = &args[0];

    print!("  Mot de passe root : ");
    flush();
    let pw = read_password();
    if pw.is_empty() {
        eprintln!("  Annulation : mot de passe non fourni.");
        process::exit(1);
    }

    match install::remove_kernel(&pw, version) {
        Ok(()) => println!("  ✓ Noyau {} supprimé.", version),
        Err(e) => {
            eprintln!("  Erreur suppression : {}", e);
            process::exit(1);
        }
    }
}

fn cmd_check() {
    println!("  Vérification de la configuration boot :");
    println!(
        "    /boot existe : {}",
        PathBuf::from("/boot").exists()
    );
    println!(
        "    /boot/grub/grub.cfg existe : {}",
        PathBuf::from("/boot/grub/grub.cfg").exists()
    );
    println!(
        "    /lib/modules existe : {}",
        PathBuf::from("/lib/modules").exists()
    );

    let running = sysutil::running_kernel();
    println!("    Noyau courant : {}", running);

    let installed = install::list_installed();
    println!(
        "    Noyaux externes installés : {}",
        installed.len()
    );
    for k in &installed {
        println!("      - {} ({})", k.display_version, k.kind.label());
    }
}

// ----------------------------------------------------------------------
// Aides
// ----------------------------------------------------------------------

fn parse_kernel_kind(args: &[String]) -> KernelKind {
    let arg = args
        .get(0)
        .map(|s| s.to_lowercase())
        .unwrap_or_default();
    match arg.as_str() {
        "cachyos" | "cachy" => KernelKind::Cachyos,
        "zen" => KernelKind::Zen,
        "liquorix" | "lqx" => KernelKind::Liquorix,
        _ => {
            eprintln!("  Type de noyau inconnu : {}", arg);
            eprintln!("  Types valides : cachyos, zen, liquorix");
            process::exit(1);
        }
    }
}

fn read_password() -> String {
    let mut input = String::new();
    let _ = std::io::stdin().read_line(&mut input).unwrap_or_default();
    input.trim().to_string()
}

fn flush() {
    let _ = std::io::stdout().flush();
}

// ----------------------------------------------------------------------
// GUI (feature optionnel) — maintenant dans src/gui.rs
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Tests
// ----------------------------------------------------------------------

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parse_kernel_kind_cachyos() {
        let args = vec!["cachyos".to_string()];
        let kind = parse_kernel_kind(&args);
        assert_eq!(kind, KernelKind::Cachyos);
    }

    #[test]
    fn parse_kernel_kind_zen() {
        let args = vec!["zen".to_string()];
        let kind = parse_kernel_kind(&args);
        assert_eq!(kind, KernelKind::Zen);
    }

    #[test]
    fn parse_kernel_kind_liquorix() {
        let args = vec!["liquorix".to_string()];
        let kind = parse_kernel_kind(&args);
        assert_eq!(kind, KernelKind::Liquorix);
    }

    #[test]
    fn parse_kernel_kind_case_insensitive() {
        let args = vec!["CACHYOS".to_string()];
        let kind = parse_kernel_kind(&args);
        assert_eq!(kind, KernelKind::Cachyos);
    }

    #[test]
    fn running_kernel_returns_string() {
        let rk = sysutil::running_kernel();
        assert!(!rk.is_empty());
    }

    #[test]
    fn state_dir_exists() {
        let dir = sysutil::state_dir();
        assert!(dir.display().to_string().contains("kernel-manager"));
    }

    #[test]
    fn log_file_in_state_dir() {
        let lf = sysutil::log_file();
        assert!(lf.display().to_string().ends_with("manager.log"));
    }
}
