#include <gtest/gtest.h>
#include <cassert>
#include <vector>
#include "myClass.hpp"

TEST(chp_18, myClass)
{
    MyClass m1(5, "jack"), m2(6, "susan"), m3(1, "qing");
    std::vector<MyClass> v{m1, m3, m2, m3};
    auto pos = max_element(v.begin(), v.end());
    ASSERT_EQ(2, std::distance(v.begin(), pos));
}