# -*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

$(eval $(call gb_Library_Library,ucpsolid))

$(eval $(call gb_Library_set_componentfile,ucpsolid,ucb/source/ucp/solid/ucpsolid,services))

$(eval $(call gb_Library_use_sdk_api,ucpsolid))

$(eval $(call gb_Library_use_libraries,ucpsolid,\
	comphelper \
	cppu \
	cppuhelper \
	sal \
	salhelper \
	tl \
	ucbhelper \
))

$(eval $(call gb_Library_use_externals,ucpsolid,\
	boost_headers \
	curl \
))

$(eval $(call gb_Library_add_exception_objects,ucpsolid,\
	ucb/source/ucp/solid/ContentProperties \
	ucb/source/ucp/solid/SolidSession \
	ucb/source/ucp/solid/SolidHttpSession \
	ucb/source/ucp/solid/SolidInputStream \
	ucb/source/ucp/solid/SolidSessionBridge \
	ucb/source/ucp/solid/SolidCallbackServer \
	ucb/source/ucp/solid/SolidUri \
	ucb/source/ucp/solid/SolidResourceAccess \
	ucb/source/ucp/solid/SolidSessionFactory \
	ucb/source/ucp/solid/SolidTypes \
	ucb/source/ucp/solid/PropertyMap \
	ucb/source/ucp/solid/SolidAuth \
	ucb/source/ucp/solid/solidcontent \
	ucb/source/ucp/solid/solidcontentcaps \
	ucb/source/ucp/solid/soliddatasupplier \
	ucb/source/ucp/solid/solidprovider \
	ucb/source/ucp/solid/solidresultset \
))

$(eval $(call gb_Library_add_defs,ucpsolid,\
	-DUCPSOLID_DLLIMPLEMENTATION \
))

$(eval $(call gb_Library_set_include,ucpsolid,\
	$$(INCLUDE) \
	-I$(SRCDIR)/ucb/source/ucp/solid \
))

# vim: set noet sw=4 ts=4: