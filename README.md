# Gestionnaire de kernel

![License](https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightblue?style=flat)


Gestionnaire de noyaux externes (CachyOS, Zen, Liquorix) pour **Fedora**.

Adapté du [solus-external-kernel-manager](https://depoa.julien68.fr/Linuxon/solus-external-kernel-manager) de Solus.

## Adaptation Solus → Fedora
- `eopkg` → `dnf` / `rpm`
- `clr-boot-manager` / systemd-boot → **GRUB2** (`grub2-mkconfig`, `GRUB_TIMEOUT`)
- Chemins standard Linux : `/boot/vmlinuz-{release}`, `/boot/initrd-{release}.img`, `/lib/modules/{release}`
- État local : `~/.local/state/kernel-manager/` + log horodaté
- CLI par défaut. La GUI Qt est derrière le feature optionnel `gui`.

## Usage (CLI)
```
kernel-manager list          # liste les noyaux externes installés
kernel-manager check         # état du système (noyau courant, espace /boot)
kernel-manager install <src> # installe un noyau external
kernel-manager remove <rel>  # supprime un noyau external
kernel-manager help
```

## Compilation
```
cargo build --release
cargo test   # 17 tests unitaires
```

## RPM
`rpm/kernel-manager-1.0.0-1.fc45.x86_64.rpm` — construit sur Fedora 45.
Fichiers contenus : `/usr/bin/kernel-manager` + `/usr/share/applications/kernel-manager.desktop`.

```
dnf install rpm/kernel-manager-1.0.0-1.fc45.x86_64.rpm
```

Le spec RPM (`kernel-manager.spec`) est en tête de repo.


