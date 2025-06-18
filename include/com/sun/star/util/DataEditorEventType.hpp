#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATAEDITOREVENTTYPE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATAEDITOREVENTTYPE_HPP

#include "sal/config.h"

#include "com/sun/star/util/DataEditorEventType.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theDataEditorEventTypeType : public rtl::StaticWithInit< ::css::uno::Type *, theDataEditorEventTypeType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.util.DataEditorEventType" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[2];
        ::rtl::OUString sEnumValue0( "DONE" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "CANCELED" );
        enumValueNames[1] = sEnumValue1.pData;

        sal_Int32 enumValues[2];
        enumValues[0] = 0;
        enumValues[1] = 1;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::util::DataEditorEventType_DONE,
            2, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::DataEditorEventType const *) {
    return *detail::theDataEditorEventTypeType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::DataEditorEventType const *) {
    return ::cppu::UnoType< ::css::util::DataEditorEventType >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATAEDITOREVENTTYPE_HPP
