%global pkgname kernel-manager
%global pkgversion 1.0.0
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
Requires: coreutils

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
* Sat Nov 15 2026 doudou00666 <doudou00666@gmail.com> - 1.0.0-1
First release.
