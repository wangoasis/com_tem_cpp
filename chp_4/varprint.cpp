#include <gtest/gtest.h>
#include <complex>
#include <string>
#include "print.hpp"

TEST(chp_4, varprint_v1)
{
    std::string s("world");
    v1::print(1, 4.3, "hello", s);
    v1::printDoubled(1, 3.2, s, std::complex<float>(4, 2));
}

// TEST(chp_4, varprint_v2)
// {
//     std::string s("world");
//     v2::print(1, 4.3, "hello", s);
//     v2::printDoubled(1, 3.2, s, std::complex<float>(4, 2));
// }