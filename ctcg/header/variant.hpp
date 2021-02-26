#ifndef _VARIANT_H
#define _VARIANT_H

#include "typelist.hpp"
#include "variantchoice.hpp"
#include "variantstorage.hpp"

namespace ctcg
{
namespace va
{
using namespace ctcg::tl;

template <typename... Types>
class Variant : public VariantStorage<Types...>,
                public VariantChoice<Types, Types...>...
{
public:
    using VariantChoice<Types, Types...>::VariantChoice...;
    Variant()
    {
        *this = Front<TypeList<Types...>>();
    }  // see variantdefaultctor.hpp
    // Variant(Variant const& source);                   // see
    // variantcopyctor.hpp Variant(Variant&& source);                        //
    // see variantmovector.hpp template<typename... SourceTypes>
    //     Variant(Variant<SourceTypes...> const& source); //
    //     variantcopyctortmpl.hpp
    // template<typename... SourceTypes>
    //     Variant(Variant<SourceTypes...>&& source);
};

}  // namespace va
}  // namespace ctcg

#endif