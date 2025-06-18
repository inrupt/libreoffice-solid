#ifndef INCLUDED_COM_SUN_STAR_UCB_CERTIFICATEVALIDATIONREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CERTIFICATEVALIDATIONREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/CertificateValidationRequest.hdl"

#include "com/sun/star/security/XCertificate.hpp"
#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline CertificateValidationRequest::CertificateValidationRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , CertificateValidity(0)
    , Certificate()
    , HostName()
{
    ::cppu::UnoType< ::css::ucb::CertificateValidationRequest >::get();
}

inline CertificateValidationRequest::CertificateValidationRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::sal_Int32& CertificateValidity_, const ::css::uno::Reference< ::css::security::XCertificate >& Certificate_, const ::rtl::OUString& HostName_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , CertificateValidity(CertificateValidity_)
    , Certificate(Certificate_)
    , HostName(HostName_)
{
    ::cppu::UnoType< ::css::ucb::CertificateValidationRequest >::get();
}

#if !defined LIBO_INTERNAL_ONLY
CertificateValidationRequest::CertificateValidationRequest(CertificateValidationRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), CertificateValidity(the_other.CertificateValidity), Certificate(the_other.Certificate), HostName(the_other.HostName) {}

CertificateValidationRequest::~CertificateValidationRequest() {}

CertificateValidationRequest & CertificateValidationRequest::operator =(CertificateValidationRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    CertificateValidity = the_other.CertificateValidity;
    Certificate = the_other.Certificate;
    HostName = the_other.HostName;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theCertificateValidationRequestType : public rtl::StaticWithInit< ::css::uno::Type *, theCertificateValidationRequestType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.CertificateValidationRequest" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::task::ClassifiedInteractionRequest >::get();
        ::cppu::UnoType< ::css::uno::Reference< ::css::security::XCertificate > >::get();

        typelib_CompoundMember_Init aMembers[3];
        ::rtl::OUString sMemberType0( "long" );
        ::rtl::OUString sMemberName0( "CertificateValidity" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
        aMembers[0].pTypeName = sMemberType0.pData;
        aMembers[0].pMemberName = sMemberName0.pData;
        ::rtl::OUString sMemberType1( "com.sun.star.security.XCertificate" );
        ::rtl::OUString sMemberName1( "Certificate" );
        aMembers[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_INTERFACE;
        aMembers[1].pTypeName = sMemberType1.pData;
        aMembers[1].pMemberName = sMemberName1.pData;
        ::rtl::OUString sMemberType2( "string" );
        ::rtl::OUString sMemberName2( "HostName" );
        aMembers[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[2].pTypeName = sMemberType2.pData;
        aMembers[2].pMemberName = sMemberName2.pData;

        typelib_typedescription_new(
            &pTD,
            (typelib_TypeClass)::css::uno::TypeClass_EXCEPTION, sTypeName.pData,
            rSuperType.getTypeLibType(),
            3,
            aMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );

        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_EXCEPTION, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::CertificateValidationRequest const *) {
    return *detail::theCertificateValidationRequestType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::CertificateValidationRequest const *) {
    return ::cppu::UnoType< ::css::ucb::CertificateValidationRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CERTIFICATEVALIDATIONREQUEST_HPP
