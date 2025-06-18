#ifndef INCLUDED_COM_SUN_STAR_UTIL_TIME_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_TIME_HPP

#include "sal/config.h"

#include "com/sun/star/util/Time.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline Time::Time()
    : NanoSeconds(0)
    , Seconds(0)
    , Minutes(0)
    , Hours(0)
    , IsUTC(false)
{
}

inline Time::Time(const ::sal_uInt32& NanoSeconds_, const ::sal_uInt16& Seconds_, const ::sal_uInt16& Minutes_, const ::sal_uInt16& Hours_, const ::sal_Bool& IsUTC_)
    : NanoSeconds(NanoSeconds_)
    , Seconds(Seconds_)
    , Minutes(Minutes_)
    , Hours(Hours_)
    , IsUTC(IsUTC_)
{
}


inline bool operator==(const Time& the_lhs, const Time& the_rhs)
{
    return the_lhs.NanoSeconds == the_rhs.NanoSeconds
        && the_lhs.Seconds == the_rhs.Seconds
        && the_lhs.Minutes == the_rhs.Minutes
        && the_lhs.Hours == the_rhs.Hours
        && the_lhs.IsUTC == the_rhs.IsUTC;
}

inline bool operator!=(const Time& the_lhs, const Time& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theTimeType : public rtl::StaticWithInit< ::css::uno::Type *, theTimeType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.Time" );
        ::rtl::OUString the_tname0( "unsigned long" );
        ::rtl::OUString the_name0( "NanoSeconds" );
        ::rtl::OUString the_tname1( "unsigned short" );
        ::rtl::OUString the_name1( "Seconds" );
        ::rtl::OUString the_name2( "Minutes" );
        ::rtl::OUString the_name3( "Hours" );
        ::rtl::OUString the_tname2( "boolean" );
        ::rtl::OUString the_name4( "IsUTC" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_UNSIGNED_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name2.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname1.pData, the_name3.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname2.pData, the_name4.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 5, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::Time const *) {
    return *detail::theTimeType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::Time const *) {
    return ::cppu::UnoType< ::css::util::Time >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_TIME_HPP
