#ifndef INCLUDED_COM_SUN_STAR_UTIL_SEARCHOPTIONS_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_SEARCHOPTIONS_HPP

#include "sal/config.h"

#include "com/sun/star/util/SearchOptions.hdl"

#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/util/SearchAlgorithms.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline SearchOptions::SearchOptions()
    : algorithmType(::css::util::SearchAlgorithms_ABSOLUTE)
    , searchFlag(0)
    , searchString()
    , replaceString()
    , Locale()
    , changedChars(0)
    , deletedChars(0)
    , insertedChars(0)
    , transliterateFlags(0)
{
}

inline SearchOptions::SearchOptions(const ::css::util::SearchAlgorithms& algorithmType_, const ::sal_Int32& searchFlag_, const ::rtl::OUString& searchString_, const ::rtl::OUString& replaceString_, const ::css::lang::Locale& Locale_, const ::sal_Int32& changedChars_, const ::sal_Int32& deletedChars_, const ::sal_Int32& insertedChars_, const ::sal_Int32& transliterateFlags_)
    : algorithmType(algorithmType_)
    , searchFlag(searchFlag_)
    , searchString(searchString_)
    , replaceString(replaceString_)
    , Locale(Locale_)
    , changedChars(changedChars_)
    , deletedChars(deletedChars_)
    , insertedChars(insertedChars_)
    , transliterateFlags(transliterateFlags_)
{
}


inline bool operator==(const SearchOptions& the_lhs, const SearchOptions& the_rhs)
{
    return the_lhs.algorithmType == the_rhs.algorithmType
        && the_lhs.searchFlag == the_rhs.searchFlag
        && the_lhs.searchString == the_rhs.searchString
        && the_lhs.replaceString == the_rhs.replaceString
        && the_lhs.Locale == the_rhs.Locale
        && the_lhs.changedChars == the_rhs.changedChars
        && the_lhs.deletedChars == the_rhs.deletedChars
        && the_lhs.insertedChars == the_rhs.insertedChars
        && the_lhs.transliterateFlags == the_rhs.transliterateFlags;
}

inline bool operator!=(const SearchOptions& the_lhs, const SearchOptions& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theSearchOptionsType : public rtl::StaticWithInit< ::css::uno::Type *, theSearchOptionsType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.SearchOptions" );
        ::cppu::UnoType< ::css::util::SearchAlgorithms >::get();
        ::rtl::OUString the_tname0( "com.sun.star.util.SearchAlgorithms" );
        ::rtl::OUString the_name0( "algorithmType" );
        ::rtl::OUString the_tname1( "long" );
        ::rtl::OUString the_name1( "searchFlag" );
        ::rtl::OUString the_tname2( "string" );
        ::rtl::OUString the_name2( "searchString" );
        ::rtl::OUString the_name3( "replaceString" );
        ::cppu::UnoType< ::css::lang::Locale >::get();
        ::rtl::OUString the_tname3( "com.sun.star.lang.Locale" );
        ::rtl::OUString the_name4( "Locale" );
        ::rtl::OUString the_name5( "changedChars" );
        ::rtl::OUString the_name6( "deletedChars" );
        ::rtl::OUString the_name7( "insertedChars" );
        ::rtl::OUString the_name8( "transliterateFlags" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ENUM, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_STRING, the_tname2.pData, the_name2.pData }, false },
            { { typelib_TypeClass_STRING, the_tname2.pData, the_name3.pData }, false },
            { { typelib_TypeClass_STRUCT, the_tname3.pData, the_name4.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name5.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name6.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name7.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name8.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 9, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::SearchOptions const *) {
    return *detail::theSearchOptionsType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::SearchOptions const *) {
    return ::cppu::UnoType< ::css::util::SearchOptions >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_SEARCHOPTIONS_HPP
