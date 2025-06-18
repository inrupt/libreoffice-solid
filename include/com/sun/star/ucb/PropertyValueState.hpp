#ifndef INCLUDED_COM_SUN_STAR_UCB_PROPERTYVALUESTATE_HPP
#define INCLUDED_COM_SUN_STAR_UCB_PROPERTYVALUESTATE_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/PropertyValueState.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct thePropertyValueStateType : public rtl::StaticWithInit< ::css::uno::Type *, thePropertyValueStateType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.PropertyValueState" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[4];
        ::rtl::OUString sEnumValue0( "UNPROCESSED" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "PROCESSED" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "INVALID_NAME" );
        enumValueNames[2] = sEnumValue2.pData;
        ::rtl::OUString sEnumValue3( "INVALID_TYPE" );
        enumValueNames[3] = sEnumValue3.pData;

        sal_Int32 enumValues[4];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;
        enumValues[3] = 3;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::ucb::PropertyValueState_UNPROCESSED,
            4, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::PropertyValueState const *) {
    return *detail::thePropertyValueStateType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::PropertyValueState const *) {
    return ::cppu::UnoType< ::css::ucb::PropertyValueState >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_PROPERTYVALUESTATE_HPP
