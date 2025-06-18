#ifndef INCLUDED_COM_SUN_STAR_UCB_COMMANDFAILEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_COMMANDFAILEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/CommandFailedException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline CommandFailedException::CommandFailedException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Reason()
{
    ::cppu::UnoType< ::css::ucb::CommandFailedException >::get();
}

inline CommandFailedException::CommandFailedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& Reason_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Reason(Reason_)
{
    ::cppu::UnoType< ::css::ucb::CommandFailedException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
CommandFailedException::CommandFailedException(CommandFailedException const & the_other): ::css::uno::Exception(the_other), Reason(the_other.Reason) {}

CommandFailedException::~CommandFailedException() {}

CommandFailedException & CommandFailedException::operator =(CommandFailedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    Reason = the_other.Reason;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theCommandFailedExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theCommandFailedExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.CommandFailedException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::Exception >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "any" );
        ::rtl::OUString sMemberName0( "Reason" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
        aMembers[0].pTypeName = sMemberType0.pData;
        aMembers[0].pMemberName = sMemberName0.pData;

        typelib_typedescription_new(
            &pTD,
            (typelib_TypeClass)::css::uno::TypeClass_EXCEPTION, sTypeName.pData,
            rSuperType.getTypeLibType(),
            1,
            aMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );

        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_EXCEPTION, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::CommandFailedException const *) {
    return *detail::theCommandFailedExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::CommandFailedException const *) {
    return ::cppu::UnoType< ::css::ucb::CommandFailedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_COMMANDFAILEDEXCEPTION_HPP
