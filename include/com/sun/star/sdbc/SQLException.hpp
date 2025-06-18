#ifndef INCLUDED_COM_SUN_STAR_SDBC_SQLEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_SQLEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/SQLException.hdl"

#include "com/sun/star/uno/Exception.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdbc {

inline SQLException::SQLException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::uno::Exception(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , SQLState()
    , ErrorCode(0)
    , NextException()
{
    ::cppu::UnoType< ::css::sdbc::SQLException >::get();
}

inline SQLException::SQLException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& SQLState_, const ::sal_Int32& ErrorCode_, const ::css::uno::Any& NextException_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::uno::Exception(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , SQLState(SQLState_)
    , ErrorCode(ErrorCode_)
    , NextException(NextException_)
{
    ::cppu::UnoType< ::css::sdbc::SQLException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
SQLException::SQLException(SQLException const & the_other): ::css::uno::Exception(the_other), SQLState(the_other.SQLState), ErrorCode(the_other.ErrorCode), NextException(the_other.NextException) {}

SQLException::~SQLException() {}

SQLException & SQLException::operator =(SQLException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::Exception::operator =(the_other);
    SQLState = the_other.SQLState;
    ErrorCode = the_other.ErrorCode;
    NextException = the_other.NextException;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace sdbc { namespace detail {

struct theSQLExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theSQLExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.sdbc.SQLException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::Exception >::get();

        typelib_CompoundMember_Init aMembers[3];
        ::rtl::OUString sMemberType0( "string" );
        ::rtl::OUString sMemberName0( "SQLState" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
        aMembers[0].pTypeName = sMemberType0.pData;
        aMembers[0].pMemberName = sMemberName0.pData;
        ::rtl::OUString sMemberType1( "long" );
        ::rtl::OUString sMemberName1( "ErrorCode" );
        aMembers[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
        aMembers[1].pTypeName = sMemberType1.pData;
        aMembers[1].pMemberName = sMemberName1.pData;
        ::rtl::OUString sMemberType2( "any" );
        ::rtl::OUString sMemberName2( "NextException" );
        aMembers[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
        aMembers[2].pTypeName = sMemberType2.pData;
        aMembers[2].pMemberName = sMemberName2.pData;

        typelib_typedescription_new(
            &pTD,
            (typelib_TypeClass)::css::uno::TypeClass_EXCEPTION, sTypeName.pData,
            rSuperType.getTypeLibType(),
            3,
            aMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );

        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_EXCEPTION, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::SQLException const *) {
    return *detail::theSQLExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdbc::SQLException const *) {
    return ::cppu::UnoType< ::css::sdbc::SQLException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_SQLEXCEPTION_HPP
