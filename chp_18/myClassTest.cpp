#include "header/myClass.hpp"
#include <vector>
#include <cassert>

int main()
{
    MyClass m1(5, "jack"), m2(6, "susan"), m3(1, "qing");
    std::vector<MyClass> v{m1, m3, m2, m3};
    auto pos = max_element(v.begin(), v.end());
    assert(std::distance(v.begin(), pos) == 2);
}