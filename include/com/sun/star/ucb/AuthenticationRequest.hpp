#ifndef INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/AuthenticationRequest.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline AuthenticationRequest::AuthenticationRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , ServerName()
    , Diagnostic()
    , HasRealm(false)
    , Realm()
    , HasUserName(false)
    , UserName()
    , HasPassword(false)
    , Password()
    , HasAccount(false)
    , Account()
{
    ::cppu::UnoType< ::css::ucb::AuthenticationRequest >::get();
}

inline AuthenticationRequest::AuthenticationRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& ServerName_, const ::rtl::OUString& Diagnostic_, const ::sal_Bool& HasRealm_, const ::rtl::OUString& Realm_, const ::sal_Bool& HasUserName_, const ::rtl::OUString& UserName_, const ::sal_Bool& HasPassword_, const ::rtl::OUString& Password_, const ::sal_Bool& HasAccount_, const ::rtl::OUString& Account_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , ServerName(ServerName_)
    , Diagnostic(Diagnostic_)
    , HasRealm(HasRealm_)
    , Realm(Realm_)
    , HasUserName(HasUserName_)
    , UserName(UserName_)
    , HasPassword(HasPassword_)
    , Password(Password_)
    , HasAccount(HasAccount_)
    , Account(Account_)
{
    ::cppu::UnoType< ::css::ucb::AuthenticationRequest >::get();
}

#if !defined LIBO_INTERNAL_ONLY
AuthenticationRequest::AuthenticationRequest(AuthenticationRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), ServerName(the_other.ServerName), Diagnostic(the_other.Diagnostic), HasRealm(the_other.HasRealm), Realm(the_other.Realm), HasUserName(the_other.HasUserName), UserName(the_other.UserName), HasPassword(the_other.HasPassword), Password(the_other.Password), HasAccount(the_other.HasAccount), Account(the_other.Account) {}

AuthenticationRequest::~AuthenticationRequest() {}

AuthenticationRequest & AuthenticationRequest::operator =(AuthenticationRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    ServerName = the_other.ServerName;
    Diagnostic = the_other.Diagnostic;
    HasRealm = the_other.HasRealm;
    Realm = the_other.Realm;
    HasUserName = the_other.HasUserName;
    UserName = the_other.UserName;
    HasPassword = the_other.HasPassword;
    Password = the_other.Password;
    HasAccount = the_other.HasAccount;
    Account = the_other.Account;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theAuthenticationRequestType : public rtl::StaticWithInit< ::css::uno::Type *, theAuthenticationRequestType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.AuthenticationRequest" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::task::ClassifiedInteractionRequest >::get();

        typelib_CompoundMember_Init aMembers[10];
        ::rtl::OUString sMemberType0( "string" );
        ::rtl::OUString sMemberName0( "ServerName" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[0].pTypeName = sMemberType0.pData;
        aMembers[0].pMemberName = sMemberName0.pData;
        ::rtl::OUString sMemberType1( "string" );
        ::rtl::OUString sMemberName1( "Diagnostic" );
        aMembers[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[1].pTypeName = sMemberType1.pData;
        aMembers[1].pMemberName = sMemberName1.pData;
        ::rtl::OUString sMemberType2( "boolean" );
        ::rtl::OUString sMemberName2( "HasRealm" );
        aMembers[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
        aMembers[2].pTypeName = sMemberType2.pData;
        aMembers[2].pMemberName = sMemberName2.pData;
        ::rtl::OUString sMemberType3( "string" );
        ::rtl::OUString sMemberName3( "Realm" );
        aMembers[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[3].pTypeName = sMemberType3.pData;
        aMembers[3].pMemberName = sMemberName3.pData;
        ::rtl::OUString sMemberType4( "boolean" );
        ::rtl::OUString sMemberName4( "HasUserName" );
        aMembers[4].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
        aMembers[4].pTypeName = sMemberType4.pData;
        aMembers[4].pMemberName = sMemberName4.pData;
        ::rtl::OUString sMemberType5( "string" );
        ::rtl::OUString sMemberName5( "UserName" );
        aMembers[5].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[5].pTypeName = sMemberType5.pData;
        aMembers[5].pMemberName = sMemberName5.pData;
        ::rtl::OUString sMemberType6( "boolean" );
        ::rtl::OUString sMemberName6( "HasPassword" );
        aMembers[6].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
        aMembers[6].pTypeName = sMemberType6.pData;
        aMembers[6].pMemberName = sMemberName6.pData;
        ::rtl::OUString sMemberType7( "string" );
        ::rtl::OUString sMemberName7( "Password" );
        aMembers[7].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[7].pTypeName = sMemberType7.pData;
        aMembers[7].pMemberName = sMemberName7.pData;
        ::rtl::OUString sMemberType8( "boolean" );
        ::rtl::OUString sMemberName8( "HasAccount" );
        aMembers[8].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
        aMembers[8].pTypeName = sMemberType8.pData;
        aMembers[8].pMemberName = sMemberName8.pData;
        ::rtl::OUString sMemberType9( "string" );
        ::rtl::OUString sMemberName9( "Account" );
        aMembers[9].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[9].pTypeName = sMemberType9.pData;
        aMembers[9].pMemberName = sMemberName9.pData;

        typelib_typedescription_new(
            &pTD,
            (typelib_TypeClass)::css::uno::TypeClass_EXCEPTION, sTypeName.pData,
            rSuperType.getTypeLibType(),
            10,
            aMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );

        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_EXCEPTION, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::AuthenticationRequest const *) {
    return *detail::theAuthenticationRequestType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::AuthenticationRequest const *) {
    return ::cppu::UnoType< ::css::ucb::AuthenticationRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_AUTHENTICATIONREQUEST_HPP
