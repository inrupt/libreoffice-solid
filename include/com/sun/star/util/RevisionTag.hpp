#ifndef INCLUDED_COM_SUN_STAR_UTIL_REVISIONTAG_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_REVISIONTAG_HPP

#include "sal/config.h"

#include "com/sun/star/util/RevisionTag.hdl"

#include "com/sun/star/util/DateTime.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline RevisionTag::RevisionTag()
    : TimeStamp()
    , Author()
    , Comment()
    , Identifier()
{
}

inline RevisionTag::RevisionTag(const ::css::util::DateTime& TimeStamp_, const ::rtl::OUString& Author_, const ::rtl::OUString& Comment_, const ::rtl::OUString& Identifier_)
    : TimeStamp(TimeStamp_)
    , Author(Author_)
    , Comment(Comment_)
    , Identifier(Identifier_)
{
}


inline bool operator==(const RevisionTag& the_lhs, const RevisionTag& the_rhs)
{
    return the_lhs.TimeStamp == the_rhs.TimeStamp
        && the_lhs.Author == the_rhs.Author
        && the_lhs.Comment == the_rhs.Comment
        && the_lhs.Identifier == the_rhs.Identifier;
}

inline bool operator!=(const RevisionTag& the_lhs, const RevisionTag& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theRevisionTagType : public rtl::StaticWithInit< ::css::uno::Type *, theRevisionTagType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.RevisionTag" );
        ::cppu::UnoType< ::css::util::DateTime >::get();
        ::rtl::OUString the_tname0( "com.sun.star.util.DateTime" );
        ::rtl::OUString the_name0( "TimeStamp" );
        ::rtl::OUString the_tname1( "string" );
        ::rtl::OUString the_name1( "Author" );
        ::rtl::OUString the_name2( "Comment" );
        ::rtl::OUString the_name3( "Identifier" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRUCT, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name2.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name3.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 4, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::RevisionTag const *) {
    return *detail::theRevisionTagType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::RevisionTag const *) {
    return ::cppu::UnoType< ::css::util::RevisionTag >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_REVISIONTAG_HPP
