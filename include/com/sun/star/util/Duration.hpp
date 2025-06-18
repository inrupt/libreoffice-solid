#ifndef INCLUDED_COM_SUN_STAR_UTIL_DURATION_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DURATION_HPP

#include "sal/config.h"

#include "com/sun/star/util/Duration.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline Duration::Duration()
    : Negative(false)
    , Years(0)
    , Months(0)
    , Days(0)
    , Hours(0)
    , Minutes(0)
    , Seconds(0)
    , NanoSeconds(0)
{
}

inline Duration::Duration(const ::sal_Bool& Negative_, const ::sal_uInt16& Years_, const ::sal_uInt16& Months_, const ::sal_uInt16& Days_, const ::sal_uInt16& Hours_, const ::sal_uInt16& Minutes_, const ::sal_uInt16& Seconds_, const ::sal_uInt32& NanoSeconds_)
    : Negative(Negative_)
    , Years(Years_)
    , Months(Months_)
    , Days(Days_)
    , Hours(Hours_)
    , Minutes(Minutes_)
    , Seconds(Seconds_)
    , NanoSeconds(NanoSeconds_)
{
}


inline bool operator==(const Duration& the_lhs, const Duration& the_rhs)
{
    return the_lhs.Negative == the_rhs.Negative
        && the_lhs.Years == the_rhs.Years
        && the_lhs.Months == the_rhs.Months
        && the_lhs.Days == the_rhs.Days
        && the_lhs.Hours == the_rhs.Hours
        && the_lhs.Minutes == the_rhs.Minutes
        && the_lhs.Seconds == the_rhs.Seconds
        && the_lhs.NanoSeconds == the_rhs.NanoSeconds;
}

inline bool operator!=(const Duration& the_lhs, const Duration& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theDurationType : public rtl::StaticWithInit< ::css::uno::Type *, theDurationType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.Duration" );
        ::rtl::OUString the_tname0( "boolean" );
        ::rtl::OUString the_name0( "Negative" );
        ::rtl::OUString the_tname1( "unsigned short" );
        ::rtl::OUString the_name1( "Years" );
        ::rtl::OUString the_name2( "Months" );
        ::rtl::OUString the_name3( "Days" );
        ::rtl::OUString the_name4( "Hours" );
        ::rtl::OUString the_name5( "Minutes" );
        ::rtl::OUString the_name6( "Seconds" );
        ::rtl::OUString the_tname2( "unsigned long" );
        ::rtl::OUString the_name7( "NanoSeconds" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_BOOLEAN, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name2.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name3.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name4.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name5.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name6.pData }, false },
            { { typelib_TypeClass_UNSIGNED_LONG, the_tname2.pData, the_name7.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 8, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::Duration const *) {
    return *detail::theDurationType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::Duration const *) {
    return ::cppu::UnoType< ::css::util::Duration >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DURATION_HPP
