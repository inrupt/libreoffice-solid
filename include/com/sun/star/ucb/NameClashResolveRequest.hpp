#ifndef INCLUDED_COM_SUN_STAR_UCB_NAMECLASHRESOLVEREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_NAMECLASHRESOLVEREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/NameClashResolveRequest.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline NameClashResolveRequest::NameClashResolveRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , TargetFolderURL()
    , ClashingName()
    , ProposedNewName()
{
    ::cppu::UnoType< ::css::ucb::NameClashResolveRequest >::get();
}

inline NameClashResolveRequest::NameClashResolveRequest(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& TargetFolderURL_, const ::rtl::OUString& ClashingName_, const ::rtl::OUString& ProposedNewName_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , TargetFolderURL(TargetFolderURL_)
    , ClashingName(ClashingName_)
    , ProposedNewName(ProposedNewName_)
{
    ::cppu::UnoType< ::css::ucb::NameClashResolveRequest >::get();
}

#if !defined LIBO_INTERNAL_ONLY
NameClashResolveRequest::NameClashResolveRequest(NameClashResolveRequest const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), TargetFolderURL(the_other.TargetFolderURL), ClashingName(the_other.ClashingName), ProposedNewName(the_other.ProposedNewName) {}

NameClashResolveRequest::~NameClashResolveRequest() {}

NameClashResolveRequest & NameClashResolveRequest::operator =(NameClashResolveRequest const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    TargetFolderURL = the_other.TargetFolderURL;
    ClashingName = the_other.ClashingName;
    ProposedNewName = the_other.ProposedNewName;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theNameClashResolveRequestType : public rtl::StaticWithInit< ::css::uno::Type *, theNameClashResolveRequestType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.NameClashResolveRequest" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::task::ClassifiedInteractionRequest >::get();

        typelib_CompoundMember_Init aMembers[3];
        ::rtl::OUString sMemberType0( "string" );
        ::rtl::OUString sMemberName0( "TargetFolderURL" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[0].pTypeName = sMemberType0.pData;
        aMembers[0].pMemberName = sMemberName0.pData;
        ::rtl::OUString sMemberType1( "string" );
        ::rtl::OUString sMemberName1( "ClashingName" );
        aMembers[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[1].pTypeName = sMemberType1.pData;
        aMembers[1].pMemberName = sMemberName1.pData;
        ::rtl::OUString sMemberType2( "string" );
        ::rtl::OUString sMemberName2( "ProposedNewName" );
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::NameClashResolveRequest const *) {
    return *detail::theNameClashResolveRequestType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::NameClashResolveRequest const *) {
    return ::cppu::UnoType< ::css::ucb::NameClashResolveRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_NAMECLASHRESOLVEREQUEST_HPP
