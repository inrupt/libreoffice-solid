#ifndef INCLUDED_COM_SUN_STAR_UCB_UNSUPPORTEDNAMECLASHEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_UNSUPPORTEDNAMECLASHEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/UnsupportedNameClashException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline UnsupportedNameClashException::UnsupportedNameClashException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , NameClash(0)
{
    ::cppu::UnoType< ::css::ucb::UnsupportedNameClashException >::get();
}

inline UnsupportedNameClashException::UnsupportedNameClashException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::sal_Int32& NameClash_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , NameClash(NameClash_)
{
    ::cppu::UnoType< ::css::ucb::UnsupportedNameClashException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
UnsupportedNameClashException::UnsupportedNameClashException(UnsupportedNameClashException const & the_other): ::css::uno::Exception(the_other), NameClash(the_other.NameClash) {}

UnsupportedNameClashException::~UnsupportedNameClashException() {}

UnsupportedNameClashException & UnsupportedNameClashException::operator =(UnsupportedNameClashException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    NameClash = the_other.NameClash;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theUnsupportedNameClashExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theUnsupportedNameClashExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.UnsupportedNameClashException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::Exception >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "long" );
        ::rtl::OUString sMemberName0( "NameClash" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::UnsupportedNameClashException const *) {
    return *detail::theUnsupportedNameClashExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::UnsupportedNameClashException const *) {
    return ::cppu::UnoType< ::css::ucb::UnsupportedNameClashException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_UNSUPPORTEDNAMECLASHEXCEPTION_HPP
