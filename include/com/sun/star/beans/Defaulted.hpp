#ifndef INCLUDED_COM_SUN_STAR_BEANS_DEFAULTED_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_DEFAULTED_HPP

#include "sal/config.h"

#include "com/sun/star/beans/Defaulted.hdl"

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

template< typename typeparam_T > inline Defaulted< typeparam_T >::Defaulted()
    : Value()
    , IsDefaulted(false)
{
}

template< typename typeparam_T > inline Defaulted< typeparam_T >::Defaulted(typeparam_T const & Value_, const ::sal_Bool& IsDefaulted_)
    : Value(Value_)
    , IsDefaulted(IsDefaulted_)
{
}

template< typename typeparam_T > 
inline Defaulted< typeparam_T >
make_Defaulted(typeparam_T const & Value_, const ::sal_Bool& IsDefaulted_)
{
    return Defaulted< typeparam_T >(Value_, IsDefaulted_);
}

template< typename typeparam_T >  inline bool operator==(const Defaulted< typeparam_T >& the_lhs, const Defaulted< typeparam_T >& the_rhs)
{
    return the_lhs.Value == the_rhs.Value
        && the_lhs.IsDefaulted == the_rhs.IsDefaulted;
}
template< typename typeparam_T >  inline bool operator!=(const Defaulted< typeparam_T >& the_lhs, const Defaulted< typeparam_T >& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace cppu {  namespace detail {

template< typename typeparam_T > struct theDefaultedType : public rtl::StaticWithInit< ::css::uno::Type *, theDefaultedType< typeparam_T > >
{
    ::css::uno::Type * operator()() const
    {
#ifdef LIBO_INTERNAL_ONLY
        ::rtl::OUString the_name =
        "com.sun.star.beans.Defaulted<" +
        ::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeName() +
        ">";
#else
        ::rtl::OUStringBuffer the_buffer;
        the_buffer.append("com.sun.star.beans.Defaulted<");
        the_buffer.append(::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeName());
        the_buffer.append(static_cast< ::sal_Unicode >('>'));
        ::rtl::OUString the_name(the_buffer.makeStringAndClear());
#endif
        ::css::uno::Type const & the_ptype0 = ::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0));
        ::typelib_TypeClass the_pclass0 = (::typelib_TypeClass) the_ptype0.getTypeClass();
        ::rtl::OUString the_pname0(the_ptype0.getTypeName());
        ::rtl::OUString the_name0( "Value" );
        ::rtl::OUString the_tname0( "boolean" );
        ::rtl::OUString the_name1( "IsDefaulted" );
        ::typelib_StructMember_Init the_members[] = {
            { { the_pclass0, the_pname0.pData, the_name0.pData }, true },
            { { typelib_TypeClass_BOOLEAN, the_tname0.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
 } }

namespace cppu {

template< typename typeparam_T > class UnoType< ::css::beans::Defaulted< typeparam_T > > {
public:
    static inline ::css::uno::Type const & get() {
        return *detail::theDefaultedType< typeparam_T >::get();
    }

private:
    UnoType(UnoType &); // not defined
    ~UnoType(); // not defined
    void operator =(UnoType); // not defined
};

}

template< typename typeparam_T > SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::Defaulted< typeparam_T > const *) {
        return ::cppu::UnoType< ::css::beans::Defaulted< typeparam_T > >::get();
    }

#endif // INCLUDED_COM_SUN_STAR_BEANS_DEFAULTED_HPP
