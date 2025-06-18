#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATE_HPP

#include "sal/config.h"

#include "com/sun/star/util/Date.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline Date::Date()
    : Day(0)
    , Month(0)
    , Year(0)
{
}

inline Date::Date(const ::sal_uInt16& Day_, const ::sal_uInt16& Month_, const ::sal_Int16& Year_)
    : Day(Day_)
    , Month(Month_)
    , Year(Year_)
{
}


inline bool operator==(const Date& the_lhs, const Date& the_rhs)
{
    return the_lhs.Day == the_rhs.Day
        && the_lhs.Month == the_rhs.Month
        && the_lhs.Year == the_rhs.Year;
}

inline bool operator!=(const Date& the_lhs, const Date& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theDateType : public rtl::StaticWithInit< ::css::uno::Type *, theDateType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.Date" );
        ::rtl::OUString the_tname0( "unsigned short" );
        ::rtl::OUString the_name0( "Day" );
        ::rtl::OUString the_name1( "Month" );
        ::rtl::OUString the_tname1( "short" );
        ::rtl::OUString the_name2( "Year" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_UNSIGNED_SHORT, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_SHORT, the_tname1.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::Date const *) {
    return *detail::theDateType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::Date const *) {
    return ::cppu::UnoType< ::css::util::Date >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATE_HPP
