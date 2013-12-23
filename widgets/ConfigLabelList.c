/* ConfigLabelList.c generated by valac 0.16.1, the Vala compiler
 * generated from ConfigLabelList.vala, do not modify */

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
#include <pango/pango.h>


#define DEJA_DUP_TYPE_CONFIG_WIDGET (deja_dup_config_widget_get_type ())
#define DEJA_DUP_CONFIG_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidget))
#define DEJA_DUP_CONFIG_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidgetClass))
#define DEJA_DUP_IS_CONFIG_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET))
#define DEJA_DUP_IS_CONFIG_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_WIDGET))
#define DEJA_DUP_CONFIG_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_WIDGET, DejaDupConfigWidgetClass))

typedef struct _DejaDupConfigWidget DejaDupConfigWidget;
typedef struct _DejaDupConfigWidgetClass DejaDupConfigWidgetClass;
typedef struct _DejaDupConfigWidgetPrivate DejaDupConfigWidgetPrivate;

#define DEJA_DUP_TYPE_CONFIG_LABEL (deja_dup_config_label_get_type ())
#define DEJA_DUP_CONFIG_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_LABEL, DejaDupConfigLabel))
#define DEJA_DUP_CONFIG_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_LABEL, DejaDupConfigLabelClass))
#define DEJA_DUP_IS_CONFIG_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_LABEL))
#define DEJA_DUP_IS_CONFIG_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_LABEL))
#define DEJA_DUP_CONFIG_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_LABEL, DejaDupConfigLabelClass))

typedef struct _DejaDupConfigLabel DejaDupConfigLabel;
typedef struct _DejaDupConfigLabelClass DejaDupConfigLabelClass;
typedef struct _DejaDupConfigLabelPrivate DejaDupConfigLabelPrivate;

#define DEJA_DUP_TYPE_CONFIG_LABEL_LIST (deja_dup_config_label_list_get_type ())
#define DEJA_DUP_CONFIG_LABEL_LIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CONFIG_LABEL_LIST, DejaDupConfigLabelList))
#define DEJA_DUP_CONFIG_LABEL_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CONFIG_LABEL_LIST, DejaDupConfigLabelListClass))
#define DEJA_DUP_IS_CONFIG_LABEL_LIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CONFIG_LABEL_LIST))
#define DEJA_DUP_IS_CONFIG_LABEL_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CONFIG_LABEL_LIST))
#define DEJA_DUP_CONFIG_LABEL_LIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CONFIG_LABEL_LIST, DejaDupConfigLabelListClass))

typedef struct _DejaDupConfigLabelList DejaDupConfigLabelList;
typedef struct _DejaDupConfigLabelListClass DejaDupConfigLabelListClass;
typedef struct _DejaDupConfigLabelListPrivate DejaDupConfigLabelListPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_variant_unref0(var) ((var == NULL) ? NULL : (var = (g_variant_unref (var), NULL)))
typedef struct _DejaDupConfigLabelListSetFromConfigData DejaDupConfigLabelListSetFromConfigData;

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

struct _DejaDupConfigLabel {
	DejaDupConfigWidget parent_instance;
	DejaDupConfigLabelPrivate * priv;
	GtkGrid* box;
	GtkLabel* label;
};

struct _DejaDupConfigLabelClass {
	DejaDupConfigWidgetClass parent_class;
	void (*fill_box) (DejaDupConfigLabel* self);
};

struct _DejaDupConfigLabelList {
	DejaDupConfigLabel parent_instance;
	DejaDupConfigLabelListPrivate * priv;
};

struct _DejaDupConfigLabelListClass {
	DejaDupConfigLabelClass parent_class;
};

