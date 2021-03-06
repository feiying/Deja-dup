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

public class ConfigDelete : ConfigChoice
{
  public static const int SEMIANNUALLY = 365/2;
  public static const int ANNUALLY = 365;
  public static int FOREVER = int.MAX;

  public ConfigDelete(string key, string ns="") {
    Object(key: key, ns: ns);
  }
  
  construct {
    var store = new Gtk.ListStore(2, typeof(string), typeof(int));
    
    Gtk.TreeIter iter;
    int i = 0;
    
    store.insert_with_values(out iter, i++, 0, _("At least six months"), 1, SEMIANNUALLY);
    store.insert_with_values(out iter, i++, 0, _("At least a year"), 1, ANNUALLY);
    store.insert_with_values(out iter, i++, 0, _("Forever"), 1, FOREVER);
    
    store.set_sort_column_id(1, Gtk.SortType.ASCENDING);
    
    init(store, 1);
  }
  
  protected override void handle_changed()
  {
    Value? val = get_current_value();
    int intval = val == null ? 0 : val.get_int();
    if (intval == int.MAX)
      intval = 0; // forever
    
    settings.set_int(key, intval);
    
    choice_changed(intval.to_string());
  }
  
  protected override async void set_from_config()
  {
    var confval = settings.get_int(key);
    if (confval <= 0)
      confval = int.MAX;
    
    bool valid;
    Gtk.TreeIter iter;
    valid = combo.model.get_iter_first(out iter);
    
    while (valid) {
      Value val;
      combo.model.get_value(iter, settings_col, out val);
      int intval = val.get_int();
      
      if (intval == confval) {
        combo.set_active_iter(iter);
        break;
      }
      valid = combo.model.iter_next(ref iter);
    }
    
    // If we didn't find the time, user must have set it to something non
    // standard.  Let's add an entry to the combo.
    if (!valid) {
      var store = (Gtk.ListStore)combo.model;
      store.insert_with_values(out iter, 0, 0,
                               dngettext(Config.GETTEXT_PACKAGE,
                                         "At least %d day",
                                         "At least %d days",
                                         confval).printf(confval),
                               1, confval);
      combo.set_active_iter(iter);
    }
  }
}

}

