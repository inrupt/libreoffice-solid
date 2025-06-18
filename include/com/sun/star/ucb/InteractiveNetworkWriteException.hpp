#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKWRITEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKWRITEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveNetworkWriteException.hdl"

#include "com/sun/star/ucb/InteractiveNetworkException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveNetworkWriteException::InteractiveNetworkWriteException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveNetworkException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Diagnostic()
{
    ::cppu::UnoType< ::css::ucb::InteractiveNetworkWriteException >::get();
}

inline InteractiveNetworkWriteException::InteractiveNetworkWriteException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& Diagnostic_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveNetworkException(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Diagnostic(Diagnostic_)
{
    ::cppu::UnoType< ::css::ucb::InteractiveNetworkWriteException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
InteractiveNetworkWriteException::InteractiveNetworkWriteException(InteractiveNetworkWriteException const & the_other): ::css::ucb::InteractiveNetworkException(the_other), Diagnostic(the_other.Diagnostic) {}

InteractiveNetworkWriteException::~InteractiveNetworkWriteException() {}

InteractiveNetworkWriteException & InteractiveNetworkWriteException::operator =(InteractiveNetworkWriteException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::InteractiveNetworkException::operator =(the_other);
    Diagnostic = the_other.Diagnostic;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theInteractiveNetworkWriteExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theInteractiveNetworkWriteExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.InteractiveNetworkWriteException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::ucb::InteractiveNetworkException >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "string" );
        ::rtl::OUString sMemberName0( "Diagnostic" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveNetworkWriteException const *) {
    return *detail::theInteractiveNetworkWriteExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveNetworkWriteException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveNetworkWriteException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKWRITEEXCEPTION_HPP
