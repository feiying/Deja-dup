/* -*- Mode: Vala; indent-tabs-mode: nil; tab-width: 2 -*- */
using GLib;

namespace DejaDup {

public class ConfigPhotoDialog : Gtk.Dialog {
	private Gtk.Switch button;

	public signal void photo_toggled (bool sensitivity);

	public ConfigPhotoDialog () {
		this.title = _("Photo Stream");
		this.border_width = 5;
		set_default_size (300, 100);
		set_modal(true);
		create_widgets ();
		connect_signals ();
	}

	private void create_widgets () {
		// Create and setup widgets
		Gtk.Label label = new Gtk.Label.with_mnemonic (_("Photo Stream"));
		button = new Gtk.Switch();
		Gtk.Label description = new Gtk.Label.with_mnemonic (_("Automatically upload photos and send them to all of you devices."));
		description.set("use-markup", true,
              		"xalign", 0.5f);

		// Layout widgets
		Gtk.Box hbox = new Gtk.Box (Gtk.Orientation.HORIZONTAL, 20);
		hbox.pack_start (label, false, true, 0);
		hbox.pack_end (button, false, false, 0);

		Gtk.Box content = get_content_area () as Gtk.Box;
		content.pack_start (hbox, false, true, 0);
		//content.pack_end (description, false, true, 0);
		content.spacing = 10;

		var settings = DejaDup.get_settings(APPS_ROOT+".photo-stream");
                var value = settings.get_boolean(BACKUP_KEY);
                button.set_active(value);
		button.notify["active"].connect(handle_toggled);

		// Add buttons to button area at the bottom
		add_button (Gtk.Stock.CLOSE, Gtk.ResponseType.CLOSE);
	}

	private void connect_signals () {
		this.response.connect (on_response);
	}

	private void on_response (Gtk.Dialog source, int response_id) {
		switch (response_id) {
		case Gtk.ResponseType.CLOSE:
			destroy ();
			break;
		}
	}

	private void handle_toggled() {
		var set = DejaDup.get_settings(APPS_ROOT+".photo-stream");
		set.set_boolean(BACKUP_KEY, button.get_active());
		photo_toggled(button.get_active());
		var configpath = set.get_string("path");
                var settings_app = DejaDup.get_settings(APPS_ROOT);
                var slist_val = settings_app.get_value(APPS_LIST_KEY);
                string*[] slist = slist_val.get_strv();
                bool found = false;
                foreach (string s in slist) {
                        if (s != null && s==configpath) {
                                found = true;
                                break;
                        }
                }

                if(button.get_active()){
                        if(!found) slist += configpath;
                        settings_app.set_value(APPS_LIST_KEY,new Variant.strv(slist));
                } else {
                        string[] paths = new string[0];
                        foreach(string s in slist) {
                                if(s!=configpath)
                                paths += s;
                        }
                        settings_app.set_value(APPS_LIST_KEY, new Variant.strv((string*[])paths));
                }
	}

}

}
