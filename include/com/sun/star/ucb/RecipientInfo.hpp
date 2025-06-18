#ifndef INCLUDED_COM_SUN_STAR_UCB_RECIPIENTINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_RECIPIENTINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/RecipientInfo.hdl"

#include "com/sun/star/ucb/OutgoingMessageState.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline RecipientInfo::RecipientInfo()
    : ProtocolType()
    , State(::css::ucb::OutgoingMessageState_WRITTEN)
    , To()
    , CC()
    , BCC()
    , Newsgroups()
    , Server()
    , Username()
    , Password()
    , VIMPostOfficePath()
    , ProtocolErrorString()
    , ProtocolErrorNumber(0)
    , SendTries(0)
{
}

inline RecipientInfo::RecipientInfo(const ::rtl::OUString& ProtocolType_, const ::css::ucb::OutgoingMessageState& State_, const ::rtl::OUString& To_, const ::rtl::OUString& CC_, const ::rtl::OUString& BCC_, const ::rtl::OUString& Newsgroups_, const ::rtl::OUString& Server_, const ::rtl::OUString& Username_, const ::rtl::OUString& Password_, const ::rtl::OUString& VIMPostOfficePath_, const ::rtl::OUString& ProtocolErrorString_, const ::sal_Int32& ProtocolErrorNumber_, const ::sal_Int32& SendTries_)
    : ProtocolType(ProtocolType_)
    , State(State_)
    , To(To_)
    , CC(CC_)
    , BCC(BCC_)
    , Newsgroups(Newsgroups_)
    , Server(Server_)
    , Username(Username_)
    , Password(Password_)
    , VIMPostOfficePath(VIMPostOfficePath_)
    , ProtocolErrorString(ProtocolErrorString_)
    , ProtocolErrorNumber(ProtocolErrorNumber_)
    , SendTries(SendTries_)
{
}


inline bool operator==(const RecipientInfo& the_lhs, const RecipientInfo& the_rhs)
{
    return the_lhs.ProtocolType == the_rhs.ProtocolType
        && the_lhs.State == the_rhs.State
        && the_lhs.To == the_rhs.To
        && the_lhs.CC == the_rhs.CC
        && the_lhs.BCC == the_rhs.BCC
        && the_lhs.Newsgroups == the_rhs.Newsgroups
        && the_lhs.Server == the_rhs.Server
        && the_lhs.Username == the_rhs.Username
        && the_lhs.Password == the_rhs.Password
        && the_lhs.VIMPostOfficePath == the_rhs.VIMPostOfficePath
        && the_lhs.ProtocolErrorString == the_rhs.ProtocolErrorString
        && the_lhs.ProtocolErrorNumber == the_rhs.ProtocolErrorNumber
        && the_lhs.SendTries == the_rhs.SendTries;
}

inline bool operator!=(const RecipientInfo& the_lhs, const RecipientInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theRecipientInfoType : public rtl::StaticWithInit< ::css::uno::Type *, theRecipientInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.RecipientInfo" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "ProtocolType" );
        ::cppu::UnoType< ::css::ucb::OutgoingMessageState >::get();
        ::rtl::OUString the_tname1( "com.sun.star.ucb.OutgoingMessageState" );
        ::rtl::OUString the_name1( "State" );
        ::rtl::OUString the_name2( "To" );
        ::rtl::OUString the_name3( "CC" );
        ::rtl::OUString the_name4( "BCC" );
        ::rtl::OUString the_name5( "Newsgroups" );
        ::rtl::OUString the_name6( "Server" );
        ::rtl::OUString the_name7( "Username" );
        ::rtl::OUString the_name8( "Password" );
        ::rtl::OUString the_name9( "VIMPostOfficePath" );
        ::rtl::OUString the_name10( "ProtocolErrorString" );
        ::rtl::OUString the_tname2( "long" );
        ::rtl::OUString the_name11( "ProtocolErrorNumber" );
        ::rtl::OUString the_name12( "SendTries" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ENUM, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name2.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name3.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name4.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name5.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name6.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name7.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name8.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name9.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name10.pData }, false },
            { { typelib_TypeClass_LONG, the_tname2.pData, the_name11.pData }, false },
            { { typelib_TypeClass_LONG, the_tname2.pData, the_name12.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 13, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::RecipientInfo const *) {
    return *detail::theRecipientInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::RecipientInfo const *) {
    return ::cppu::UnoType< ::css::ucb::RecipientInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_RECIPIENTINFO_HPP
