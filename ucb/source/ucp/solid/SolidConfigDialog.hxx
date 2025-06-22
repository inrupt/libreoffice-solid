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
#include <vcl/button.hxx>
#include <vcl/edit.hxx>
#include <vcl/fixed.hxx>
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

class SolidConfigDialog : public ModalDialog
{
private:
    VclPtr<Edit> m_pServiceNameEdit;
    VclPtr<Edit> m_pPodUrlEdit;
    VclPtr<Edit> m_pWebIdEdit;
    VclPtr<CheckBox> m_pDpopCheck;
    VclPtr<CheckBox> m_pRememberCheck;
    VclPtr<PushButton> m_pTestButton;
    VclPtr<OKButton> m_pOkButton;
    VclPtr<CancelButton> m_pCancelButton;
    
    DECL_LINK(TestConnectionHdl, Button*, void);
    DECL_LINK(OkHdl, Button*, void);
    DECL_LINK(CancelHdl, Button*, void);
    DECL_LINK(UrlModifyHdl, Edit&, void);

public:
    explicit SolidConfigDialog(vcl::Window* pParent);
    virtual ~SolidConfigDialog() override;
    virtual void dispose() override;
    
    SolidServiceConfig getServiceConfig() const;
    void setServiceConfig(const SolidServiceConfig& config);
};

} // namespace libreoffice
} // namespace solid

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */