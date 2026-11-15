//! Interface graphique GTK4 pour le gestionnaire de noyaux.
//!
//! Fenêtre principale : choix du type de noyau (CachyOS / Zen /
//! Liquorix), liste des versions disponibles, barre de progression
//! du téléchargement, journal d'activité et boutons Rafraîchir /
//! Installer.
//!
//! Les widgets GTK4 ne sont pas `Send` ; toute logique interactive
//! est donc exécutée via `gtk4::glib::spawn_future_local`, qui reste
//! sur le thread principal du main loop et permet d'actualiser
//! directement les widgets.

use crate::repo::{fetch_latest_kernels, KernelKind};
use crate::sysutil::running_kernel;
use gtk4::gio::ApplicationFlags;
use gtk4::glib::spawn_future_local;
use gtk4::prelude::*;
use gtk4::{
    Align, Application, ApplicationWindow, Button, ComboBoxText, Box, Label, Orientation,
    ProgressBar, ScrolledWindow,
};

/// Une version mise en cache pour le clic d'installation.
#[derive(Debug, Clone)]
pub struct Cached {
    pub version: String,
    pub kernel_version: String,
    pub kind: KernelKind,
}

impl Cached {
    pub fn new(version: &str, kind: KernelKind) -> Self {
        Cached {
            version: version.to_string(),
            kernel_version: format!("{}{}", version, kind.unique_suffix()),
            kind,
        }
    }
}

/// Type de noyau choisi, d'après l'index actif du ComboBox.
fn kind_of_combo(active: Option<u32>) -> KernelKind {
    match active {
        Some(0) => KernelKind::Cachyos,
        Some(1) => KernelKind::Zen,
        Some(2) => KernelKind::Liquorix,
        _ => KernelKind::Cachyos,
    }
}

/// Journal dans le Box : ajoute une ligne de texte.
fn log(journal: &Box, msg: &str) {
    let l = Label::new(Some(msg));
    journal.append(&l);
}

