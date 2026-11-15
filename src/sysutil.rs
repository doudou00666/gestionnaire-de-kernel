//! Utilitaires système pour le Kernel Manager Fedora.
//!
//! - Chemins standard Fedora : /boot/vmlinuz-{release}, /lib/modules/{release}
//! - GRUB2 pour la détection des noyaux
//! - Registre local des noyaux installés (~/.local/state/kernel-manager/)
//! - Log horodaté (~/.local/state/kernel-manager/manager.log)

use crate::repo::KernelKind;
use std::fs;
use std::path::PathBuf;

// ----------------------------------------------------------------------
// Chemins & registre
// ----------------------------------------------------------------------

/// Répertoire d'état local.
pub fn state_dir() -> PathBuf {
    let home = std::env::var("HOME").unwrap_or_else(|_| "/root".to_string());
    PathBuf::from(home).join(".local/state/kernel-manager")
}

/// Fichier de log.
pub fn log_file() -> PathBuf {
    state_dir().join("manager.log")
}

/// Fichier du registre (JSON).
pub fn registry_file() -> PathBuf {
    state_dir().join("registry.json")
}

// ----------------------------------------------------------------------
// Log
// ----------------------------------------------------------------------

/// Écrit un message dans le log horodaté.
pub fn log(msg: &str) {
    let dir = state_dir();
    let _ = fs::create_dir_all(&dir);
    let file = log_file();
    let ts = chrono::Local::now().format("%Y-%m-%d %H:%M:%S");
    let _ = fs::OpenOptions::new()
        .append(true)
        .create(true)
        .write(true)
        .open(&file)
        .and_then(|mut f| {
            use std::io::Write;
            let data = format!("[{}] {}\n", ts, msg);
            f.write_all(data.as_bytes())
        });
}

// ----------------------------------------------------------------------
// Registre
// ----------------------------------------------------------------------

/// Entrée du registre.
#[derive(Debug, Clone)]
pub struct RegistryEntry {
    pub kind: KernelKind,
    pub display_version: String,
}

/// Lit le registre. Retourne un hashmap name → entry.
pub fn read_registry() -> std::collections::HashMap<String, RegistryEntry> {
    let file = registry_file();
    if !file.exists() {
        return std::collections::HashMap::new();
    }
    let content = fs::read_to_string(&file).unwrap_or_default();
    let parsed: std::collections::HashMap<String, serde_json::Value> =
        serde_json::from_str(&content).unwrap_or_default();

    let mut out = std::collections::HashMap::new();
    for (k, v) in &parsed {
        let kind_str = v["kind"].as_str().unwrap_or("CachyOS");
        let kind = KernelKind::from_label(kind_str).unwrap_or(KernelKind::Cachyos);
        let display = v["display"].as_str().unwrap_or(k.as_str());
        out.insert(k.clone(), RegistryEntry {
            kind,
            display_version: display.to_string(),
        });
    }
    out
}

/// Enregistre un noyau installé.
pub fn record_install(name: &str, kind: KernelKind, display: Option<&str>) {
    let dir = state_dir();
    let _ = fs::create_dir_all(&dir);
    let file = registry_file();
    let content = fs::read_to_string(&file).unwrap_or_default();
    let mut reg: std::collections::HashMap<String, serde_json::Value> =
        serde_json::from_str(&content).unwrap_or_default();

    let display = display.unwrap_or(name);
    reg.insert(
        name.to_string(),
        serde_json::json!({
            "kind": kind.label(),
            "display": display,
        }),
    );
    let json = serde_json::to_string_pretty(&reg).unwrap_or_default();
    let _ = fs::write(&file, json);
}

/// Oublie un noyau du registre.
pub fn forget_install(name: &str) {
    let file = registry_file();
    if !file.exists() {
        return;
    }
    let content = fs::read_to_string(&file).unwrap_or_default();
    let mut reg: std::collections::HashMap<String, serde_json::Value> =
        serde_json::from_str(&content).unwrap_or_default();
    reg.remove(name);
    let json = serde_json::to_string_pretty(&reg).unwrap_or_default();
    let _ = fs::write(&file, json);
}

/// Récupère le type d'un noyau depuis le registre.
pub fn registry_kind(name: &str) -> Option<KernelKind> {
    let reg = read_registry();
    reg.get(name).map(|e| e.kind)
}

/// Récupère le display_version d'un noyau depuis le registre.
pub fn registry_display(name: &str) -> Option<String> {
    let reg = read_registry();
    reg.get(name).map(|e| e.display_version.clone())
}

// ----------------------------------------------------------------------
// Noyaux
// ----------------------------------------------------------------------

/// Noyau actuellement en cours d'exécution.
pub fn running_kernel() -> String {
    // /proc/version : "Linux version 7.3.3-300.fc45.x86_64 ... "
    if let Some(v) = fs::read_to_string("/proc/version")
        .ok()
        .and_then(|s| s.split_whitespace().nth(2).map(|w| w.to_string()))
    {
        return v;
    }
    // Fallback : uname -r
    run("uname", &["-r"])
        .1
        .trim()
        .to_string()
}

