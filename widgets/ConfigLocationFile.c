/* ConfigLocationFile.c generated by valac 0.16.1, the Vala compiler
 * generated from ConfigLocationFile.vala, do not modify */

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

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <glib/gi18n-lib.h>
#include <stdlib.h>
#include <string.h>
#include <common.h>


#define DEJA_DUP_TYPE_CONFIG_LOCATION_TABLE (deja_dup_config_location_table_get_type ())
#define DEJA_DUP_CONFIG_LOCATION_TABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_LOCATION_TABLE, DejaDupConfigLocationTable))
#define DEJA_DUP_CONFIG_LOCATION_TABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_LOCATION_TABLE, DejaDupConfigLocationTableClass))
#define DEJA_DUP_IS_CONFIG_LOCATION_TABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_LOCATION_TABLE))
#define DEJA_DUP_IS_CONFIG_LOCATION_TABLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_LOCATION_TABLE))
#define DEJA_DUP_CONFIG_LOCATION_TABLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_LOCATION_TABLE, DejaDupConfigLocationTableClass))

typedef struct _DejaDupConfigLocationTable DejaDupConfigLocationTable;
typedef struct _DejaDupConfigLocationTableClass DejaDupConfigLocationTableClass;
typedef struct _DejaDupConfigLocationTablePrivate DejaDupConfigLocationTablePrivate;

#define DEJA_DUP_TYPE_CONFIG_LOCATION_FILE (deja_dup_config_location_file_get_type ())
#define DEJA_DUP_CONFIG_LOCATION_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_LOCATION_FILE, DejaDupConfigLocationFile))
#define DEJA_DUP_CONFIG_LOCATION_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_LOCATION_FILE, DejaDupConfigLocationFileClass))
#define DEJA_DUP_IS_CONFIG_LOCATION_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_LOCATION_FILE))
#define DEJA_DUP_IS_CONFIG_LOCATION_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_LOCATION_FILE))
#define DEJA_DUP_CONFIG_LOCATION_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_LOCATION_FILE, DejaDupConfigLocationFileClass))

typedef struct _DejaDupConfigLocationFile DejaDupConfigLocationFile;
typedef struct _DejaDupConfigLocationFileClass DejaDupConfigLocationFileClass;
typedef struct _DejaDupConfigLocationFilePrivate DejaDupConfigLocationFilePrivate;

#define DEJA_DUP_TYPE_CONFIG_WIDGET (deja_dup_config_widget_get_type ())
#define DEJA_DUP_CONFIG_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidget))
#define DEJA_DUP_CONFIG_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidgetClass))
#define DEJA_DUP_IS_CONFIG_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET))
#define DEJA_DUP_IS_CONFIG_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_WIDGET))
#define DEJA_DUP_CONFIG_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidgetClass))

typedef struct _DejaDupConfigWidget DejaDupConfigWidget;
typedef struct _DejaDupConfigWidgetClass DejaDupConfigWidgetClass;

#define DEJA_DUP_TYPE_CONFIG_ENTRY (deja_dup_config_entry_get_type ())
#define DEJA_DUP_CONFIG_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_ENTRY, DejaDupConfigEntry))
#define DEJA_DUP_CONFIG_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_ENTRY, DejaDupConfigEntryClass))
#define DEJA_DUP_IS_CONFIG_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_ENTRY))
#define DEJA_DUP_IS_CONFIG_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_ENTRY))
#define DEJA_DUP_CONFIG_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_ENTRY, DejaDupConfigEntryClass))

typedef struct _DejaDupConfigEntry DejaDupConfigEntry;
typedef struct _DejaDupConfigEntryClass DejaDupConfigEntryClass;

#define DEJA_DUP_TYPE_CONFIG_URL_PART (deja_dup_config_url_part_get_type ())
#define DEJA_DUP_CONFIG_URL_PART(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_URL_PART, DejaDupConfigURLPart))
#define DEJA_DUP_CONFIG_URL_PART_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_URL_PART, DejaDupConfigURLPartClass))
#define DEJA_DUP_IS_CONFIG_URL_PART(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_URL_PART))
#define DEJA_DUP_IS_CONFIG_URL_PART_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_URL_PART))
#define DEJA_DUP_CONFIG_URL_PART_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_URL_PART, DejaDupConfigURLPartClass))

