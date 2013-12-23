/* -*- Mode: Vala; indent-tabs-mode: nil; tab-width: 2 -*- */
/*
    This file is part of Déjà Dup.
    For copyright information, see AUTHORS.

    Déjà Dup is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Déjà Dup is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Déjà Dup.  If not, see <http://www.gnu.org/licenses/>.
*/

using GLib;

namespace DejaDup {

public class OperationRestore : Operation
{
  public string dest {get; construct;} // Directory user wants to put files in
  public string time {get; construct;} // Date user wants to restore to
  private List<File> _restore_files;
  public List<File> restore_files {
    get {
      return this._restore_files;
    }
    construct {
      foreach (File f in this._restore_files)
        f.unref();
      this._restore_files = value.copy();
      foreach (File f in this._restore_files)
        f.ref();
    }
  }
  
  public OperationRestore(string dest_in,
                          string? time_in = null,
                          List<File>? files_in = null) {
    Object(dest: dest_in, time: time_in, restore_files: files_in,
           mode: ToolJob.Mode.RESTORE);
  }
  
  public async override void start(bool try_claim_bus = true)
  {
    action_desc_changed(_("Restoring files…"));
    yield base.start(try_claim_bus);
  }

  protected override List<string>? make_argv()
  {
    job.restore_files = restore_files;
    job.time = time;
    job.local = File.new_for_path(dest);
    return null;
  }
 
  public void restore_gsettings()
  {
    string home_dir = Environment.get_home_dir();
    File file_restore = File.new_for_path (home_dir+"/.apps-gsettings");
    bool tmp = file_restore.query_exists();
    if (tmp == true) {
        try {
                FileStream stream = FileStream.open (home_dir+"/.apps-gsettings", "r");
                assert (stream != null);

		List<string> schema_list = new List<string> ();
    		var app_settings = DejaDup.get_settings(APPS_ROOT);
    		foreach (string app in app_settings.list_children()) {
      		  var file = File.new_for_path("/usr/bin/"+app);
      		  if(file.query_exists()) {
        	    var set = DejaDup.get_settings(APPS_ROOT+"."+app);
        	    var val = set.get_boolean(BACKUP_KEY);
        	    if(val == true) {
          	      var schema = set.get_string("settings");
          	      if(schema!="")
                        schema_list.append(schema);
        	    }
                  }
                }

                string line = null;
                while ((line = stream.read_line ()) != null) {
		  bool found = false;
		  schema_list.foreach ((entry) => {
		      bool is_in  = line.contains (entry);
		      if(is_in)  found = true;
		  });
	  	  if(!found)  continue;

		  string ls_stdout;
        	  string ls_stderr;
        	  int ls_status;
                  string[] words = line.split (" ");
                  var appsetlist = DejaDup.get_app_settings(words[0]);
                  var t_val = appsetlist.get_value(words[1]);
                  string type = t_val.get_type_string();
                  if("b" == type) {
                    //appsetlist.set_boolean(words[1], bool.parse(words[2]));
		    string command = "gsettings set "+words[0]+" "+words[1]+" "+words[2];
		    Process.spawn_command_line_sync (command,
                                           out ls_stdout,
                                           out ls_stderr,
                                           out ls_status);
                  }
                  if("i" == type) {
                    //appsetlist.set_int(words[1], int.parse(words[2]));
		    string command = "gsettings set "+words[0]+" "+words[1]+" "+words[2];
		    Process.spawn_command_line_sync (command,
                                           out ls_stdout,
                                           out ls_stderr,
                                           out ls_status);
                  }
                  if("s" == type) {
                    //appsetlist.set_string(words[1], words[2]);
		    string command = "gsettings set "+words[0]+" "+words[1]+" "+words[2];
		    Process.spawn_command_line_sync (command,
                                           out ls_stdout,
                                           out ls_stderr,
                                           out ls_status);
                  }
                  if("as" == type) {
                    string[] item = words[2].split (",");
                    //appsetlist.set_value(words[1], new Variant.strv((string*[])item));
		    string command = "gsettings set "+words[0]+" "+words[1]+" \"[";
                    foreach (string ss in item) {
                        if(item[0] == ss)
		          command = command + "'" + ss + "'";
                        else
		          command = command + ",'" + ss + "'";
                    }
		    command = command + "]\"";
		    Process.spawn_command_line_sync (command,
                                           out ls_stdout,
                                           out ls_stderr,
                                           out ls_status);
                  }
		}
	} catch (Error e) {
                stdout.printf ("Error: %s\n", e.message);
        }
    }
    else {
        stdout.printf ("File not found Error:\n");
    }
  }
 
  internal async override void operation_finished(ToolJob job, bool success, bool cancelled, string? detail)
  {
    if (success)
      DejaDup.update_last_run_timestamp(DejaDup.TimestampType.RESTORE);

    yield base.operation_finished(job, success, cancelled, detail);

    restore_gsettings();
  }
}

} // end namespace

