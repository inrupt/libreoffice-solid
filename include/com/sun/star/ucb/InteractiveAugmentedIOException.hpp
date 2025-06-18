#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEAUGMENTEDIOEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEAUGMENTEDIOEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveAugmentedIOException.hdl"

#include "com/sun/star/ucb/InteractiveIOException.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveAugmentedIOException::InteractiveAugmentedIOException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveIOException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Arguments()
{
    ::cppu::UnoType< ::css::ucb::InteractiveAugmentedIOException >::get();
}

inline InteractiveAugmentedIOException::InteractiveAugmentedIOException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::css::ucb::IOErrorCode& Code_, const ::css::uno::Sequence< ::css::uno::Any >& Arguments_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveIOException(Message_, Context_, Classification_, Code_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Arguments(Arguments_)
{
    ::cppu::UnoType< ::css::ucb::InteractiveAugmentedIOException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
InteractiveAugmentedIOException::InteractiveAugmentedIOException(InteractiveAugmentedIOException const & the_other): ::css::ucb::InteractiveIOException(the_other), Arguments(the_other.Arguments) {}

InteractiveAugmentedIOException::~InteractiveAugmentedIOException() {}

InteractiveAugmentedIOException & InteractiveAugmentedIOException::operator =(InteractiveAugmentedIOException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::InteractiveIOException::operator =(the_other);
    Arguments = the_other.Arguments;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theInteractiveAugmentedIOExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theInteractiveAugmentedIOExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.InteractiveAugmentedIOException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::ucb::InteractiveIOException >::get();
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::uno::Any > >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "[]any" );
        ::rtl::OUString sMemberName0( "Arguments" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveAugmentedIOException const *) {
    return *detail::theInteractiveAugmentedIOExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveAugmentedIOException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveAugmentedIOException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEAUGMENTEDIOEXCEPTION_HPP
