#include <gtest/gtest.h>
#include <type_traits>
#include "../header/variantchoice.hpp"

using namespace ctcg;
using namespace ctcg::tl;
using namespace ctcg::va;

class S
{
public:
    S() {}

private:
    int a[10];
};

TEST(testVariantChoice, copyConstructor)
{
    VariantChoice<int, double, char> vs(2.0);
    EXPECT_EQ(vs.getDerived().getDiscriminator(), 2);
}