#ifndef INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONFALLBACKREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONFALLBACKREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/AuthenticationFallbackRequest.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline AuthenticationFallbackRequest::AuthenticationFallbackRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , instructions()
    , url()
{
    ::cppu::UnoType< ::css::ucb::AuthenticationFallbackRequest >::get();
}

inline AuthenticationFallbackRequest::AuthenticationFallbackRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& instructions_, const ::rtl::OUString& url_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , instructions(instructions_)
    , url(url_)
{
    ::cppu::UnoType< ::css::ucb::AuthenticationFallbackRequest >::get();
}

#if !defined LIBO_INTERNAL_ONLY
AuthenticationFallbackRequest::AuthenticationFallbackRequest(AuthenticationFallbackRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), instructions(the_other.instructions), url(the_other.url) {}

AuthenticationFallbackRequest::~AuthenticationFallbackRequest() {}

AuthenticationFallbackRequest & AuthenticationFallbackRequest::operator =(AuthenticationFallbackRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    instructions = the_other.instructions;
    url = the_other.url;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theAuthenticationFallbackRequestType : public rtl::StaticWithInit< ::css::uno::Type *, theAuthenticationFallbackRequestType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.AuthenticationFallbackRequest" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::task::ClassifiedInteractionRequest >::get();

        typelib_CompoundMember_Init aMembers[2];
        ::rtl::OUString sMemberType0( "string" );
        ::rtl::OUString sMemberName0( "instructions" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[0].pTypeName = sMemberType0.pData;
        aMembers[0].pMemberName = sMemberName0.pData;
        ::rtl::OUString sMemberType1( "string" );
        ::rtl::OUString sMemberName1( "url" );
        aMembers[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[1].pTypeName = sMemberType1.pData;
        aMembers[1].pMemberName = sMemberName1.pData;

        typelib_typedescription_new(
            &pTD,
            (typelib_TypeClass)::css::uno::TypeClass_EXCEPTION, sTypeName.pData,
            rSuperType.getTypeLibType(),
            2,
            aMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );

        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_EXCEPTION, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::AuthenticationFallbackRequest const *) {
    return *detail::theAuthenticationFallbackRequestType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::AuthenticationFallbackRequest const *) {
    return ::cppu::UnoType< ::css::ucb::AuthenticationFallbackRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONFALLBACKREQUEST_HPP
