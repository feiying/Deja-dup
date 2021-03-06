/* BackendAuto.c generated by valac 0.16.1, the Vala compiler
 * generated from BackendAuto.vala, do not modify */

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
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define DEJA_DUP_TYPE_BACKEND (deja_dup_backend_get_type ())
#define DEJA_DUP_BACKEND(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_BACKEND, DejaDupBackend))
#define DEJA_DUP_BACKEND_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_BACKEND, DejaDupBackendClass))
#define DEJA_DUP_IS_BACKEND(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_BACKEND))
#define DEJA_DUP_IS_BACKEND_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_BACKEND))
#define DEJA_DUP_BACKEND_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_BACKEND, DejaDupBackendClass))

typedef struct _DejaDupBackend DejaDupBackend;
typedef struct _DejaDupBackendClass DejaDupBackendClass;
typedef struct _DejaDupBackendPrivate DejaDupBackendPrivate;

#define DEJA_DUP_TOOL_JOB_TYPE_MODE (deja_dup_tool_job_mode_get_type ())

#define DEJA_DUP_TYPE_BACKEND_AUTO (deja_dup_backend_auto_get_type ())
#define DEJA_DUP_BACKEND_AUTO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_BACKEND_AUTO, DejaDupBackendAuto))
#define DEJA_DUP_BACKEND_AUTO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_BACKEND_AUTO, DejaDupBackendAutoClass))
#define DEJA_DUP_IS_BACKEND_AUTO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_BACKEND_AUTO))
#define DEJA_DUP_IS_BACKEND_AUTO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_BACKEND_AUTO))
#define DEJA_DUP_BACKEND_AUTO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_BACKEND_AUTO, DejaDupBackendAutoClass))

typedef struct _DejaDupBackendAuto DejaDupBackendAuto;
typedef struct _DejaDupBackendAutoClass DejaDupBackendAutoClass;
typedef struct _DejaDupBackendAutoPrivate DejaDupBackendAutoPrivate;

#define DEJA_DUP_TYPE_CHECKER (deja_dup_checker_get_type ())
#define DEJA_DUP_CHECKER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_CHECKER, DejaDupChecker))
#define DEJA_DUP_CHECKER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_CHECKER, DejaDupCheckerClass))
#define DEJA_DUP_IS_CHECKER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_CHECKER))
#define DEJA_DUP_IS_CHECKER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_CHECKER))
#define DEJA_DUP_CHECKER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_CHECKER, DejaDupCheckerClass))

typedef struct _DejaDupChecker DejaDupChecker;
typedef struct _DejaDupCheckerClass DejaDupCheckerClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _DejaDupBackendAutoIsReadyData DejaDupBackendAutoIsReadyData;

#define DEJA_DUP_TYPE_SIMPLE_SETTINGS (deja_dup_simple_settings_get_type ())
#define DEJA_DUP_SIMPLE_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), DEJA_DUP_TYPE_SIMPLE_SETTINGS, DejaDupSimpleSettings))
#define DEJA_DUP_SIMPLE_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), DEJA_DUP_TYPE_SIMPLE_SETTINGS, DejaDupSimpleSettingsClass))
#define DEJA_DUP_IS_SIMPLE_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DEJA_DUP_TYPE_SIMPLE_SETTINGS))
#define DEJA_DUP_IS_SIMPLE_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), DEJA_DUP_TYPE_SIMPLE_SETTINGS))
#define DEJA_DUP_SIMPLE_SETTINGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), DEJA_DUP_TYPE_SIMPLE_SETTINGS, DejaDupSimpleSettingsClass))

typedef struct _DejaDupSimpleSettings DejaDupSimpleSettings;
typedef struct _DejaDupSimpleSettingsClass DejaDupSimpleSettingsClass;

typedef enum  {
	DEJA_DUP_TOOL_JOB_MODE_INVALID,
	DEJA_DUP_TOOL_JOB_MODE_BACKUP,
	DEJA_DUP_TOOL_JOB_MODE_RESTORE,
	DEJA_DUP_TOOL_JOB_MODE_STATUS,
	DEJA_DUP_TOOL_JOB_MODE_LIST,
	DEJA_DUP_TOOL_JOB_MODE_HISTORY
} DejaDupToolJobMode;

struct _DejaDupBackend {
	GObject parent_instance;
	DejaDupBackendPrivate * priv;
};

struct _DejaDupBackendClass {
	GObjectClass parent_class;
	gboolean (*is_native) (DejaDupBackend* self);
	GIcon* (*get_icon) (DejaDupBackend* self);
	gchar* (*get_location) (DejaDupBackend* self, gboolean* as_root);
	gchar* (*get_location_pretty) (DejaDupBackend* self);
	void (*is_ready) (DejaDupBackend* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	gboolean (*is_ready_finish) (DejaDupBackend* self, GAsyncResult* _res_, gchar** when);
	void (*get_envp) (DejaDupBackend* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
	void (*get_envp_finish) (DejaDupBackend* self, GAsyncResult* _res_, GError** error);
	void (*get_space) (DejaDupBackend* self, gboolean free, GAsyncReadyCallback _callback_, gpointer _user_data_);
	guint64 (*get_space_finish) (DejaDupBackend* self, GAsyncResult* _res_);
	gboolean (*space_can_be_infinite) (DejaDupBackend* self);
	void (*add_argv) (DejaDupBackend* self, DejaDupToolJobMode mode, GList** argv);
	DejaDupBackend* (*clone) (DejaDupBackend* self);
};

struct _DejaDupBackendAuto {
	DejaDupBackend parent_instance;
	DejaDupBackendAutoPrivate * priv;
};

struct _DejaDupBackendAutoClass {
	DejaDupBackendClass parent_class;
};

struct _DejaDupBackendAutoPrivate {
	DejaDupChecker* u1checker;
	DejaDupChecker* s3checker;
};

struct _DejaDupBackendAutoIsReadyData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	DejaDupBackendAuto* self;
	gchar* when;
	gboolean result;
};


static gpointer deja_dup_backend_auto_parent_class = NULL;
static gboolean deja_dup_backend_auto_started;
static gboolean deja_dup_backend_auto_started = FALSE;
static gboolean deja_dup_backend_auto_done;
static gboolean deja_dup_backend_auto_done = FALSE;

GType deja_dup_backend_get_type (void) G_GNUC_CONST;
GType deja_dup_tool_job_mode_get_type (void) G_GNUC_CONST;
GType deja_dup_backend_auto_get_type (void) G_GNUC_CONST;
GType deja_dup_checker_get_type (void) G_GNUC_CONST;
#define DEJA_DUP_BACKEND_AUTO_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), DEJA_DUP_TYPE_BACKEND_AUTO, DejaDupBackendAutoPrivate))
enum  {
	DEJA_DUP_BACKEND_AUTO_DUMMY_PROPERTY
};
static DejaDupBackend* deja_dup_backend_auto_real_clone (DejaDupBackend* base);
DejaDupBackendAuto* deja_dup_backend_auto_new (void);
DejaDupBackendAuto* deja_dup_backend_auto_construct (GType object_type);
static gboolean deja_dup_backend_auto_real_is_native (DejaDupBackend* base);
static GIcon* deja_dup_backend_auto_real_get_icon (DejaDupBackend* base);
static void deja_dup_backend_auto_real_is_ready_data_free (gpointer _data);
static void deja_dup_backend_auto_real_is_ready (DejaDupBackend* base, GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean deja_dup_backend_auto_real_is_ready_co (DejaDupBackendAutoIsReadyData* _data_);
static gchar* deja_dup_backend_auto_real_get_location (DejaDupBackend* base, gboolean* as_root);
static gchar* deja_dup_backend_auto_real_get_location_pretty (DejaDupBackend* base);
static void deja_dup_backend_auto_examine_checkers (DejaDupBackendAuto* self);
gboolean deja_dup_checker_get_complete (DejaDupChecker* self);
gboolean deja_dup_checker_get_available (DejaDupChecker* self);
static void deja_dup_backend_auto_finish (DejaDupBackendAuto* self, const gchar* mode);
GType deja_dup_simple_settings_get_type (void) G_GNUC_CONST;
DejaDupSimpleSettings* deja_dup_get_settings (const gchar* subdir);
#define DEJA_DUP_FILE_ROOT "File"
void deja_dup_simple_settings_set_string (DejaDupSimpleSettings* self, const gchar* k, const gchar* v);
#define DEJA_DUP_FILE_TYPE_KEY "type"
#define DEJA_DUP_FILE_PATH_KEY "path"
void deja_dup_simple_settings_apply (DejaDupSimpleSettings* self);
#define DEJA_DUP_BACKEND_KEY "backend"
DejaDupBackend* deja_dup_backend_construct (GType object_type);
static GObject * deja_dup_backend_auto_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
DejaDupChecker* deja_dup_backend_u1_get_checker (void);
static void _deja_dup_backend_auto_examine_checkers_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
DejaDupChecker* deja_dup_backend_s3_get_checker (void);
static void deja_dup_backend_auto_finalize (GObject* obj);


static DejaDupBackend* deja_dup_backend_auto_real_clone (DejaDupBackend* base) {
	DejaDupBackendAuto * self;
	DejaDupBackend* result = NULL;
	DejaDupBackendAuto* _tmp0_;
	self = (DejaDupBackendAuto*) base;
	_tmp0_ = deja_dup_backend_auto_new ();
	result = (DejaDupBackend*) _tmp0_;
	return result;
}


static gboolean deja_dup_backend_auto_real_is_native (DejaDupBackend* base) {
	DejaDupBackendAuto * self;
	gboolean result = FALSE;
	self = (DejaDupBackendAuto*) base;
	result = FALSE;
	return result;
}


static GIcon* deja_dup_backend_auto_real_get_icon (DejaDupBackend* base) {
	DejaDupBackendAuto * self;
	GIcon* result = NULL;
	self = (DejaDupBackendAuto*) base;
	result = NULL;
	return result;
}


static void deja_dup_backend_auto_real_is_ready_data_free (gpointer _data) {
	DejaDupBackendAutoIsReadyData* _data_;
	_data_ = _data;
	_g_object_unref0 (_data_->self);
	g_slice_free (DejaDupBackendAutoIsReadyData, _data_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void deja_dup_backend_auto_real_is_ready (DejaDupBackend* base, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	DejaDupBackendAuto * self;
	DejaDupBackendAutoIsReadyData* _data_;
	DejaDupBackendAuto* _tmp0_;
	self = (DejaDupBackendAuto*) base;
	_data_ = g_slice_new0 (DejaDupBackendAutoIsReadyData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, deja_dup_backend_auto_real_is_ready);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, deja_dup_backend_auto_real_is_ready_data_free);
	_tmp0_ = _g_object_ref0 (self);
	_data_->self = _tmp0_;
	deja_dup_backend_auto_real_is_ready_co (_data_);
}


static gboolean deja_dup_backend_auto_real_is_ready_finish (DejaDupBackend* base, GAsyncResult* _res_, gchar** when) {
	gboolean result;
	DejaDupBackendAutoIsReadyData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	if (when) {
		*when = _data_->when;
	} else {
		_g_free0 (_data_->when);
	}
	_data_->when = NULL;
	result = _data_->result;
	return result;
}


static gboolean deja_dup_backend_auto_real_is_ready_co (DejaDupBackendAutoIsReadyData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_g_free0 (_data_->when);
	_data_->when = NULL;
	_data_->result = FALSE;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static gchar* deja_dup_backend_auto_real_get_location (DejaDupBackend* base, gboolean* as_root) {
	DejaDupBackendAuto * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (DejaDupBackendAuto*) base;
	_tmp0_ = g_strdup ("invalid");
	result = _tmp0_;
	return result;
}


static gchar* deja_dup_backend_auto_real_get_location_pretty (DejaDupBackend* base) {
	DejaDupBackendAuto * self;
	gchar* result = NULL;
	gchar* _tmp0_;
	self = (DejaDupBackendAuto*) base;
	_tmp0_ = g_strdup ("");
	result = _tmp0_;
	return result;
}


static void deja_dup_backend_auto_examine_checkers (DejaDupBackendAuto* self) {
	gboolean _tmp0_;
	DejaDupChecker* _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	g_return_if_fail (self != NULL);
	_tmp0_ = deja_dup_backend_auto_done;
	if (_tmp0_) {
		return;
	}
	_tmp1_ = self->priv->u1checker;
	_tmp2_ = deja_dup_checker_get_complete (_tmp1_);
	_tmp3_ = _tmp2_;
	if (_tmp3_) {
		DejaDupChecker* _tmp4_;
		gboolean _tmp5_;
		gboolean _tmp6_;
		_tmp4_ = self->priv->u1checker;
		_tmp5_ = deja_dup_checker_get_available (_tmp4_);
		_tmp6_ = _tmp5_;
		if (_tmp6_) {
			deja_dup_backend_auto_finish (self, "u1");
		} else {
			DejaDupChecker* _tmp7_;
			gboolean _tmp8_;
			gboolean _tmp9_;
			_tmp7_ = self->priv->s3checker;
			_tmp8_ = deja_dup_checker_get_complete (_tmp7_);
			_tmp9_ = _tmp8_;
			if (_tmp9_) {
				DejaDupChecker* _tmp10_;
				gboolean _tmp11_;
				gboolean _tmp12_;
				_tmp10_ = self->priv->s3checker;
				_tmp11_ = deja_dup_checker_get_available (_tmp10_);
				_tmp12_ = _tmp11_;
				if (_tmp12_) {
					deja_dup_backend_auto_finish (self, "s3");
				} else {
					deja_dup_backend_auto_finish (self, "file");
				}
			}
		}
	}
}


static void deja_dup_backend_auto_finish (DejaDupBackendAuto* self, const gchar* mode) {
	const gchar* _tmp0_;
	DejaDupSimpleSettings* _tmp9_ = NULL;
	DejaDupSimpleSettings* settings;
	const gchar* _tmp10_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (mode != NULL);
	_tmp0_ = mode;
	if (g_strcmp0 (_tmp0_, "file") == 0) {
		DejaDupSimpleSettings* _tmp1_ = NULL;
		DejaDupSimpleSettings* file_settings;
		DejaDupSimpleSettings* _tmp2_;
		DejaDupSimpleSettings* _tmp3_;
		const gchar* _tmp4_ = NULL;
		gchar* _tmp5_ = NULL;
		gchar* path;
		DejaDupSimpleSettings* _tmp6_;
		const gchar* _tmp7_;
		DejaDupSimpleSettings* _tmp8_;
		_tmp1_ = deja_dup_get_settings (DEJA_DUP_FILE_ROOT);
		file_settings = _tmp1_;
		_tmp2_ = file_settings;
		g_settings_delay ((GSettings*) _tmp2_);
		_tmp3_ = file_settings;
		deja_dup_simple_settings_set_string (_tmp3_, DEJA_DUP_FILE_TYPE_KEY, "normal");
		_tmp4_ = g_get_home_dir ();
		_tmp5_ = g_build_filename (_tmp4_, "deja-dup", NULL);
		path = _tmp5_;
		_tmp6_ = file_settings;
		_tmp7_ = path;
		deja_dup_simple_settings_set_string (_tmp6_, DEJA_DUP_FILE_PATH_KEY, _tmp7_);
		_tmp8_ = file_settings;
		deja_dup_simple_settings_apply (_tmp8_);
		_g_free0 (path);
		_g_object_unref0 (file_settings);
	}
	_tmp9_ = deja_dup_get_settings (NULL);
	settings = _tmp9_;
	_tmp10_ = mode;
	deja_dup_simple_settings_set_string (settings, DEJA_DUP_BACKEND_KEY, _tmp10_);
	deja_dup_backend_auto_done = TRUE;
	g_object_unref ((GObject*) self);
	_g_object_unref0 (settings);
}


DejaDupBackendAuto* deja_dup_backend_auto_construct (GType object_type) {
	DejaDupBackendAuto * self = NULL;
	self = (DejaDupBackendAuto*) deja_dup_backend_construct (object_type);
	return self;
}


DejaDupBackendAuto* deja_dup_backend_auto_new (void) {
	return deja_dup_backend_auto_construct (DEJA_DUP_TYPE_BACKEND_AUTO);
}


static void _deja_dup_backend_auto_examine_checkers_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	deja_dup_backend_auto_examine_checkers (self);
}


static GObject * deja_dup_backend_auto_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	DejaDupBackendAuto * self;
	gboolean _tmp0_;
	parent_class = G_OBJECT_CLASS (deja_dup_backend_auto_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = DEJA_DUP_BACKEND_AUTO (obj);
	_tmp0_ = deja_dup_backend_auto_started;
	if (!_tmp0_) {
		DejaDupChecker* _tmp1_ = NULL;
		DejaDupChecker* _tmp2_;
		DejaDupChecker* _tmp3_ = NULL;
		DejaDupChecker* _tmp4_;
		deja_dup_backend_auto_started = TRUE;
		g_object_ref ((GObject*) self);
		_tmp1_ = deja_dup_backend_u1_get_checker ();
		_g_object_unref0 (self->priv->u1checker);
		self->priv->u1checker = _tmp1_;
		_tmp2_ = self->priv->u1checker;
		g_signal_connect_object ((GObject*) _tmp2_, "notify::complete", (GCallback) _deja_dup_backend_auto_examine_checkers_g_object_notify, self, 0);
		_tmp3_ = deja_dup_backend_s3_get_checker ();
		_g_object_unref0 (self->priv->s3checker);
		self->priv->s3checker = _tmp3_;
		_tmp4_ = self->priv->s3checker;
		g_signal_connect_object ((GObject*) _tmp4_, "notify::complete", (GCallback) _deja_dup_backend_auto_examine_checkers_g_object_notify, self, 0);
		deja_dup_backend_auto_examine_checkers (self);
	}
	return obj;
}


static void deja_dup_backend_auto_class_init (DejaDupBackendAutoClass * klass) {
	deja_dup_backend_auto_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (DejaDupBackendAutoPrivate));
	DEJA_DUP_BACKEND_CLASS (klass)->clone = deja_dup_backend_auto_real_clone;
	DEJA_DUP_BACKEND_CLASS (klass)->is_native = deja_dup_backend_auto_real_is_native;
	DEJA_DUP_BACKEND_CLASS (klass)->get_icon = deja_dup_backend_auto_real_get_icon;
	DEJA_DUP_BACKEND_CLASS (klass)->is_ready = deja_dup_backend_auto_real_is_ready;
	DEJA_DUP_BACKEND_CLASS (klass)->is_ready_finish = deja_dup_backend_auto_real_is_ready_finish;
	DEJA_DUP_BACKEND_CLASS (klass)->get_location = deja_dup_backend_auto_real_get_location;
	DEJA_DUP_BACKEND_CLASS (klass)->get_location_pretty = deja_dup_backend_auto_real_get_location_pretty;
	G_OBJECT_CLASS (klass)->constructor = deja_dup_backend_auto_constructor;
	G_OBJECT_CLASS (klass)->finalize = deja_dup_backend_auto_finalize;
}


static void deja_dup_backend_auto_instance_init (DejaDupBackendAuto * self) {
	self->priv = DEJA_DUP_BACKEND_AUTO_GET_PRIVATE (self);
}


static void deja_dup_backend_auto_finalize (GObject* obj) {
	DejaDupBackendAuto * self;
	self = DEJA_DUP_BACKEND_AUTO (obj);
	_g_object_unref0 (self->priv->u1checker);
	_g_object_unref0 (self->priv->s3checker);
	G_OBJECT_CLASS (deja_dup_backend_auto_parent_class)->finalize (obj);
}


GType deja_dup_backend_auto_get_type (void) {
	static volatile gsize deja_dup_backend_auto_type_id__volatile = 0;
	if (g_once_init_enter (&deja_dup_backend_auto_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (DejaDupBackendAutoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) deja_dup_backend_auto_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (DejaDupBackendAuto), 0, (GInstanceInitFunc) deja_dup_backend_auto_instance_init, NULL };
		GType deja_dup_backend_auto_type_id;
		deja_dup_backend_auto_type_id = g_type_register_static (DEJA_DUP_TYPE_BACKEND, "DejaDupBackendAuto", &g_define_type_info, 0);
		g_once_init_leave (&deja_dup_backend_auto_type_id__volatile, deja_dup_backend_auto_type_id);
	}
	return deja_dup_backend_auto_type_id__volatile;
}



