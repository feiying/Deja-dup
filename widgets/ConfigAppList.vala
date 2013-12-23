/* -*- Mode: Vala; indent-tabs-mode: nil; tab-width: 2 -*- */
using GLib;

namespace DejaDup {

public class ConfigAppList : ConfigWidget
{
  public ConfigAppList()
  {
    //Object(key: key, ns: ns);
  }

  construct {
    var scroll = new Gtk.ScrolledWindow(null, null);
    scroll.hscrollbar_policy = Gtk.PolicyType.AUTOMATIC;
    scroll.vscrollbar_policy = Gtk.PolicyType.AUTOMATIC;
    scroll.shadow_type = Gtk.ShadowType.IN;
    add(scroll);

    var viewport = new Gtk.Viewport(null, null);
    scroll.add(viewport);

    var box = new Gtk.VBox(false, 0); 
    viewport.add(box);

    settings = DejaDup.get_settings(APPS_ROOT);

    foreach (string name in settings.list_children()) {
      var file = File.new_for_path("/usr/bin/"+name);
      if(!(file.query_exists()))continue;
      var app = new DejaDup.ConfigApp(name);
      box.pack_start(app, false, false, 0);
    }

    var appphoto = new DejaDup.ConfigAppPhoto();
    box.pack_start(appphoto, false, false, 0);

    var appdoc = new DejaDup.ConfigAppDoc();
    box.pack_start(appdoc, false, false, 0);

    set_from_config.begin();
  }

  protected override async void set_from_config()
  {
  }
}

}

