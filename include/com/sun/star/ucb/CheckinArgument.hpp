#ifndef INCLUDED_COM_SUN_STAR_UCB_CHECKINARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CHECKINARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/CheckinArgument.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline CheckinArgument::CheckinArgument()
    : MajorVersion(false)
    , VersionComment()
    , SourceURL()
    , TargetURL()
    , NewTitle()
    , MimeType()
{
}

inline CheckinArgument::CheckinArgument(const ::sal_Bool& MajorVersion_, const ::rtl::OUString& VersionComment_, const ::rtl::OUString& SourceURL_, const ::rtl::OUString& TargetURL_, const ::rtl::OUString& NewTitle_, const ::rtl::OUString& MimeType_)
    : MajorVersion(MajorVersion_)
    , VersionComment(VersionComment_)
    , SourceURL(SourceURL_)
    , TargetURL(TargetURL_)
    , NewTitle(NewTitle_)
    , MimeType(MimeType_)
{
}


inline bool operator==(const CheckinArgument& the_lhs, const CheckinArgument& the_rhs)
{
    return the_lhs.MajorVersion == the_rhs.MajorVersion
        && the_lhs.VersionComment == the_rhs.VersionComment
        && the_lhs.SourceURL == the_rhs.SourceURL
        && the_lhs.TargetURL == the_rhs.TargetURL
        && the_lhs.NewTitle == the_rhs.NewTitle
        && the_lhs.MimeType == the_rhs.MimeType;
}

inline bool operator!=(const CheckinArgument& the_lhs, const CheckinArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theCheckinArgumentType : public rtl::StaticWithInit< ::css::uno::Type *, theCheckinArgumentType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.CheckinArgument" );
        ::rtl::OUString the_tname0( "boolean" );
        ::rtl::OUString the_name0( "MajorVersion" );
        ::rtl::OUString the_tname1( "string" );
        ::rtl::OUString the_name1( "VersionComment" );
        ::rtl::OUString the_name2( "SourceURL" );
        ::rtl::OUString the_name3( "TargetURL" );
        ::rtl::OUString the_name4( "NewTitle" );
        ::rtl::OUString the_name5( "MimeType" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_BOOLEAN, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name2.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name3.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name4.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name5.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 6, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::CheckinArgument const *) {
    return *detail::theCheckinArgumentType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::CheckinArgument const *) {
    return ::cppu::UnoType< ::css::ucb::CheckinArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CHECKINARGUMENT_HPP
