#ifndef INCLUDED_COM_SUN_STAR_UCB_CONTENTCREATIONERROR_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CONTENTCREATIONERROR_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ContentCreationError.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theContentCreationErrorType : public rtl::StaticWithInit< ::css::uno::Type *, theContentCreationErrorType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.ContentCreationError" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[6];
        ::rtl::OUString sEnumValue0( "UNKNOWN" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "NO_CONTENT_BROKER" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "NO_IDENTIFIER_FACTORY" );
        enumValueNames[2] = sEnumValue2.pData;
        ::rtl::OUString sEnumValue3( "IDENTIFIER_CREATION_FAILED" );
        enumValueNames[3] = sEnumValue3.pData;
        ::rtl::OUString sEnumValue4( "NO_CONTENT_PROVIDER" );
        enumValueNames[4] = sEnumValue4.pData;
        ::rtl::OUString sEnumValue5( "CONTENT_CREATION_FAILED" );
        enumValueNames[5] = sEnumValue5.pData;

        sal_Int32 enumValues[6];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;
        enumValues[3] = 3;
        enumValues[4] = 4;
        enumValues[5] = 5;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::ucb::ContentCreationError_UNKNOWN,
            6, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ContentCreationError const *) {
    return *detail::theContentCreationErrorType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ContentCreationError const *) {
    return ::cppu::UnoType< ::css::ucb::ContentCreationError >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CONTENTCREATIONERROR_HPP
