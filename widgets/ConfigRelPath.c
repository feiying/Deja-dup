/* ConfigRelPath.c generated by valac 0.16.1, the Vala compiler
 * generated from ConfigRelPath.vala, do not modify */

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

#define DEJA_DUP_TYPE_CONFIG_REL_PATH (deja_dup_config_rel_path_get_type ())
#define DEJA_DUP_CONFIG_REL_PATH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_REL_PATH, DejaDupConfigRelPath))
#define DEJA_DUP_CONFIG_REL_PATH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_REL_PATH, DejaDupConfigRelPathClass))
#define DEJA_DUP_IS_CONFIG_REL_PATH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_REL_PATH))
#define DEJA_DUP_IS_CONFIG_REL_PATH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_REL_PATH))
#define DEJA_DUP_CONFIG_REL_PATH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_REL_PATH, DejaDupConfigRelPathClass))

typedef struct _DejaDupConfigRelPath DejaDupConfigRelPath;
typedef struct _DejaDupConfigRelPathClass DejaDupConfigRelPathClass;
typedef struct _DejaDupConfigRelPathPrivate DejaDupConfigRelPathPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_variant_unref0(var) ((var == NULL) ? NULL : (var = (g_variant_unref (var), NULL)))
typedef struct _DejaDupConfigRelPathSetFromConfigData DejaDupConfigRelPathSetFromConfigData;

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

struct _DejaDupConfigRelPath {
	DejaDupConfigEntry parent_instance;
	DejaDupConfigRelPathPrivate * priv;
};

struct _DejaDupConfigRelPathClass {
	DejaDupConfigEntryClass parent_class;
};

struct _DejaDupConfigRelPathSetFromConfigData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DejaDupConfigRelPath* self;
	DejaDupSimpleSettings* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	GVariant* _tmp3_;
	GVariant* byte_val;
	gchar* val;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	GError* e;
	GError* _tmp7_;
	const gchar* _tmp8_;
	const gchar* _tmp9_;
	gchar* _tmp10_;
	GtkEntry* _tmp11_;
	const gchar* _tmp12_;
	GError * _inner_error_;
};


static gpointer deja_dup_config_rel_path_parent_class = NULL;

