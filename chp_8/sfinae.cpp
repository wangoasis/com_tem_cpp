#include <gtest/gtest.h>

#include <iostream>
#include <vector>

namespace {

template <typename T>
typename T::size_type len(T t) {
    std::cout << "t.size()" << std::endl;
    return t.size();
}

// SFINAE:
// Rather than requiring the compiler to give error on that array doesn't have
// size() function, the first template overload is removed from the list of
// candidate functions.
template <typename T, unsigned N>
std::size_t len(T (&)[N]) {
    std::cout << "called with T&[N]" << std::endl;
    return N;
}

std::size_t len(...) {
    return 0;
}
}

TEST(chp_8, SFINAE) {
    std::vector<int> v{10, 1, 3};
    int a[4]{4, 5, 6, 4};

    EXPECT_EQ(3, len(v));
    EXPECT_EQ(4, len(a));

#if 0
    // This would compile, but would cause runtime error.
    // `std::allocator` has member `size_type`, but it does not have "size()" function.
    std::allocator<int> x;
    EXPECT_EQ(0, len(x));
#endif
}
