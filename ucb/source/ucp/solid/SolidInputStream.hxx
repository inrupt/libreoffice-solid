/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <rtl/string.hxx>
#include <rtl/ustring.hxx>
#include <com/sun/star/io/XInputStream.hpp>
#include <com/sun/star/io/XSeekable.hpp>
#include <cppuhelper/implbase2.hxx>

using rtl::OUString;
using rtl::OString;
namespace css = com::sun::star;

namespace solid { namespace libreoffice
{

/**
 * Simple input stream implementation for Solid HTTP responses
 */
class SolidInputStream : public cppu::WeakImplHelper2< css::io::XInputStream, css::io::XSeekable >
{
private:
    css::uno::Sequence<sal_Int8> m_aData;
    sal_Int32 m_nPos;
    
public:
    explicit SolidInputStream(const OString& data);
    explicit SolidInputStream(const css::uno::Sequence<sal_Int8>& data);
    virtual ~SolidInputStream();
    
    // XInputStream
    virtual sal_Int32 SAL_CALL readBytes(
        css::uno::Sequence<sal_Int8>& aData, sal_Int32 nBytesToRead) override;
    virtual sal_Int32 SAL_CALL readSomeBytes(
        css::uno::Sequence<sal_Int8>& aData, sal_Int32 nMaxBytesToRead) override;
    virtual void SAL_CALL skipBytes(sal_Int32 nBytesToSkip) override;
    virtual sal_Int32 SAL_CALL available() override;
    virtual void SAL_CALL closeInput() override;
    
    // XSeekable
    virtual void SAL_CALL seek(sal_Int64 location) override;
    virtual sal_Int64 SAL_CALL getPosition() override;
    virtual sal_Int64 SAL_CALL getLength() override;
};

} // namespace libreoffice
} // namespace solid