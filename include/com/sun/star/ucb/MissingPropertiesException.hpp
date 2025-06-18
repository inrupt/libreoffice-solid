#ifndef INCLUDED_COM_SUN_STAR_UCB_MISSINGPROPERTIESEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_MISSINGPROPERTIESEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/MissingPropertiesException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline MissingPropertiesException::MissingPropertiesException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Properties()
{
    ::cppu::UnoType< ::css::ucb::MissingPropertiesException >::get();
}

inline MissingPropertiesException::MissingPropertiesException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::uno::Sequence< ::rtl::OUString >& Properties_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Properties(Properties_)
{
    ::cppu::UnoType< ::css::ucb::MissingPropertiesException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
MissingPropertiesException::MissingPropertiesException(MissingPropertiesException const & the_other): ::css::uno::Exception(the_other), Properties(the_other.Properties) {}

MissingPropertiesException::~MissingPropertiesException() {}

MissingPropertiesException & MissingPropertiesException::operator =(MissingPropertiesException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    Properties = the_other.Properties;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theMissingPropertiesExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theMissingPropertiesExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.MissingPropertiesException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::Exception >::get();
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get();

        typelib_CompoundMember_Init aMembers[1];
        ::rtl::OUString sMemberType0( "[]string" );
        ::rtl::OUString sMemberName0( "Properties" );
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::MissingPropertiesException const *) {
    return *detail::theMissingPropertiesExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::MissingPropertiesException const *) {
    return ::cppu::UnoType< ::css::ucb::MissingPropertiesException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_MISSINGPROPERTIESEXCEPTION_HPP
