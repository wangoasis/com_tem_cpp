#ifndef _ISCONVERTIBLE_HPP
#define _ISCONVERTIBLE_HPP

#include <utility>

template <typename FROM, typename TO>
struct isConvertibleHelper {
private:
    static void aux(TO);

    template <  typename F,
                typename = decltype(aux(std::declval<F>()))>
    static std::true_type test(void*);

    template <  typename>
    static std::false_type test(...);

public:
    using Type = decltype(test<FROM>(nullptr));
};

template <  typename FROM, typename TO>
constexpr bool isConvertible = isConvertibleHelper<FROM, TO>::Type::value;

#endif