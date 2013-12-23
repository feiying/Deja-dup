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

public class AppsPlugin : Peas.ExtensionBase, Peas.Activatable
{
  // Peas methods
  public Object object {owned get; construct;}
  public virtual void activate () {}
  public virtual void deactivate () {}
  public virtual void update_state () {}

  construct
  {
    string output;
    //Process.spawn_command_line_sync("notify-send AppsPlugin", out output, null, null);
    //print ("AppsPlugin: hello, world\n");
  }

}

[ModuleInit]
public void peas_register_types (GLib.TypeModule module)
{
  var objmodule = module as Peas.ObjectModule;
  objmodule.register_extension_type (typeof (Peas.Activatable),
                                     typeof (AppsPlugin));
}

