#include <utility>
#include <string>
#include <iostream>
using std::string; using std::cout; using std::endl;

class Person {
private:
    string name;
public:
    template <typename STR>
    explicit Person(STR&& n) : name(std::forward<STR>(n)) {
        cout << "forward constructor called for " << name << endl;
    }

    Person(Person const& p) : name(p.name) {
        cout << "copy constructor " << name << endl;
    }

    Person(Person&& p) : name(std::move(p.name)) {
        cout << "move constructor " << name << endl;
    }
};

int main() {
    string s("Mike");

    Person p1(s);
    Person p2("tmp");

    // this line would cause compilation error.
    // because Person(STR&&) is a better match for a nonconstant lvalue
    // Person p3(p1);

    const Person p3("Henry");
    // this line works because p3 is const variable
    // calls the copy constructor
    Person p5(p3);
    
    Person p4(std::move(p1));
}
