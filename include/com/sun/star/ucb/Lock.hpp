#ifndef INCLUDED_COM_SUN_STAR_UCB_LOCK_HPP
#define INCLUDED_COM_SUN_STAR_UCB_LOCK_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/Lock.hdl"

#include "com/sun/star/ucb/LockDepth.hpp"
#include "com/sun/star/ucb/LockEntry.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline Lock::Lock()
    : ::css::ucb::LockEntry()
    , Depth(::css::ucb::LockDepth_ZERO)
    , Owner()
    , Timeout(0)
    , LockTokens()
{
}

inline Lock::Lock(const ::css::ucb::LockScope& Scope_, const ::css::ucb::LockType& Type_, const ::css::ucb::LockDepth& Depth_, const ::css::uno::Any& Owner_, const ::sal_Int64& Timeout_, const ::css::uno::Sequence< ::rtl::OUString >& LockTokens_)
    : ::css::ucb::LockEntry(Scope_, Type_)
    , Depth(Depth_)
    , Owner(Owner_)
    , Timeout(Timeout_)
    , LockTokens(LockTokens_)
{
}


inline bool operator==(const Lock& the_lhs, const Lock& the_rhs)
{
    return operator==( static_cast<const ::css::ucb::LockEntry&>(the_lhs), static_cast<const ::css::ucb::LockEntry&>(the_rhs) )

        && the_lhs.Depth == the_rhs.Depth
        && the_lhs.Owner == the_rhs.Owner
        && the_lhs.Timeout == the_rhs.Timeout
        && the_lhs.LockTokens == the_rhs.LockTokens;
}

inline bool operator!=(const Lock& the_lhs, const Lock& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theLockType : public rtl::StaticWithInit< ::css::uno::Type *, theLockType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.Lock" );
        ::cppu::UnoType< ::css::ucb::LockDepth >::get();
        ::rtl::OUString the_tname0( "com.sun.star.ucb.LockDepth" );
        ::rtl::OUString the_name0( "Depth" );
        ::rtl::OUString the_tname1( "any" );
        ::rtl::OUString the_name1( "Owner" );
        ::rtl::OUString the_tname2( "hyper" );
        ::rtl::OUString the_name2( "Timeout" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get();
        ::rtl::OUString the_tname3( "[]string" );
        ::rtl::OUString the_name3( "LockTokens" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ENUM, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ANY, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_HYPER, the_tname2.pData, the_name2.pData }, false },
            { { typelib_TypeClass_SEQUENCE, the_tname3.pData, the_name3.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::ucb::LockEntry >::get().getTypeLibType(), 4, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::Lock const *) {
    return *detail::theLockType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::Lock const *) {
    return ::cppu::UnoType< ::css::ucb::Lock >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_LOCK_HPP