struct _DejaDupConfigLabelListSetFromConfigData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DejaDupConfigLabelList* self;
	gchar* val;
	DejaDupSimpleSettings* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	GVariant* _tmp3_;
	GVariant* slist_val;
	GVariant* _tmp4_;
	size_t _tmp5_;
	const gchar** _tmp6_;
	const gchar** slist;
	gint slist_length1;
	gint _slist_size_;
	const gchar** _tmp7_;
	gint _tmp7__length1;
	gint _tmp8_;
	GFile** _tmp9_;
	GFile** list;
	gint list_length1;
	gint _list_size_;
	GFile** _tmp10_;
	gint _tmp10__length1;
	GFile** f_collection;
	gint f_collection_length1;
	gint _f_collection_size_;
	gint f_it;
	GFile* _tmp11_;
	GFile* f;
	GFile* _tmp12_;
	gchar* _tmp13_;
	gchar* s;
	gboolean _tmp14_;
	const gchar* _tmp15_;
	gint _tmp16_;
	gint _tmp17_;
	const gchar* _tmp18_;
	gboolean _tmp19_;
	gboolean _tmp20_;
	const gchar* _tmp21_;
	gchar* _tmp22_;
	const gchar* _tmp23_;
	const gchar* _tmp24_;
	const gchar* _tmp25_;
	gchar* _tmp26_;
	gchar* _tmp27_;
	gchar* _tmp28_;
	const gchar* _tmp29_;
	gchar* _tmp30_;
	const gchar* _tmp31_;
	const gchar* _tmp32_;
	const gchar* _tmp33_;
	GtkLabel* _tmp34_;
	const gchar* _tmp35_;
};


static gpointer deja_dup_config_label_list_parent_class = NULL;

