//! Source de noyaux externes : fetching de versions disponibles.
//! Adaptation Fedora : mêmes sources Arch (CachyOS, Zen, Liquorix).

use serde::{Deserialize, Serialize};
use std::fs;
use std::io::{Read, Write};
use std::path::Path;
use std::path::PathBuf;

/// Type de noyau externe.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
pub enum KernelKind {
    Cachyos,
    Zen,
    Liquorix,
}

impl KernelKind {
    pub fn label(&self) -> &'static str {
        match self {
            KernelKind::Cachyos => "CachyOS",
            KernelKind::Zen => "Zen",
            KernelKind::Liquorix => "Liquorix",
        }
    }

    pub fn from_label(s: &str) -> Option<Self> {
        match s {
            "CachyOS" => Some(KernelKind::Cachyos),
            "Zen" => Some(KernelKind::Zen),
            "Liquorix" => Some(KernelKind::Liquorix),
            _ => None,
        }
    }

    /// Suffixe unique pour identifier un noyau de ce type.
    pub fn unique_suffix(&self) -> &'static str {
        match self {
            KernelKind::Cachyos => "-cachyos",
            KernelKind::Zen => ".zen",
            KernelKind::Liquorix => "-lqx",
        }
    }

    /// URL de base du dépôt pacman.
    pub fn repo_base(&self) -> &'static str {
        match self {
            KernelKind::Cachyos => "https://repo.cachyos.org/x86_64/",
            KernelKind::Zen => "https://repo.zen-kernel.org/x86_64/",
            KernelKind::Liquorix => "https://liquorix-org.org/archlinux/",
        }
    }

    /// Préfixe du nom de paquet.
    pub fn package_prefix(&self) -> &'static str {
        match self {
            KernelKind::Cachyos => "cachyos-linux",
            KernelKind::Zen => "zen",
            KernelKind::Liquorix => "linux-liquorix",
        }
    }
}

/// Un noyau spécifique (version dans le dépôt).
#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct KernelRelease {
    /// Version d'affichage (ex : "6.8.6-1").
    pub version: String,
    /// Version du noyau (ex : "6.8.6-1-cachyos").
    pub kernel_version: String,
    /// Type de noyau.
    pub kind: KernelKind,
    /// URL du tarball.
    pub url: String,
    /// Taille compressed (octets).
    pub csize: u64,
    /// SHA256 du fichier.
    pub sha256: String,
    /// Date de modification (ISO 8601).
    pub modified: Option<String>,
}

/// Fetch les versions disponibles d'un dépôt.
pub fn fetch_latest_kernels(kind: KernelKind) -> Result<Vec<KernelRelease>, String> {
    let base = kind.repo_base();
    let prefix = kind.package_prefix().to_string();
    let mut releases: Vec<KernelRelease> = Vec::new();

    let resp = ureq::get(base)
        .set("User-Agent", "kernel-manager/1.0")
        .call()
        .map_err(|e| format!("HTTP : {}", e))?;
    let body = resp.into_string().map_err(|e| format!("body : {}", e))?;

    for line in body.lines() {
        let line = line.trim();
        let file_name = extract_filename(line);
        if file_name.is_empty() {
            continue;
        }
        if file_name.starts_with(&prefix) && file_name.ends_with(".tar.xz") {
            let ver = file_name
                .strip_prefix(&prefix)
                .and_then(|s| s.strip_prefix('-'))
                .and_then(|s| s.strip_suffix(".tar.xz"))
                .unwrap_or("")
                .to_string();
            if !ver.is_empty() {
                let kver = format!("{}-{}", ver, suffix_for_kind(kind));
                releases.push(KernelRelease {
                    version: ver.clone(),
                    kernel_version: kver,
                    kind,
                    url: format!("{}{}", base, file_name),
                    csize: 0,
                    sha256: String::new(),
                    modified: None,
                });
            }
        }
    }

    // Trier : plus récent d'abord.
    releases.sort_by(|a, b| b.version.cmp(&a.version));
    Ok(releases)
}

/// URL du tarball .tar.xz pour une version donnée d'un dépôt.
pub fn repo_url(version: &str, kind: KernelKind) -> String {
    let base = kind.repo_base();
    let prefix = kind.package_prefix();
    format!("{}{}-{}.tar.xz", base, prefix, version)
}

/// Extrait le nom de fichier depuis une ligne HTML/listing.
fn extract_filename(line: &str) -> String {
    let mut s = line.to_string();
    // Virgule (listing HTML) : "name, size, date"
    if s.contains(',') {
        s = s.split(',').next().unwrap_or("").to_string();
    }
    if s.contains('/') {
        s = s.split('/').next_back().unwrap_or(&s).to_string();
    }
    if s.contains('.') {
        s = s.split('?').next().unwrap_or(&s).to_string();
    }
    s.trim().to_string()
}

fn suffix_for_kind(kind: KernelKind) -> &'static str {
    match kind {
        KernelKind::Cachyos => "cachyos",
        KernelKind::Zen => "zen",
        KernelKind::Liquorix => "lqx",
    }
}

/// Callback de progression : (écrit, total).
pub type ProgressFn = dyn Fn(u64, u64);

