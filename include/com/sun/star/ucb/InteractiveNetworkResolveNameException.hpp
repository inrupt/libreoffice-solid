#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKRESOLVENAMEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKRESOLVENAMEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveNetworkResolveNameException.hdl"

#include "com/sun/star/ucb/InteractiveNetworkException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveNetworkResolveNameException::InteractiveNetworkResolveNameException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveNetworkException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Server()
{
    ::cppu::UnoType< ::css::ucb::InteractiveNetworkResolveNameException >::get();
}

inline InteractiveNetworkResolveNameException::InteractiveNetworkResolveNameException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& Server_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveNetworkException(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Server(Server_)
{
    ::cppu::UnoType< ::css::ucb::InteractiveNetworkResolveNameException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
InteractiveNetworkResolveNameException::InteractiveNetworkResolveNameException(InteractiveNetworkResolveNameException const & the_other): ::css::ucb::InteractiveNetworkException(the_other), Server(the_other.Server) {}

InteractiveNetworkResolveNameException::~InteractiveNetworkResolveNameException() {}

InteractiveNetworkResolveNameException & InteractiveNetworkResolveNameException::operator =(InteractiveNetworkResolveNameException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::InteractiveNetworkException::operator =(the_other);
    Server = the_other.Server;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theInteractiveNetworkResolveNameExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theInteractiveNetworkResolveNameExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.InteractiveNetworkResolveNameException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::ucb::InteractiveNetworkException >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "string" );
        ::rtl::OUString sMemberName0( "Server" );
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveNetworkResolveNameException const *) {
    return *detail::theInteractiveNetworkResolveNameExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveNetworkResolveNameException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveNetworkResolveNameException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKRESOLVENAMEEXCEPTION_HPP
