#ifndef INCLUDED_COM_SUN_STAR_UCB_FETCHRESULT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_FETCHRESULT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/FetchResult.hdl"

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

inline FetchResult::FetchResult()
    : Rows()
    , StartIndex(0)
    , Orientation(false)
    , FetchError(0)
{
}

inline FetchResult::FetchResult(const ::css::uno::Sequence< ::css::uno::Any >& Rows_, const ::sal_Int32& StartIndex_, const ::sal_Bool& Orientation_, const ::sal_Int16& FetchError_)
    : Rows(Rows_)
    , StartIndex(StartIndex_)
    , Orientation(Orientation_)
    , FetchError(FetchError_)
{
}


inline bool operator==(const FetchResult& the_lhs, const FetchResult& the_rhs)
{
    return the_lhs.Rows == the_rhs.Rows
        && the_lhs.StartIndex == the_rhs.StartIndex
        && the_lhs.Orientation == the_rhs.Orientation
        && the_lhs.FetchError == the_rhs.FetchError;
}

inline bool operator!=(const FetchResult& the_lhs, const FetchResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theFetchResultType : public rtl::StaticWithInit< ::css::uno::Type *, theFetchResultType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.FetchResult" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::uno::Any > >::get();
        ::rtl::OUString the_tname0( "[]any" );
        ::rtl::OUString the_name0( "Rows" );
        ::rtl::OUString the_tname1( "long" );
        ::rtl::OUString the_name1( "StartIndex" );
        ::rtl::OUString the_tname2( "boolean" );
        ::rtl::OUString the_name2( "Orientation" );
        ::rtl::OUString the_tname3( "short" );
        ::rtl::OUString the_name3( "FetchError" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_SEQUENCE, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname2.pData, the_name2.pData }, false },
            { { typelib_TypeClass_SHORT, the_tname3.pData, the_name3.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 4, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::FetchResult const *) {
    return *detail::theFetchResultType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::FetchResult const *) {
    return ::cppu::UnoType< ::css::ucb::FetchResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_FETCHRESULT_HPP
