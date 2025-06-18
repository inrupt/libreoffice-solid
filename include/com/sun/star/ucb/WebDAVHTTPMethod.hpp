#ifndef INCLUDED_COM_SUN_STAR_UCB_WEBDAVHTTPMETHOD_HPP
#define INCLUDED_COM_SUN_STAR_UCB_WEBDAVHTTPMETHOD_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/WebDAVHTTPMethod.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theWebDAVHTTPMethodType : public rtl::StaticWithInit< ::css::uno::Type *, theWebDAVHTTPMethodType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.WebDAVHTTPMethod" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[16];
        ::rtl::OUString sEnumValue0( "GET" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "HEAD" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "POST" );
        enumValueNames[2] = sEnumValue2.pData;
        ::rtl::OUString sEnumValue3( "PUT" );
        enumValueNames[3] = sEnumValue3.pData;
        ::rtl::OUString sEnumValue4( "DELETE" );
        enumValueNames[4] = sEnumValue4.pData;
        ::rtl::OUString sEnumValue5( "TRACE" );
        enumValueNames[5] = sEnumValue5.pData;
        ::rtl::OUString sEnumValue6( "OPTIONS" );
        enumValueNames[6] = sEnumValue6.pData;
        ::rtl::OUString sEnumValue7( "CONNECT" );
        enumValueNames[7] = sEnumValue7.pData;
        ::rtl::OUString sEnumValue8( "PATCH" );
        enumValueNames[8] = sEnumValue8.pData;
        ::rtl::OUString sEnumValue9( "PROPFIND" );
        enumValueNames[9] = sEnumValue9.pData;
        ::rtl::OUString sEnumValue10( "PROPPATCH" );
        enumValueNames[10] = sEnumValue10.pData;
        ::rtl::OUString sEnumValue11( "MKCOL" );
        enumValueNames[11] = sEnumValue11.pData;
        ::rtl::OUString sEnumValue12( "COPY" );
        enumValueNames[12] = sEnumValue12.pData;
        ::rtl::OUString sEnumValue13( "MOVE" );
        enumValueNames[13] = sEnumValue13.pData;
        ::rtl::OUString sEnumValue14( "LOCK" );
        enumValueNames[14] = sEnumValue14.pData;
        ::rtl::OUString sEnumValue15( "UNLOCK" );
        enumValueNames[15] = sEnumValue15.pData;

        sal_Int32 enumValues[16];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;
        enumValues[3] = 3;
        enumValues[4] = 4;
        enumValues[5] = 5;
        enumValues[6] = 6;
        enumValues[7] = 7;
        enumValues[8] = 8;
        enumValues[9] = 9;
        enumValues[10] = 10;
        enumValues[11] = 11;
        enumValues[12] = 12;
        enumValues[13] = 13;
        enumValues[14] = 14;
        enumValues[15] = 15;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::ucb::WebDAVHTTPMethod_GET,
            16, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::WebDAVHTTPMethod const *) {
    return *detail::theWebDAVHTTPMethodType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::WebDAVHTTPMethod const *) {
    return ::cppu::UnoType< ::css::ucb::WebDAVHTTPMethod >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_WEBDAVHTTPMETHOD_HPP