/// Télécharge un fichier avec progression.
pub fn download_kernel(
    k: &KernelRelease,
    progress: &ProgressFn,
) -> Result<PathBuf, String> {
    let tmp_dir = PathBuf::from(format!("/tmp/km-dl-{}", std::process::id()));
    fs::create_dir_all(&tmp_dir).map_err(|e| e.to_string())?;
    let dest = tmp_dir.join(format!("{}.tar.xz", k.kernel_version));
    let url = &k.url;

    let resp = ureq::get(url)
        .set("User-Agent", "kernel-manager/1.0")
        .call()
        .map_err(|e| e.to_string())?;

    let total = resp
        .header("Content-Length")
        .and_then(|s| s
            .parse::<u64>()
            .ok())
        .unwrap_or(0);

    let mut body = resp.into_reader();
    let mut file = fs::OpenOptions::new()
        .create(true)
        .write(true)
        .truncate(true)
        .open(&dest)
        .map_err(|e| e.to_string())?;

    let mut written = 0u64;
    let mut buf = [0u8; 65536];
    loop {
        let n = body.read(&mut buf).map_err(|e| e.to_string())?;
        if n == 0 {
            break;
        }
        file.write_all(&buf[..n]).map_err(|e| e.to_string())?;
        written += n as u64;
        if total > 0 {
            progress(written, total);
        }
    }
    drop(file);

    // Vérifier le SHA256.
    if !k.sha256.is_empty() {
        let hash = sha256_of_file(&dest)?;
        if hash != k.sha256
        {
            let _ = fs::remove_file(&dest);
            return Err(format!(
                "SHA256 ne correspond pas : attendu {}, calculé {}",
                k.sha256, hash
            ));
        }
    }

    Ok(dest)
}

/// Extrait un tarball .tar.xz dans un répertoire.
pub fn extract_tarball(tar_path: &Path, dest_dir: &Path) -> Result<(), String> {
    // 1. Décompresser xz → .tar (xz -f -d remplace le fichier).
    let (code, _o, err) = run_cmd("xz", &[&tar_path.to_string_lossy(), "-f", "-d"]);
    if code != 0 {
        return Err(format!("xz échoué : {}", err.trim()));
    }
    let tar_path = tar_path.with_extension("tar");

    // 2. Extraire le tar.
    let (code, _o, err) = run_cmd(
        "tar",
        &[
            "-xf",
            &tar_path.to_string_lossy(),
            "-C",
            &dest_dir.to_string_lossy(),
        ],
    );
    if code != 0 {
        return Err(format!("tar échoué : {}", err.trim()));
    }
    Ok(())
}

fn run_cmd(cmd: &str, args: &[&str]) -> (i32, String, String) {
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

fn sha256_of_file(path: &Path) -> Result<String, String> {
    use sha2::{Digest, Sha256};
    let mut file = fs::File::open(path).map_err(|e| e.to_string())?;
    let mut hasher = Sha256::new();
    let mut buf = [0u8; 8192];
    loop {
        let n = file.read(&mut buf).map_err(|e| e.to_string())?;
        if n == 0 {
            break;
        }
        hasher.update(&buf[..n]);
    }
    let result = hasher.finalize();
    Ok(hex::encode(result.as_slice()))
}

// ----------------------------------------------------------------------
// Tests unitaires
// ----------------------------------------------------------------------

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn kernel_kind_labels() {
        assert_eq!(KernelKind::Cachyos.label(), "CachyOS");
        assert_eq!(KernelKind::Zen.label(), "Zen");
        assert_eq!(KernelKind::Liquorix.label(), "Liquorix");
    }

    #[test]
    fn kernel_kind_from_label() {
        assert_eq!(KernelKind::from_label("CachyOS"), Some(KernelKind::Cachyos));
        assert_eq!(KernelKind::from_label("Zen"), Some(KernelKind::Zen));
        assert_eq!(KernelKind::from_label("Liquorix"), Some(KernelKind::Liquorix));
        assert_eq!(KernelKind::from_label("unknown"), None);
    }

    #[test]
    fn kernel_kind_unique_suffix() {
        assert_eq!(KernelKind::Cachyos.unique_suffix(), "-cachyos");
        assert_eq!(KernelKind::Zen.unique_suffix(), ".zen");
        assert_eq!(KernelKind::Liquorix.unique_suffix(), "-lqx");
    }

    #[test]
    fn test_suffix_for_kind() {
        assert_eq!(suffix_for_kind(KernelKind::Cachyos), "cachyos");
        assert_eq!(suffix_for_kind(KernelKind::Zen), "zen");
        assert_eq!(suffix_for_kind(KernelKind::Liquorix), "lqx");
    }

    #[test]
    fn kernel_release_serialization() {
        let kr = KernelRelease {
            version: "6.8.6-1".to_string(),
            kernel_version: "6.8.6-1-cachyos".to_string(),
            kind: KernelKind::Cachyos,
            url: "https://example.com/pkg.tar.xz".to_string(),
            csize: 50_000_000,
            sha256: "abc123".to_string(),
            modified: Some("2025-01-01T00:00:00Z".to_string()),
        };
        let json = serde_json::to_string(&kr).unwrap();
        let parsed: KernelRelease = serde_json::from_str(&json).unwrap();
        assert_eq!(parsed.version, "6.8.6-1");
        assert_eq!(parsed.kind, KernelKind::Cachyos);
    }

    #[test]
    fn extract_filename_simple() {
        assert_eq!(extract_filename("cachyos-linux-6.8.6-1.tar.xz"), "cachyos-linux-6.8.6-1.tar.xz");
    }

    #[test]
    fn extract_filename_comma() {
        assert_eq!(
            extract_filename("cachyos-linux-6.8.6-1.tar.xz, 5000000, 2025"),
            "cachyos-linux-6.8.6-1.tar.xz"
        );
    }
}
