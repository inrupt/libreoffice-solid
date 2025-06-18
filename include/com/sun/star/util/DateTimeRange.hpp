#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATETIMERANGE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATETIMERANGE_HPP

#include "sal/config.h"

#include "com/sun/star/util/DateTimeRange.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline DateTimeRange::DateTimeRange()
    : StartNanoSeconds(0)
    , StartSeconds(0)
    , StartMinutes(0)
    , StartHours(0)
    , StartDay(0)
    , StartMonth(0)
    , StartYear(0)
    , EndNanoSeconds(0)
    , EndSeconds(0)
    , EndMinutes(0)
    , EndHours(0)
    , EndDay(0)
    , EndMonth(0)
    , EndYear(0)
    , IsUTC(false)
{
}

inline DateTimeRange::DateTimeRange(const ::sal_uInt32& StartNanoSeconds_, const ::sal_uInt16& StartSeconds_, const ::sal_uInt16& StartMinutes_, const ::sal_uInt16& StartHours_, const ::sal_uInt16& StartDay_, const ::sal_uInt16& StartMonth_, const ::sal_Int16& StartYear_, const ::sal_uInt32& EndNanoSeconds_, const ::sal_uInt16& EndSeconds_, const ::sal_uInt16& EndMinutes_, const ::sal_uInt16& EndHours_, const ::sal_uInt16& EndDay_, const ::sal_uInt16& EndMonth_, const ::sal_Int16& EndYear_, const ::sal_Bool& IsUTC_)
    : StartNanoSeconds(StartNanoSeconds_)
    , StartSeconds(StartSeconds_)
    , StartMinutes(StartMinutes_)
    , StartHours(StartHours_)
    , StartDay(StartDay_)
    , StartMonth(StartMonth_)
    , StartYear(StartYear_)
    , EndNanoSeconds(EndNanoSeconds_)
    , EndSeconds(EndSeconds_)
    , EndMinutes(EndMinutes_)
    , EndHours(EndHours_)
    , EndDay(EndDay_)
    , EndMonth(EndMonth_)
    , EndYear(EndYear_)
    , IsUTC(IsUTC_)
{
}


inline bool operator==(const DateTimeRange& the_lhs, const DateTimeRange& the_rhs)
{
    return the_lhs.StartNanoSeconds == the_rhs.StartNanoSeconds
        && the_lhs.StartSeconds == the_rhs.StartSeconds
        && the_lhs.StartMinutes == the_rhs.StartMinutes
        && the_lhs.StartHours == the_rhs.StartHours
        && the_lhs.StartDay == the_rhs.StartDay
        && the_lhs.StartMonth == the_rhs.StartMonth
        && the_lhs.StartYear == the_rhs.StartYear
        && the_lhs.EndNanoSeconds == the_rhs.EndNanoSeconds
        && the_lhs.EndSeconds == the_rhs.EndSeconds
        && the_lhs.EndMinutes == the_rhs.EndMinutes
        && the_lhs.EndHours == the_rhs.EndHours
        && the_lhs.EndDay == the_rhs.EndDay
        && the_lhs.EndMonth == the_rhs.EndMonth
        && the_lhs.EndYear == the_rhs.EndYear
        && the_lhs.IsUTC == the_rhs.IsUTC;
}

inline bool operator!=(const DateTimeRange& the_lhs, const DateTimeRange& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theDateTimeRangeType : public rtl::StaticWithInit< ::css::uno::Type *, theDateTimeRangeType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.DateTimeRange" );
        ::rtl::OUString the_tname0( "unsigned long" );
        ::rtl::OUString the_name0( "StartNanoSeconds" );
        ::rtl::OUString the_tname1( "unsigned short" );
        ::rtl::OUString the_name1( "StartSeconds" );
        ::rtl::OUString the_name2( "StartMinutes" );
        ::rtl::OUString the_name3( "StartHours" );
        ::rtl::OUString the_name4( "StartDay" );
        ::rtl::OUString the_name5( "StartMonth" );
        ::rtl::OUString the_tname2( "short" );
        ::rtl::OUString the_name6( "StartYear" );
        ::rtl::OUString the_name7( "EndNanoSeconds" );
        ::rtl::OUString the_name8( "EndSeconds" );
        ::rtl::OUString the_name9( "EndMinutes" );
        ::rtl::OUString the_name10( "EndHours" );
        ::rtl::OUString the_name11( "EndDay" );
        ::rtl::OUString the_name12( "EndMonth" );
        ::rtl::OUString the_name13( "EndYear" );
        ::rtl::OUString the_tname3( "boolean" );
        ::rtl::OUString the_name14( "IsUTC" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_UNSIGNED_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name2.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name3.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name4.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name5.pData }, false },
            { { typelib_TypeClass_SHORT, the_tname2.pData, the_name6.pData }, false },
            { { typelib_TypeClass_UNSIGNED_LONG, the_tname0.pData, the_name7.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name8.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name9.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name10.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name11.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name12.pData }, false },
            { { typelib_TypeClass_SHORT, the_tname2.pData, the_name13.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname3.pData, the_name14.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 15, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::DateTimeRange const *) {
    return *detail::theDateTimeRangeType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::DateTimeRange const *) {
    return ::cppu::UnoType< ::css::util::DateTimeRange >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATETIMERANGE_HPP
