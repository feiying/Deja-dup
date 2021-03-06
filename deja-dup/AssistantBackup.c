/* AssistantBackup.c generated by valac 0.16.1, the Vala compiler
 * generated from AssistantBackup.vala, do not modify */

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
#include <common.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gi18n-lib.h>


#define TYPE_ASSISTANT (assistant_get_type ())
#define ASSISTANT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ASSISTANT, Assistant))
#define ASSISTANT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ASSISTANT, AssistantClass))
#define IS_ASSISTANT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ASSISTANT))
#define IS_ASSISTANT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ASSISTANT))
#define ASSISTANT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ASSISTANT, AssistantClass))

typedef struct _Assistant Assistant;
typedef struct _AssistantClass AssistantClass;
typedef struct _AssistantPrivate AssistantPrivate;

#define ASSISTANT_TYPE_PAGE_INFO (assistant_page_info_get_type ())
#define ASSISTANT_PAGE_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ASSISTANT_TYPE_PAGE_INFO, AssistantPageInfo))
#define ASSISTANT_PAGE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ASSISTANT_TYPE_PAGE_INFO, AssistantPageInfoClass))
#define ASSISTANT_IS_PAGE_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ASSISTANT_TYPE_PAGE_INFO))
#define ASSISTANT_IS_PAGE_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ASSISTANT_TYPE_PAGE_INFO))
#define ASSISTANT_PAGE_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ASSISTANT_TYPE_PAGE_INFO, AssistantPageInfoClass))

typedef struct _AssistantPageInfo AssistantPageInfo;
typedef struct _AssistantPageInfoClass AssistantPageInfoClass;

#define TYPE_ASSISTANT_OPERATION (assistant_operation_get_type ())
#define ASSISTANT_OPERATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ASSISTANT_OPERATION, AssistantOperation))
#define ASSISTANT_OPERATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ASSISTANT_OPERATION, AssistantOperationClass))
#define IS_ASSISTANT_OPERATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ASSISTANT_OPERATION))
#define IS_ASSISTANT_OPERATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ASSISTANT_OPERATION))
#define ASSISTANT_OPERATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ASSISTANT_OPERATION, AssistantOperationClass))

typedef struct _AssistantOperation AssistantOperation;
typedef struct _AssistantOperationClass AssistantOperationClass;
typedef struct _AssistantOperationPrivate AssistantOperationPrivate;

#define TYPE_STATUS_ICON (status_icon_get_type ())
#define STATUS_ICON(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_STATUS_ICON, StatusIcon))
#define STATUS_ICON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_STATUS_ICON, StatusIconClass))
#define IS_STATUS_ICON(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_STATUS_ICON))
#define IS_STATUS_ICON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_STATUS_ICON))
#define STATUS_ICON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_STATUS_ICON, StatusIconClass))

typedef struct _StatusIcon StatusIcon;
typedef struct _StatusIconClass StatusIconClass;

#define TYPE_ASSISTANT_BACKUP (assistant_backup_get_type ())
#define ASSISTANT_BACKUP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_ASSISTANT_BACKUP, AssistantBackup))
#define ASSISTANT_BACKUP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_ASSISTANT_BACKUP, AssistantBackupClass))
#define IS_ASSISTANT_BACKUP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_ASSISTANT_BACKUP))
#define IS_ASSISTANT_BACKUP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_ASSISTANT_BACKUP))
#define ASSISTANT_BACKUP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_ASSISTANT_BACKUP, AssistantBackupClass))

typedef struct _AssistantBackup AssistantBackup;
typedef struct _AssistantBackupClass AssistantBackupClass;
typedef struct _AssistantBackupPrivate AssistantBackupPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _Assistant {
	GtkWindow parent_instance;
	AssistantPrivate * priv;
	GtkImage* header_icon;
	GtkEventBox* page_box;
	GList* current;
};

struct _AssistantClass {
	GtkWindowClass parent_class;
};

struct _AssistantOperation {
	Assistant parent_instance;
	AssistantOperationPrivate * priv;
	StatusIcon* status_icon;
	gboolean succeeded;
	gboolean nagged;
	GtkLabel* summary_label;
	GtkWidget* detail_widget;
	DejaDupOperation* op;
};

struct _AssistantOperationClass {
	AssistantClass parent_class;
	GtkWidget* (*make_confirm_page) (AssistantOperation* self);
	void (*add_setup_pages) (AssistantOperation* self);
	void (*add_custom_config_pages) (AssistantOperation* self);
	DejaDupOperation* (*create_op) (AssistantOperation* self);
	gchar* (*get_progress_file_prefix) (AssistantOperation* self);
	GtkWidget* (*make_progress_page) (AssistantOperation* self);
	void (*show_error) (AssistantOperation* self, const gchar* _error_, const gchar* detail);
	GtkWidget* (*make_summary_page) (AssistantOperation* self);
	void (*apply_finished) (AssistantOperation* self, DejaDupOperation* op, gboolean success, gboolean cancelled, const gchar* detail);
	void (*do_prepare) (AssistantOperation* self, Assistant* assist, GtkWidget* page);
	void (*do_cancel) (AssistantOperation* self);
	void (*do_close) (AssistantOperation* self);
};

struct _AssistantBackup {
	AssistantOperation parent_instance;
	AssistantBackupPrivate * priv;
};

struct _AssistantBackupClass {
	AssistantOperationClass parent_class;
};


static gpointer assistant_backup_parent_class = NULL;

GType assistant_get_type (void) G_GNUC_CONST;
gpointer assistant_page_info_ref (gpointer instance);
void assistant_page_info_unref (gpointer instance);
GParamSpec* assistant_param_spec_page_info (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void assistant_value_set_page_info (GValue* value, gpointer v_object);
void assistant_value_take_page_info (GValue* value, gpointer v_object);
gpointer assistant_value_get_page_info (const GValue* value);
GType assistant_page_info_get_type (void) G_GNUC_CONST;
GType assistant_operation_get_type (void) G_GNUC_CONST;
GType status_icon_get_type (void) G_GNUC_CONST;
GType assistant_backup_get_type (void) G_GNUC_CONST;
enum  {
	ASSISTANT_BACKUP_DUMMY_PROPERTY
};
AssistantBackup* assistant_backup_new (gboolean automatic);
AssistantBackup* assistant_backup_construct (GType object_type, gboolean automatic);
static DejaDupOperation* assistant_backup_real_create_op (AssistantOperation* base);
void assistant_operation_ensure_status_icon (AssistantOperation* self, DejaDupOperation* o);
gboolean assistant_operation_get_automatic (AssistantOperation* self);
gboolean status_icon_get_show_automatic_progress (StatusIcon* self);
static void __lambda29_ (AssistantBackup* self, DejaDupOperation* op, gboolean first);
void assistant_operation_set_secondary_label (AssistantOperation* self, const gchar* text);
void assistant_operation_ask_passphrase (AssistantOperation* self, gboolean first);
static void ___lambda29__deja_dup_operation_is_full (DejaDupOperation* _sender, gboolean first, gpointer self);
void assistant_hide_for_now (Assistant* self);
static void assistant_backup_do_resume (AssistantBackup* self);
void assistant_operation_hide_everything (AssistantOperation* self);
void assistant_operation_do_close (AssistantOperation* self);
static gchar* assistant_backup_real_get_progress_file_prefix (AssistantOperation* base);
static void assistant_backup_real_do_prepare (AssistantOperation* base, Assistant* assist, GtkWidget* page);
void assistant_operation_do_prepare (AssistantOperation* self, Assistant* assist, GtkWidget* page);
GtkWidget* assistant_operation_get_summary_page (AssistantOperation* self);
gboolean assistant_operation_get_error_occurred (AssistantOperation* self);
void assistant_set_page_title (Assistant* self, GtkWidget* page, const gchar* title);
static gboolean ______lambda30_ (AssistantBackup* self);
static gboolean _______lambda30__gsource_func (gpointer self);
GtkWidget* assistant_operation_get_progress_page (AssistantOperation* self);
static GObject * assistant_backup_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
void assistant_set_apply_text (Assistant* self, const gchar* value);
static void _assistant_backup_do_resume_assistant_resumed (Assistant* _sender, gpointer self);


AssistantBackup* assistant_backup_construct (GType object_type, gboolean automatic) {
	AssistantBackup * self = NULL;
	gboolean _tmp0_;
	_tmp0_ = automatic;
	self = (AssistantBackup*) g_object_new (object_type, "automatic", _tmp0_, NULL);
	return self;
}


AssistantBackup* assistant_backup_new (gboolean automatic) {
	return assistant_backup_construct (TYPE_ASSISTANT_BACKUP, automatic);
}


static void __lambda29_ (AssistantBackup* self, DejaDupOperation* op, gboolean first) {
	DejaDupOperation* _tmp0_;
	const gchar* _tmp1_ = NULL;
	gboolean _tmp2_;
	const gchar* _tmp5_;
	gboolean _tmp6_;
	g_return_if_fail (op != NULL);
	_tmp0_ = op;
	deja_dup_operation_set_use_progress (_tmp0_, TRUE);
	_tmp2_ = first;
	if (_tmp2_) {
		const gchar* _tmp3_ = NULL;
		_tmp3_ = _ ("Creating the first backup.  This may take a while.");
		_tmp1_ = _tmp3_;
	} else {
		const gchar* _tmp4_ = NULL;
		_tmp4_ = _ ("Creating a fresh backup to protect against backup corruption.  This wi" \
"ll take longer than normal.");
		_tmp1_ = _tmp4_;
	}
	_tmp5_ = _tmp1_;
	assistant_operation_set_secondary_label ((AssistantOperation*) self, _tmp5_);
	_tmp6_ = first;
	if (_tmp6_) {
		gboolean _tmp7_;
		_tmp7_ = first;
		assistant_operation_ask_passphrase ((AssistantOperation*) self, _tmp7_);
	}
}


static void ___lambda29__deja_dup_operation_is_full (DejaDupOperation* _sender, gboolean first, gpointer self) {
	__lambda29_ (self, _sender, first);
}


static DejaDupOperation* assistant_backup_real_create_op (AssistantOperation* base) {
	AssistantBackup * self;
	DejaDupOperation* result = NULL;
	DejaDupOperationBackup* _tmp0_;
	DejaDupOperationBackup* rv;
	DejaDupOperationBackup* _tmp1_;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_;
	gboolean _tmp4_;
	gboolean _tmp11_;
	DejaDupOperationBackup* _tmp13_;
	gboolean _tmp14_;
	gboolean _tmp15_;
	self = (AssistantBackup*) base;
	gtk_widget_realize ((GtkWidget*) self);
	_tmp0_ = deja_dup_operation_backup_new ();
	rv = _tmp0_;
	_tmp1_ = rv;
	assistant_operation_ensure_status_icon ((AssistantOperation*) self, (DejaDupOperation*) _tmp1_);
	_tmp3_ = assistant_operation_get_automatic ((AssistantOperation*) self);
	_tmp4_ = _tmp3_;
	if (_tmp4_) {
		gboolean _tmp5_ = FALSE;
		StatusIcon* _tmp6_;
		gboolean _tmp10_;
		_tmp6_ = ((AssistantOperation*) self)->status_icon;
		if (_tmp6_ == NULL) {
			_tmp5_ = TRUE;
		} else {
			StatusIcon* _tmp7_;
			gboolean _tmp8_;
			gboolean _tmp9_;
			_tmp7_ = ((AssistantOperation*) self)->status_icon;
			_tmp8_ = status_icon_get_show_automatic_progress (_tmp7_);
			_tmp9_ = _tmp8_;
			_tmp5_ = !_tmp9_;
		}
		_tmp10_ = _tmp5_;
		_tmp2_ = _tmp10_;
	} else {
		_tmp2_ = FALSE;
	}
	_tmp11_ = _tmp2_;
	if (_tmp11_) {
		DejaDupOperationBackup* _tmp12_;
		_tmp12_ = rv;
		deja_dup_operation_set_use_progress ((DejaDupOperation*) _tmp12_, FALSE);
	}
	_tmp13_ = rv;
	g_signal_connect_object ((DejaDupOperation*) _tmp13_, "is-full", (GCallback) ___lambda29__deja_dup_operation_is_full, self, 0);
	_tmp14_ = assistant_operation_get_automatic ((AssistantOperation*) self);
	_tmp15_ = _tmp14_;
	if (_tmp15_) {
		assistant_hide_for_now ((Assistant*) self);
	} else {
		gtk_widget_show_all ((GtkWidget*) self);
	}
	result = (DejaDupOperation*) rv;
	return result;
}


static void assistant_backup_do_resume (AssistantBackup* self) {
	DejaDupOperation* _tmp0_;
	g_return_if_fail (self != NULL);
	assistant_operation_hide_everything ((AssistantOperation*) self);
	_tmp0_ = ((AssistantOperation*) self)->op;
	if (_tmp0_ != NULL) {
		DejaDupOperation* _tmp1_;
		_tmp1_ = ((AssistantOperation*) self)->op;
		deja_dup_operation_stop (_tmp1_);
	} else {
		((AssistantOperation*) self)->succeeded = TRUE;
		assistant_operation_do_close ((AssistantOperation*) self);
	}
}


static gchar* assistant_backup_real_get_progress_file_prefix (AssistantOperation* base) {
	AssistantBackup * self;
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	self = (AssistantBackup*) base;
	_tmp0_ = _ ("Backing up:");
	_tmp1_ = g_strdup (_tmp0_);
	result = _tmp1_;
	return result;
}


static gboolean ______lambda30_ (AssistantBackup* self) {
	gboolean result = FALSE;
	assistant_operation_do_close ((AssistantOperation*) self);
	result = FALSE;
	return result;
}


static gboolean _______lambda30__gsource_func (gpointer self) {
	gboolean result;
	result = ______lambda30_ (self);
	return result;
}


static void assistant_backup_real_do_prepare (AssistantOperation* base, Assistant* assist, GtkWidget* page) {
	AssistantBackup * self;
	Assistant* _tmp0_;
	GtkWidget* _tmp1_;
	GtkWidget* _tmp2_;
	GtkWidget* _tmp3_;
	GtkWidget* _tmp4_;
	self = (AssistantBackup*) base;
	g_return_if_fail (assist != NULL);
	g_return_if_fail (page != NULL);
	_tmp0_ = assist;
	_tmp1_ = page;
	ASSISTANT_OPERATION_CLASS (assistant_backup_parent_class)->do_prepare (ASSISTANT_OPERATION (self), _tmp0_, _tmp1_);
	_tmp2_ = page;
	_tmp3_ = assistant_operation_get_summary_page ((AssistantOperation*) self);
	_tmp4_ = _tmp3_;
	if (_tmp2_ == _tmp4_) {
		gboolean _tmp5_;
		gboolean _tmp6_;
		_tmp5_ = assistant_operation_get_error_occurred ((AssistantOperation*) self);
		_tmp6_ = _tmp5_;
		if (_tmp6_) {
			GtkWidget* _tmp7_;
			const gchar* _tmp8_ = NULL;
			_tmp7_ = page;
			_tmp8_ = _ ("Backup Failed");
			assistant_set_page_title ((Assistant*) self, _tmp7_, _tmp8_);
		} else {
			GtkWidget* _tmp9_;
			const gchar* _tmp10_ = NULL;
			gboolean _tmp11_;
			_tmp9_ = page;
			_tmp10_ = _ ("Backup Finished");
			assistant_set_page_title ((Assistant*) self, _tmp9_, _tmp10_);
			_tmp11_ = ((AssistantOperation*) self)->nagged;
			if (_tmp11_) {
				GtkLabel* _tmp12_;
				const gchar* _tmp13_ = NULL;
				_tmp12_ = ((AssistantOperation*) self)->summary_label;
				_tmp13_ = _ ("Your files were successfully backed up and tested.");
				gtk_label_set_label (_tmp12_, _tmp13_);
			} else {
				GtkWidget* _tmp14_;
				gboolean _tmp15_ = FALSE;
				_tmp14_ = ((AssistantOperation*) self)->detail_widget;
				_tmp15_ = gtk_widget_get_visible (_tmp14_);
				if (!_tmp15_) {
					g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _______lambda30__gsource_func, g_object_ref (self), g_object_unref);
				}
			}
		}
	} else {
		GtkWidget* _tmp16_;
		GtkWidget* _tmp17_;
		GtkWidget* _tmp18_;
		_tmp16_ = page;
		_tmp17_ = assistant_operation_get_progress_page ((AssistantOperation*) self);
		_tmp18_ = _tmp17_;
		if (_tmp16_ == _tmp18_) {
			GtkWidget* _tmp19_;
			const gchar* _tmp20_ = NULL;
			_tmp19_ = page;
			_tmp20_ = _ ("Backing Up…");
			assistant_set_page_title ((Assistant*) self, _tmp19_, _tmp20_);
		}
	}
}


