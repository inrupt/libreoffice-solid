#ifndef INCLUDED_COM_SUN_STAR_UCB_EXPORTSTREAMINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_EXPORTSTREAMINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ExportStreamInfo.hdl"

#include "com/sun/star/io/XOutputStream.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ExportStreamInfo::ExportStreamInfo()
    : Target()
    , ForceBodies(false)
{
}

inline ExportStreamInfo::ExportStreamInfo(const ::css::uno::Reference< ::css::io::XOutputStream >& Target_, const ::sal_Bool& ForceBodies_)
    : Target(Target_)
    , ForceBodies(ForceBodies_)
{
}


inline bool operator==(const ExportStreamInfo& the_lhs, const ExportStreamInfo& the_rhs)
{
    return the_lhs.Target == the_rhs.Target
        && the_lhs.ForceBodies == the_rhs.ForceBodies;
}

inline bool operator!=(const ExportStreamInfo& the_lhs, const ExportStreamInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theExportStreamInfoType : public rtl::StaticWithInit< ::css::uno::Type *, theExportStreamInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.ExportStreamInfo" );
        ::cppu::UnoType< ::css::uno::Reference< ::css::io::XOutputStream > >::get();
        ::rtl::OUString the_tname0( "com.sun.star.io.XOutputStream" );
        ::rtl::OUString the_name0( "Target" );
        ::rtl::OUString the_tname1( "boolean" );
        ::rtl::OUString the_name1( "ForceBodies" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_INTERFACE, the_tname0.pData, the_name0.pData }, false },
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ExportStreamInfo const *) {
    return *detail::theExportStreamInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ExportStreamInfo const *) {
    return ::cppu::UnoType< ::css::ucb::ExportStreamInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_EXPORTSTREAMINFO_HPP
