//! Installation de noyaux externes sur Fedora.
//!
//! Layout Fedora :
//!   /boot/vmlinuz-{release}
//!   /boot/initrd-{release}.img
//!   /lib/modules/{release}
//!
//! GRUB2 détecte automatiquement ces fichiers.

use crate::repo::{KernelKind};
use crate::sysutil;
use std::fs;
use std::path::PathBuf;

/// Un noyau externe installé (pour la list UI).
#[derive(Debug, Clone)]
pub struct InstalledKernel {
    /// nom de la version
    pub version: String,
    /// type
    pub kind: KernelKind,
    /// en cours d'exécution ?
    pub running: bool,
    /// version d'affichage (peut être différente de version)
    pub display_version: String,
    /// chemins
    pub path: KernelPaths,
}

/// Chemins d'installation Fedora.
#[derive(Debug, Clone)]
pub struct KernelPaths {
    pub vmlinuz: PathBuf,
    pub initrd: PathBuf,
    pub modules: PathBuf,
    /// Entrée de boot (informative)
    pub boot_entry: PathBuf,
}

impl KernelPaths {
    pub fn for_version(v: &str) -> Self {
        Self {
            vmlinuz: PathBuf::from(format!("/boot/vmlinuz-{}", v)),
            initrd: PathBuf::from(format!("/boot/initrd-{}.img", v)),
            modules: PathBuf::from(format!("/lib/modules/{}", v)),
            boot_entry: PathBuf::from(format!("/boot/EFI/entries/{}.conf", v)),
        }
    }
}

/// Callback de progression (étape 1..8, texte).
pub type StepFn = dyn Fn(u32, &str);

// ----------------------------------------------------------------------
// liste des noyaux installés
// ----------------------------------------------------------------------

/// Liste des noyaux externes installés sur la machine.
pub fn list_installed() -> Vec<InstalledKernel> {
    let running = sysutil::running_kernel();
    let mut out = Vec::new();

    // D'abord le registre (source de vérité)
    let reg = sysutil::read_registry();
    for (name, _entry) in &reg {
        if let Some(kind) = sysutil::registry_kind(name) {
            let display = sysutil::registry_display(name).unwrap_or_else(|| name.clone());
            let path = KernelPaths::for_version(name);
            out.push(InstalledKernel {
                version: name.clone(),
                kind,
                running: name == &running,
                display_version: display.clone(),
                path,
            });
        }
    }

    // Compléter par détection (modules + guess_kind)
    let installed = sysutil::installed_ext_kernels();
    for name in &installed {
        // Ne pas dupliquer
        if !out.iter().any(|k| k.version == *name) {
            if let Some(kind) = sysutil::guess_kind(name) {
                out.push(InstalledKernel {
                    version: name.clone(),
                    kind,
                    running: name == &running,
                    display_version: name.clone(),
                    path: KernelPaths::for_version(name),
                });
            }
        }
    }

    out.sort_by(|a, b| b.version.cmp(&a.version));
    out
}

// ----------------------------------------------------------------------
// installation
// ----------------------------------------------------------------------

/// Installe un noyau externe à partir d'un tarball pacman.
///
/// `pw` : mot de passe root
/// `path` : chemin du tarball .tar.xz
/// `kernel_version` : nom du noyau (ex : 6.8.6-cachyos)
/// `kind` : type de noyau
/// `step` : callback de progression (étape, texte)
///
/// Retourne le chemin de l'entrée de boot (informative).
pub fn install_kernel(
    pw: &str,
    path: &PathBuf,
    kernel_version: &str,
    kind: KernelKind,
    step: &StepFn,
) -> Result<String, String> {
    let kp = KernelPaths::for_version(kernel_version);
    let tmp_extract = PathBuf::from(format!(
        "/tmp/km-extract-{}",
        std::process::id()
    ));
    let _ = fs::remove_dir_all(&tmp_extract);
    let _ = fs::create_dir_all(&tmp_extract);

    // 1. Extract
    step(1, "Extraction du tarball…");
    crate::repo::extract_tarball(&path, &tmp_extract)
        .map_err(|e| format!("Extraction : {}", e))?;

    // 2. Identifier le nom du noyau (vmlinuz)
    step(2, "Identification du noyau…");
    let release = find_kernel_release(&tmp_extract, kernel_version);
    if release.is_empty() {
        let _ = fs::remove_dir_all(&tmp_extract);
        return Err("Impossible d'identifier le nom du noyau (vmlinuz)".to_string());
    }

    // 3. Vérifier espace /boot
    step(3, "Vérification de l'espace /boot…");
    if let Ok(sp) = sysutil::boot_space_with_sudo(pw) {
        if sp.free < 50_000_000 {
            let _ = fs::remove_dir_all(&tmp_extract);
            return Err(format!(
                "Espace insuffisant sur /boot : {} Mo libres, il faut ≥ 50 Mo",
                sp.free / 1_000_000
            ));
        }
    }

    // 4. Copier vmlinuz + initrd
    step(4, "Copie de vmlinuz + initrd dans /boot…");
    install_to_boot(&kp, &tmp_extract, pw)
        .map_err(|e| format!("Copie /boot : {}", e))?;

    // 5. Copier les modules
    step(5, "Installation des modules dans /lib/modules/…");
    install_modules(&kp.modules, &tmp_extract, pw)
        .map_err(|e| format!("Modules : {}", e))?;

    // 6. Régénérer GRUB2
    step(6, "Régénération de GRUB2…");
    let grub = sysutil::run_grub2_mkconfig(pw);
    if !grub.success {
        let _ = fs::remove_dir_all(&tmp_extract);
        return Err(format!(
            "GRUB2 n'a pas été régénéré : {}",
            grub.message
        ));
    }

    // 7. Enregistrer dans le registre
    step(7, "Enregistrement…");
    sysutil::record_install(&release, kind, Some(kernel_version));

    // 8. Nettoyage
    step(8, "Nettoyage…");
    let _ = fs::remove_dir_all(&tmp_extract);

    // Retourner l'entrée de boot (informative)
    Ok(format!("/boot/vmlinuz-{}", release))
}

fn install_to_boot(
    kp: &KernelPaths,
    extract_dir: &PathBuf,
    pw: &str,
) -> Result<(), String> {
    let mut errors = Vec::new();

    // vmlinuz
    let src_vmlinuz = find_file_in_dir(extract_dir, &kp.vmlinuz.file_name().unwrap().to_string_lossy().to_string());
    match src_vmlinuz {
        Some(src) => {
            let (code, _o, e) = sysutil::run_sudo(pw, "cp", &[&src, &kp.vmlinuz.to_string_lossy()]);
            if code != 0 {
                errors.push(format!("cp vmlinuz : {}", e.trim()));
            }
        }
        None => errors.push("vmlinuz introuvable dans le paquet".to_string()),
    }

    // initrd
    let initrd_name = kp.initrd.file_name().unwrap().to_string_lossy().to_string();
    let src_initrd = find_file_in_dir(extract_dir, &initrd_name);
    if let Some(src) = src_initrd {
        let (code, _o, e) = sysutil::run_sudo(pw, "cp", &[&src, &kp.initrd.to_string_lossy()]);
        if code != 0 {
            errors.push(format!("cp initrd : {}", e.trim()));
        }
    }

    if !errors.is_empty() {
        return Err(errors.join("; "));
    }
    Ok(())
}

fn install_modules(modules_dst: &PathBuf, extract_dir: &PathBuf, pw: &str) -> Result<(), String> {
    // Chercher le dossier modules
    let modules_src = find_dir_in_dir(extract_dir, "modules");
    match modules_src {
        Some(src) => {
            let (code, _o, e) = sysutil::run_sudo(pw, "cp", &[
                "-r",
                &src,
                &format!("/lib/"),
            ]);
            if code != 0 {
                return Err(format!("cp modules : {}", e.trim()));
            }
            // Renommer le dossier modules
            let mod_name = src
                .strip_prefix("/")
                .unwrap_or(&src)
                .to_string();
            let dir_name = mod_name.rsplit('/').next().unwrap_or(&mod_name).to_string();
            let (code, _o, e) = sysutil::run_sudo(pw, "mv", &[
                &format!("/lib/{}", dir_name),
                &modules_dst.to_string_lossy(),
            ]);
            if code != 0 {
                // Le dossier modules est peut-être déjà au bon endroit
                // (si cp -r a copié directement)
                if modules_dst.exists() {
                    return Ok(());
                }
                return Err(format!("mv modules : {}", e.trim()));
            }
        }
        None => {
            return Err("Dossier modules introuvable dans le paquet".to_string());
        }
    }
    Ok(())
}

