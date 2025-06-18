#ifndef INCLUDED_COM_SUN_STAR_UCB_TRANSFERRESULT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_TRANSFERRESULT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/TransferResult.hdl"

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

inline TransferResult::TransferResult()
    : Source()
    , Target()
    , Result()
{
}

inline TransferResult::TransferResult(const ::rtl::OUString& Source_, const ::rtl::OUString& Target_, const ::css::uno::Any& Result_)
    : Source(Source_)
    , Target(Target_)
    , Result(Result_)
{
}


inline bool operator==(const TransferResult& the_lhs, const TransferResult& the_rhs)
{
    return the_lhs.Source == the_rhs.Source
        && the_lhs.Target == the_rhs.Target
        && the_lhs.Result == the_rhs.Result;
}

inline bool operator!=(const TransferResult& the_lhs, const TransferResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theTransferResultType : public rtl::StaticWithInit< ::css::uno::Type *, theTransferResultType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.TransferResult" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Source" );
        ::rtl::OUString the_name1( "Target" );
        ::rtl::OUString the_tname1( "any" );
        ::rtl::OUString the_name2( "Result" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_ANY, the_tname1.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::TransferResult const *) {
    return *detail::theTransferResultType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::TransferResult const *) {
    return ::cppu::UnoType< ::css::ucb::TransferResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_TRANSFERRESULT_HPP
