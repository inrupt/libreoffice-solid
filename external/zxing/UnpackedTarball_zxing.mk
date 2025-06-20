#-*- Mode: makefile-gmake; tab-width: 4; indent-tabs-mode: t -*-
#
# This file is part of the LibreOffice project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

$(eval $(call gb_UnpackedTarball_UnpackedTarball,zxing))

$(eval $(call gb_UnpackedTarball_set_tarball,zxing,$(ZXING_TARBALL)))

$(eval $(call gb_UnpackedTarball_set_patchlevel,zxing,1))

# * external/zxing/include.patch.0 sent upstream as
#   <https://github.com/zxing-cpp/zxing-cpp/pull/864> "Missing include (for std::nullptr_t)":
$(eval $(call gb_UnpackedTarball_add_patches,zxing, \
	external/zxing/0001-add-ZXVersion-h.patch \
	external/zxing/include.patch.0 \
))

# vim: set noet sw=4 ts=4:
