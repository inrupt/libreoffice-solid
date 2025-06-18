#ifndef INCLUDED_COM_SUN_STAR_REFLECTION_INVOCATIONTARGETEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_REFLECTION_INVOCATIONTARGETEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/reflection/InvocationTargetException.hdl"

#include "com/sun/star/lang/WrappedTargetException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace reflection {

inline InvocationTargetException::InvocationTargetException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::lang::WrappedTargetException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::reflection::InvocationTargetException >::get();
}

inline InvocationTargetException::InvocationTargetException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& TargetException_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::lang::WrappedTargetException(Message_, Context_, TargetException_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::reflection::InvocationTargetException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
InvocationTargetException::InvocationTargetException(InvocationTargetException const & the_other): ::css::lang::WrappedTargetException(the_other) {}

InvocationTargetException::~InvocationTargetException() {}

InvocationTargetException & InvocationTargetException::operator =(InvocationTargetException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::lang::WrappedTargetException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace reflection { namespace detail {

struct theInvocationTargetExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theInvocationTargetExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.reflection.InvocationTargetException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::lang::WrappedTargetException >::get();

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

namespace com { namespace sun { namespace star { namespace reflection {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::reflection::InvocationTargetException const *) {
    return *detail::theInvocationTargetExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::reflection::InvocationTargetException const *) {
    return ::cppu::UnoType< ::css::reflection::InvocationTargetException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_REFLECTION_INVOCATIONTARGETEXCEPTION_HPP
