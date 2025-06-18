#ifndef INCLUDED_COM_SUN_STAR_UCB_URLAUTHENTICATIONREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_URLAUTHENTICATIONREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/URLAuthenticationRequest.hdl"

#include "com/sun/star/ucb/AuthenticationRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline URLAuthenticationRequest::URLAuthenticationRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::ucb::AuthenticationRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , URL()
{
    ::cppu::UnoType< ::css::ucb::URLAuthenticationRequest >::get();
}

inline URLAuthenticationRequest::URLAuthenticationRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& ServerName_, const ::rtl::OUString& Diagnostic_, const ::sal_Bool& HasRealm_, const ::rtl::OUString& Realm_, const ::sal_Bool& HasUserName_, const ::rtl::OUString& UserName_, const ::sal_Bool& HasPassword_, const ::rtl::OUString& Password_, const ::sal_Bool& HasAccount_, const ::rtl::OUString& Account_, const ::rtl::OUString& URL_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::ucb::AuthenticationRequest(Message_, Context_, Classification_, ServerName_, Diagnostic_, HasRealm_, Realm_, HasUserName_, UserName_, HasPassword_, Password_, HasAccount_, Account_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , URL(URL_)
{
    ::cppu::UnoType< ::css::ucb::URLAuthenticationRequest >::get();
}

#if !defined LIBO_INTERNAL_ONLY
URLAuthenticationRequest::URLAuthenticationRequest(URLAuthenticationRequest const & the_other): ::css::ucb::AuthenticationRequest(the_other), URL(the_other.URL) {}

URLAuthenticationRequest::~URLAuthenticationRequest() {}

URLAuthenticationRequest & URLAuthenticationRequest::operator =(URLAuthenticationRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::AuthenticationRequest::operator =(the_other);
    URL = the_other.URL;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theURLAuthenticationRequestType : public rtl::StaticWithInit< ::css::uno::Type *, theURLAuthenticationRequestType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.URLAuthenticationRequest" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::ucb::AuthenticationRequest >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "string" );
        ::rtl::OUString sMemberName0( "URL" );
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::URLAuthenticationRequest const *) {
    return *detail::theURLAuthenticationRequestType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::URLAuthenticationRequest const *) {
    return ::cppu::UnoType< ::css::ucb::URLAuthenticationRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_URLAUTHENTICATIONREQUEST_HPP
