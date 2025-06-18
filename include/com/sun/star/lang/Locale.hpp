#ifndef INCLUDED_COM_SUN_STAR_LANG_LOCALE_HPP
#define INCLUDED_COM_SUN_STAR_LANG_LOCALE_HPP

#include "sal/config.h"

#include "com/sun/star/lang/Locale.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace lang {

inline Locale::Locale()
    : Language()
    , Country()
    , Variant()
{
}

inline Locale::Locale(const ::rtl::OUString& Language_, const ::rtl::OUString& Country_, const ::rtl::OUString& Variant_)
    : Language(Language_)
    , Country(Country_)
    , Variant(Variant_)
{
}


inline bool operator==(const Locale& the_lhs, const Locale& the_rhs)
{
    return the_lhs.Language == the_rhs.Language
        && the_lhs.Country == the_rhs.Country
        && the_lhs.Variant == the_rhs.Variant;
}

inline bool operator!=(const Locale& the_lhs, const Locale& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace lang { namespace detail {

struct theLocaleType : public rtl::StaticWithInit< ::css::uno::Type *, theLocaleType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.lang.Locale" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Language" );
        ::rtl::OUString the_name1( "Country" );
        ::rtl::OUString the_name2( "Variant" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace lang {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::lang::Locale const *) {
    return *detail::theLocaleType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::lang::Locale const *) {
    return ::cppu::UnoType< ::css::lang::Locale >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LANG_LOCALE_HPP
