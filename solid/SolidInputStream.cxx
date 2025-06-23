/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidInputStream.hxx"
#include <algorithm>
#include <cstring>
#include <com/sun/star/io/IOException.hpp>

using namespace css;
using namespace css::uno;
using namespace css::io;

namespace libreoffice { namespace solid
{

SolidInputStream::SolidInputStream(const OString& data)
    : m_nPos(0)
{
    m_aData.realloc(data.getLength());
    if (data.getLength() > 0)
    {
        std::memcpy(m_aData.getArray(), data.getStr(), data.getLength());
    }
}

SolidInputStream::SolidInputStream(const uno::Sequence<sal_Int8>& data)
    : m_aData(data)
    , m_nPos(0)
{
}

SolidInputStream::~SolidInputStream()
{
}

sal_Int32 SAL_CALL SolidInputStream::readBytes(uno::Sequence<sal_Int8>& aData, sal_Int32 nBytesToRead)
{
    sal_Int32 nAvailable = m_aData.getLength() - m_nPos;
    sal_Int32 nRead = std::min(nBytesToRead, nAvailable);

    aData.realloc(nRead);
    if (nRead > 0)
    {
        std::memcpy(aData.getArray(), m_aData.getConstArray() + m_nPos, nRead);
        m_nPos += nRead;
    }

    return nRead;
}

sal_Int32 SAL_CALL SolidInputStream::readSomeBytes(uno::Sequence<sal_Int8>& aData, sal_Int32 nMaxBytesToRead)
{
    return readBytes(aData, nMaxBytesToRead);
}

void SAL_CALL SolidInputStream::skipBytes(sal_Int32 nBytesToSkip)
{
    sal_Int32 nAvailable = m_aData.getLength() - m_nPos;
    sal_Int32 nSkip = std::min(nBytesToSkip, nAvailable);
    m_nPos += nSkip;
}

sal_Int32 SAL_CALL SolidInputStream::available()
{
    return m_aData.getLength() - m_nPos;
}

void SAL_CALL SolidInputStream::closeInput()
{
    // Nothing to do
}

void SAL_CALL SolidInputStream::seek(sal_Int64 location)
{
    if (location < 0 || location > m_aData.getLength())
        throw io::IOException("Invalid seek position");
    m_nPos = static_cast<sal_Int32>(location);
}

sal_Int64 SAL_CALL SolidInputStream::getPosition()
{
    return m_nPos;
}

sal_Int64 SAL_CALL SolidInputStream::getLength()
{
    return m_aData.getLength();
}

} // namespace libreoffice
} // namespace libreoffice