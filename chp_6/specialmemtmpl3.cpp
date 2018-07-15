#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <utility>
using std::cout;
using std::endl;
using std::string;

class Person
{
private:
    string name;

public:
    // By enable_if or enable_if_t, we defined a template function
    // that only applies to STR, that can convert to string
    template <typename STR,
              typename = std::enable_if_t<std::is_convertible_v<STR, string>>>
    explicit Person(STR&& n) : name(std::forward<STR>(n))
    {
        cout << "forward constructor called for " << name << endl;
    }

    Person(Person const& p) : name(p.name)
    {
        cout << "copy constructor " << name << endl;
    }

    Person(Person&& p) : name(std::move(p.name))
    {
        cout << "move constructor " << name << endl;
    }
};

TEST(chp_6, function_matching_2)
{
    string s("Mike");

    Person p1(s);
    Person p2("tmp");

    Person p6(p1);  // should call copy constructor

    const Person p3("Henry");
    Person p5(p3);

    Person p4(std::move(p1));
}
