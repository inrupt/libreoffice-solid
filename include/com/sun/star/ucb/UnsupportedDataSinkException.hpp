#ifndef INCLUDED_COM_SUN_STAR_UCB_UNSUPPORTEDDATASINKEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_UNSUPPORTEDDATASINKEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/UnsupportedDataSinkException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline UnsupportedDataSinkException::UnsupportedDataSinkException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Sink()
{
    ::cppu::UnoType< ::css::ucb::UnsupportedDataSinkException >::get();
}

inline UnsupportedDataSinkException::UnsupportedDataSinkException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Reference< ::css::uno::XInterface >& Sink_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Sink(Sink_)
{
    ::cppu::UnoType< ::css::ucb::UnsupportedDataSinkException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
UnsupportedDataSinkException::UnsupportedDataSinkException(UnsupportedDataSinkException const & the_other): ::css::uno::Exception(the_other), Sink(the_other.Sink) {}

UnsupportedDataSinkException::~UnsupportedDataSinkException() {}

UnsupportedDataSinkException & UnsupportedDataSinkException::operator =(UnsupportedDataSinkException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    Sink = the_other.Sink;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theUnsupportedDataSinkExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theUnsupportedDataSinkExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.UnsupportedDataSinkException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::Exception >::get();
        ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "com.sun.star.uno.XInterface" );
        ::rtl::OUString sMemberName0( "Sink" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_INTERFACE;
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::UnsupportedDataSinkException const *) {
    return *detail::theUnsupportedDataSinkExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::UnsupportedDataSinkException const *) {
    return ::cppu::UnoType< ::css::ucb::UnsupportedDataSinkException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_UNSUPPORTEDDATASINKEXCEPTION_HPP
