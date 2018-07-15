#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "print.hpp"

std::vector<std::string> coll = {"good", "times", "say", "bye"};

TEST(chp_4, var_indices_print_v1)
{
    testing::internal::CaptureStdout();
    v1::printElemsFromIdxs(coll, 2, 0, 3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "say\ngood\nbye\n");
}

TEST(chp_4, var_indices_print_v2)
{
    testing::internal::CaptureStdout();
    v2::printElemsFromIdxs(coll, 2, 0, 3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "say\ngood\nbye\n");
}