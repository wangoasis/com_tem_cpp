#ifndef _TYPELIST_H
#define _TYPELIST_H

#include <type_traits>
#include "ifthenelse.hpp"

namespace ctcg {
namespace tl {

/*
    definition of TypeList
*/
template <typename... Types>
class TypeList {

};

/*
    TypeList isEmpty
*/
template <typename List>
class IsEmptyT {
public:
    using Type = std::false_type;
};

// partial specialization
template <>
class IsEmptyT<TypeList<>> {
public:
    using Type = std::true_type;
};

template <typename List>
using IsEmpty = typename IsEmptyT<List>::Type;

/*
    Front element of TypeList
*/
template <typename List>
class FrontT;

template <typename Head, typename... Tail>
class FrontT<TypeList<Head, Tail...>> {
public:
    using Type = Head;
};

template <typename List>
using Front = typename FrontT<List>::Type;

/*
    push front
*/
template <typename List, typename Element>
class PushFrontT;

template <typename... List, typename Element>
class PushFrontT<TypeList<List...>, Element> {
    using Type = TypeList<Element, List...>; 
};

template <typename List, typename Element>
using PushFront = typename PushFrontT<List, Element>::Type;

/*
    pop front
*/
template <typename List>
class PopFrontT;

template <typename Head, typename... Tail>
class PopFrontT<TypeList<Head, Tail...>> {
public:
    using Type = TypeList<Tail...>;
};

template <typename List>
using PopFront = typename PopFrontT<List>::Type;

/*
    get by index
*/
template <typename List, unsigned N>
class GetByIndexT {
public:
    using Type = typename GetByIndexT<PopFront<List>, N-1>::Type;
};

template <typename List> 
class GetByIndexT<List, 0> {
public:
    using Type = Front<List>;
};

template <typename List, unsigned N>
using GetByIndex = typename GetByIndexT<List, N>::Type;

/*
    length
*/
template <typename List>
class LengthT;

template <typename... Elements>
class LengthT<TypeList<Elements...>> {
public:
    using Result = std::integral_constant<int, sizeof...(Elements)>;
};

template <>
class LengthT<TypeList<>> {
public:
    using Result = std::integral_constant<int, 0>;
};

template <typename List>
using Length = typename LengthT<List>::Result;

/*
    back
*/
template <typename List>
using Back = GetByIndex<List, Length<List>::value-1>;

/*
    largest type
*/
template <typename List>
class LargestTypeT {
private:
    using First = Front<List>;
    using Rest = typename LargestTypeT<PopFront<List>>::Type;
public:
    using Type = IfThenElse<(sizeof(First) >= sizeof(Rest)), First, Rest>;
};

template <>
class LargestTypeT<TypeList<>> {
public:
    using Type = char;
};

template <typename List>
using LargestType = typename LargestTypeT<List>::Type;

/*
    find index of
*/
template <typename List, typename T, unsigned N = 0,
        bool Empty = IsEmpty<List>::value>
class FindIndexOf;

template <typename List, typename T, unsigned N>
class FindIndexOf<List, T, N, false>
: public IfThenElse<std::is_same_v<Front<List>, T>,
                    std::integral_constant<unsigned, N>,
                    FindIndexOf<PopFront<List>, T, N+1>>
{ };

template <typename List, typename T, unsigned N>
class FindIndexOf<List, T, N, true>
{ };

} // namespace tl {
} // namespace ctcg {

#endif