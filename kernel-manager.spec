%global pkgname kernel-manager
%global pkgversion 1.0.4
%global pkgrelease 1
%global pkgarch x86_64

Name: %{pkgname}
Version: %{pkgversion}
Release: %{pkgrelease}%{?dist}
Summary: Gestionnaire de noyaux externes pour Fedora
License: GPL-3.0-or-later
URL: https://github.com/doudou00666/gestionnaire-de-kernel
Source: %{pkgname}-%{pkgversion}.tar.gz
BuildRequires: rust
BuildRequires: cargo
BuildRequires: gcc
BuildRequires: gcc-c++
BuildRequires: gtk4-devel
BuildRequires: pkgconf-pkg-config
Requires: coreutils
Requires: gtk4

%description
Gestionnaire de noyaux externes pour Fedora.
Permet d'installer, lister et supprimer des noyaux externes
(CachyOS, Zen, Liquorix) sur un système Fedora avec GRUB2.

%prep
%autosetup -n %{pkgname}

%build
cargo build --release

%install
install -D -m 755 target/release/%{pkgname} %{buildroot}/%{_bindir}/%{pkgname}
install -D -m 644 %{pkgname}.desktop %{buildroot}/%{_datadir}/applications/%{pkgname}.desktop

%files
%{_bindir}/%{pkgname}
%{_datadir}/applications/%{pkgname}.desktop

%changelog
* Mon Nov 16 2026 doudou00666 <doudou00666@gmail.com> - 1.0.4-1
Correction du crash SIGSEGV au lancement de la GUI. La fenêtre GTK4
était créée avant app.run() (avant l'initialisation du CSS), ce qui
causait un SIGSEGV dans gtk_css_static_style_get_default. La fenêtre
est désormais créée dans le handler connect_activate, après
l'initialisation de GTK4. 19 tests unitaires validés.

* Sat Nov 15 2026 doudou00666 <doudou00666@gmail.com> - 1.0.3-1
Ajout de l'interface graphique GTK4 (fenêtre principale, choix du type
de noyau, liste des versions, barre de progression, journal, boutons
Rafraîchir/Installer). Terminal=false dans le desktop file. 19 tests
unitaires validés.

* Sat Nov 15 2026 doudou00666 <doudou00666@gmail.com> - 1.0.2-1
Correction: Terminal=true dans le desktop file (CLI), Categories=System

* Sat Nov 15 2026 doudou00666 <doudou00666@gmail.com> - 1.0.1-1
Correction du desktop file: Exec=/usr/bin/kernel-manager (absolu) pour KDE Plasma

* Sat Nov 15 2026 doudou00666 <doudou00666@gmail.com> - 1.0.0-1
First release.
