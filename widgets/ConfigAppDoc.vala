/* -*- Mode: Vala; indent-tabs-mode: nil; tab-width: 2 -*- */
using GLib;

namespace DejaDup {

public class ConfigAppDoc : ConfigWidget
{
  public ConfigAppDoc()
  {
    //Object(key: key, ns: ns);
  }

  protected Gtk.HBox hbox;
  protected Gtk.Image icon;
  protected new Gtk.Label label;
  protected new Gtk.Label status;
  protected Gtk.Arrow next;
  protected Gtk.EventBox event_box;
  protected bool user_driven = true;
  construct {
    Gtk.Alignment align;
    align = new Gtk.Alignment(0.5f, 0.5f, 1.0f, 1.0f);
    align.left_padding = 5;
    align.right_padding = 5;
    add(align);

    hbox = new Gtk.HBox(false, 5);
    align.add(hbox);

    icon = new Gtk.Image.from_icon_name ("gnome-documents", Gtk.IconSize.BUTTON);
    
    label = new Gtk.Label("%s".printf(_("Documents and Data")));
    label.set("use-markup", true,
              "xalign", 0.0f);

    var settings = DejaDup.get_settings(APPS_ROOT+".document-data");
    var val = settings.get_boolean(BACKUP_KEY);

    if(val)
        status =  new Gtk.Label("%s".printf(_("On")));
    else
        status =  new Gtk.Label("%s".printf(_("Off")));
    status.set("use-markup", true, "xalign", 0.0f);

    next = new Gtk.Arrow(Gtk.ArrowType.RIGHT, Gtk.ShadowType.ETCHED_IN);

    this.event_box = new Gtk.EventBox();
    this.event_box.add(next);
//    this.event_box.realize();
    this.event_box.set_size_request(30,30);

    this.event_box.add_events(Gdk.EventMask.BUTTON_PRESS_MASK);
    event_box.button_press_event.connect(this.on_click);

    fill_box();

    set_from_config.begin();
    event_box.show();
  }

  protected virtual void fill_box()
  {
    hbox.pack_start(icon, false, false, 0);
    hbox.pack_start(label, false, false, 0);
    hbox.pack_end(event_box, false, false, 0);
    hbox.pack_end(status, false, false, 0);
  }

  protected override async void set_from_config()
  {
  }

  private bool on_click(Gdk.EventButton event) {
    var docdlg = new DejaDup.ConfigDocDialog();
    docdlg.set_transient_for(get_ancestor(typeof(Gtk.Window)) as Gtk.Window);
    docdlg.doc_toggled.connect(on_doc_toggled);
    docdlg.show_all();

    return true;
  }

  protected void on_doc_toggled(bool sensitivity) {
    if(sensitivity)
        status.set_text(_("On"));
    else
        status.set_text(_("Off"));
  }

}

}

