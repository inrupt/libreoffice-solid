#ifndef INCLUDED_COM_SUN_STAR_UCB_TRANSFERINFO2_HPP
#define INCLUDED_COM_SUN_STAR_UCB_TRANSFERINFO2_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/TransferInfo2.hdl"

#include "com/sun/star/ucb/TransferInfo.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline TransferInfo2::TransferInfo2()
    : ::css::ucb::TransferInfo()
    , MimeType()
{
}

inline TransferInfo2::TransferInfo2(const ::sal_Bool& MoveData_, const ::rtl::OUString& SourceURL_, const ::rtl::OUString& NewTitle_, const ::sal_Int32& NameClash_, const ::rtl::OUString& MimeType_)
    : ::css::ucb::TransferInfo(MoveData_, SourceURL_, NewTitle_, NameClash_)
    , MimeType(MimeType_)
{
}


inline bool operator==(const TransferInfo2& the_lhs, const TransferInfo2& the_rhs)
{
    return operator==( static_cast<const ::css::ucb::TransferInfo&>(the_lhs), static_cast<const ::css::ucb::TransferInfo&>(the_rhs) )

        && the_lhs.MimeType == the_rhs.MimeType;
}

inline bool operator!=(const TransferInfo2& the_lhs, const TransferInfo2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theTransferInfo2Type : public rtl::StaticWithInit< ::css::uno::Type *, theTransferInfo2Type >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.TransferInfo2" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "MimeType" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::ucb::TransferInfo >::get().getTypeLibType(), 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::TransferInfo2 const *) {
    return *detail::theTransferInfo2Type::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::TransferInfo2 const *) {
    return ::cppu::UnoType< ::css::ucb::TransferInfo2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_TRANSFERINFO2_HPP
