#ifndef INCLUDED_COM_SUN_STAR_IO_DATATRANSFEREVENT_HPP
#define INCLUDED_COM_SUN_STAR_IO_DATATRANSFEREVENT_HPP

#include "sal/config.h"

#include "com/sun/star/io/DataTransferEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace io {

inline DataTransferEvent::DataTransferEvent()
    : ::css::lang::EventObject()
    , aException()
{
}

inline DataTransferEvent::DataTransferEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Any& aException_)
    : ::css::lang::EventObject(Source_)
    , aException(aException_)
{
}


inline bool operator==(const DataTransferEvent& the_lhs, const DataTransferEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.aException == the_rhs.aException;
}

inline bool operator!=(const DataTransferEvent& the_lhs, const DataTransferEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace io { namespace detail {

struct theDataTransferEventType : public rtl::StaticWithInit< ::css::uno::Type *, theDataTransferEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.io.DataTransferEvent" );
        ::rtl::OUString the_tname0( "any" );
        ::rtl::OUString the_name0( "aException" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ANY, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace io {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::io::DataTransferEvent const *) {
    return *detail::theDataTransferEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::io::DataTransferEvent const *) {
    return ::cppu::UnoType< ::css::io::DataTransferEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_IO_DATATRANSFEREVENT_HPP
