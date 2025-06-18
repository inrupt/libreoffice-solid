#ifndef INCLUDED_COM_SUN_STAR_REGISTRY_INVALIDVALUEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_REGISTRY_INVALIDVALUEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/registry/InvalidValueException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace registry {

inline InvalidValueException::InvalidValueException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::registry::InvalidValueException >::get();
}

inline InvalidValueException::InvalidValueException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::registry::InvalidValueException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
InvalidValueException::InvalidValueException(InvalidValueException const & the_other): ::css::uno::Exception(the_other) {}

InvalidValueException::~InvalidValueException() {}

InvalidValueException & InvalidValueException::operator =(InvalidValueException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace registry { namespace detail {

struct theInvalidValueExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theInvalidValueExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.registry.InvalidValueException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::Exception >::get();

        typelib_typedescription_new(
            &pTD,
            (typelib_TypeClass)::css::uno::TypeClass_EXCEPTION, sTypeName.pData,
            rSuperType.getTypeLibType(),
            0,
            0 );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );

        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_EXCEPTION, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace registry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::registry::InvalidValueException const *) {
    return *detail::theInvalidValueExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::registry::InvalidValueException const *) {
    return ::cppu::UnoType< ::css::registry::InvalidValueException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REGISTRY_INVALIDVALUEEXCEPTION_HPP
