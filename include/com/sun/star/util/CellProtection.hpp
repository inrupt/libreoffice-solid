#ifndef INCLUDED_COM_SUN_STAR_UTIL_CELLPROTECTION_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_CELLPROTECTION_HPP

#include "sal/config.h"

#include "com/sun/star/util/CellProtection.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline CellProtection::CellProtection()
    : IsLocked(false)
    , IsFormulaHidden(false)
    , IsHidden(false)
    , IsPrintHidden(false)
{
}

inline CellProtection::CellProtection(const ::sal_Bool& IsLocked_, const ::sal_Bool& IsFormulaHidden_, const ::sal_Bool& IsHidden_, const ::sal_Bool& IsPrintHidden_)
    : IsLocked(IsLocked_)
    , IsFormulaHidden(IsFormulaHidden_)
    , IsHidden(IsHidden_)
    , IsPrintHidden(IsPrintHidden_)
{
}


inline bool operator==(const CellProtection& the_lhs, const CellProtection& the_rhs)
{
    return the_lhs.IsLocked == the_rhs.IsLocked
        && the_lhs.IsFormulaHidden == the_rhs.IsFormulaHidden
        && the_lhs.IsHidden == the_rhs.IsHidden
        && the_lhs.IsPrintHidden == the_rhs.IsPrintHidden;
}

inline bool operator!=(const CellProtection& the_lhs, const CellProtection& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theCellProtectionType : public rtl::StaticWithInit< ::css::uno::Type *, theCellProtectionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.CellProtection" );
        ::rtl::OUString the_tname0( "boolean" );
        ::rtl::OUString the_name0( "IsLocked" );
        ::rtl::OUString the_name1( "IsFormulaHidden" );
        ::rtl::OUString the_name2( "IsHidden" );
        ::rtl::OUString the_name3( "IsPrintHidden" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_BOOLEAN, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname0.pData, the_name2.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname0.pData, the_name3.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 4, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::CellProtection const *) {
    return *detail::theCellProtectionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::CellProtection const *) {
    return ::cppu::UnoType< ::css::util::CellProtection >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_CELLPROTECTION_HPP
