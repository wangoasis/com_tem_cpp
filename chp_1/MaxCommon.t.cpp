#include <gtest/gtest.h>

#include "MaxCommon.hpp"

namespace tmpl {

// This test verifies `max()` function returns the common type of given
// arguments.
TEST(Chp_1, MaxCommon)
{
    EXPECT_TRUE(max(4, 7.2) == 7.2);
    EXPECT_FALSE(max(4, 7.2) == 7);
}

} // namespace tmpl
