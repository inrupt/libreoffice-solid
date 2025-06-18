#ifndef INCLUDED_COM_SUN_STAR_UTIL_URL_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_URL_HPP

#include "sal/config.h"

#include "com/sun/star/util/URL.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline URL::URL()
    : Complete()
    , Main()
    , Protocol()
    , User()
    , Password()
    , Server()
    , Port(0)
    , Path()
    , Name()
    , Arguments()
    , Mark()
{
}

inline URL::URL(const ::rtl::OUString& Complete_, const ::rtl::OUString& Main_, const ::rtl::OUString& Protocol_, const ::rtl::OUString& User_, const ::rtl::OUString& Password_, const ::rtl::OUString& Server_, const ::sal_Int16& Port_, const ::rtl::OUString& Path_, const ::rtl::OUString& Name_, const ::rtl::OUString& Arguments_, const ::rtl::OUString& Mark_)
    : Complete(Complete_)
    , Main(Main_)
    , Protocol(Protocol_)
    , User(User_)
    , Password(Password_)
    , Server(Server_)
    , Port(Port_)
    , Path(Path_)
    , Name(Name_)
    , Arguments(Arguments_)
    , Mark(Mark_)
{
}


inline bool operator==(const URL& the_lhs, const URL& the_rhs)
{
    return the_lhs.Complete == the_rhs.Complete
        && the_lhs.Main == the_rhs.Main
        && the_lhs.Protocol == the_rhs.Protocol
        && the_lhs.User == the_rhs.User
        && the_lhs.Password == the_rhs.Password
        && the_lhs.Server == the_rhs.Server
        && the_lhs.Port == the_rhs.Port
        && the_lhs.Path == the_rhs.Path
        && the_lhs.Name == the_rhs.Name
        && the_lhs.Arguments == the_rhs.Arguments
        && the_lhs.Mark == the_rhs.Mark;
}

inline bool operator!=(const URL& the_lhs, const URL& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theURLType : public rtl::StaticWithInit< ::css::uno::Type *, theURLType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.URL" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Complete" );
        ::rtl::OUString the_name1( "Main" );
        ::rtl::OUString the_name2( "Protocol" );
        ::rtl::OUString the_name3( "User" );
        ::rtl::OUString the_name4( "Password" );
        ::rtl::OUString the_name5( "Server" );
        ::rtl::OUString the_tname1( "short" );
        ::rtl::OUString the_name6( "Port" );
        ::rtl::OUString the_name7( "Path" );
        ::rtl::OUString the_name8( "Name" );
        ::rtl::OUString the_name9( "Arguments" );
        ::rtl::OUString the_name10( "Mark" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name2.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name3.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name4.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name5.pData }, false },
            { { typelib_TypeClass_SHORT, the_tname1.pData, the_name6.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name7.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name8.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name9.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name10.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 11, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::URL const *) {
    return *detail::theURLType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::URL const *) {
    return ::cppu::UnoType< ::css::util::URL >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_URL_HPP