/// Liste des noyaux externes installés (via /lib/modules/).
pub fn installed_ext_kernels() -> Vec<String> {
    let modules_dir = PathBuf::from("/lib/modules");
    if !modules_dir.exists() {
        return Vec::new();
    }
    let mut out = Vec::new();
    if let Ok(entries) = fs::read_dir(&modules_dir) {
        for entry in entries.flatten() {
            let name = entry.file_name().to_string_lossy().to_string();
            // Filter : n'évaluer que les noyaux externes (suffixe connu)
            if name.contains("-cachyos") || name.contains(".zen") || name.contains("-lqx") {
                out.push(name);
            }
        }
    }
    out.sort();
    out
}

/// Devine le type d'un noyau basé sur son nom.
pub fn guess_kind(name: &str) -> Option<KernelKind> {
    if name.contains("-cachyos") {
        Some(KernelKind::Cachyos)
    } else if name.contains(".zen") {
        Some(KernelKind::Zen)
    } else if name.contains("-lqx") {
        Some(KernelKind::Liquorix)
    } else {
        None
    }
}

// ----------------------------------------------------------------------
// Espace disque
// ----------------------------------------------------------------------

/// Info sur l'espace disque.
#[derive(Debug, Clone)]
pub struct DiskSpace {
    pub free: u64,
}

/// Espace libre sur /boot (via df -k).
pub fn boot_space_with_sudo(_pw: &str) -> Result<DiskSpace, String> {
    let (code, out, _err) = run("df", &["-k", "/boot"]);
    if code != 0 {
        return Err("df /boot échoué".to_string());
    }
    let lines: Vec<&str> = out.lines().collect();
    if lines.len() >= 2 {
        let parts: Vec<&str> = lines[1].split_whitespace().collect();
        if parts.len() >= 4 {
            // Available (4th column) en Kio
            if let Ok(avail_k) = parts[3].parse::<u64>() {
                return Ok(DiskSpace { free: avail_k * 1024 });
            }
        }
    }
    Err("Impossible de déterminer l'espace /boot".to_string())
}

// ----------------------------------------------------------------------
// Sudo
// ----------------------------------------------------------------------

/// Structure de sortie d'une commande sudo.
pub struct SudoResult {
    pub success: bool,
    pub message: String,
}

/// Exécute une commande avec sudo (mot de passe passé sur stdin).
pub fn run_sudo(pw: &str, cmd: &str, args: &[&str]) -> (i32, String, String) {
    use std::io::Write;
    use std::process::Command;
    use std::process::Stdio;

    let mut command = Command::new("sudo");
    command.arg("-S").arg("-p").arg("- ");
    command.arg(cmd);
    for a in args {
        command.arg(a);
    }

    let mut child = match command
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
    {
        Ok(c) => c,
        Err(e) => return (-1, String::new(), format!("spawn : {}", e)),
    };

    if let Some(mut stdin) = child.stdin.take() {
        let _ = stdin.write_all(pw.as_bytes());
        let _ = stdin.flush();
    }

    let status = match child.wait() {
        Ok(s) => s,
        Err(e) => return (-1, String::new(), format!("wait : {}", e)),
    };

    let stdout = child
        .stdout
        .and_then(|mut s| {
            let mut buf = String::new();
            use std::io::Read;
            let _ = s.read_to_string(&mut buf);
            Some(buf)
        })
        .unwrap_or_default();
    let stderr = child
        .stderr
        .and_then(|mut s| {
            let mut buf = String::new();
            use std::io::Read;
            let _ = s.read_to_string(&mut buf);
            Some(buf)
        })
        .unwrap_or_default();

    (status.code().unwrap_or(-1), stdout, stderr)
}

/// Exécute une commande simple (sans sudo).
pub fn run(cmd: &str, args: &[&str]) -> (i32, String, String) {
    use std::process::Command;
    let output = match Command::new(cmd).args(args).output() {
        Ok(o) => o,
        Err(e) => return (-1, String::new(), e.to_string()),
    };
    (
        output.status.code().unwrap_or(-1),
        String::from_utf8_lossy(&output.stdout).to_string(),
        String::from_utf8_lossy(&output.stderr).to_string(),
    )
}

// ----------------------------------------------------------------------
// GRUB2
// ----------------------------------------------------------------------

/// Génère la config GRUB2.
pub fn run_grub2_mkconfig(pw: &str) -> SudoResult {
    let (code, _out, err) = run_sudo(pw, "grub2-mkconfig", &["-o", "/boot/grub/grub.cfg"]);
    if code != 0 {
        SudoResult {
            success: false,
            message: format!("grub2-mkconfig : {}", err.trim()),
        }
    } else {
        SudoResult {
            success: true,
            message: "ok".to_string(),
        }
    }
}

// ----------------------------------------------------------------------
// Password
// ----------------------------------------------------------------------

/// Demande le mot de passe root via le dialogue Qt.
/// Le caller (main.rs) gère le thread UI.
pub fn ask_root_password() -> Option<String> {
    None // placeholder — main.rs gère le dialogue
}
