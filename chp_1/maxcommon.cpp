#include "maxcommon.hpp"
#include <gtest/gtest.h>

TEST(chp_1, maxcommon)
{
    EXPECT_TRUE(std11::max(4, 7.2) == 7.2);
    EXPECT_FALSE(std11::max(4, 7.2) == 7);
    EXPECT_TRUE(std14::max(4, 7.2) == 7.2);
    EXPECT_FALSE(std14::max(4, 7.2) == 7);
}
