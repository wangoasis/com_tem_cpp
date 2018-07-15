#ifndef _ISSAME_HPP
#define _ISSAME_HPP

#include <type_traits>

template <typename T1, typename T2>
struct IsSameT : std::false_type {
};

template <typename T>
struct IsSameT<T, T> : std::true_type {
};

template <typename T1, typename T2>
constexpr bool IsSame = IsSameT<T1, T2>::value;

#endif