#include <gtest/gtest.h>
#include <type_traits>
#include "../header/variantstorage.hpp"

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

TEST(testVariantStorage, Discriminator)
{
    VariantStorage<S, double, char> vs;
    vs.setDiscriminator(2);
    EXPECT_EQ(vs.getDiscriminator(), 2);
}

TEST(testVariantStorage, largestSize)
{
    VariantStorage<S, double, char> vs;
    EXPECT_EQ(vs.largestSize(), sizeof(S));
}