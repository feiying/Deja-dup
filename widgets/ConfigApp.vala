/* -*- Mode: Vala; indent-tabs-mode: nil; tab-width: 2 -*- */
using GLib;

namespace DejaDup {

public class ConfigApp : ConfigWidget, Togglable
{
  public ConfigApp(string key)
  {
    Object(key: key);
  }

  public bool get_active() {return button.get_active();}

  protected Gtk.HBox hbox;
  protected Gtk.VBox vbox;
  protected Gtk.VBox vbox2;
  protected Gtk.Image icon;
  protected new Gtk.Label label;
  protected Gtk.Switch button;
  protected int size;
  protected bool user_driven = true;
  construct {
    Gtk.Alignment align;
    align = new Gtk.Alignment(0.5f, 0.5f, 1.0f, 1.0f);
    align.left_padding = 5;
    align.right_padding = 5;
    add(align);

    hbox = new Gtk.HBox(false, 5);
    align.add(hbox);

    icon = new Gtk.Image.from_icon_name (key, Gtk.IconSize.BUTTON);
    
    vbox = new Gtk.VBox(false, 0);
    label = new Gtk.Label("%s".printf(key));
    label.set("use-markup", true,
              "xalign", 0.0f);
    vbox.pack_start(label, false, false, 0);
    label = new Gtk.Label("<small>%s</small>".printf(_("0")));
    label.set("use-markup", true,
              "xalign", 0.0f);
    vbox.pack_start(label, false, false, 0);

    vbox2 = new Gtk.VBox(false, 0);
    button = new Gtk.Switch();
    var settings = DejaDup.get_settings(APPS_ROOT+"."+key);
    var val = settings.get_boolean(BACKUP_KEY);
    button.set_active(val);
    vbox2.pack_start(button, true, false, 0);
    
    fill_box();

    set_from_config.begin();
    button.notify["active"].connect(handle_toggled);

    do_calc_in_bg.begin(0.001, (obj, res) => {
            try {
                string result = do_calc_in_bg.end(res);
                //stderr.printf(@"Result: $result");
		string markup = "<small>"+@"$result"+"</small>";
		label.set_markup(markup);
            } catch (ThreadError e) {
                string msg = e.message;
                stderr.printf(@"Thread error: $msg\n");
            }
            //loop.quit();
    });
  }

  async string do_calc_in_bg(double val) throws ThreadError {
    SourceFunc callback = do_calc_in_bg.callback;
    string[] output = new string[1];
    ThreadFunc<void*> run = () => {
        string result = "0";
	string ls_stdout;
        string ls_stderr;
        int ls_status;
        try {
	  var set = DejaDup.get_settings(APPS_ROOT+"."+key);
	  string configpath = set.get_string("path");
	  string home_dir = Environment.get_home_dir();
	  string command = "du -sh "+home_dir+"/"+configpath;
          Process.spawn_command_line_sync (command,
                                           out ls_stdout,
                                           out ls_stderr,
                                           out ls_status);

        } catch (SpawnError e) {
          stdout.printf ("Error: %s\n", e.message);
        }
	if(ls_stdout == "") {
	  result = "0";
	} else {
	  string[] words = ls_stdout.split ("\t");
	  result = words[0];
	}
        output[0] = result;
        Idle.add((owned) callback);
        return null;
    };

    Thread.create<void*>(run, false);

    yield;
    return output[0];
  }

  protected virtual void fill_box()
  {
    hbox.pack_start(icon, false, false, 0);
    hbox.pack_start(vbox, false, false, 0);
    hbox.pack_end(vbox2, false, false, 0);
  }

  protected override async void set_from_config()
  {
  }

  protected void restore_gsettings()
  {
    string home_dir = Environment.get_home_dir();
    File file_restore = File.new_for_path (home_dir+"/.apps-gsettings");
    bool tmp = file_restore.query_exists();
    if (tmp == true) {
        	stdout.printf ("File found\n");
                FileStream stream = FileStream.open (home_dir+"/.apps-gsettings", "r");
                assert (stream != null);

                string line = null;
                while ((line = stream.read_line ()) != null) {
                  stdout.puts (line);
                  stdout.putc ('\n');
                  string[] words = line.split (" ");
                  stdout.printf ("%s\n",words[0]);
                  stdout.printf ("%s\n",words[1]);
                  stdout.printf ("%s\n",words[2]);
                  var appsetlist = DejaDup.get_app_settings(words[0]);
                  var t_val = appsetlist.get_value(words[1]);
                  string type = t_val.get_type_string();
                  if("b" == type) {
                    appsetlist.set_boolean(words[1],  bool.parse(words[2]));
                  }
                  if("i" == type) {
                    appsetlist.set_int(words[1],  int.parse(words[2]));
                  }
                  if("s" == type) {
                    appsetlist.set_string(words[1], words[2]);
                  }
                  if("as" == type) {
                    string[] item = words[2].split (",");
                    appsetlist.set_value(words[1], new Variant.strv((string*[])item));
                  }
                }
    } else {
        stdout.printf ("File not found Error:\n");
    }
  }



  protected virtual void handle_toggled()
  {
    var set = DejaDup.get_settings(APPS_ROOT+"."+key);
    set.set_boolean(BACKUP_KEY, button.get_active());
    var configpath = set.get_string("path");
    toggled(this, user_driven);
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
    //restore_gsettings();
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
    /*var loop = new MainLoop();
    do_calc_in_bg.begin(0.001, (obj, res) => {
            try {
                double result = do_calc_in_bg.end(res);
                stderr.printf(@"Result: $result\n");
            } catch (ThreadError e) {
                string msg = e.message;
                stderr.printf(@"Thread error: $msg\n");
            }
            //loop.quit();
        });
    loop.run();*/
  }
}

}

