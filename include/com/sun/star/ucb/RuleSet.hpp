#ifndef INCLUDED_COM_SUN_STAR_UCB_RULESET_HPP
#define INCLUDED_COM_SUN_STAR_UCB_RULESET_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/RuleSet.hdl"

#include "com/sun/star/ucb/Rule.hpp"
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

inline RuleSet::RuleSet()
    : Rules()
    , HandleFolder(false)
{
}

inline RuleSet::RuleSet(const ::css::uno::Sequence< ::css::ucb::Rule >& Rules_, const ::sal_Bool& HandleFolder_)
    : Rules(Rules_)
    , HandleFolder(HandleFolder_)
{
}


inline bool operator==(const RuleSet& the_lhs, const RuleSet& the_rhs)
{
    return the_lhs.Rules == the_rhs.Rules
        && the_lhs.HandleFolder == the_rhs.HandleFolder;
}

inline bool operator!=(const RuleSet& the_lhs, const RuleSet& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theRuleSetType : public rtl::StaticWithInit< ::css::uno::Type *, theRuleSetType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.RuleSet" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::Rule > >::get();
        ::rtl::OUString the_tname0( "[]com.sun.star.ucb.Rule" );
        ::rtl::OUString the_name0( "Rules" );
        ::rtl::OUString the_tname1( "boolean" );
        ::rtl::OUString the_name1( "HandleFolder" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_SEQUENCE, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::RuleSet const *) {
    return *detail::theRuleSetType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::RuleSet const *) {
    return ::cppu::UnoType< ::css::ucb::RuleSet >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_RULESET_HPP