typedef struct _DejaDupConfigURLPart DejaDupConfigURLPart;
typedef struct _DejaDupConfigURLPartClass DejaDupConfigURLPartClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define DEJA_DUP_CONFIG_URL_PART_TYPE_PART (deja_dup_config_url_part_part_get_type ())

#define DEJA_DUP_TYPE_TOGGLABLE (deja_dup_togglable_get_type ())
#define DEJA_DUP_TOGGLABLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_TOGGLABLE, DejaDupTogglable))
#define DEJA_DUP_IS_TOGGLABLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_TOGGLABLE))
#define DEJA_DUP_TOGGLABLE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), DEJA_DUP_TYPE_TOGGLABLE, DejaDupTogglableIface))

typedef struct _DejaDupTogglable DejaDupTogglable;
typedef struct _DejaDupTogglableIface DejaDupTogglableIface;

struct _DejaDupConfigLocationTable {
	GtkGrid parent_instance;
	DejaDupConfigLocationTablePrivate * priv;
	gint row;
};

struct _DejaDupConfigLocationTableClass {
	GtkGridClass parent_class;
};

struct _DejaDupConfigLocationFile {
	DejaDupConfigLocationTable parent_instance;
	DejaDupConfigLocationFilePrivate * priv;
};

struct _DejaDupConfigLocationFileClass {
	DejaDupConfigLocationTableClass parent_class;
};

struct _DejaDupConfigLocationFilePrivate {
	DejaDupConfigURLPart* entry;
};

typedef enum  {
	DEJA_DUP_CONFIG_URL_PART_PART_SCHEME,
	DEJA_DUP_CONFIG_URL_PART_PART_SERVER,
	DEJA_DUP_CONFIG_URL_PART_PART_PORT,
	DEJA_DUP_CONFIG_URL_PART_PART_USER,
	DEJA_DUP_CONFIG_URL_PART_PART_FOLDER,
	DEJA_DUP_CONFIG_URL_PART_PART_DOMAIN
} DejaDupConfigURLPartPart;

struct _DejaDupTogglableIface {
	GTypeInterface parent_iface;
	gboolean (*get_active) (DejaDupTogglable* self);
};


static gpointer deja_dup_config_location_file_parent_class = NULL;

GType deja_dup_config_location_table_get_type (void) G_GNUC_CONST;
GType deja_dup_config_location_file_get_type (void) G_GNUC_CONST;
GType deja_dup_config_widget_get_type (void) G_GNUC_CONST;
GType deja_dup_config_entry_get_type (void) G_GNUC_CONST;
GType deja_dup_config_url_part_get_type (void) G_GNUC_CONST;
#define DEJA_DUP_CONFIG_LOCATION_FILE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), DEJA_DUP_TYPE_CONFIG_LOCATION_FILE, DejaDupConfigLocationFilePrivate))
enum  {
	DEJA_DUP_CONFIG_LOCATION_FILE_DUMMY_PROPERTY
};
DejaDupConfigLocationFile* deja_dup_config_location_file_new (GtkSizeGroup* sg);
DejaDupConfigLocationFile* deja_dup_config_location_file_construct (GType object_type, GtkSizeGroup* sg);
static void deja_dup_config_location_file_browse_clicked (DejaDupConfigLocationFile* self);
gchar* deja_dup_config_entry_get_text (DejaDupConfigEntry* self);
void deja_dup_destroy_widget (GtkWidget* w);
static GObject * deja_dup_config_location_file_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
GType deja_dup_config_url_part_part_get_type (void) G_GNUC_CONST;
DejaDupConfigURLPart* deja_dup_config_url_part_new (DejaDupConfigURLPartPart part, const gchar* key, const gchar* ns);
DejaDupConfigURLPart* deja_dup_config_url_part_construct (GType object_type, DejaDupConfigURLPartPart part, const gchar* key, const gchar* ns);
void deja_dup_config_entry_set_accessible_name (DejaDupConfigEntry* self, const gchar* name);
static void _deja_dup_config_location_file_browse_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self);
GType deja_dup_togglable_get_type (void) G_GNUC_CONST;
void deja_dup_config_location_table_add_widget (DejaDupConfigLocationTable* self, const gchar* msg, GtkWidget* w, DejaDupTogglable* check, GtkWidget* mnemonic);
static void deja_dup_config_location_file_finalize (GObject* obj);


