#ifndef INCLUDED_COM_SUN_STAR_BEANS_OPTIONAL_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_OPTIONAL_HPP

#include "sal/config.h"

#include "com/sun/star/beans/Optional.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/string.h"
#include "rtl/ustrbuf.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

template< typename typeparam_T > inline Optional< typeparam_T >::Optional()
    : IsPresent(false)
    , Value()
{
}

template< typename typeparam_T > inline Optional< typeparam_T >::Optional(const ::sal_Bool& IsPresent_, typeparam_T const & Value_)
    : IsPresent(IsPresent_)
    , Value(Value_)
{
}

template< typename typeparam_T > 
inline Optional< typeparam_T >
make_Optional(const ::sal_Bool& IsPresent_, typeparam_T const & Value_)
{
    return Optional< typeparam_T >(IsPresent_, Value_);
}

template< typename typeparam_T >  inline bool operator==(const Optional< typeparam_T >& the_lhs, const Optional< typeparam_T >& the_rhs)
{
    return the_lhs.IsPresent == the_rhs.IsPresent
        && the_lhs.Value == the_rhs.Value;
}
template< typename typeparam_T >  inline bool operator!=(const Optional< typeparam_T >& the_lhs, const Optional< typeparam_T >& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace cppu {  namespace detail {

template< typename typeparam_T > struct theOptionalType : public rtl::StaticWithInit< ::css::uno::Type *, theOptionalType< typeparam_T > >
{
    ::css::uno::Type * operator()() const
    {
#ifdef LIBO_INTERNAL_ONLY
        ::rtl::OUString the_name =
        "com.sun.star.beans.Optional<" +
        ::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeName() +
        ">";
#else
        ::rtl::OUStringBuffer the_buffer;
        the_buffer.append("com.sun.star.beans.Optional<");
        the_buffer.append(::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeName());
        the_buffer.append(static_cast< ::sal_Unicode >('>'));
        ::rtl::OUString the_name(the_buffer.makeStringAndClear());
#endif
        ::rtl::OUString the_tname0( "boolean" );
        ::rtl::OUString the_name0( "IsPresent" );
        ::css::uno::Type const & the_ptype0 = ::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0));
        ::typelib_TypeClass the_pclass0 = (::typelib_TypeClass) the_ptype0.getTypeClass();
        ::rtl::OUString the_pname0(the_ptype0.getTypeName());
        ::rtl::OUString the_name1( "Value" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_BOOLEAN, the_tname0.pData, the_name0.pData }, false },
            { { the_pclass0, the_pname0.pData, the_name1.pData }, true } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
 } }

namespace cppu {

template< typename typeparam_T > class UnoType< ::css::beans::Optional< typeparam_T > > {
public:
    static inline ::css::uno::Type const & get() {
        return *detail::theOptionalType< typeparam_T >::get();
    }

private:
    UnoType(UnoType &); // not defined
    ~UnoType(); // not defined
    void operator =(UnoType); // not defined
};

}

template< typename typeparam_T > SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::Optional< typeparam_T > const *) {
        return ::cppu::UnoType< ::css::beans::Optional< typeparam_T > >::get();
    }

#endif // INCLUDED_COM_SUN_STAR_BEANS_OPTIONAL_HPP
