# -*- Mode: Makefile; indent-tabs-mode: t; tab-width: 2 -*-
#
# This file is part of Déjà Dup.
# For copyright information, see AUTHORS.
#
# Déjà Dup is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# Déjà Dup is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Déjà Dup.  If not, see <http://www.gnu.org/licenses/>.

pluginsdir = $(pkglibexecdir)/plugins
plugins_LTLIBRARIES = libapps.la
dist_plugins_DATA = apps.plugin

libapps_la_CFLAGS = \
	-I$(top_srcdir)/common \
	$(COMMON_CFLAGS) \
	-w \
	-DPKG_LIBEXEC_DIR=\"$(pkglibexecdir)\" \
	-DGETTEXT_PACKAGE=\"$(GETTEXT_PACKAGE)\"

libapps_la_LDFLAGS = -module -avoid-version

libapps_la_LIBADD = \
	$(COMMON_LIBS) \
	@INTLLIBS@ \
	$(top_builddir)/common/libcommon.la

libapps_la_VALASOURCES = \
	AppsPlugin.vala

libapps_la_SOURCES = \
	$(libapps_la_VALASOURCES)

AM_VALAFLAGS = \
	--library=libapps \
	--vapidir $(top_srcdir)/common \
	--vapidir=$(top_srcdir)/vapi \
	$(SHARED_VALAFLAGS) \
	--pkg gio-2.0 \
	--pkg libpeas-1.0 \
	--pkg gio-unix-2.0 \
	--pkg posix \
	--pkg libcommon \
	--pkg config

libapps_la_vala.stamp: $(top_srcdir)/config.h

dist-hook:
	cd $(distdir) && rm -f $(libapps_la_VALASOURCES:.vala=.c) \
	                       libapps_la_vala.stamp

CLEANFILES = libapps_la_vala.stamp