DejaDupConfigLocationFile* deja_dup_config_location_file_construct (GType object_type, GtkSizeGroup* sg) {
	DejaDupConfigLocationFile * self = NULL;
	GtkSizeGroup* _tmp0_;
	g_return_val_if_fail (sg != NULL, NULL);
	_tmp0_ = sg;
	self = (DejaDupConfigLocationFile*) g_object_new (object_type, "label-sizes", _tmp0_, NULL);
	return self;
}


DejaDupConfigLocationFile* deja_dup_config_location_file_new (GtkSizeGroup* sg) {
	return deja_dup_config_location_file_construct (DEJA_DUP_TYPE_CONFIG_LOCATION_FILE, sg);
}


static void deja_dup_config_location_file_browse_clicked (DejaDupConfigLocationFile* self) {
	const gchar* _tmp0_ = NULL;
	GtkWidget* _tmp1_ = NULL;
	GtkFileChooserDialog* _tmp2_;
	GtkFileChooserDialog* _tmp3_;
	GtkFileChooserDialog* dlg;
	DejaDupConfigURLPart* _tmp4_;
	gchar* _tmp5_ = NULL;
	gchar* dir;
	GtkFileChooserDialog* _tmp6_;
	const gchar* _tmp7_;
	GtkFileChooserDialog* _tmp8_;
	gint _tmp9_ = 0;
	GtkFileChooserDialog* _tmp15_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _ ("Choose Folder");
	_tmp1_ = gtk_widget_get_ancestor ((GtkWidget*) self, GTK_TYPE_WINDOW);
	_tmp2_ = (GtkFileChooserDialog*) gtk_file_chooser_dialog_new (_tmp0_, GTK_IS_WINDOW (_tmp1_) ? ((GtkWindow*) _tmp1_) : NULL, GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, NULL);
	_tmp3_ = g_object_ref_sink (_tmp2_);
	dlg = _tmp3_;
	_tmp4_ = self->priv->entry;
	_tmp5_ = deja_dup_config_entry_get_text ((DejaDupConfigEntry*) _tmp4_);
	dir = _tmp5_;
	_tmp6_ = dlg;
	_tmp7_ = dir;
	gtk_file_chooser_set_current_folder ((GtkFileChooser*) _tmp6_, _tmp7_);
	_tmp8_ = dlg;
	_tmp9_ = gtk_dialog_run ((GtkDialog*) _tmp8_);
	if (_tmp9_ == ((gint) GTK_RESPONSE_ACCEPT)) {
		DejaDupSimpleSettings* _tmp10_ = NULL;
		DejaDupSimpleSettings* settings;
		DejaDupSimpleSettings* _tmp11_;
		GtkFileChooserDialog* _tmp12_;
		gchar* _tmp13_ = NULL;
		gchar* _tmp14_;
		_tmp10_ = deja_dup_get_settings (DEJA_DUP_FILE_ROOT);
		settings = _tmp10_;
		_tmp11_ = settings;
		_tmp12_ = dlg;
		_tmp13_ = gtk_file_chooser_get_uri ((GtkFileChooser*) _tmp12_);
		_tmp14_ = _tmp13_;
		deja_dup_simple_settings_set_string (_tmp11_, DEJA_DUP_FILE_PATH_KEY, _tmp14_);
		_g_free0 (_tmp14_);
		_g_object_unref0 (settings);
	}
	_tmp15_ = dlg;
	deja_dup_destroy_widget ((GtkWidget*) _tmp15_);
	_g_free0 (dir);
	_g_object_unref0 (dlg);
}


static void _deja_dup_config_location_file_browse_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
	deja_dup_config_location_file_browse_clicked (self);
}


