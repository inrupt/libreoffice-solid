/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <rtl/ustring.hxx>

namespace libreoffice { namespace solid {

class SolidServiceDetector
{
public:
    /**
     * Check if the given URL is a Solid pod URL
     */
    static bool isSolidUrl(const rtl::OUString& rUrl);

    /**
     * Get service type name for Solid URLs
     */
    static rtl::OUString getServiceType(const rtl::OUString& rUrl);

    /**
     * Normalize solid:// URLs to https://storage.inrupt.com/ format
     */
    static rtl::OUString normalizeUrl(const rtl::OUString& rUrl);
};

} // namespace libreoffice
} // namespace libreoffice

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */