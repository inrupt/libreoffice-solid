#ifndef INCLUDED_COM_SUN_STAR_UCB_GLOBALTRANSFERCOMMANDARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_GLOBALTRANSFERCOMMANDARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/GlobalTransferCommandArgument.hdl"

#include "com/sun/star/ucb/TransferCommandOperation.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline GlobalTransferCommandArgument::GlobalTransferCommandArgument()
    : Operation(::css::ucb::TransferCommandOperation_COPY)
    , SourceURL()
    , TargetURL()
    , NewTitle()
    , NameClash(0)
{
}

inline GlobalTransferCommandArgument::GlobalTransferCommandArgument(const ::css::ucb::TransferCommandOperation& Operation_, const ::rtl::OUString& SourceURL_, const ::rtl::OUString& TargetURL_, const ::rtl::OUString& NewTitle_, const ::sal_Int32& NameClash_)
    : Operation(Operation_)
    , SourceURL(SourceURL_)
    , TargetURL(TargetURL_)
    , NewTitle(NewTitle_)
    , NameClash(NameClash_)
{
}


inline bool operator==(const GlobalTransferCommandArgument& the_lhs, const GlobalTransferCommandArgument& the_rhs)
{
    return the_lhs.Operation == the_rhs.Operation
        && the_lhs.SourceURL == the_rhs.SourceURL
        && the_lhs.TargetURL == the_rhs.TargetURL
        && the_lhs.NewTitle == the_rhs.NewTitle
        && the_lhs.NameClash == the_rhs.NameClash;
}

inline bool operator!=(const GlobalTransferCommandArgument& the_lhs, const GlobalTransferCommandArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theGlobalTransferCommandArgumentType : public rtl::StaticWithInit< ::css::uno::Type *, theGlobalTransferCommandArgumentType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.GlobalTransferCommandArgument" );
        ::cppu::UnoType< ::css::ucb::TransferCommandOperation >::get();
        ::rtl::OUString the_tname0( "com.sun.star.ucb.TransferCommandOperation" );
        ::rtl::OUString the_name0( "Operation" );
        ::rtl::OUString the_tname1( "string" );
        ::rtl::OUString the_name1( "SourceURL" );
        ::rtl::OUString the_name2( "TargetURL" );
        ::rtl::OUString the_name3( "NewTitle" );
        ::rtl::OUString the_tname2( "long" );
        ::rtl::OUString the_name4( "NameClash" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ENUM, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name2.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name3.pData }, false },
            { { typelib_TypeClass_LONG, the_tname2.pData, the_name4.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 5, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::GlobalTransferCommandArgument const *) {
    return *detail::theGlobalTransferCommandArgumentType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::GlobalTransferCommandArgument const *) {
    return ::cppu::UnoType< ::css::ucb::GlobalTransferCommandArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_GLOBALTRANSFERCOMMANDARGUMENT_HPP
