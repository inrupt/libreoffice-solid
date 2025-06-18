#ifndef INCLUDED_COM_SUN_STAR_UCB_RULETERM_HPP
#define INCLUDED_COM_SUN_STAR_UCB_RULETERM_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/RuleTerm.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline RuleTerm::RuleTerm()
    : Property()
    , Operand()
    , Operator(0)
    , CaseSensitive(false)
    , RegularExpression(false)
{
}

inline RuleTerm::RuleTerm(const ::rtl::OUString& Property_, const ::css::uno::Any& Operand_, const ::sal_Int16& Operator_, const ::sal_Bool& CaseSensitive_, const ::sal_Bool& RegularExpression_)
    : Property(Property_)
    , Operand(Operand_)
    , Operator(Operator_)
    , CaseSensitive(CaseSensitive_)
    , RegularExpression(RegularExpression_)
{
}


inline bool operator==(const RuleTerm& the_lhs, const RuleTerm& the_rhs)
{
    return the_lhs.Property == the_rhs.Property
        && the_lhs.Operand == the_rhs.Operand
        && the_lhs.Operator == the_rhs.Operator
        && the_lhs.CaseSensitive == the_rhs.CaseSensitive
        && the_lhs.RegularExpression == the_rhs.RegularExpression;
}

inline bool operator!=(const RuleTerm& the_lhs, const RuleTerm& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theRuleTermType : public rtl::StaticWithInit< ::css::uno::Type *, theRuleTermType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.RuleTerm" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Property" );
        ::rtl::OUString the_tname1( "any" );
        ::rtl::OUString the_name1( "Operand" );
        ::rtl::OUString the_tname2( "short" );
        ::rtl::OUString the_name2( "Operator" );
        ::rtl::OUString the_tname3( "boolean" );
        ::rtl::OUString the_name3( "CaseSensitive" );
        ::rtl::OUString the_name4( "RegularExpression" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ANY, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_SHORT, the_tname2.pData, the_name2.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname3.pData, the_name3.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname3.pData, the_name4.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 5, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::RuleTerm const *) {
    return *detail::theRuleTermType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::RuleTerm const *) {
    return ::cppu::UnoType< ::css::ucb::RuleTerm >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_RULETERM_HPP
