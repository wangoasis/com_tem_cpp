#include <type_traits>
#include "issame.hpp"

#define VERSION 2

#if (VERSION == 1)
template <typename T>
struct IsDefaultConstructibleT {
private:
    template <typename U, typename = decltype(U())>
    static char test(void*);

    // fallback
    template <typename>
    static long test(...);

public:
    static constexpr bool value = IsSame<decltype(test<T>(nullptr)), char>;
};
#elif (VERSION == 2)
template <typename T>
struct IsDefaultConstructibleT {
private:
    template <typename U, typename = decltype(U())>
    static std::true_type test(void*);

    // fallback
    template <typename>
    static std::false_type test(...);

public:
    static constexpr bool value = decltype(test<T>(nullptr))::value;
};
#elif (VERSION == 3)  // using std::voit_t
// fallback version
template <typename, typename = std::void_t<> >
struct IsDefaultConstructibleT : std::false_type {
};

// try to initialize T with no argument
template <typename T>
struct IsDefaultConstructibleT<T, std::void_t<decltype(T())> >
    : std::true_type {
};
#endif

template <typename T>
constexpr bool IsDefaultConstructible = IsDefaultConstructibleT<T>::value;