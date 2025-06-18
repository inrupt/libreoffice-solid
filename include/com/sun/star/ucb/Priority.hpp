#ifndef INCLUDED_COM_SUN_STAR_UCB_PRIORITY_HPP
#define INCLUDED_COM_SUN_STAR_UCB_PRIORITY_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/Priority.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct thePriorityType : public rtl::StaticWithInit< ::css::uno::Type *, thePriorityType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.Priority" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[5];
        ::rtl::OUString sEnumValue0( "HIGHEST" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "HIGH" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "NORMAL" );
        enumValueNames[2] = sEnumValue2.pData;
        ::rtl::OUString sEnumValue3( "LOW" );
        enumValueNames[3] = sEnumValue3.pData;
        ::rtl::OUString sEnumValue4( "LOWEST" );
        enumValueNames[4] = sEnumValue4.pData;

        sal_Int32 enumValues[5];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;
        enumValues[3] = 3;
        enumValues[4] = 4;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::ucb::Priority_HIGHEST,
            5, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::Priority const *) {
    return *detail::thePriorityType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::Priority const *) {
    return ::cppu::UnoType< ::css::ucb::Priority >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_PRIORITY_HPP