fn find_file_in_dir(dir: &PathBuf, name: &str) -> Option<String> {
    let mut stack = vec![dir.clone()];
    while let Some(current) = stack.pop() {
        if let Ok(entries) = fs::read_dir(&current) {
            for entry in entries.flatten() {
                let p = entry.path();
                if p.is_file() {
                    if let Some(n) = p.file_name() {
                        if n.to_string_lossy() == name {
                            return Some(p.to_string_lossy().to_string());
                        }
                    }
                } else if p.is_dir() {
                    stack.push(p);
                }
            }
        }
    }
    None
}

fn find_dir_in_dir(dir: &PathBuf, name: &str) -> Option<String> {
    let mut stack = vec![dir.clone()];
    while let Some(current) = stack.pop() {
        if let Ok(entries) = fs::read_dir(&current) {
            for entry in entries.flatten() {
                let p = entry.path();
                if p.is_dir() {
                    if let Some(n) = p.file_name() {
                        if n.to_string_lossy() == name {
                            return Some(p.to_string_lossy().to_string());
                        }
                    }
                    stack.push(p);
                }
            }
        }
    }
    None
}

fn find_kernel_release(extract_dir: &PathBuf, expected: &str) -> String {
    // Chercher vmlinuz-*.
    if let Some(path) = find_file_in_dir(extract_dir, &format!("vmlinuz-{}", expected)) {
        let name = PathBuf::from(&path)
            .file_name()
            .unwrap()
            .to_string_lossy()
            .to_string();
        name.strip_prefix("vmlinuz-").unwrap_or(&name).to_string()
    } else {
        // Fallback : chercher un vmlinuz-*.
        let boot_dir = extract_dir.join("boot");
        let vmlinuz_files: Vec<PathBuf> = fs::read_dir(&boot_dir)
            .map(|d| {
                d.flatten()
                    .filter(|e| {
                        e.file_name()
                            .to_string_lossy()
                            .starts_with("vmlinuz-")
                    })
                    .map(|e| e.path())
                    .collect()
            })
            .unwrap_or_default();

        if let Some(v) = vmlinuz_files.first() {
            let name = v.file_name().unwrap().to_string_lossy().to_string();
            name.strip_prefix("vmlinuz-").unwrap_or(&name).to_string()
        } else {
            expected.to_string()
        }
    }
}

// ----------------------------------------------------------------------
// suppression
// ----------------------------------------------------------------------

/// Supprime un noyau externe installé.
pub fn remove_kernel(pw: &str, version: &str) -> Result<(), String> {
    let kp = KernelPaths::for_version(version);

    for p in [&kp.vmlinuz, &kp.initrd] {
        if p.exists() {
            let (code, _o, _e) = sysutil::run_sudo(pw, "rm", &["-f", &p.to_string_lossy()]);
            if code != 0 {
                return Err(format!("Suppression de {} échouée", p.to_string_lossy()));
            }
        }
    }

    if kp.modules.exists() {
        let (code, _o, _e) = sysutil::run_sudo(pw, "rm", &["-rf", &kp.modules.to_string_lossy()]);
        if code != 0 {
            return Err(format!("Suppression des modules échouée"));
        }
    }

    let grub = sysutil::run_grub2_mkconfig(pw);
    if !grub.success {
        return Err(format!("GRUB2 n'a pas été régénéré : {}", grub.message));
    }

    sysutil::forget_install(version);
    Ok(())
}

// ----------------------------------------------------------------------
// Tests
// ----------------------------------------------------------------------

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn kernel_paths_fedora() {
        let kp = KernelPaths::for_version("6.8.6-cachyos");
        assert_eq!(kp.vmlinuz.to_string_lossy(), "/boot/vmlinuz-6.8.6-cachyos");
        assert_eq!(kp.initrd.to_string_lossy(), "/boot/initrd-6.8.6-cachyos.img");
        assert_eq!(kp.modules.to_string_lossy(), "/lib/modules/6.8.6-cachyos");
    }

    #[test]
    fn list_installed_returns_vec() {
        let inst = list_installed();
        assert!(inst.iter().all(|k| !k.version.is_empty()));
    }

    #[test]
    fn installed_kernel_fields() {
        let kp = KernelPaths::for_version("6.8.6-zen");
        let k = InstalledKernel {
            version: "6.8.6-zen".to_string(),
            kind: KernelKind::Zen,
            running: false,
            display_version: "6.8.6-zen".to_string(),
            path: kp,
        };
        assert_eq!(k.kind, KernelKind::Zen);
        assert!(!k.running);
        assert!(!k.version.is_empty());
    }
}
