#ifndef INCLUDED_COM_SUN_STAR_UCB_SEARCHCRITERIUM_HPP
#define INCLUDED_COM_SUN_STAR_UCB_SEARCHCRITERIUM_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/SearchCriterium.hdl"

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

inline SearchCriterium::SearchCriterium()
    : Terms()
{
}

inline SearchCriterium::SearchCriterium(const ::css::uno::Sequence< ::css::ucb::RuleTerm >& Terms_)
    : Terms(Terms_)
{
}


inline bool operator==(const SearchCriterium& the_lhs, const SearchCriterium& the_rhs)
{
    return the_lhs.Terms == the_rhs.Terms;
}

inline bool operator!=(const SearchCriterium& the_lhs, const SearchCriterium& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theSearchCriteriumType : public rtl::StaticWithInit< ::css::uno::Type *, theSearchCriteriumType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.SearchCriterium" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::RuleTerm > >::get();
        ::rtl::OUString the_tname0( "[]com.sun.star.ucb.RuleTerm" );
        ::rtl::OUString the_name0( "Terms" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_SEQUENCE, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::SearchCriterium const *) {
    return *detail::theSearchCriteriumType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::SearchCriterium const *) {
    return ::cppu::UnoType< ::css::ucb::SearchCriterium >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_SEARCHCRITERIUM_HPP
