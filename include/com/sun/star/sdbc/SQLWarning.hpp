#ifndef INCLUDED_COM_SUN_STAR_SDBC_SQLWARNING_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_SQLWARNING_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/SQLWarning.hdl"

#include "com/sun/star/sdbc/SQLException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace sdbc {

inline SQLWarning::SQLWarning(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::sdbc::SQLException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::sdbc::SQLWarning >::get();
}

inline SQLWarning::SQLWarning(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& SQLState_, const ::sal_Int32& ErrorCode_, const ::css::uno::Any& NextException_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::sdbc::SQLException(Message_, Context_, SQLState_, ErrorCode_, NextException_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::sdbc::SQLWarning >::get();
}

#if !defined LIBO_INTERNAL_ONLY
SQLWarning::SQLWarning(SQLWarning const & the_other): ::css::sdbc::SQLException(the_other) {}

SQLWarning::~SQLWarning() {}

SQLWarning & SQLWarning::operator =(SQLWarning const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::sdbc::SQLException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace sdbc { namespace detail {

struct theSQLWarningType : public rtl::StaticWithInit< ::css::uno::Type *, theSQLWarningType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.sdbc.SQLWarning" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::sdbc::SQLException >::get();

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

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::SQLWarning const *) {
    return *detail::theSQLWarningType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdbc::SQLWarning const *) {
    return ::cppu::UnoType< ::css::sdbc::SQLWarning >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_SQLWARNING_HPP
