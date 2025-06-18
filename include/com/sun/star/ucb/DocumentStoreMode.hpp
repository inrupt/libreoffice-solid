#ifndef INCLUDED_COM_SUN_STAR_UCB_DOCUMENTSTOREMODE_HPP
#define INCLUDED_COM_SUN_STAR_UCB_DOCUMENTSTOREMODE_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/DocumentStoreMode.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theDocumentStoreModeType : public rtl::StaticWithInit< ::css::uno::Type *, theDocumentStoreModeType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.DocumentStoreMode" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[2];
        ::rtl::OUString sEnumValue0( "REMOTE" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "LOCAL" );
        enumValueNames[1] = sEnumValue1.pData;

        sal_Int32 enumValues[2];
        enumValues[0] = 0;
        enumValues[1] = 1;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::ucb::DocumentStoreMode_REMOTE,
            2, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::DocumentStoreMode const *) {
    return *detail::theDocumentStoreModeType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::DocumentStoreMode const *) {
    return ::cppu::UnoType< ::css::ucb::DocumentStoreMode >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_DOCUMENTSTOREMODE_HPP
