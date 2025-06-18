#ifndef INCLUDED_COM_SUN_STAR_UTIL_SEARCHRESULT_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_SEARCHRESULT_HPP

#include "sal/config.h"

#include "com/sun/star/util/SearchResult.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline SearchResult::SearchResult()
    : subRegExpressions(0)
    , startOffset()
    , endOffset()
{
}

inline SearchResult::SearchResult(const ::sal_Int32& subRegExpressions_, const ::css::uno::Sequence< ::sal_Int32 >& startOffset_, const ::css::uno::Sequence< ::sal_Int32 >& endOffset_)
    : subRegExpressions(subRegExpressions_)
    , startOffset(startOffset_)
    , endOffset(endOffset_)
{
}


inline bool operator==(const SearchResult& the_lhs, const SearchResult& the_rhs)
{
    return the_lhs.subRegExpressions == the_rhs.subRegExpressions
        && the_lhs.startOffset == the_rhs.startOffset
        && the_lhs.endOffset == the_rhs.endOffset;
}

inline bool operator!=(const SearchResult& the_lhs, const SearchResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theSearchResultType : public rtl::StaticWithInit< ::css::uno::Type *, theSearchResultType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.SearchResult" );
        ::rtl::OUString the_tname0( "long" );
        ::rtl::OUString the_name0( "subRegExpressions" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::sal_Int32 > >::get();
        ::rtl::OUString the_tname1( "[]long" );
        ::rtl::OUString the_name1( "startOffset" );
        ::rtl::OUString the_name2( "endOffset" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_SEQUENCE, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_SEQUENCE, the_tname1.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::SearchResult const *) {
    return *detail::theSearchResultType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::SearchResult const *) {
    return ::cppu::UnoType< ::css::util::SearchResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_SEARCHRESULT_HPP
