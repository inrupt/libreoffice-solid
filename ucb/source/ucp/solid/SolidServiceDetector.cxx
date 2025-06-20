/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidServiceDetector.hxx"
#include <rtl/ustring.hxx>
#include <tools/urlobj.hxx>

using namespace com::sun::star;
using namespace solid::libreoffice;

bool SolidServiceDetector::isSolidUrl(const rtl::OUString& rUrl)
{
    INetURLObject aUrl(rUrl);
    
    // Check for solid:// protocol
    if (aUrl.GetProtocol() == INetProtocol::Generic && 
        rUrl.startsWithIgnoreAsciiCase("solid://"))
    {
        return true;
    }
    
    // Check for https://storage.inrupt.com URLs
    if (aUrl.GetProtocol() == INetProtocol::Https &&
        aUrl.GetHost().equalsIgnoreAsciiCase("storage.inrupt.com"))
    {
        return true;
    }
    
    return false;
}

rtl::OUString SolidServiceDetector::getServiceType(const rtl::OUString& rUrl)
{
    if (isSolidUrl(rUrl))
    {
        return rtl::OUString("Solid");
    }
    
    return rtl::OUString();
}

rtl::OUString SolidServiceDetector::normalizeUrl(const rtl::OUString& rUrl)
{
    // Convert solid:// URLs to https://storage.inrupt.com/ format
    if (rUrl.startsWithIgnoreAsciiCase("solid://"))
    {
        rtl::OUString sPodId = rUrl.copy(8); // Remove "solid://"
        return rtl::OUString("https://storage.inrupt.com/") + sPodId;
    }
    
    return rUrl;
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */