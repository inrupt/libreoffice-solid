#ifndef INCLUDED_COM_SUN_STAR_UCB_RULE_HPP
#define INCLUDED_COM_SUN_STAR_UCB_RULE_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/Rule.hdl"

#include "com/sun/star/ucb/RuleTerm.hpp"
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

inline Rule::Rule()
    : Terms()
    , Parameter()
    , Action(0)
{
}

inline Rule::Rule(const ::css::uno::Sequence< ::css::ucb::RuleTerm >& Terms_, const ::rtl::OUString& Parameter_, const ::sal_Int16& Action_)
    : Terms(Terms_)
    , Parameter(Parameter_)
    , Action(Action_)
{
}


inline bool operator==(const Rule& the_lhs, const Rule& the_rhs)
{
    return the_lhs.Terms == the_rhs.Terms
        && the_lhs.Parameter == the_rhs.Parameter
        && the_lhs.Action == the_rhs.Action;
}

inline bool operator!=(const Rule& the_lhs, const Rule& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theRuleType : public rtl::StaticWithInit< ::css::uno::Type *, theRuleType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.Rule" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::RuleTerm > >::get();
        ::rtl::OUString the_tname0( "[]com.sun.star.ucb.RuleTerm" );
        ::rtl::OUString the_name0( "Terms" );
        ::rtl::OUString the_tname1( "string" );
        ::rtl::OUString the_name1( "Parameter" );
        ::rtl::OUString the_tname2( "short" );
        ::rtl::OUString the_name2( "Action" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_SEQUENCE, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_SHORT, the_tname2.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::Rule const *) {
    return *detail::theRuleType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::Rule const *) {
    return ::cppu::UnoType< ::css::ucb::Rule >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_RULE_HPP
