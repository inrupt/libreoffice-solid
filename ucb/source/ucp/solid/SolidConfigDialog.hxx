/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <vcl/weld.hxx>
#include <rtl/ustring.hxx>

namespace solid { namespace libreoffice {

struct SolidServiceConfig
{
    rtl::OUString serviceName;
    rtl::OUString podUrl;
    rtl::OUString webId;
    bool enableDpop = true;
    bool rememberCredentials = true;
};

class SolidConfigDialog
{
private:
    std::unique_ptr<weld::Dialog> m_xDialog;
    std::unique_ptr<weld::Entry> m_xServiceNameEdit;
    std::unique_ptr<weld::Entry> m_xPodUrlEdit;
    std::unique_ptr<weld::Entry> m_xWebIdEdit;
    std::unique_ptr<weld::CheckButton> m_xDpopCheck;
    std::unique_ptr<weld::CheckButton> m_xRememberCheck;
    std::unique_ptr<weld::Button> m_xTestButton;
    std::unique_ptr<weld::Button> m_xOkButton;
    std::unique_ptr<weld::Button> m_xCancelButton;
    
    DECL_LINK(TestConnectionHdl, weld::Button&, void);
    DECL_LINK(OkHdl, weld::Button&, void);
    DECL_LINK(CancelHdl, weld::Button&, void);
    DECL_LINK(UrlModifyHdl, weld::Entry&, void);

public:
    explicit SolidConfigDialog(weld::Window* pParent);
    virtual ~SolidConfigDialog();
    
    short run() { return m_xDialog->run(); }
    
    SolidServiceConfig getServiceConfig() const;
    void setServiceConfig(const SolidServiceConfig& config);
};

} // namespace libreoffice
} // namespace solid

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */