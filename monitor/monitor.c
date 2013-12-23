/* monitor.c generated by valac 0.16.1, the Vala compiler
 * generated from monitor.vala, do not modify */

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
#include <common.h>
#include <libnotify/notify.h>
#include <gio/gio.h>
#include <config.h>
#include <glib/gi18n-lib.h>


#define TYPE_MONITOR (monitor_get_type ())
#define MONITOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MONITOR, Monitor))
#define MONITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MONITOR, MonitorClass))
#define IS_MONITOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MONITOR))
#define IS_MONITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MONITOR))
#define MONITOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MONITOR, MonitorClass))

typedef struct _Monitor Monitor;
typedef struct _MonitorClass MonitorClass;
typedef struct _MonitorPrivate MonitorPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _MonitorIsReadyData MonitorIsReadyData;
#define _g_date_time_unref0(var) ((var == NULL) ? NULL : (var = (g_date_time_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _MonitorKickoffData MonitorKickoffData;
#define _g_option_context_free0(var) ((var == NULL) ? NULL : (var = (g_option_context_free (var), NULL)))
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))

struct _Monitor {
	GObject parent_instance;
	MonitorPrivate * priv;
};

struct _MonitorClass {
	GObjectClass parent_class;
};

struct _MonitorIsReadyData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	gchar* when;
	gboolean result;
	gboolean _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	gchar* _tmp4_;
	DejaDupBackend* _tmp5_;
	DejaDupBackend* _tmp6_;
	gchar* _tmp7_;
	gboolean _tmp8_;
	gboolean _tmp9_;
};

struct _MonitorKickoffData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	GTimeSpan wait_time;
	GTimeSpan _tmp0_;
	gboolean _tmp1_;
	GTimeSpan _tmp2_;
	gboolean _tmp3_;
	gchar* when;
	gchar* _tmp4_;
	gboolean _tmp5_;
	gboolean ready;
	gboolean _tmp6_;
	gboolean _tmp7_;
	gboolean _tmp8_;
	const gchar* _tmp9_;
	gboolean _tmp10_;
	const gchar* _tmp11_;
	const gchar* _tmp12_;
	NotifyNotification* _tmp13_;
	NotifyNotification* _tmp14_;
	GError* e2;
	GError* _tmp15_;
	const gchar* _tmp16_;
	gboolean _tmp17_;
	GPid _tmp18_;
	gboolean _tmp19_;
	gboolean _tmp20_;
	gchar** _tmp21_;
	gchar** argv;
	gint argv_length1;
	gint _argv_size_;
	gint i;
	gchar* _tmp22_;
	gchar* _tmp23_;
	gboolean _tmp24_;
	gchar** _tmp25_;
	gint _tmp25__length1;
	gint _tmp26_;
	gchar* _tmp27_;
	gchar* _tmp28_;
	gchar* _tmp29_;
	gchar* _tmp30_;
	gboolean _tmp31_;
	gchar** _tmp32_;
	gint _tmp32__length1;
	gint _tmp33_;
	gchar* _tmp34_;
	gchar* _tmp35_;
	gchar** _tmp36_;
	gint _tmp36__length1;
	gint _tmp37_;
	gchar* _tmp38_;
	gchar* _tmp39_;
	gchar** _tmp40_;
	gint _tmp40__length1;
	gint _tmp41_;
	gchar* _tmp42_;
	gchar* _tmp43_;
	gchar** _tmp44_;
	gint _tmp44__length1;
	gint _tmp45_;
	gchar* _tmp46_;
	gchar* _tmp47_;
	gchar** _tmp48_;
	gint _tmp48__length1;
	gint _tmp49_;
	gchar* _tmp50_;
	gchar* _tmp51_;
	gchar** _tmp52_;
	gint _tmp52__length1;
	gint _tmp53_;
	gchar* _tmp54_;
	gchar* _tmp55_;
	gchar** _tmp56_;
	gint _tmp56__length1;
	gint _tmp57_;
	gchar* _tmp58_;
	gboolean _tmp59_;
	gchar** _tmp60_;
	gint _tmp60__length1;
	GPid _tmp61_;
	GPid _tmp62_;
	GError* e;
	GError* _tmp63_;
	const gchar* _tmp64_;
	GError * _inner_error_;
};


static gpointer monitor_parent_class = NULL;
static guint monitor_timeout_id;
static guint monitor_timeout_id = 0U;
static guint monitor_netcheck_id;
static guint monitor_netcheck_id = 0U;
static GPid monitor_pid;
static GPid monitor_pid = 0;
static gboolean monitor_op_active;
static gboolean monitor_op_active = FALSE;
static gboolean monitor_reactive_check;
static gboolean monitor_reactive_check = FALSE;
static gboolean monitor_first_check;
static gboolean monitor_first_check = FALSE;
static DejaDupSimpleSettings* monitor_settings;
static DejaDupSimpleSettings* monitor_settings = NULL;
static gboolean monitor_testing_delay;
static gboolean monitor_testing_delay = TRUE;
static gboolean monitor_show_version;
static gboolean monitor_show_version = FALSE;
static NotifyNotification* monitor_note;
static NotifyNotification* monitor_note = NULL;

GType monitor_get_type (void) G_GNUC_CONST;
enum  {
	MONITOR_DUMMY_PROPERTY
};
static void monitor_op_started (GDBusConnection* conn, const gchar* name, const gchar* name_owner);
static void monitor_op_ended (GDBusConnection* conn, const gchar* name);
static gboolean monitor_network_check (void);
static void monitor_prepare_next_run (void);
static void monitor_network_changed (void);
static gboolean _monitor_network_check_gsource_func (gpointer self);
static void monitor_volume_added (GVolumeMonitor* vm, GVolume* vol);
static void monitor_is_ready_data_free (gpointer _data);
static void monitor_is_ready (GAsyncReadyCallback _callback_, gpointer _user_data_);
static gboolean monitor_is_ready_finish (GAsyncResult* _res_, gchar** when);
static gboolean monitor_is_ready_co (MonitorIsReadyData* _data_);
static void monitor_is_ready_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean monitor_handle_options (gint* status);
static GTimeSpan monitor_time_until (GDateTime* date);
static void monitor_close_pid (GPid child_pid, gint status);
static void monitor_notify_delay (const gchar* header, const gchar* reason);
static void ___lambda3_ (NotifyNotification* n);
static void ____lambda3__notify_notification_closed (NotifyNotification* _sender, gpointer self);
static void monitor_kickoff_data_free (gpointer _data);
static void monitor_kickoff (GAsyncReadyCallback _callback_, gpointer _user_data_);
static void monitor_kickoff_finish (GAsyncResult* _res_);
static gboolean monitor_kickoff_co (MonitorKickoffData* _data_);
static gboolean monitor_time_until_next_run (GTimeSpan* time);
static void monitor_prepare_tomorrow (void);
static void monitor_kickoff_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void _monitor_close_pid_gchild_watch_func (GPid pid, gint status, gpointer self);
static void monitor_prepare_run (GTimeSpan wait_time);
static gboolean ___lambda2_ (void);
static gboolean ____lambda2__gsource_func (gpointer self);
static void monitor_prepare_if_necessary (const gchar* key);
static void monitor_make_first_check (void);
static gboolean __lambda4_ (void);
static gboolean ___lambda4__gsource_func (gpointer self);
static void monitor_watch_settings (void);
static void _monitor_prepare_if_necessary_g_settings_changed (GSettings* _sender, const gchar* key, gpointer self);
static gint monitor_main (gchar** args, int args_length1);
static void _monitor_network_changed_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
static void _monitor_op_started_gbus_name_appeared_callback (GDBusConnection* connection, const gchar* name, const gchar* name_owner, gpointer self);
static void _monitor_op_ended_gbus_name_vanished_callback (GDBusConnection* connection, const gchar* name, gpointer self);
static void _monitor_volume_added_g_volume_monitor_volume_added (GVolumeMonitor* _sender, GVolume* volume, gpointer self);
static gboolean ___lambda5_ (void);
static gboolean ____lambda5__gsource_func (gpointer self);
Monitor* monitor_new (void);
Monitor* monitor_construct (GType object_type);
static void monitor_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);

static const GOptionEntry MONITOR_options[2] = {{"version", (gchar) 0, 0, G_OPTION_ARG_NONE, &monitor_show_version, "Show version", NULL}, {NULL}};

static void monitor_op_started (GDBusConnection* conn, const gchar* name, const gchar* name_owner) {
	g_return_if_fail (conn != NULL);
	g_return_if_fail (name != NULL);
	g_return_if_fail (name_owner != NULL);
	monitor_op_active = TRUE;
}


static void monitor_op_ended (GDBusConnection* conn, const gchar* name) {
	g_return_if_fail (conn != NULL);
	g_return_if_fail (name != NULL);
	monitor_op_active = FALSE;
}


static gboolean monitor_network_check (void) {
	gboolean result = FALSE;
	DejaDupNetwork* _tmp0_ = NULL;
	DejaDupNetwork* _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	gboolean _tmp4_;
	monitor_reactive_check = TRUE;
	_tmp0_ = deja_dup_network_get ();
	_tmp1_ = _tmp0_;
	_tmp2_ = deja_dup_network_get_connected (_tmp1_);
	_tmp3_ = _tmp2_;
	_tmp4_ = _tmp3_;
	_g_object_unref0 (_tmp1_);
	if (_tmp4_) {
		monitor_prepare_next_run ();
	}
	monitor_reactive_check = FALSE;
	result = FALSE;
	return result;
}


static gboolean _monitor_network_check_gsource_func (gpointer self) {
	gboolean result;
	result = monitor_network_check ();
	return result;
}


static void monitor_network_changed (void) {
	guint _tmp0_;
	DejaDupNetwork* _tmp2_ = NULL;
	DejaDupNetwork* _tmp3_;
	gboolean _tmp4_;
	gboolean _tmp5_;
	gboolean _tmp6_;
	_tmp0_ = monitor_netcheck_id;
	if (_tmp0_ > ((guint) 0)) {
		guint _tmp1_;
		_tmp1_ = monitor_netcheck_id;
		g_source_remove (_tmp1_);
	}
	_tmp2_ = deja_dup_network_get ();
	_tmp3_ = _tmp2_;
	_tmp4_ = deja_dup_network_get_connected (_tmp3_);
	_tmp5_ = _tmp4_;
	_tmp6_ = _tmp5_;
	_g_object_unref0 (_tmp3_);
	if (_tmp6_) {
		guint _tmp7_ = 0U;
		_tmp7_ = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 120, _monitor_network_check_gsource_func, NULL, NULL);
		monitor_netcheck_id = _tmp7_;
	}
}


