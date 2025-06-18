#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEFILEIOEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEFILEIOEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveFileIOException.hdl"

#include "com/sun/star/ucb/InteractiveIOException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveFileIOException::InteractiveFileIOException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveIOException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , FileName()
{
    ::cppu::UnoType< ::css::ucb::InteractiveFileIOException >::get();
}

inline InteractiveFileIOException::InteractiveFileIOException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::css::ucb::IOErrorCode& Code_, const ::rtl::OUString& FileName_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveIOException(Message_, Context_, Classification_, Code_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , FileName(FileName_)
{
    ::cppu::UnoType< ::css::ucb::InteractiveFileIOException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
InteractiveFileIOException::InteractiveFileIOException(InteractiveFileIOException const & the_other): ::css::ucb::InteractiveIOException(the_other), FileName(the_other.FileName) {}

InteractiveFileIOException::~InteractiveFileIOException() {}

InteractiveFileIOException & InteractiveFileIOException::operator =(InteractiveFileIOException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::InteractiveIOException::operator =(the_other);
    FileName = the_other.FileName;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theInteractiveFileIOExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theInteractiveFileIOExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.InteractiveFileIOException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::ucb::InteractiveIOException >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "string" );
        ::rtl::OUString sMemberName0( "FileName" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveFileIOException const *) {
    return *detail::theInteractiveFileIOExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveFileIOException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveFileIOException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVEFILEIOEXCEPTION_HPP
