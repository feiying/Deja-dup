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

SUBDIRS = data po vapi common tools widgets monitor preferences deja-dup nautilus plugins help man tests

# Distribute pot file
update-pot:
	$(MAKE) -C po "$(GETTEXT_PACKAGE).pot"
	$(MAKE) -C help pot
dist-hook: update-pot

# call like 'make copy-po TD=path-to-translation-dir'
copy-po:
	test -d $(TD)
	cp -a $(TD)/po/*.po po
	for po in $(TD)/help/*.po; do \
		mkdir -p help/$$(basename $$po .po); \
		cp -a $$po help/$$(basename $$po .po)/; \
	done
	bzr add po/*.po
	bzr add help/*/*.po

sign:
	gpg --armor --sign --detach-sig deja-dup-$(PACKAGE_VERSION).tar.xz

# This next test check is line-broken this way to make it easier to compare 
# lists when something breaks
check:
	test \
	     "$(shell ls -1 $(srcdir)/po/*.po | sed 's|.*/\(.*\)\.po|\1|' | sort)" = \
	     "$(shell cat $(srcdir)/po/LINGUAS)"

releasecheck: all distcheck sign
release: all dist sign

# distcheck complains if we try to install into /usr, so respect prefix
DISTCHECK_CONFIGURE_FLAGS = --without-extensiondir

ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

EXTRA_DIST = \
	autogen.sh \
	intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

DISTCLEANFILES = \
	intltool-extract \
	intltool-merge \
	intltool-update
