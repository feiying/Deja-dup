/* ConfigFolder.c generated by valac 0.16.1, the Vala compiler
 * generated from ConfigFolder.vala, do not modify */

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
#include <gio/gio.h>
#include <common.h>
#include <stdlib.h>
#include <string.h>


#define DEJA_DUP_TYPE_CONFIG_WIDGET (deja_dup_config_widget_get_type ())
#define DEJA_DUP_CONFIG_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidget))
#define DEJA_DUP_CONFIG_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidgetClass))
#define DEJA_DUP_IS_CONFIG_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET))
#define DEJA_DUP_IS_CONFIG_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_WIDGET))
#define DEJA_DUP_CONFIG_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidgetClass))

typedef struct _DejaDupConfigWidget DejaDupConfigWidget;
typedef struct _DejaDupConfigWidgetClass DejaDupConfigWidgetClass;
typedef struct _DejaDupConfigWidgetPrivate DejaDupConfigWidgetPrivate;

#define DEJA_DUP_TYPE_CONFIG_ENTRY (deja_dup_config_entry_get_type ())
#define DEJA_DUP_CONFIG_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_ENTRY, DejaDupConfigEntry))
#define DEJA_DUP_CONFIG_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_ENTRY, DejaDupConfigEntryClass))
#define DEJA_DUP_IS_CONFIG_ENTRY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_ENTRY))
#define DEJA_DUP_IS_CONFIG_ENTRY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_ENTRY))
#define DEJA_DUP_CONFIG_ENTRY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_ENTRY, DejaDupConfigEntryClass))

typedef struct _DejaDupConfigEntry DejaDupConfigEntry;
typedef struct _DejaDupConfigEntryClass DejaDupConfigEntryClass;
typedef struct _DejaDupConfigEntryPrivate DejaDupConfigEntryPrivate;

#define DEJA_DUP_TYPE_CONFIG_FOLDER (deja_dup_config_folder_get_type ())
#define DEJA_DUP_CONFIG_FOLDER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_FOLDER, DejaDupConfigFolder))
#define DEJA_DUP_CONFIG_FOLDER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_FOLDER, DejaDupConfigFolderClass))
#define DEJA_DUP_IS_CONFIG_FOLDER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_FOLDER))
#define DEJA_DUP_IS_CONFIG_FOLDER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_FOLDER))
#define DEJA_DUP_CONFIG_FOLDER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_FOLDER, DejaDupConfigFolderClass))

typedef struct _DejaDupConfigFolder DejaDupConfigFolder;
typedef struct _DejaDupConfigFolderClass DejaDupConfigFolderClass;
typedef struct _DejaDupConfigFolderPrivate DejaDupConfigFolderPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _DejaDupConfigFolderSetFromConfigData DejaDupConfigFolderSetFromConfigData;

struct _DejaDupConfigWidget {
	GtkEventBox parent_instance;
	DejaDupConfigWidgetPrivate * priv;
	gboolean syncing;
	DejaDupSimpleSettings* settings;
	GList* all_settings;
};

struct _DejaDupConfigWidgetClass {
	GtkEventBoxClass parent_class;
	void (*set_from_config) (DejaDupConfigWidget* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*set_from_config_finish) (DejaDupConfigWidget* self, GAsyncResult* _res_);
};

struct _DejaDupConfigEntry {
	DejaDupConfigWidget parent_instance;
	DejaDupConfigEntryPrivate * priv;
	GtkEntry* entry;
};

struct _DejaDupConfigEntryClass {
	DejaDupConfigWidgetClass parent_class;
	void (*write_to_config) (DejaDupConfigEntry* self);
};

struct _DejaDupConfigFolder {
	DejaDupConfigEntry parent_instance;
	DejaDupConfigFolderPrivate * priv;
};

struct _DejaDupConfigFolderClass {
	DejaDupConfigEntryClass parent_class;
};

struct _DejaDupConfigFolderSetFromConfigData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DejaDupConfigFolder* self;
	DejaDupSimpleSettings* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* val;
	GtkEntry* _tmp4_;
};


static gpointer deja_dup_config_folder_parent_class = NULL;

