#ifndef INCLUDED_COM_SUN_STAR_LANG_ILLEGALARGUMENTEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_LANG_ILLEGALARGUMENTEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/lang/IllegalArgumentException.hdl"

#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace lang {

inline IllegalArgumentException::IllegalArgumentException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::uno::RuntimeException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , ArgumentPosition(0)
{
    ::cppu::UnoType< ::css::lang::IllegalArgumentException >::get();
}

inline IllegalArgumentException::IllegalArgumentException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int16& ArgumentPosition_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::uno::RuntimeException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , ArgumentPosition(ArgumentPosition_)
{
    ::cppu::UnoType< ::css::lang::IllegalArgumentException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
IllegalArgumentException::IllegalArgumentException(IllegalArgumentException const & the_other): ::css::uno::RuntimeException(the_other), ArgumentPosition(the_other.ArgumentPosition) {}

IllegalArgumentException::~IllegalArgumentException() {}

IllegalArgumentException & IllegalArgumentException::operator =(IllegalArgumentException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::RuntimeException::operator =(the_other);
    ArgumentPosition = the_other.ArgumentPosition;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace lang { namespace detail {

struct theIllegalArgumentExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theIllegalArgumentExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.lang.IllegalArgumentException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::RuntimeException >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "short" );
        ::rtl::OUString sMemberName0( "ArgumentPosition" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SHORT;
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::lang::IllegalArgumentException const *) {
    return *detail::theIllegalArgumentExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::lang::IllegalArgumentException const *) {
    return ::cppu::UnoType< ::css::lang::IllegalArgumentException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LANG_ILLEGALARGUMENTEXCEPTION_HPP
