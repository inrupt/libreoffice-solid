#ifndef INCLUDED_COM_SUN_STAR_LANG_WRAPPEDTARGETEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_LANG_WRAPPEDTARGETEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/lang/WrappedTargetException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace lang {

inline WrappedTargetException::WrappedTargetException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , TargetException()
{
    ::cppu::UnoType< ::css::lang::WrappedTargetException >::get();
}

inline WrappedTargetException::WrappedTargetException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Any& TargetException_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , TargetException(TargetException_)
{
    ::cppu::UnoType< ::css::lang::WrappedTargetException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
WrappedTargetException::WrappedTargetException(WrappedTargetException const & the_other): ::css::uno::Exception(the_other), TargetException(the_other.TargetException) {}

WrappedTargetException::~WrappedTargetException() {}

WrappedTargetException & WrappedTargetException::operator =(WrappedTargetException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    TargetException = the_other.TargetException;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace lang { namespace detail {

struct theWrappedTargetExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theWrappedTargetExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.lang.WrappedTargetException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::Exception >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "any" );
        ::rtl::OUString sMemberName0( "TargetException" );
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

namespace com { namespace sun { namespace star { namespace lang {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::lang::WrappedTargetException const *) {
    return *detail::theWrappedTargetExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::lang::WrappedTargetException const *) {
    return ::cppu::UnoType< ::css::lang::WrappedTargetException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LANG_WRAPPEDTARGETEXCEPTION_HPP