static void monitor_volume_added (GVolumeMonitor* vm, GVolume* vol) {
	g_return_if_fail (vm != NULL);
	g_return_if_fail (vol != NULL);
	monitor_reactive_check = TRUE;
	monitor_prepare_next_run ();
	monitor_reactive_check = FALSE;
}


static void monitor_is_ready_data_free (gpointer _data) {
	MonitorIsReadyData* _data_;
	_data_ = _data;
	g_slice_free (MonitorIsReadyData, _data_);
}


static void monitor_is_ready (GAsyncReadyCallback _callback_, gpointer _user_data_) {
	MonitorIsReadyData* _data_;
	_data_ = g_slice_new0 (MonitorIsReadyData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, monitor_is_ready);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, monitor_is_ready_data_free);
	monitor_is_ready_co (_data_);
}


static gboolean monitor_is_ready_finish (GAsyncResult* _res_, gchar** when) {
	gboolean result;
	MonitorIsReadyData* _data_;
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


static void monitor_is_ready_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	MonitorIsReadyData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	monitor_is_ready_co (_data_);
}


static gboolean monitor_is_ready_co (MonitorIsReadyData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp1_ = FALSE;
	_data_->_tmp1_ = deja_dup_in_testing_mode ();
	if (_data_->_tmp1_) {
		_data_->_tmp2_ = monitor_testing_delay;
		_data_->_tmp0_ = _data_->_tmp2_;
	} else {
		_data_->_tmp0_ = FALSE;
	}
	_data_->_tmp3_ = _data_->_tmp0_;
	if (_data_->_tmp3_) {
		monitor_testing_delay = FALSE;
		_data_->_tmp4_ = g_strdup ("Testing");
		_g_free0 (_data_->when);
		_data_->when = _data_->_tmp4_;
		_data_->result = FALSE;
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp5_ = NULL;
	_data_->_tmp5_ = deja_dup_backend_get_default ();
	_data_->_tmp6_ = _data_->_tmp5_;
	_data_->_tmp7_ = NULL;
	_data_->_state_ = 1;
	deja_dup_backend_is_ready (_data_->_tmp6_, monitor_is_ready_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp8_ = FALSE;
	_data_->_tmp8_ = deja_dup_backend_is_ready_finish (_data_->_tmp6_, _data_->_res_, &_data_->_tmp7_);
	_g_free0 (_data_->when);
	_data_->when = _data_->_tmp7_;
	_data_->_tmp9_ = _data_->_tmp8_;
	_g_object_unref0 (_data_->_tmp6_);
	_data_->result = _data_->_tmp9_;
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


static gboolean monitor_handle_options (gint* status) {
	gint _vala_status = 0;
	gboolean result = FALSE;
	gboolean _tmp0_;
	_vala_status = 0;
	_tmp0_ = monitor_show_version;
	if (_tmp0_) {
		g_print ("%s %s\n", "deja-dup-monitor", VERSION);
		result = FALSE;
		if (status) {
			*status = _vala_status;
		}
		return result;
	}
	result = TRUE;
	if (status) {
		*status = _vala_status;
	}
	return result;
}


static GTimeSpan monitor_time_until (GDateTime* date) {
	GTimeSpan result = 0LL;
	GDateTime* _tmp0_;
	GDateTime* _tmp1_;
	GDateTime* _tmp2_;
	GTimeSpan _tmp3_ = 0LL;
	GTimeSpan _tmp4_;
	g_return_val_if_fail (date != NULL, 0LL);
	_tmp0_ = date;
	_tmp1_ = g_date_time_new_now_local ();
	_tmp2_ = _tmp1_;
	_tmp3_ = g_date_time_difference (_tmp0_, _tmp2_);
	_tmp4_ = _tmp3_;
	_g_date_time_unref0 (_tmp2_);
	result = _tmp4_;
	return result;
}


static void monitor_close_pid (GPid child_pid, gint status) {
	GPid _tmp0_;
	_tmp0_ = child_pid;
	g_spawn_close_pid (_tmp0_);
	monitor_pid = (GPid) 0;
}


static void ___lambda3_ (NotifyNotification* n) {
	g_return_if_fail (n != NULL);
	_g_object_unref0 (monitor_note);
	monitor_note = NULL;
}


static void ____lambda3__notify_notification_closed (NotifyNotification* _sender, gpointer self) {
	___lambda3_ (_sender);
}


static void monitor_notify_delay (const gchar* header, const gchar* reason) {
	NotifyNotification* _tmp0_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (header != NULL);
	g_return_if_fail (reason != NULL);
	_tmp0_ = monitor_note;
	if (_tmp0_ == NULL) {
		const gchar* _tmp1_ = NULL;
		const gchar* _tmp2_;
		const gchar* _tmp3_;
		NotifyNotification* _tmp4_;
		NotifyNotification* _tmp5_;
		_tmp1_ = _ ("Backup");
		notify_init (_tmp1_);
		_tmp2_ = header;
		_tmp3_ = reason;
		_tmp4_ = notify_notification_new (_tmp2_, _tmp3_, "deja-dup");
		_g_object_unref0 (monitor_note);
		monitor_note = _tmp4_;
		_tmp5_ = monitor_note;
		g_signal_connect (_tmp5_, "closed", (GCallback) ____lambda3__notify_notification_closed, NULL);
	} else {
		NotifyNotification* _tmp6_;
		const gchar* _tmp7_;
		const gchar* _tmp8_;
		_tmp6_ = monitor_note;
		_tmp7_ = header;
		_tmp8_ = reason;
		notify_notification_update (_tmp6_, _tmp7_, _tmp8_, "deja-dup");
	}
	{
		NotifyNotification* _tmp9_;
		_tmp9_ = monitor_note;
		notify_notification_show (_tmp9_, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch0_g_error;
		}
	}
	goto __finally0;
	__catch0_g_error:
	{
		GError* e = NULL;
		GError* _tmp10_;
		const gchar* _tmp11_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp10_ = e;
		_tmp11_ = _tmp10_->message;
		g_warning ("monitor.vala:127: %s\n", _tmp11_);
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void monitor_kickoff_data_free (gpointer _data) {
	MonitorKickoffData* _data_;
	_data_ = _data;
	g_slice_free (MonitorKickoffData, _data_);
}


static void monitor_kickoff (GAsyncReadyCallback _callback_, gpointer _user_data_) {
	MonitorKickoffData* _data_;
	_data_ = g_slice_new0 (MonitorKickoffData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, monitor_kickoff);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, monitor_kickoff_data_free);
	monitor_kickoff_co (_data_);
}


static void monitor_kickoff_finish (GAsyncResult* _res_) {
	MonitorKickoffData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void monitor_kickoff_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	MonitorKickoffData* _data_;
	_data_ = _user_data_;
	_data_->_source_object_ = source_object;
	_data_->_res_ = _res_;
	monitor_kickoff_co (_data_);
}


static void _monitor_close_pid_gchild_watch_func (GPid pid, gint status, gpointer self) {
	monitor_close_pid (pid, status);
}


static gboolean monitor_kickoff_co (MonitorKickoffData* _data_) {
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_tmp0_ = 0LL;
	_data_->_tmp1_ = FALSE;
	_data_->_tmp1_ = monitor_time_until_next_run (&_data_->_tmp0_);
	_data_->wait_time = _data_->_tmp0_;
	if (!_data_->_tmp1_) {
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp2_ = _data_->wait_time;
	if (_data_->_tmp2_ > ((GTimeSpan) 0)) {
		monitor_prepare_next_run ();
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp3_ = monitor_reactive_check;
	if (!_data_->_tmp3_) {
		monitor_prepare_tomorrow ();
	}
	_data_->_tmp4_ = NULL;
	_data_->_state_ = 1;
	monitor_is_ready (monitor_kickoff_ready, _data_);
	return FALSE;
	_state_1:
	_data_->_tmp5_ = FALSE;
	_data_->_tmp5_ = monitor_is_ready_finish (_data_->_res_, &_data_->_tmp4_);
	_g_free0 (_data_->when);
	_data_->when = _data_->_tmp4_;
	_data_->ready = _data_->_tmp5_;
	_data_->_tmp6_ = _data_->ready;
	if (!_data_->_tmp6_) {
		g_debug ("monitor.vala:154: Postponing the backup.");
		_data_->_tmp8_ = monitor_reactive_check;
		if (!_data_->_tmp8_) {
			_data_->_tmp9_ = _data_->when;
			_data_->_tmp7_ = _data_->_tmp9_ != NULL;
		} else {
			_data_->_tmp7_ = FALSE;
		}
		_data_->_tmp10_ = _data_->_tmp7_;
		if (_data_->_tmp10_) {
			_data_->_tmp11_ = NULL;
			_data_->_tmp11_ = _ ("Scheduled backup delayed");
			_data_->_tmp12_ = _data_->when;
			monitor_notify_delay (_data_->_tmp11_, _data_->_tmp12_);
		}
		_g_free0 (_data_->when);
		if (_data_->_state_ == 0) {
			g_simple_async_result_complete_in_idle (_data_->_async_result);
		} else {
			g_simple_async_result_complete (_data_->_async_result);
		}
		g_object_unref (_data_->_async_result);
		return FALSE;
	}
	_data_->_tmp13_ = monitor_note;
	if (_data_->_tmp13_ != NULL) {
		{
			_data_->_tmp14_ = monitor_note;
			notify_notification_close (_data_->_tmp14_, &_data_->_inner_error_);
			if (_data_->_inner_error_ != NULL) {
				goto __catch1_g_error;
			}
		}
		goto __finally1;
		__catch1_g_error:
		{
			_data_->e2 = _data_->_inner_error_;
			_data_->_inner_error_ = NULL;
			_data_->_tmp15_ = _data_->e2;
			_data_->_tmp16_ = _data_->_tmp15_->message;
			g_warning ("monitor.vala:165: %s\n", _data_->_tmp16_);
			_g_error_free0 (_data_->e2);
		}
		__finally1:
		if (_data_->_inner_error_ != NULL) {
			_g_free0 (_data_->when);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
		_g_object_unref0 (monitor_note);
		monitor_note = NULL;
	}
	_data_->_tmp18_ = monitor_pid;
	if (_data_->_tmp18_ == ((GPid) 0)) {
		_data_->_tmp19_ = monitor_op_active;
		_data_->_tmp17_ = !_data_->_tmp19_;
	} else {
		_data_->_tmp17_ = FALSE;
	}
	_data_->_tmp20_ = _data_->_tmp17_;
	if (_data_->_tmp20_) {
		{
			_data_->_tmp21_ = NULL;
			_data_->_tmp21_ = g_new0 (gchar*, 8 + 1);
			_data_->argv = _data_->_tmp21_;
			_data_->argv_length1 = 8;
			_data_->_argv_size_ = _data_->argv_length1;
			_data_->i = 0;
			g_debug ("monitor.vala:176: Running automatic backup.");
			_data_->_tmp22_ = NULL;
			_data_->_tmp22_ = g_find_program_in_path ("nice");
			_data_->_tmp23_ = _data_->_tmp22_;
			_data_->_tmp24_ = _data_->_tmp23_ != NULL;
			_g_free0 (_data_->_tmp23_);
			if (_data_->_tmp24_) {
				_data_->_tmp25_ = _data_->argv;
				_data_->_tmp25__length1 = _data_->argv_length1;
				_data_->_tmp26_ = _data_->i;
				_data_->i = _data_->_tmp26_ + 1;
				_data_->_tmp27_ = g_strdup ("nice");
				_g_free0 (_data_->_tmp25_[_data_->_tmp26_]);
				_data_->_tmp25_[_data_->_tmp26_] = _data_->_tmp27_;
				_data_->_tmp28_ = _data_->_tmp25_[_data_->_tmp26_];
			}
			_data_->_tmp29_ = NULL;
			_data_->_tmp29_ = g_find_program_in_path ("ionice");
			_data_->_tmp30_ = _data_->_tmp29_;
			_data_->_tmp31_ = _data_->_tmp30_ != NULL;
			_g_free0 (_data_->_tmp30_);
			if (_data_->_tmp31_) {
				_data_->_tmp32_ = _data_->argv;
				_data_->_tmp32__length1 = _data_->argv_length1;
				_data_->_tmp33_ = _data_->i;
				_data_->i = _data_->_tmp33_ + 1;
				_data_->_tmp34_ = g_strdup ("ionice");
				_g_free0 (_data_->_tmp32_[_data_->_tmp33_]);
				_data_->_tmp32_[_data_->_tmp33_] = _data_->_tmp34_;
				_data_->_tmp35_ = _data_->_tmp32_[_data_->_tmp33_];
				_data_->_tmp36_ = _data_->argv;
				_data_->_tmp36__length1 = _data_->argv_length1;
				_data_->_tmp37_ = _data_->i;
				_data_->i = _data_->_tmp37_ + 1;
				_data_->_tmp38_ = g_strdup ("-c2");
				_g_free0 (_data_->_tmp36_[_data_->_tmp37_]);
				_data_->_tmp36_[_data_->_tmp37_] = _data_->_tmp38_;
				_data_->_tmp39_ = _data_->_tmp36_[_data_->_tmp37_];
				_data_->_tmp40_ = _data_->argv;
				_data_->_tmp40__length1 = _data_->argv_length1;
				_data_->_tmp41_ = _data_->i;
				_data_->i = _data_->_tmp41_ + 1;
				_data_->_tmp42_ = g_strdup ("-n7");
				_g_free0 (_data_->_tmp40_[_data_->_tmp41_]);
				_data_->_tmp40_[_data_->_tmp41_] = _data_->_tmp42_;
				_data_->_tmp43_ = _data_->_tmp40_[_data_->_tmp41_];
			}
			_data_->_tmp44_ = _data_->argv;
			_data_->_tmp44__length1 = _data_->argv_length1;
			_data_->_tmp45_ = _data_->i;
			_data_->i = _data_->_tmp45_ + 1;
			_data_->_tmp46_ = g_strdup ("deja-dup");
			_g_free0 (_data_->_tmp44_[_data_->_tmp45_]);
			_data_->_tmp44_[_data_->_tmp45_] = _data_->_tmp46_;
			_data_->_tmp47_ = _data_->_tmp44_[_data_->_tmp45_];
			_data_->_tmp48_ = _data_->argv;
			_data_->_tmp48__length1 = _data_->argv_length1;
			_data_->_tmp49_ = _data_->i;
			_data_->i = _data_->_tmp49_ + 1;
			_data_->_tmp50_ = g_strdup ("--backup");
			_g_free0 (_data_->_tmp48_[_data_->_tmp49_]);
			_data_->_tmp48_[_data_->_tmp49_] = _data_->_tmp50_;
			_data_->_tmp51_ = _data_->_tmp48_[_data_->_tmp49_];
			_data_->_tmp52_ = _data_->argv;
			_data_->_tmp52__length1 = _data_->argv_length1;
			_data_->_tmp53_ = _data_->i;
			_data_->i = _data_->_tmp53_ + 1;
			_data_->_tmp54_ = g_strdup ("--auto");
			_g_free0 (_data_->_tmp52_[_data_->_tmp53_]);
			_data_->_tmp52_[_data_->_tmp53_] = _data_->_tmp54_;
			_data_->_tmp55_ = _data_->_tmp52_[_data_->_tmp53_];
			_data_->_tmp56_ = _data_->argv;
			_data_->_tmp56__length1 = _data_->argv_length1;
			_data_->_tmp57_ = _data_->i;
			_data_->i = _data_->_tmp57_ + 1;
			_g_free0 (_data_->_tmp56_[_data_->_tmp57_]);
			_data_->_tmp56_[_data_->_tmp57_] = NULL;
			_data_->_tmp58_ = _data_->_tmp56_[_data_->_tmp57_];
			_data_->_tmp59_ = FALSE;
			_data_->_tmp59_ = deja_dup_in_testing_mode ();
			if (_data_->_tmp59_) {
				deja_dup_update_last_run_timestamp (DEJA_DUP_TIMESTAMP_TYPE_BACKUP);
			} else {
				_data_->_tmp60_ = _data_->argv;
				_data_->_tmp60__length1 = _data_->argv_length1;
				_data_->_tmp61_ = 0;
				g_spawn_async (NULL, _data_->_tmp60_, NULL, ((G_SPAWN_SEARCH_PATH | G_SPAWN_DO_NOT_REAP_CHILD) | G_SPAWN_STDOUT_TO_DEV_NULL) | G_SPAWN_STDERR_TO_DEV_NULL, NULL, NULL, &_data_->_tmp61_, &_data_->_inner_error_);
				monitor_pid = _data_->_tmp61_;
				if (_data_->_inner_error_ != NULL) {
					_data_->argv = (_vala_array_free (_data_->argv, _data_->argv_length1, (GDestroyNotify) g_free), NULL);
					goto __catch2_g_error;
				}
				_data_->_tmp62_ = monitor_pid;
				g_child_watch_add_full (G_PRIORITY_DEFAULT_IDLE, _data_->_tmp62_, _monitor_close_pid_gchild_watch_func, NULL, NULL);
			}
			_data_->argv = (_vala_array_free (_data_->argv, _data_->argv_length1, (GDestroyNotify) g_free), NULL);
		}
		goto __finally2;
		__catch2_g_error:
		{
			_data_->e = _data_->_inner_error_;
			_data_->_inner_error_ = NULL;
			_data_->_tmp63_ = _data_->e;
			_data_->_tmp64_ = _data_->_tmp63_->message;
			g_warning ("monitor.vala:209: %s\n", _data_->_tmp64_);
			_g_error_free0 (_data_->e);
		}
		__finally2:
		if (_data_->_inner_error_ != NULL) {
			_g_free0 (_data_->when);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _data_->_inner_error_->message, g_quark_to_string (_data_->_inner_error_->domain), _data_->_inner_error_->code);
			g_clear_error (&_data_->_inner_error_);
			return FALSE;
		}
	} else {
		g_debug ("monitor.vala:213: Not rerunning deja-dup, already doing so.");
	}
	_g_free0 (_data_->when);
	if (_data_->_state_ == 0) {
		g_simple_async_result_complete_in_idle (_data_->_async_result);
	} else {
		g_simple_async_result_complete (_data_->_async_result);
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}


static gboolean monitor_time_until_next_run (GTimeSpan* time) {
	GTimeSpan _vala_time = 0LL;
	gboolean result = FALSE;
	GDateTime* _tmp0_ = NULL;
	GDateTime* next_date;
	GDateTime* _tmp1_;
	GDateTime* _tmp2_;
	GTimeSpan _tmp3_ = 0LL;
	_vala_time = (GTimeSpan) 0;
	_tmp0_ = deja_dup_next_run_date ();
	next_date = _tmp0_;
	_tmp1_ = next_date;
	if (_tmp1_ == NULL) {
		g_debug ("monitor.vala:222: Automatic backups disabled.  Not scheduling a backup" \
".");
		result = FALSE;
		_g_date_time_unref0 (next_date);
		if (time) {
			*time = _vala_time;
		}
		return result;
	}
	_tmp2_ = next_date;
	_tmp3_ = monitor_time_until (_tmp2_);
	_vala_time = _tmp3_;
	result = TRUE;
	_g_date_time_unref0 (next_date);
	if (time) {
		*time = _vala_time;
	}
	return result;
}


static gboolean ___lambda2_ (void) {
	gboolean result = FALSE;
	monitor_kickoff (NULL, NULL);
	result = FALSE;
	return result;
}


static gboolean ____lambda2__gsource_func (gpointer self) {
	gboolean result;
	result = ___lambda2_ ();
	return result;
}


static void monitor_prepare_run (GTimeSpan wait_time) {
	guint _tmp0_;
	GTimeSpan _tmp2_;
	GTimeSpan secs;
	gboolean _tmp3_ = FALSE;
	GTimeSpan _tmp4_;
	gboolean _tmp6_;
	_tmp0_ = monitor_timeout_id;
	if (_tmp0_ != ((guint) 0)) {
		guint _tmp1_;
		_tmp1_ = monitor_timeout_id;
		g_source_remove (_tmp1_);
	}
	_tmp2_ = wait_time;
	secs = (_tmp2_ / G_TIME_SPAN_SECOND) + 1;
	_tmp4_ = wait_time;
	if (_tmp4_ > ((GTimeSpan) 0)) {
		GTimeSpan _tmp5_;
		_tmp5_ = secs;
		_tmp3_ = _tmp5_ > ((GTimeSpan) 0);
	} else {
		_tmp3_ = FALSE;
	}
	_tmp6_ = _tmp3_;
	if (_tmp6_) {
		GTimeSpan _tmp7_;
		GTimeSpan _tmp8_;
		guint _tmp9_ = 0U;
		_tmp7_ = secs;
		g_debug ("monitor.vala:238: Waiting %ld seconds until next backup.", (glong) _tmp7_);
		_tmp8_ = secs;
		_tmp9_ = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) _tmp8_, ____lambda2__gsource_func, NULL, NULL);
		monitor_timeout_id = _tmp9_;
	} else {
		GTimeSpan _tmp10_;
		_tmp10_ = secs;
		g_debug ("monitor.vala:245: Late by %ld seconds.  Backing up now.", (glong) (_tmp10_ * (-1)));
		monitor_kickoff (NULL, NULL);
	}
}


static void monitor_prepare_tomorrow (void) {
	GDateTime* _tmp0_;
	GDateTime* now;
	GTimeSpan _tmp1_ = 0LL;
	GDateTime* _tmp2_ = NULL;
	GDateTime* tomorrow;
	GTimeSpan _tmp3_ = 0LL;
	GTimeSpan time;
	_tmp0_ = g_date_time_new_now_local ();
	now = _tmp0_;
	_tmp1_ = deja_dup_get_day ();
	_tmp2_ = g_date_time_add (now, _tmp1_);
	tomorrow = _tmp2_;
	_tmp3_ = monitor_time_until (tomorrow);
	time = _tmp3_;
	monitor_prepare_run (time);
	_g_date_time_unref0 (tomorrow);
	_g_date_time_unref0 (now);
}


static void monitor_prepare_next_run (void) {
	gboolean _tmp0_;
	GTimeSpan wait_time = 0LL;
	GTimeSpan _tmp1_ = 0LL;
	gboolean _tmp2_ = FALSE;
	GTimeSpan _tmp3_;
	_tmp0_ = monitor_first_check;
	if (!_tmp0_) {
		return;
	}
	_tmp2_ = monitor_time_until_next_run (&_tmp1_);
	wait_time = _tmp1_;
	if (!_tmp2_) {
		return;
	}
	_tmp3_ = wait_time;
	monitor_prepare_run (_tmp3_);
}


static void monitor_prepare_if_necessary (const gchar* key) {
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	const gchar* _tmp2_;
	gboolean _tmp4_;
	gboolean _tmp6_;
	g_return_if_fail (key != NULL);
	_tmp2_ = key;
	if (g_strcmp0 (_tmp2_, DEJA_DUP_LAST_BACKUP_KEY) == 0) {
		_tmp1_ = TRUE;
	} else {
		const gchar* _tmp3_;
		_tmp3_ = key;
		_tmp1_ = g_strcmp0 (_tmp3_, DEJA_DUP_PERIODIC_KEY) == 0;
	}
	_tmp4_ = _tmp1_;
	if (_tmp4_) {
		_tmp0_ = TRUE;
	} else {
		const gchar* _tmp5_;
		_tmp5_ = key;
		_tmp0_ = g_strcmp0 (_tmp5_, DEJA_DUP_PERIODIC_PERIOD_KEY) == 0;
	}
	_tmp6_ = _tmp0_;
	if (_tmp6_) {
		monitor_prepare_next_run ();
	}
}


static gboolean __lambda4_ (void) {
	gboolean result = FALSE;
	deja_dup_make_prompt_check ();
	result = TRUE;
	return result;
}


static gboolean ___lambda4__gsource_func (gpointer self) {
	gboolean result;
	result = __lambda4_ ();
	return result;
}


static void monitor_make_first_check (void) {
	gint _tmp0_ = 0;
	monitor_first_check = TRUE;
	deja_dup_make_prompt_check ();
	_tmp0_ = deja_dup_get_prompt_delay ();
	g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) _tmp0_, ___lambda4__gsource_func, NULL, NULL);
	monitor_prepare_next_run ();
}


static void _monitor_prepare_if_necessary_g_settings_changed (GSettings* _sender, const gchar* key, gpointer self) {
	monitor_prepare_if_necessary (key);
}


static void monitor_watch_settings (void) {
	DejaDupSimpleSettings* _tmp0_ = NULL;
	DejaDupSimpleSettings* _tmp1_;
	_tmp0_ = deja_dup_get_settings (NULL);
	_g_object_unref0 (monitor_settings);
	monitor_settings = _tmp0_;
	_tmp1_ = monitor_settings;
	g_signal_connect ((GSettings*) _tmp1_, "changed", (GCallback) _monitor_prepare_if_necessary_g_settings_changed, NULL);
}


static void _monitor_network_changed_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	monitor_network_changed ();
}


static void _monitor_op_started_gbus_name_appeared_callback (GDBusConnection* connection, const gchar* name, const gchar* name_owner, gpointer self) {
	monitor_op_started (connection, name, name_owner);
}


static void _monitor_op_ended_gbus_name_vanished_callback (GDBusConnection* connection, const gchar* name, gpointer self) {
	monitor_op_ended (connection, name);
}


static void _monitor_volume_added_g_volume_monitor_volume_added (GVolumeMonitor* _sender, GVolume* volume, gpointer self) {
	monitor_volume_added (_sender, volume);
}


static gboolean ___lambda5_ (void) {
	gboolean result = FALSE;
	monitor_make_first_check ();
	result = FALSE;
	return result;
}


static gboolean ____lambda5__gsource_func (gpointer self) {
	gboolean result;
	result = ___lambda5_ ();
	return result;
}


static gint monitor_main (gchar** args, int args_length1) {
	gint result = 0;
	const gchar* _tmp0_ = NULL;
	GOptionContext* _tmp1_;
	GOptionContext* context;
	GOptionContext* _tmp2_;
	gint status = 0;
	gint _tmp9_ = 0;
	gboolean _tmp10_ = FALSE;
	gboolean _tmp11_ = FALSE;
	DejaDupNetwork* _tmp12_ = NULL;
	DejaDupNetwork* _tmp13_;
	GVolumeMonitor* _tmp14_ = NULL;
	GVolumeMonitor* mon;
	GVolumeMonitor* _tmp15_;
	GVolumeMonitor* _tmp16_;
	GMainLoop* _tmp17_;
	GMainLoop* loop;
	gboolean _tmp18_ = FALSE;
	GMainLoop* _tmp19_;
	GError * _inner_error_ = NULL;
	deja_dup_i18n_setup ();
	_tmp0_ = _ ("Backup Monitor");
	g_set_application_name (_tmp0_);
	_tmp1_ = g_option_context_new ("");
	context = _tmp1_;
	_tmp2_ = context;
	g_option_context_add_main_entries (_tmp2_, MONITOR_options, GETTEXT_PACKAGE);
	{
		GOptionContext* _tmp3_;
		_tmp3_ = context;
		g_option_context_parse (_tmp3_, &args_length1, &args, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch3_g_error;
		}
	}
	goto __finally3;
	__catch3_g_error:
	{
		GError* e = NULL;
		GError* _tmp4_;
		const gchar* _tmp5_;
		GOptionContext* _tmp6_;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp4_ = e;
		_tmp5_ = _tmp4_->message;
		_tmp6_ = context;
		_tmp7_ = g_option_context_get_help (_tmp6_, TRUE, NULL);
		_tmp8_ = _tmp7_;
		g_printerr ("%s\n\n%s", _tmp5_, _tmp8_);
		_g_free0 (_tmp8_);
		result = 1;
		_g_error_free0 (e);
		_g_option_context_free0 (context);
		return result;
	}
	__finally3:
	if (_inner_error_ != NULL) {
		_g_option_context_free0 (context);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	_tmp10_ = monitor_handle_options (&_tmp9_);
	status = _tmp9_;
	if (!_tmp10_) {
		result = status;
		_g_option_context_free0 (context);
		return result;
	}
	_tmp11_ = deja_dup_initialize (NULL, NULL);
	if (!_tmp11_) {
		result = 1;
		_g_option_context_free0 (context);
		return result;
	}
	deja_dup_network_ensure_status (NULL, NULL);
	_tmp12_ = deja_dup_network_get ();
	_tmp13_ = _tmp12_;
	g_signal_connect ((GObject*) _tmp13_, "notify::connected", (GCallback) _monitor_network_changed_g_object_notify, NULL);
	_g_object_unref0 (_tmp13_);
	g_bus_watch_name_with_closures (G_BUS_TYPE_SESSION, "org.gnome.DejaDup.Operation", G_BUS_NAME_WATCHER_FLAGS_NONE, (GClosure*) ((_monitor_op_started_gbus_name_appeared_callback == NULL) ? NULL : g_cclosure_new ((GCallback) _monitor_op_started_gbus_name_appeared_callback, NULL, NULL)), (GClosure*) ((_monitor_op_ended_gbus_name_vanished_callback == NULL) ? NULL : g_cclosure_new ((GCallback) _monitor_op_ended_gbus_name_vanished_callback, NULL, NULL)));
	_tmp14_ = g_volume_monitor_get ();
	mon = _tmp14_;
	_tmp15_ = mon;
	g_object_ref ((GObject*) _tmp15_);
	_tmp16_ = mon;
	g_signal_connect (_tmp16_, "volume-added", (GCallback) _monitor_volume_added_g_volume_monitor_volume_added, NULL);
	_tmp17_ = g_main_loop_new (NULL, FALSE);
	loop = _tmp17_;
	_tmp18_ = deja_dup_in_testing_mode ();
	if (_tmp18_) {
		monitor_make_first_check ();
	} else {
		g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 120, ____lambda5__gsource_func, NULL, NULL);
	}
	monitor_watch_settings ();
	_tmp19_ = loop;
	g_main_loop_run (_tmp19_);
	result = 0;
	_g_main_loop_unref0 (loop);
	_g_object_unref0 (mon);
	_g_option_context_free0 (context);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return monitor_main (argv, argc);
}


Monitor* monitor_construct (GType object_type) {
	Monitor * self = NULL;
	self = (Monitor*) g_object_new (object_type, NULL);
	return self;
}


Monitor* monitor_new (void) {
	return monitor_construct (TYPE_MONITOR);
}


static void monitor_class_init (MonitorClass * klass) {
	monitor_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = monitor_finalize;
}


static void monitor_instance_init (Monitor * self) {
}


static void monitor_finalize (GObject* obj) {
	Monitor * self;
	self = MONITOR (obj);
	G_OBJECT_CLASS (monitor_parent_class)->finalize (obj);
}


GType monitor_get_type (void) {
	static volatile gsize monitor_type_id__volatile = 0;
	if (g_once_init_enter (&monitor_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MonitorClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) monitor_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Monitor), 0, (GInstanceInitFunc) monitor_instance_init, NULL };
		GType monitor_type_id;
		monitor_type_id = g_type_register_static (G_TYPE_OBJECT, "Monitor", &g_define_type_info, 0);
		g_once_init_leave (&monitor_type_id__volatile, monitor_type_id);
	}
	return monitor_type_id__volatile;
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


