#include <gtest/gtest.h>
#include <type_traits>
#include "../header/typelist.hpp"

using namespace ctcg;
using namespace ctcg::tl;

class S {
public:
    S() {}
};

TEST(testTypeList, Front)
{
    using types = TypeList<int, double, char>;
    ASSERT_FALSE(IsEmpty<types>::value);
    EXPECT_TRUE((std::is_same_v<Front<types>, int>));
    EXPECT_FALSE((std::is_same_v<Front<types>, double>));
    EXPECT_FALSE((std::is_same_v<Front<types>, char>));
}

TEST(testTypeList, IsEmpty_notEmptyList)
{
    using types = TypeList<int, double, char>;
    EXPECT_FALSE(IsEmpty<types>::value);
}

TEST(testTypeList, IsEmpty_emptyTypeList)
{
    using types = TypeList<>;
    EXPECT_TRUE(IsEmpty<types>::value);
}

TEST(testTypeList, PopFront)
{
    using types1 = TypeList<int, double, char>;
    using types2 = PopFront<types1>;
    using types3 = PopFront<types2>;
    using result2 = TypeList<double, char>;
    using result3 = TypeList<char>;
    EXPECT_TRUE((std::is_same_v<types2, result2>));
    EXPECT_TRUE((std::is_same_v<types3, result3>));
}

TEST(testTypeList, GetByIndex)
{
    using types = TypeList<int, double, S>;
    EXPECT_TRUE((std::is_same_v<GetByIndex<types, 0>, int>));
    EXPECT_TRUE((std::is_same_v<GetByIndex<types, 1>, double>));
    EXPECT_TRUE((std::is_same_v<GetByIndex<types, 2>, S>));
}

TEST(testTypeList, Length_notEmpty)
{
    using types = TypeList<int, double, char>;
    EXPECT_EQ(Length<types>::value, 3);
}

TEST(testTypeList, Length_Empty)
{
    using types = TypeList<>;
    EXPECT_EQ(Length<types>::value, 0);
}

TEST(testTypeList, Length_withPopFront)
{
    using types = TypeList<int, double, char>;
    EXPECT_EQ(Length<types>::value, 3);
    EXPECT_EQ(Length<PopFront<types>>::value, 2);
}

TEST(testTypeList, Back)
{
    using types = TypeList<int, double, S>;
    EXPECT_TRUE((std::is_same_v<Back<types>, S>));
}