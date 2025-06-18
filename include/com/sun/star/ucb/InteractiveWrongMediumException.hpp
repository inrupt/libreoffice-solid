#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEWRONGMEDIUMEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEWRONGMEDIUMEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveWrongMediumException.hdl"

#include "com/sun/star/task/ClassifiedInteractionRequest.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveWrongMediumException::InteractiveWrongMediumException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Medium()
{
    ::cppu::UnoType< ::css::ucb::InteractiveWrongMediumException >::get();
}

inline InteractiveWrongMediumException::InteractiveWrongMediumException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::css::uno::Any& Medium_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::task::ClassifiedInteractionRequest(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Medium(Medium_)
{
    ::cppu::UnoType< ::css::ucb::InteractiveWrongMediumException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
InteractiveWrongMediumException::InteractiveWrongMediumException(InteractiveWrongMediumException const & the_other): ::css::task::ClassifiedInteractionRequest(the_other), Medium(the_other.Medium) {}

InteractiveWrongMediumException::~InteractiveWrongMediumException() {}

InteractiveWrongMediumException & InteractiveWrongMediumException::operator =(InteractiveWrongMediumException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::task::ClassifiedInteractionRequest::operator =(the_other);
    Medium = the_other.Medium;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theInteractiveWrongMediumExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theInteractiveWrongMediumExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.InteractiveWrongMediumException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::task::ClassifiedInteractionRequest >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "any" );
        ::rtl::OUString sMemberName0( "Medium" );
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveWrongMediumException const *) {
    return *detail::theInteractiveWrongMediumExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveWrongMediumException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveWrongMediumException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEWRONGMEDIUMEXCEPTION_HPP