/// Construit l'interface principale et retourne la fenêtre.
pub fn build_gui(app: &Application) -> ApplicationWindow {
    let window = ApplicationWindow::new(app);
    window.set_title(Some("Gestionnaire de Noyaux"));
    window.set_default_size(720, 540);

    let vbox = Box::new(Orientation::Vertical, 8);
    window.set_child(Some(&vbox));

    // -- Noyau courant --
    let running = running_kernel();
    let info = Label::new(Some(
        format!("Noyau en cours : {}", running).as_str(),
    ));
    info.set_halign(Align::Start);
    vbox.append(&info);

    // -- Type de noyau --
    let kind_label = Label::new(Some("Type de noyau :"));
    kind_label.set_halign(Align::Start);
    vbox.append(&kind_label);
    let combo = ComboBoxText::new();
    combo.append_text("CachyOS");
    combo.append_text("Zen");
    combo.append_text("Liquorix");
    combo.set_active(Some(0));
    vbox.append(&combo);

    // -- Versions disponibles --
    let list_label = Label::new(Some("Versions disponibles :"));
    list_label.set_halign(Align::Start);
    vbox.append(&list_label);
    let list_box = Box::new(Orientation::Vertical, 0);
    let scroll = ScrolledWindow::new();
    scroll.set_min_content_height(140);
    scroll.set_child(Some(&list_box));
    vbox.append(&scroll);

    // -- Barre de progression --
    let prog_label = Label::new(Some("Téléchargement :"));
    prog_label.set_halign(Align::Start);
    vbox.append(&prog_label);
    let progress = ProgressBar::new();
    progress.set_fraction(0.0);
    vbox.append(&progress);

    // -- Journal --
    let journal_label = Label::new(Some("Journal :"));
    journal_label.set_halign(Align::Start);
    vbox.append(&journal_label);
    let journal = Box::new(Orientation::Vertical, 0);
    let scroll2 = ScrolledWindow::new();
    scroll2.set_min_content_height(120);
    scroll2.set_child(Some(&journal));
    vbox.append(&scroll2);

    // -- Boutons --
    let btn_box = Box::new(Orientation::Horizontal, 8);
    let refresh_btn = Button::new();
    refresh_btn.set_label("Rafraîchir les versions");
    let install_btn = Button::new();
    install_btn.set_label("Installer le noyau sélectionné");
    install_btn.set_sensitive(false);
    btn_box.append(&refresh_btn);
    btn_box.append(&install_btn);
    vbox.append(&btn_box);

    // Cloner les widgets AVANT les closures (move ...)
    let combo_ref = combo.clone();
    let list_box_ref = list_box.clone();
    let journal_ref = journal.clone();
    let install_btn_ref = install_btn.clone();

    // Rafraîchir : lister les versions du kind sélectionné.
    let combo_c1 = combo_ref.clone();
    let list_box_c1 = list_box_ref.clone();
    let journal_c1 = journal_ref.clone();
    let install_btn_c1 = install_btn_ref.clone();
    refresh_btn.connect_clicked(move |_| {
        let combo = combo_c1.clone();
        let list_box = list_box_c1.clone();
        let journal = journal_c1.clone();
        let install_btn = install_btn_c1.clone();
        spawn_future_local(async move {
            let kind = kind_of_combo(combo.active());
            journal.append(&Label::new(Some(
                format!("Recherche des versions de {}…", kind.label()).as_str(),
            )));
            let releases = fetch_latest_kernels(kind);
            match releases {
                Ok(rs) => {
                    journal.append(&Label::new(Some(
                        format!(
                            "{} versions trouvées pour {}.",
                            rs.len(),
                            kind.label()
                        )
                        .as_str(),
                    )));
                    install_btn.set_sensitive(true);
                    for rel in &rs {
                        list_box.append(&Label::new(Some(
                            format!(
                                "{}  ({}{})",
                                rel.version,
                                kind.label(),
                                kind.unique_suffix()
                            )
                            .as_str(),
                        )));
                    }
                }
                Err(e) => {
                    journal.append(&Label::new(Some(format!("Erreur : {}", e).as_str())));
                    install_btn.set_sensitive(false);
                }
            }
        });
    });

    // Installer : afficher la commande d'installation de la première version.
    let combo_c2 = combo_ref.clone();
    let list_box_c2 = list_box_ref.clone();
    let journal_c2 = journal_ref.clone();
    install_btn.connect_clicked(move |_| {
        let combo = combo_c2.clone();
        let list_box = list_box_c2.clone();
        let journal = journal_c2.clone();
        spawn_future_local(async move {
            let kind = kind_of_combo(combo.active());
            let _ = kind;
            let first = list_box.first_child();
            let msg = match first {
                Some(child) => {
                    let text = child.downcast::<Label>().map(|l| l.text().to_string())
                        .unwrap_or_default();
                    let version = text.split_whitespace().next().unwrap_or("").to_string();
                    if version.is_empty() {
                        "Sélectionnez une version dans la liste.".to_string()
                    } else {
                        format!(
                            "Téléchargement de {}…\nPour l'installer :\n  sudo kernel-manager install {}",
                            version, version
                        )
                    }
                }
                None => "Aucune version à installer : cliquez Rafraîchir d'abord.".to_string(),
            };
            journal.append(&Label::new(Some(msg.as_str())));
        });
    });

    window
}

/// Point d'entrée de la GUI.
pub fn run_gui() {
    let app = Application::new(
        Some("org.fedoraproject.kernelmanager"),
        ApplicationFlags::FLAGS_NONE,
    );
    let window = build_gui(&app);
    window.present();
    app.run();
}

#[cfg(test)]
mod tests {
    use super::*;

    /// Le type de noyau correspond à l'index du ComboBox.
    #[test]
    fn kind_of_combo_index() {
        assert_eq!(kind_of_combo(Some(0)), KernelKind::Cachyos);
        assert_eq!(kind_of_combo(Some(1)), KernelKind::Zen);
        assert_eq!(kind_of_combo(Some(2)), KernelKind::Liquorix);
        assert_eq!(kind_of_combo(Some(9)), KernelKind::Cachyos);
        assert_eq!(kind_of_combo(None), KernelKind::Cachyos);
    }

    /// La version d'affichage est correcte pour chaque kind.
    #[test]
    fn cached_kernel_version() {
        let c = Cached::new("6.8.6-1", KernelKind::Cachyos);
        assert_eq!(c.kernel_version, "6.8.6-1-cachyos");
        let c = Cached::new("6.8.6-1", KernelKind::Zen);
        assert_eq!(c.kernel_version, "6.8.6-1.zen");
        let c = Cached::new("6.8.6-1", KernelKind::Liquorix);
        assert_eq!(c.kernel_version, "6.8.6-1-lqx");
    }
}
