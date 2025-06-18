#ifndef INCLUDED_COM_SUN_STAR_UCB_SYNCHRONIZEPOLICY_HPP
#define INCLUDED_COM_SUN_STAR_UCB_SYNCHRONIZEPOLICY_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/SynchronizePolicy.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theSynchronizePolicyType : public rtl::StaticWithInit< ::css::uno::Type *, theSynchronizePolicyType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.SynchronizePolicy" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[3];
        ::rtl::OUString sEnumValue0( "SERVER_IS_MASTER" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "CLIENT_IS_MASTER" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "NONE_IS_MASTER" );
        enumValueNames[2] = sEnumValue2.pData;

        sal_Int32 enumValues[3];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::ucb::SynchronizePolicy_SERVER_IS_MASTER,
            3, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::SynchronizePolicy const *) {
    return *detail::theSynchronizePolicyType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::SynchronizePolicy const *) {
    return ::cppu::UnoType< ::css::ucb::SynchronizePolicy >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_SYNCHRONIZEPOLICY_HPP
