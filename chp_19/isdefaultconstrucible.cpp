#include <gtest/gtest.h>
#include "isdefaultconstruct.hpp"

class S
{
    S(int i) {}
};

TEST(chp_19, isdefaultconstruct)
{
    // check whether a class can be initialized without
    // parameters
    static_assert(IsDefaultConstructible<int>);
    static_assert(IsDefaultConstructible<S> == false);
}