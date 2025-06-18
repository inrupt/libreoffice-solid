#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATEWITHTIMEZONE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATEWITHTIMEZONE_HPP

#include "sal/config.h"

#include "com/sun/star/util/DateWithTimezone.hdl"

#include "com/sun/star/util/Date.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline DateWithTimezone::DateWithTimezone()
    : DateInTZ()
    , Timezone(0)
{
}

inline DateWithTimezone::DateWithTimezone(const ::css::util::Date& DateInTZ_, const ::sal_Int16& Timezone_)
    : DateInTZ(DateInTZ_)
    , Timezone(Timezone_)
{
}


inline bool operator==(const DateWithTimezone& the_lhs, const DateWithTimezone& the_rhs)
{
    return the_lhs.DateInTZ == the_rhs.DateInTZ
        && the_lhs.Timezone == the_rhs.Timezone;
}

inline bool operator!=(const DateWithTimezone& the_lhs, const DateWithTimezone& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theDateWithTimezoneType : public rtl::StaticWithInit< ::css::uno::Type *, theDateWithTimezoneType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.DateWithTimezone" );
        ::cppu::UnoType< ::css::util::Date >::get();
        ::rtl::OUString the_tname0( "com.sun.star.util.Date" );
        ::rtl::OUString the_name0( "DateInTZ" );
        ::rtl::OUString the_tname1( "short" );
        ::rtl::OUString the_name1( "Timezone" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRUCT, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_SHORT, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::DateWithTimezone const *) {
    return *detail::theDateWithTimezoneType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::DateWithTimezone const *) {
    return ::cppu::UnoType< ::css::util::DateWithTimezone >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATEWITHTIMEZONE_HPP