static GObject * deja_dup_config_location_file_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	DejaDupConfigLocationFile * self;
	GtkBox* _tmp0_;
	GtkBox* _tmp1_;
	GtkBox* hbox;
	DejaDupConfigURLPart* _tmp2_;
	DejaDupConfigURLPart* _tmp3_;
	DejaDupConfigURLPart* _tmp4_;
	const gchar* _tmp5_ = NULL;
	GtkButton* _tmp6_;
	GtkButton* _tmp7_;
	GtkButton* browse;
	GtkButton* _tmp8_;
	GtkBox* _tmp9_;
	DejaDupConfigURLPart* _tmp10_;
	GtkBox* _tmp11_;
	GtkButton* _tmp12_;
	const gchar* _tmp13_ = NULL;
	GtkBox* _tmp14_;
	DejaDupConfigURLPart* _tmp15_;
	parent_class = G_OBJECT_CLASS (deja_dup_config_location_file_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = DEJA_DUP_CONFIG_LOCATION_FILE (obj);
	_tmp0_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 6);
	_tmp1_ = g_object_ref_sink (_tmp0_);
	hbox = _tmp1_;
	_tmp2_ = deja_dup_config_url_part_new (DEJA_DUP_CONFIG_URL_PART_PART_FOLDER, DEJA_DUP_FILE_PATH_KEY, DEJA_DUP_FILE_ROOT);
	_tmp3_ = g_object_ref_sink (_tmp2_);
	_g_object_unref0 (self->priv->entry);
	self->priv->entry = _tmp3_;
	_tmp4_ = self->priv->entry;
	deja_dup_config_entry_set_accessible_name ((DejaDupConfigEntry*) _tmp4_, "FileFolder");
	_tmp5_ = _ ("_Choose Folder…");
	_tmp6_ = (GtkButton*) gtk_button_new_with_mnemonic (_tmp5_);
	_tmp7_ = g_object_ref_sink (_tmp6_);
	browse = _tmp7_;
	_tmp8_ = browse;
	g_signal_connect_object (_tmp8_, "clicked", (GCallback) _deja_dup_config_location_file_browse_clicked_gtk_button_clicked, self, 0);
	_tmp9_ = hbox;
	_tmp10_ = self->priv->entry;
	gtk_box_pack_start (_tmp9_, (GtkWidget*) _tmp10_, TRUE, TRUE, (guint) 0);
	_tmp11_ = hbox;
	_tmp12_ = browse;
	gtk_box_pack_start (_tmp11_, (GtkWidget*) _tmp12_, FALSE, FALSE, (guint) 0);
	_tmp13_ = _ ("_Folder");
	_tmp14_ = hbox;
	_tmp15_ = self->priv->entry;
	deja_dup_config_location_table_add_widget ((DejaDupConfigLocationTable*) self, _tmp13_, (GtkWidget*) _tmp14_, NULL, (GtkWidget*) _tmp15_);
	_g_object_unref0 (browse);
	_g_object_unref0 (hbox);
	return obj;
}


static void deja_dup_config_location_file_class_init (DejaDupConfigLocationFileClass * klass) {
	deja_dup_config_location_file_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (DejaDupConfigLocationFilePrivate));
	G_OBJECT_CLASS (klass)->constructor = deja_dup_config_location_file_constructor;
	G_OBJECT_CLASS (klass)->finalize = deja_dup_config_location_file_finalize;
}


static void deja_dup_config_location_file_instance_init (DejaDupConfigLocationFile * self) {
	self->priv = DEJA_DUP_CONFIG_LOCATION_FILE_GET_PRIVATE (self);
}


static void deja_dup_config_location_file_finalize (GObject* obj) {
	DejaDupConfigLocationFile * self;
	self = DEJA_DUP_CONFIG_LOCATION_FILE (obj);
	_g_object_unref0 (self->priv->entry);
	G_OBJECT_CLASS (deja_dup_config_location_file_parent_class)->finalize (obj);
}


GType deja_dup_config_location_file_get_type (void) {
	static volatile gsize deja_dup_config_location_file_type_id__volatile = 0;
	if (g_once_init_enter (&deja_dup_config_location_file_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DejaDupConfigLocationFileClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) deja_dup_config_location_file_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DejaDupConfigLocationFile), 0, (GInstanceInitFunc) deja_dup_config_location_file_instance_init, NULL };
		GType deja_dup_config_location_file_type_id;
		deja_dup_config_location_file_type_id = g_type_register_static (DEJA_DUP_TYPE_CONFIG_LOCATION_TABLE, "DejaDupConfigLocationFile", &g_define_type_info, 0);
		g_once_init_leave (&deja_dup_config_location_file_type_id__volatile, deja_dup_config_location_file_type_id);
	}
	return deja_dup_config_location_file_type_id__volatile;
}