static void _assistant_backup_do_resume_assistant_resumed (Assistant* _sender, gpointer self) {
	assistant_backup_do_resume (self);
}


static GObject * assistant_backup_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	AssistantBackup * self;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	parent_class = G_OBJECT_CLASS (assistant_backup_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = ASSISTANT_BACKUP (obj);
	_tmp0_ = C_ ("back up is verb", "Back Up");
	gtk_window_set_title ((GtkWindow*) self, _tmp0_);
	_tmp1_ = C_ ("back up is verb", "_Back Up");
	assistant_set_apply_text ((Assistant*) self, _tmp1_);
	g_signal_connect_object ((Assistant*) self, "resumed", (GCallback) _assistant_backup_do_resume_assistant_resumed, self, 0);
	return obj;
}


static void assistant_backup_class_init (AssistantBackupClass * klass) {
	assistant_backup_parent_class = g_type_class_peek_parent (klass);
	ASSISTANT_OPERATION_CLASS (klass)->create_op = assistant_backup_real_create_op;
	ASSISTANT_OPERATION_CLASS (klass)->get_progress_file_prefix = assistant_backup_real_get_progress_file_prefix;
	ASSISTANT_OPERATION_CLASS (klass)->do_prepare = assistant_backup_real_do_prepare;
	G_OBJECT_CLASS (klass)->constructor = assistant_backup_constructor;
}


static void assistant_backup_instance_init (AssistantBackup * self) {
}


GType assistant_backup_get_type (void) {
	static volatile gsize assistant_backup_type_id__volatile = 0;
	if (g_once_init_enter (&assistant_backup_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (AssistantBackupClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) assistant_backup_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (AssistantBackup), 0, (GInstanceInitFunc) assistant_backup_instance_init, NULL };
		GType assistant_backup_type_id;
		assistant_backup_type_id = g_type_register_static (TYPE_ASSISTANT_OPERATION, "AssistantBackup", &g_define_type_info, 0);
		g_once_init_leave (&assistant_backup_type_id__volatile, assistant_backup_type_id);
	}
	return assistant_backup_type_id__volatile;
}



