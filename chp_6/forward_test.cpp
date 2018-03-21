#include <iostream>
using std::cout; using std::endl;
#include <utility>

class X {

};

void g(X&) {
    cout << "g(X&) called" << endl;
}

void g(X const&) {
    cout << "g(X const&) called" << endl;
}

void g(X&&) {
    cout << "g(X&&) called" << endl;
}

// perfect forward
// T&& for a template parameter T declares a forwarding reference
// (also called universal reference). It can be bound to a mutable
// immutable, or movable object.
template <typename T>
void f(T&& val) // universal reference, or forward reference
{
    g(std::forward<T>(val));
}

// not right form
template <typename T>
void f2(T val) {
    g(val);
}

int main() {
    X v;
    X const c;

    f(v); // g(X&)
    f(c); // g(X const&)
    f(X()); // g(X&&)
    f(std::move(v)); // g(X&&)
    f2(v); // g(X&)
    f2(c); // g(X&)
    f2(X()); // g(X&)
    f2(std::move(v)); // g(X&)
}