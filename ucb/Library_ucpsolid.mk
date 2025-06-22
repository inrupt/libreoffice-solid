# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

$(eval $(call gb_Library_Library,ucpsolid))

$(eval $(call gb_Library_use_sdk_api,ucpsolid))

$(eval $(call gb_Library_set_include,ucpsolid,\
    -I$(SRCDIR)/ucb/source/ucp/inc \
    $$(INCLUDE) \
))

$(eval $(call gb_Library_use_libraries,ucpsolid,\
	comphelper \
	cppu \
	cppuhelper \
	sal \
	salhelper \
	svl \
	svt \
	tk \
	tl \
	ucbhelper \
	utl \
	vcl \
))

$(eval $(call gb_Library_set_componentfile,ucpsolid,ucb/source/ucp/solid/ucpsolid,services))

$(eval $(call gb_Library_use_externals,ucpsolid,\
	curl \
	openssl \
))

$(eval $(call gb_Library_use_custom_headers,ucpsolid,\
	officecfg/registry \
))

$(eval $(call gb_Library_add_exception_objects,ucpsolid,\
	ucb/source/ucp/solid/SolidAuthTest \
	ucb/source/ucp/solid/SolidCallbackServer \
	ucb/source/ucp/solid/SolidConfigDialog \
	ucb/source/ucp/solid/SolidHttpSession \
	ucb/source/ucp/solid/SolidInputStream \
	ucb/source/ucp/solid/SolidOAuth \
	ucb/source/ucp/solid/SolidRemoteFilesService \
	ucb/source/ucp/solid/SolidServiceDetector \
	ucb/source/ucp/solid/SolidSessionBridge \
	ucb/source/ucp/solid/SolidSessionFactory \
	ucb/source/ucp/solid/solidcontent \
	ucb/source/ucp/solid/solidprovider \
))

ifeq ($(OS),WNT)
$(eval $(call gb_Library_use_system_win32_libs,ucpsolid,\
	ws2_32 \
))
endif

ifeq ($(OS),SOLARIS)
$(eval $(call gb_Library_add_libs,ucpsolid,\
	-ldl \
	-lnsl \
	-lsocket \
))
endif

# vim: set noet sw=4 ts=4: