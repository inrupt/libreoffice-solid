#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEAPPEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEAPPEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveAppException.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveAppException::InteractiveAppException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Code(0)
{
    ::cppu::UnoType< ::css::ucb::InteractiveAppException >::get();
}

inline InteractiveAppException::InteractiveAppException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::sal_uInt32& Code_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Code(Code_)
{
    ::cppu::UnoType< ::css::ucb::InteractiveAppException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
InteractiveAppException::InteractiveAppException(InteractiveAppException const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), Code(the_other.Code) {}

InteractiveAppException::~InteractiveAppException() {}

InteractiveAppException & InteractiveAppException::operator =(InteractiveAppException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    Code = the_other.Code;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theInteractiveAppExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theInteractiveAppExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.InteractiveAppException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::task::ClassifiedInteractionRequest >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "unsigned long" );
        ::rtl::OUString sMemberName0( "Code" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_UNSIGNED_LONG;
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveAppException const *) {
    return *detail::theInteractiveAppExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveAppException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveAppException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEAPPEXCEPTION_HPP
