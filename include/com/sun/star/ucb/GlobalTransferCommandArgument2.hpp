#ifndef INCLUDED_COM_SUN_STAR_UCB_GLOBALTRANSFERCOMMANDARGUMENT2_HPP
#define INCLUDED_COM_SUN_STAR_UCB_GLOBALTRANSFERCOMMANDARGUMENT2_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/GlobalTransferCommandArgument2.hdl"

#include "com/sun/star/ucb/GlobalTransferCommandArgument.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline GlobalTransferCommandArgument2::GlobalTransferCommandArgument2()
    : ::css::ucb::GlobalTransferCommandArgument()
    , MimeType()
    , DocumentId()
{
}

inline GlobalTransferCommandArgument2::GlobalTransferCommandArgument2(const ::css::ucb::TransferCommandOperation& Operation_, const ::rtl::OUString& SourceURL_, const ::rtl::OUString& TargetURL_, const ::rtl::OUString& NewTitle_, const ::sal_Int32& NameClash_, const ::rtl::OUString& MimeType_, const ::rtl::OUString& DocumentId_)
    : ::css::ucb::GlobalTransferCommandArgument(Operation_, SourceURL_, TargetURL_, NewTitle_, NameClash_)
    , MimeType(MimeType_)
    , DocumentId(DocumentId_)
{
}


inline bool operator==(const GlobalTransferCommandArgument2& the_lhs, const GlobalTransferCommandArgument2& the_rhs)
{
    return operator==( static_cast<const ::css::ucb::GlobalTransferCommandArgument&>(the_lhs), static_cast<const ::css::ucb::GlobalTransferCommandArgument&>(the_rhs) )

        && the_lhs.MimeType == the_rhs.MimeType
        && the_lhs.DocumentId == the_rhs.DocumentId;
}

inline bool operator!=(const GlobalTransferCommandArgument2& the_lhs, const GlobalTransferCommandArgument2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theGlobalTransferCommandArgument2Type : public rtl::StaticWithInit< ::css::uno::Type *, theGlobalTransferCommandArgument2Type >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.GlobalTransferCommandArgument2" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "MimeType" );
        ::rtl::OUString the_name1( "DocumentId" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::ucb::GlobalTransferCommandArgument >::get().getTypeLibType(), 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::GlobalTransferCommandArgument2 const *) {
    return *detail::theGlobalTransferCommandArgument2Type::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::GlobalTransferCommandArgument2 const *) {
    return ::cppu::UnoType< ::css::ucb::GlobalTransferCommandArgument2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_GLOBALTRANSFERCOMMANDARGUMENT2_HPP
