#include <gtest/gtest.h>
#include <type_traits>
#include "../header/ifthenelse.hpp"
using namespace ctcg;

TEST(testIfThenElse, trueCond)
{
    constexpr static bool value = (3 < 5);
    EXPECT_TRUE((std::is_same_v<IfThenElse<value, int, char>, int>));
}

TEST(testIfThenElse, falseCond)
{
    constexpr static bool value = (3 > 5);
    EXPECT_TRUE((std::is_same_v<IfThenElse<value, int, char>, char>));
}
