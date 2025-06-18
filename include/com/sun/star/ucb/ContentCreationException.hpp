#ifndef INCLUDED_COM_SUN_STAR_UCB_CONTENTCREATIONEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CONTENTCREATIONEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ContentCreationException.hdl"

#include "com/sun/star/ucb/ContentCreationError.hpp"
#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline ContentCreationException::ContentCreationException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , eError(::css::ucb::ContentCreationError_UNKNOWN)
{
    ::cppu::UnoType< ::css::ucb::ContentCreationException >::get();
}

inline ContentCreationException::ContentCreationException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::ucb::ContentCreationError& eError_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , eError(eError_)
{
    ::cppu::UnoType< ::css::ucb::ContentCreationException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
ContentCreationException::ContentCreationException(ContentCreationException const & the_other): ::css::uno::Exception(the_other), eError(the_other.eError) {}

ContentCreationException::~ContentCreationException() {}

ContentCreationException & ContentCreationException::operator =(ContentCreationException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    eError = the_other.eError;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theContentCreationExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theContentCreationExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.ContentCreationException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::Exception >::get();
        ::cppu::UnoType< ::css::ucb::ContentCreationError >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "com.sun.star.ucb.ContentCreationError" );
        ::rtl::OUString sMemberName0( "eError" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ENUM;
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ContentCreationException const *) {
    return *detail::theContentCreationExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ContentCreationException const *) {
    return ::cppu::UnoType< ::css::ucb::ContentCreationException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CONTENTCREATIONEXCEPTION_HPP