GType deja_dup_config_widget_get_type (void) G_GNUC_CONST;
GType deja_dup_config_entry_get_type (void) G_GNUC_CONST;
GType deja_dup_config_rel_path_get_type (void) G_GNUC_CONST;
enum  {
	DEJA_DUP_CONFIG_REL_PATH_DUMMY_PROPERTY
};
DejaDupConfigRelPath* deja_dup_config_rel_path_new (const gchar* key, const gchar* ns);
DejaDupConfigRelPath* deja_dup_config_rel_path_construct (GType object_type, const gchar* key, const gchar* ns);
static void deja_dup_config_rel_path_real_set_from_config_data_free (gpointer _data);
static void deja_dup_config_rel_path_real_set_from_config (DejaDupConfigWidget* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean deja_dup_config_rel_path_real_set_from_config_co (DejaDupConfigRelPathSetFromConfigData* _data_);
const gchar* deja_dup_config_widget_get_key (DejaDupConfigWidget* self);
static void deja_dup_config_rel_path_real_write_to_config (DejaDupConfigEntry* base);


DejaDupConfigRelPath* deja_dup_config_rel_path_construct (GType object_type, const gchar* key, const gchar* ns) {
	DejaDupConfigRelPath * self = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	g_return_val_if_fail (key != NULL, NULL);
	g_return_val_if_fail (ns != NULL, NULL);
	_tmp0_ = key;
	_tmp1_ = ns;
	self = (DejaDupConfigRelPath*) g_object_new (object_type, "key", _tmp0_, "ns", _tmp1_, NULL);
	return self;
}


DejaDupConfigRelPath* deja_dup_config_rel_path_new (const gchar* key, const gchar* ns) {
	return deja_dup_config_rel_path_construct (DEJA_DUP_TYPE_CONFIG_REL_PATH, key, ns);
}


static void deja_dup_config_rel_path_real_set_from_config_data_free (gpointer _data) {
	DejaDupConfigRelPathSetFromConfigData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DejaDupConfigRelPathSetFromConfigData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void deja_dup_config_rel_path_real_set_from_config (DejaDupConfigWidget* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DejaDupConfigRelPath * self;
	DejaDupConfigRelPathSetFromConfigData* _data_;
	DejaDupConfigRelPath* _tmp0_;
	self = (DejaDupConfigRelPath*) base;
	_data_ = g_slice_new0 (DejaDupConfigRelPathSetFromConfigData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, deja_dup_config_rel_path_real_set_from_config);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, deja_dup_config_rel_path_real_set_from_config_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	deja_dup_config_rel_path_real_set_from_config_co (_data_);
}


static void deja_dup_config_rel_path_real_set_from_config_finish (DejaDupConfigWidget* base, GAsyncResult* _res_) {
	DejaDupConfigRelPathSetFromConfigData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static gboolean deja_dup_config_rel_path_real_set_from_config_co (DejaDupConfigRelPathSetFromConfigData* _data_) {
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
	_data_->_tmp3_ = g_settings_get_value ((GSettings*) _data_->_tmp0_, _data_->_tmp2_);
	_data_->byte_val = _data_->_tmp3_;
	_data_->val = NULL;
	{
		_data_->_tmp4_ = NULL;
		_data_->_tmp4_ = g_variant_get_bytestring (_data_->byte_val);
		_data_->_tmp5_ = NULL;
		_data_->_tmp5_ = g_filename_to_utf8 (_data_->_tmp4_, (gssize) (-1), NULL, NULL, &_data_->_inner_error_);
		_data_->_tmp6_ = _data_->_tmp5_;
		if (_data_->_inner_error_ != NULL) {
			goto __catch6_g_error;
		}
		_g_free0 (_data_->val);
		_data_->val = _data_->_tmp6_;
	}
	goto __finally6;
	__catch6_g_error:
	{
		_data_->e = _data_->_inner_error_;
		_data_->_inner_error_ = NULL;
		_data_->_tmp7_ = _data_->e;
		_data_->_tmp8_ = _data_->_tmp7_->message;
		g_warning ("ConfigRelPath.vala:39: %s\n", _data_->_tmp8_);
		_g_error_free0 (_data_->e);
	}
	__finally6:
	if (_data_->_inner_error_ != NULL) {
		_g_free0 (_data_->val);
		_g_variant_unref0 (_data_->byte_val);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
		g_clear_error (&_data_->_inner_error_);
		return FALSE;
	}
	_data_->_tmp9_ = _data_->val;
	if (_data_->_tmp9_ == NULL) {
		_data_->_tmp10_ = g_strdup ("");
		_g_free0 (_data_->val);
		_data_->val = _data_->_tmp10_;
	}
	_data_->_tmp11_ = ((DejaDupConfigEntry*) _data_->self)->entry;
	_data_->_tmp12_ = _data_->val;
	gtk_entry_set_text (_data_->_tmp11_, _data_->_tmp12_);
	_g_free0 (_data_->val);
	_g_variant_unref0 (_data_->byte_val);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static void deja_dup_config_rel_path_real_write_to_config (DejaDupConfigEntry* base) {
	DejaDupConfigRelPath * self;
	GtkEntry* _tmp0_;
	const gchar* _tmp1_ = NULL;
	GVariant* _tmp2_;
	GVariant* _tmp3_;
	GVariant* val;
	DejaDupSimpleSettings* _tmp4_;
	const gchar* _tmp5_;
	const gchar* _tmp6_;
	self = (DejaDupConfigRelPath*) base;
	_tmp0_ = ((DejaDupConfigEntry*) self)->entry;
	_tmp1_ = gtk_entry_get_text (_tmp0_);
	_tmp2_ = g_variant_new_bytestring (_tmp1_);
	_tmp3_ = g_variant_ref_sink (_tmp2_);
	val = _tmp3_;
	_tmp4_ = ((DejaDupConfigWidget*) self)->settings;
	_tmp5_ = deja_dup_config_widget_get_key ((DejaDupConfigWidget*) self);
	_tmp6_ = _tmp5_;
	deja_dup_simple_settings_set_value (_tmp4_, _tmp6_, val);
	_g_variant_unref0 (val);
}


static void deja_dup_config_rel_path_class_init (DejaDupConfigRelPathClass * klass) {
	deja_dup_config_rel_path_parent_class = g_type_class_peek_parent (klass);
	DEJA_DUP_CONFIG_WIDGET_CLASS (klass)->set_from_config = deja_dup_config_rel_path_real_set_from_config;
	DEJA_DUP_CONFIG_WIDGET_CLASS (klass)->set_from_config_finish = deja_dup_config_rel_path_real_set_from_config_finish;
	DEJA_DUP_CONFIG_ENTRY_CLASS (klass)->write_to_config = deja_dup_config_rel_path_real_write_to_config;
}


static void deja_dup_config_rel_path_instance_init (DejaDupConfigRelPath * self) {
}


GType deja_dup_config_rel_path_get_type (void) {
	static volatile gsize deja_dup_config_rel_path_type_id__volatile = 0;
	if (g_once_init_enter (&deja_dup_config_rel_path_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DejaDupConfigRelPathClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) deja_dup_config_rel_path_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DejaDupConfigRelPath), 0, (GInstanceInitFunc) deja_dup_config_rel_path_instance_init, NULL };
		GType deja_dup_config_rel_path_type_id;
		deja_dup_config_rel_path_type_id = g_type_register_static (DEJA_DUP_TYPE_CONFIG_ENTRY, "DejaDupConfigRelPath", &g_define_type_info, 0);
		g_once_init_leave (&deja_dup_config_rel_path_type_id__volatile, deja_dup_config_rel_path_type_id);
	}
	return deja_dup_config_rel_path_type_id__volatile;
}


