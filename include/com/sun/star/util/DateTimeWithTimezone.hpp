#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATETIMEWITHTIMEZONE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATETIMEWITHTIMEZONE_HPP

#include "sal/config.h"

#include "com/sun/star/util/DateTimeWithTimezone.hdl"

#include "com/sun/star/util/DateTime.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline DateTimeWithTimezone::DateTimeWithTimezone()
    : DateTimeInTZ()
    , Timezone(0)
{
}

inline DateTimeWithTimezone::DateTimeWithTimezone(const ::css::util::DateTime& DateTimeInTZ_, const ::sal_Int16& Timezone_)
    : DateTimeInTZ(DateTimeInTZ_)
    , Timezone(Timezone_)
{
}


inline bool operator==(const DateTimeWithTimezone& the_lhs, const DateTimeWithTimezone& the_rhs)
{
    return the_lhs.DateTimeInTZ == the_rhs.DateTimeInTZ
        && the_lhs.Timezone == the_rhs.Timezone;
}

inline bool operator!=(const DateTimeWithTimezone& the_lhs, const DateTimeWithTimezone& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theDateTimeWithTimezoneType : public rtl::StaticWithInit< ::css::uno::Type *, theDateTimeWithTimezoneType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.DateTimeWithTimezone" );
        ::cppu::UnoType< ::css::util::DateTime >::get();
        ::rtl::OUString the_tname0( "com.sun.star.util.DateTime" );
        ::rtl::OUString the_name0( "DateTimeInTZ" );
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::DateTimeWithTimezone const *) {
    return *detail::theDateTimeWithTimezoneType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::DateTimeWithTimezone const *) {
    return ::cppu::UnoType< ::css::util::DateTimeWithTimezone >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATETIMEWITHTIMEZONE_HPP
