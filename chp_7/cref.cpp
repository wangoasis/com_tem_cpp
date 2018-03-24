#include <functional>
#include <iostream>
#include <string>
#include <cassert>

void printString(std::string const& s) {
    std::cout << s << std::endl;
}

template <typename T>
void printT(T arg) {
    printString(arg);
}

void modifyNumber(int &s) {
    s = 100;
}

template <typename T>
void modifyT(T arg) {
    modifyNumber(arg);
    std::cout << "Inside modifyT: " << arg << std::endl;
}

int main() {
    std::string s("hello");
    printT(s);
    printT(std::cref(s));

    int i = 43;
    modifyT(i);
    assert(i == 43); // i should not be modified
    modifyT(std::ref(i));
    assert(i == 100); // i should be modified
}