GType deja_dup_config_widget_get_type (void) G_GNUC_CONST;
GType deja_dup_config_entry_get_type (void) G_GNUC_CONST;
GType deja_dup_config_folder_get_type (void) G_GNUC_CONST;
enum  {
	DEJA_DUP_CONFIG_FOLDER_DUMMY_PROPERTY
};
DejaDupConfigFolder* deja_dup_config_folder_new (const gchar* key, const gchar* ns);
DejaDupConfigFolder* deja_dup_config_folder_construct (GType object_type, const gchar* key, const gchar* ns);
static void deja_dup_config_folder_real_set_from_config_data_free (gpointer _data);
static void deja_dup_config_folder_real_set_from_config (DejaDupConfigWidget* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean deja_dup_config_folder_real_set_from_config_co (DejaDupConfigFolderSetFromConfigData* _data_);
const gchar* deja_dup_config_widget_get_key (DejaDupConfigWidget* self);


DejaDupConfigFolder* deja_dup_config_folder_construct (GType object_type, const gchar* key, const gchar* ns) {
	DejaDupConfigFolder * self = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	g_return_val_if_fail (key != NULL, NULL);
	g_return_val_if_fail (ns != NULL, NULL);
	_tmp0_ = key;
	_tmp1_ = ns;
	self = (DejaDupConfigFolder*) g_object_new (object_type, "key", _tmp0_, "ns", _tmp1_, NULL);
	return self;
}


DejaDupConfigFolder* deja_dup_config_folder_new (const gchar* key, const gchar* ns) {
	return deja_dup_config_folder_construct (DEJA_DUP_TYPE_CONFIG_FOLDER, key, ns);
}


static void deja_dup_config_folder_real_set_from_config_data_free (gpointer _data) {
	DejaDupConfigFolderSetFromConfigData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DejaDupConfigFolderSetFromConfigData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void deja_dup_config_folder_real_set_from_config (DejaDupConfigWidget* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DejaDupConfigFolder * self;
	DejaDupConfigFolderSetFromConfigData* _data_;
	DejaDupConfigFolder* _tmp0_;
	self = (DejaDupConfigFolder*) base;
	_data_ = g_slice_new0 (DejaDupConfigFolderSetFromConfigData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, deja_dup_config_folder_real_set_from_config);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, deja_dup_config_folder_real_set_from_config_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	deja_dup_config_folder_real_set_from_config_co (_data_);
}


static void deja_dup_config_folder_real_set_from_config_finish (DejaDupConfigWidget* base, GAsyncResult* _res_) {
	DejaDupConfigFolderSetFromConfigData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean deja_dup_config_folder_real_set_from_config_co (DejaDupConfigFolderSetFromConfigData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = ((DejaDupConfigWidget*) _data_->self)->settings;
	_data_->_tmp1_ = deja_dup_config_widget_get_key ((DejaDupConfigWidget*) _data_->self);
	_data_->_tmp2_ = _data_->_tmp1_;
	_data_->_tmp3_ = NULL;
	_data_->_tmp3_ = deja_dup_get_folder_key (_data_->_tmp0_, _data_->_tmp2_);
	_data_->val = _data_->_tmp3_;
	_data_->_tmp4_ = ((DejaDupConfigEntry*) _data_->self)->entry;
	gtk_entry_set_text (_data_->_tmp4_, _data_->val);
	_g_free0 (_data_->val);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void deja_dup_config_folder_class_init (DejaDupConfigFolderClass * klass) {
	deja_dup_config_folder_parent_class = g_type_class_peek_parent (klass);
	DEJA_DUP_CONFIG_WIDGET_CLASS (klass)->set_from_config = deja_dup_config_folder_real_set_from_config;
	DEJA_DUP_CONFIG_WIDGET_CLASS (klass)->set_from_config_finish = deja_dup_config_folder_real_set_from_config_finish;
}


static void deja_dup_config_folder_instance_init (DejaDupConfigFolder * self) {
}


GType deja_dup_config_folder_get_type (void) {
	static volatile gsize deja_dup_config_folder_type_id__volatile = 0;
	if (g_once_init_enter (&deja_dup_config_folder_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DejaDupConfigFolderClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) deja_dup_config_folder_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DejaDupConfigFolder), 0, (GInstanceInitFunc) deja_dup_config_folder_instance_init, NULL };
		GType deja_dup_config_folder_type_id;
		deja_dup_config_folder_type_id = g_type_register_static (DEJA_DUP_TYPE_CONFIG_ENTRY, "DejaDupConfigFolder", &g_define_type_info, 0);
		g_once_init_leave (&deja_dup_config_folder_type_id__volatile, deja_dup_config_folder_type_id);
	}
	return deja_dup_config_folder_type_id__volatile;
}


