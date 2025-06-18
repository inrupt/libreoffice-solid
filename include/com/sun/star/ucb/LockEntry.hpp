#ifndef INCLUDED_COM_SUN_STAR_UCB_LOCKENTRY_HPP
#define INCLUDED_COM_SUN_STAR_UCB_LOCKENTRY_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/LockEntry.hdl"

#include "com/sun/star/ucb/LockScope.hpp"
#include "com/sun/star/ucb/LockType.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline LockEntry::LockEntry()
    : Scope(::css::ucb::LockScope_EXCLUSIVE)
    , Type(::css::ucb::LockType_WRITE)
{
}

inline LockEntry::LockEntry(const ::css::ucb::LockScope& Scope_, const ::css::ucb::LockType& Type_)
    : Scope(Scope_)
    , Type(Type_)
{
}


inline bool operator==(const LockEntry& the_lhs, const LockEntry& the_rhs)
{
    return the_lhs.Scope == the_rhs.Scope
        && the_lhs.Type == the_rhs.Type;
}

inline bool operator!=(const LockEntry& the_lhs, const LockEntry& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theLockEntryType : public rtl::StaticWithInit< ::css::uno::Type *, theLockEntryType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.LockEntry" );
        ::cppu::UnoType< ::css::ucb::LockScope >::get();
        ::rtl::OUString the_tname0( "com.sun.star.ucb.LockScope" );
        ::rtl::OUString the_name0( "Scope" );
        ::cppu::UnoType< ::css::ucb::LockType >::get();
        ::rtl::OUString the_tname1( "com.sun.star.ucb.LockType" );
        ::rtl::OUString the_name1( "Type" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ENUM, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ENUM, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::LockEntry const *) {
    return *detail::theLockEntryType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::LockEntry const *) {
    return ::cppu::UnoType< ::css::ucb::LockEntry >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_LOCKENTRY_HPP