GType deja_dup_config_widget_get_type (void) G_GNUC_CONST;
GType deja_dup_config_label_get_type (void) G_GNUC_CONST;
GType deja_dup_config_label_list_get_type (void) G_GNUC_CONST;
enum  {
	DEJA_DUP_CONFIG_LABEL_LIST_DUMMY_PROPERTY
};
DejaDupConfigLabelList* deja_dup_config_label_list_new (const gchar* key, const gchar* ns);
DejaDupConfigLabelList* deja_dup_config_label_list_construct (GType object_type, const gchar* key, const gchar* ns);
static void deja_dup_config_label_list_real_set_from_config_data_free (gpointer _data);
static void deja_dup_config_label_list_real_set_from_config (DejaDupConfigWidget* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean deja_dup_config_label_list_real_set_from_config_co (DejaDupConfigLabelListSetFromConfigData* _data_);
const gchar* deja_dup_config_widget_get_key (DejaDupConfigWidget* self);
static void deja_dup_config_label_list_set_from_config_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static GObject * deja_dup_config_label_list_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


DejaDupConfigLabelList* deja_dup_config_label_list_construct (GType object_type, const gchar* key, const gchar* ns) {
	DejaDupConfigLabelList * self = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	g_return_val_if_fail (key != NULL, NULL);
	g_return_val_if_fail (ns != NULL, NULL);
	_tmp0_ = key;
	_tmp1_ = ns;
	self = (DejaDupConfigLabelList*) g_object_new (object_type, "key", _tmp0_, "ns", _tmp1_, NULL);
	return self;
}


DejaDupConfigLabelList* deja_dup_config_label_list_new (const gchar* key, const gchar* ns) {
	return deja_dup_config_label_list_construct (DEJA_DUP_TYPE_CONFIG_LABEL_LIST, key, ns);
}


static void deja_dup_config_label_list_real_set_from_config_data_free (gpointer _data) {
	DejaDupConfigLabelListSetFromConfigData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DejaDupConfigLabelListSetFromConfigData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void deja_dup_config_label_list_real_set_from_config (DejaDupConfigWidget* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DejaDupConfigLabelList * self;
	DejaDupConfigLabelListSetFromConfigData* _data_;
	DejaDupConfigLabelList* _tmp0_;
	self = (DejaDupConfigLabelList*) base;
	_data_ = g_slice_new0 (DejaDupConfigLabelListSetFromConfigData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, deja_dup_config_label_list_real_set_from_config);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, deja_dup_config_label_list_real_set_from_config_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	deja_dup_config_label_list_real_set_from_config_co (_data_);
}


static void deja_dup_config_label_list_real_set_from_config_finish (DejaDupConfigWidget* base, GAsyncResult* _res_) {
	DejaDupConfigLabelListSetFromConfigData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void deja_dup_config_label_list_set_from_config_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	DejaDupConfigLabelListSetFromConfigData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	deja_dup_config_label_list_real_set_from_config_co (_data_);
}


static gchar* string_splice (const gchar* self, glong start, glong end, const gchar* str) {
	gchar* result = NULL;
	gint _tmp0_;
	gint _tmp1_;
	glong string_length;
	glong _tmp2_;
	glong _tmp5_;
	gboolean _tmp8_ = FALSE;
	glong _tmp9_;
	gboolean _tmp12_;
	gboolean _tmp13_ = FALSE;
	glong _tmp14_;
	gboolean _tmp17_;
	glong _tmp18_;
	glong _tmp19_;
	gsize str_size = 0UL;
	const gchar* _tmp20_;
	gint _tmp24_;
	gint _tmp25_;
	glong _tmp26_;
	glong _tmp27_;
	gsize _tmp28_;
	void* _tmp29_ = NULL;
	const gchar* _result_;
	const gchar* _tmp30_;
	gchar* dest;
	gchar* _tmp31_;
	glong _tmp32_;
	gchar* _tmp33_;
	glong _tmp34_;
	gchar* _tmp35_;
	const gchar* _tmp36_;
	gsize _tmp37_;
	gchar* _tmp38_;
	gsize _tmp39_;
	gchar* _tmp40_;
	glong _tmp41_;
	glong _tmp42_;
	glong _tmp43_;
	const gchar* _tmp44_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = strlen (self);
	_tmp1_ = _tmp0_;
	string_length = (glong) _tmp1_;
	_tmp2_ = start;
	if (_tmp2_ < ((glong) 0)) {
		glong _tmp3_;
		glong _tmp4_;
		_tmp3_ = string_length;
		_tmp4_ = start;
		start = _tmp3_ + _tmp4_;
	}
	_tmp5_ = end;
	if (_tmp5_ < ((glong) 0)) {
		glong _tmp6_;
		glong _tmp7_;
		_tmp6_ = string_length;
		_tmp7_ = end;
		end = _tmp6_ + _tmp7_;
	}
	_tmp9_ = start;
	if (_tmp9_ >= ((glong) 0)) {
		glong _tmp10_;
		glong _tmp11_;
		_tmp10_ = start;
		_tmp11_ = string_length;
		_tmp8_ = _tmp10_ <= _tmp11_;
	} else {
		_tmp8_ = FALSE;
	}
	_tmp12_ = _tmp8_;
	g_return_val_if_fail (_tmp12_, NULL);
	_tmp14_ = end;
	if (_tmp14_ >= ((glong) 0)) {
		glong _tmp15_;
		glong _tmp16_;
		_tmp15_ = end;
		_tmp16_ = string_length;
		_tmp13_ = _tmp15_ <= _tmp16_;
	} else {
		_tmp13_ = FALSE;
	}
	_tmp17_ = _tmp13_;
	g_return_val_if_fail (_tmp17_, NULL);
	_tmp18_ = start;
	_tmp19_ = end;
	g_return_val_if_fail (_tmp18_ <= _tmp19_, NULL);
	_tmp20_ = str;
	if (_tmp20_ == NULL) {
		str_size = (gsize) 0;
	} else {
		const gchar* _tmp21_;
		gint _tmp22_;
		gint _tmp23_;
		_tmp21_ = str;
		_tmp22_ = strlen ((const gchar*) _tmp21_);
		_tmp23_ = _tmp22_;
		str_size = (gsize) _tmp23_;
	}
	_tmp24_ = strlen (self);
	_tmp25_ = _tmp24_;
	_tmp26_ = end;
	_tmp27_ = start;
	_tmp28_ = str_size;
	_tmp29_ = g_malloc0 (((_tmp25_ - (_tmp26_ - _tmp27_)) + _tmp28_) + 1);
	_result_ = _tmp29_;
	_tmp30_ = _result_;
	dest = (gchar*) _tmp30_;
	_tmp31_ = dest;
	_tmp32_ = start;
	memcpy (_tmp31_, self, (gsize) _tmp32_);
	_tmp33_ = dest;
	_tmp34_ = start;
	dest = _tmp33_ + _tmp34_;
	_tmp35_ = dest;
	_tmp36_ = str;
	_tmp37_ = str_size;
	memcpy (_tmp35_, _tmp36_, _tmp37_);
	_tmp38_ = dest;
	_tmp39_ = str_size;
	dest = _tmp38_ + _tmp39_;
	_tmp40_ = dest;
	_tmp41_ = end;
	_tmp42_ = string_length;
	_tmp43_ = end;
	memcpy (_tmp40_, ((gchar*) self) + _tmp41_, (gsize) (_tmp42_ - _tmp43_));
	_tmp44_ = _result_;
	_result_ = NULL;
	result = (gchar*) _tmp44_;
	return result;
}


static gboolean deja_dup_config_label_list_real_set_from_config_co (DejaDupConfigLabelListSetFromConfigData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->val = NULL;
	_data_->_tmp0_ = ((DejaDupConfigWidget*) _data_->self)->settings;
	_data_->_tmp1_ = deja_dup_config_widget_get_key ((DejaDupConfigWidget*) _data_->self);
	_data_->_tmp2_ = _data_->_tmp1_;
	_data_->_tmp3_ = NULL;
	_data_->_tmp3_ = g_settings_get_value ((GSettings*) _data_->_tmp0_, _data_->_tmp2_);
	_data_->slist_val = _data_->_tmp3_;
	_data_->_tmp4_ = _data_->slist_val;
	memset (&_data_->_tmp5_, 0, sizeof (size_t));
	_data_->_tmp6_ = NULL;
	_data_->_tmp6_ = g_variant_get_strv (_data_->_tmp4_, &_data_->_tmp5_);
	_data_->slist = _data_->_tmp6_;
	_data_->slist_length1 = _data_->_tmp5_;
	_data_->_slist_size_ = _data_->slist_length1;
	_data_->_tmp7_ = _data_->slist;
	_data_->_tmp7__length1 = _data_->slist_length1;
	_data_->_tmp8_ = 0;
	_data_->_tmp9_ = NULL;
	_data_->_tmp9_ = deja_dup_parse_dir_list (_data_->_tmp7_, _data_->_tmp7__length1, &_data_->_tmp8_);
	_data_->list = _data_->_tmp9_;
	_data_->list_length1 = _data_->_tmp8_;
	_data_->_list_size_ = _data_->list_length1;
	_data_->_tmp10_ = _data_->list;
	_data_->_tmp10__length1 = _data_->list_length1;
	{
		_data_->f_collection_length1 = 0;
		_data_->_f_collection_size_ = 0;
		_data_->f_collection = _data_->_tmp10_;
		_data_->f_collection_length1 = _data_->_tmp10__length1;
		for (_data_->f_it = 0; _data_->f_it < _data_->_tmp10__length1; _data_->f_it = _data_->f_it + 1) {
			_data_->_tmp11_ = _g_object_ref0 (_data_->f_collection[_data_->f_it]);
			_data_->f = _data_->_tmp11_;
			{
				_data_->_tmp12_ = _data_->f;
				_data_->_state_ = 1;
				deja_dup_get_nickname (_data_->_tmp12_, deja_dup_config_label_list_set_from_config_ready, _data_);
				return FALSE;
				_state_1:
				_data_->_tmp13_ = NULL;
				_data_->_tmp13_ = deja_dup_get_nickname_finish (_data_->_res_);
				_data_->s = _data_->_tmp13_;
				_data_->_tmp15_ = _data_->s;
				_data_->_tmp16_ = strlen (_data_->_tmp15_);
				_data_->_tmp17_ = _data_->_tmp16_;
				if (_data_->_tmp17_ > 1) {
					_data_->_tmp18_ = _data_->s;
					_data_->_tmp19_ = FALSE;
					_data_->_tmp19_ = g_str_has_prefix (_data_->_tmp18_, ".");
					_data_->_tmp14_ = _data_->_tmp19_;
				} else {
					_data_->_tmp14_ = FALSE;
				}
				_data_->_tmp20_ = _data_->_tmp14_;
				if (_data_->_tmp20_) {
					_data_->_tmp21_ = _data_->s;
					_data_->_tmp22_ = NULL;
					_data_->_tmp22_ = string_splice (_data_->_tmp21_, (glong) 0, (glong) 1, "․\xE2\x81\xA0");
					_g_free0 (_data_->s);
					_data_->s = _data_->_tmp22_;
				}
				_data_->_tmp23_ = _data_->val;
				if (_data_->_tmp23_ != NULL) {
					_data_->_tmp24_ = _data_->val;
					_data_->_tmp25_ = _data_->s;
					_data_->_tmp26_ = NULL;
					_data_->_tmp26_ = g_strdup_printf (", %s", _data_->_tmp25_);
					_data_->_tmp27_ = _data_->_tmp26_;
					_data_->_tmp28_ = g_strconcat (_data_->_tmp24_, _data_->_tmp27_, NULL);
					_g_free0 (_data_->val);
					_data_->val = _data_->_tmp28_;
					_g_free0 (_data_->_tmp27_);
				} else {
					_data_->_tmp29_ = _data_->s;
					_data_->_tmp30_ = g_strdup (_data_->_tmp29_);
					_g_free0 (_data_->val);
					_data_->val = _data_->_tmp30_;
				}
				_g_free0 (_data_->s);
				_g_object_unref0 (_data_->f);
			}
		}
	}
	_data_->_tmp32_ = _data_->val;
	if (_data_->_tmp32_ == NULL) {
		_data_->_tmp31_ = "";
	} else {
		_data_->_tmp33_ = _data_->val;
		_data_->_tmp31_ = _data_->_tmp33_;
	}
	_data_->_tmp34_ = ((DejaDupConfigLabel*) _data_->self)->label;
	_data_->_tmp35_ = _data_->_tmp31_;
	gtk_label_set_label (_data_->_tmp34_, _data_->_tmp35_);
	_data_->list = (_vala_array_free (_data_->list, _data_->list_length1, (GDestroyNotify) g_object_unref), NULL);
	_data_->slist = (g_free (_data_->slist), NULL);
	_g_variant_unref0 (_data_->slist_val);
	_g_free0 (_data_->val);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static GObject * deja_dup_config_label_list_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	DejaDupConfigLabelList * self;
	GtkLabel* _tmp0_;
	GtkLabel* _tmp1_;
	parent_class = G_OBJECT_CLASS (deja_dup_config_label_list_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = DEJA_DUP_CONFIG_LABEL_LIST (obj);
	_tmp0_ = ((DejaDupConfigLabel*) self)->label;
	gtk_label_set_ellipsize (_tmp0_, PANGO_ELLIPSIZE_END);
	_tmp1_ = ((DejaDupConfigLabel*) self)->label;
	gtk_label_set_line_wrap (_tmp1_, FALSE);
	return obj;
}


static void deja_dup_config_label_list_class_init (DejaDupConfigLabelListClass * klass) {
	deja_dup_config_label_list_parent_class = g_type_class_peek_parent (klass);
	DEJA_DUP_CONFIG_WIDGET_CLASS (klass)->set_from_config = deja_dup_config_label_list_real_set_from_config;
	DEJA_DUP_CONFIG_WIDGET_CLASS (klass)->set_from_config_finish = deja_dup_config_label_list_real_set_from_config_finish;
	G_OBJECT_CLASS (klass)->constructor = deja_dup_config_label_list_constructor;
}


static void deja_dup_config_label_list_instance_init (DejaDupConfigLabelList * self) {
}


GType deja_dup_config_label_list_get_type (void) {
	static volatile gsize deja_dup_config_label_list_type_id__volatile = 0;
	if (g_once_init_enter (&deja_dup_config_label_list_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DejaDupConfigLabelListClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) deja_dup_config_label_list_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DejaDupConfigLabelList), 0, (GInstanceInitFunc) deja_dup_config_label_list_instance_init, NULL };
		GType deja_dup_config_label_list_type_id;
		deja_dup_config_label_list_type_id = g_type_register_static (DEJA_DUP_TYPE_CONFIG_LABEL, "DejaDupConfigLabelList", &g_define_type_info, 0);
		g_once_init_leave (&deja_dup_config_label_list_type_id__volatile, deja_dup_config_label_list_type_id);
	}
	return deja_dup_config_label_list_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


