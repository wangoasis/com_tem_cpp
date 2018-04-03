#include "header/isconvertible.hpp"
#include <string>

class A
{
public:
    A();
};

class B : public A
{
public:
    B();
};

int main()
{
    static_assert(isConvertible<int, double>);
    static_assert(isConvertible<int, char>);
    static_assert(isConvertible<double, std::string> == false);
    static_assert(isConvertible<char const*, std::string>);
    static_assert(isConvertible<std::string, char const*> == false);
    static_assert(isConvertible<A, B> == false); // Base class cannot convert to Derived class
    static_assert(isConvertible<B, A>);
    static_assert(isConvertible<B, B>);
    static_assert(isConvertible<A*, B*> == false);
    static_assert(isConvertible<B*, A*>);
    static_assert(isConvertible<A&, B&> == false);
    static_assert(isConvertible<B&, A&>);
}
