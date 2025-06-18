#ifndef INCLUDED_COM_SUN_STAR_UCB_OUTGOINGMESSAGESTATE_HPP
#define INCLUDED_COM_SUN_STAR_UCB_OUTGOINGMESSAGESTATE_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/OutgoingMessageState.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theOutgoingMessageStateType : public rtl::StaticWithInit< ::css::uno::Type *, theOutgoingMessageStateType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.OutgoingMessageState" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[8];
        ::rtl::OUString sEnumValue0( "WRITTEN" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "PARTIALLY_LOCALLY_SENT" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "COMPLETELY_LOCALLY_SENT" );
        enumValueNames[2] = sEnumValue2.pData;
        ::rtl::OUString sEnumValue3( "RECOVERABLE_LOCAL_ERROR" );
        enumValueNames[3] = sEnumValue3.pData;
        ::rtl::OUString sEnumValue4( "NONRECOVERABLE_LOCAL_ERROR" );
        enumValueNames[4] = sEnumValue4.pData;
        ::rtl::OUString sEnumValue5( "EXTERNAL_ERROR" );
        enumValueNames[5] = sEnumValue5.pData;
        ::rtl::OUString sEnumValue6( "WAITING_CONFIRMATION" );
        enumValueNames[6] = sEnumValue6.pData;
        ::rtl::OUString sEnumValue7( "CONFIRMED" );
        enumValueNames[7] = sEnumValue7.pData;

        sal_Int32 enumValues[8];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;
        enumValues[3] = 3;
        enumValues[4] = 4;
        enumValues[5] = 5;
        enumValues[6] = 6;
        enumValues[7] = 7;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::ucb::OutgoingMessageState_WRITTEN,
            8, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::OutgoingMessageState const *) {
    return *detail::theOutgoingMessageStateType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::OutgoingMessageState const *) {
    return ::cppu::UnoType< ::css::ucb::OutgoingMessageState >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_OUTGOINGMESSAGESTATE_HPP
