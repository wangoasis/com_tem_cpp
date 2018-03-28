#ifndef _MYCLASS_H
#define _MYCLASS_H
#include <iostream>
#include <string>

class MyClass
{
public:
    int _id;
    std::string _name;

public:
    MyClass(int id, std::string const& name)
    : _id(id), _name(name) {

    }

    friend bool operator< (MyClass const& m1, MyClass const& m2)
    {
        return m1._id < m2._id;
    }

    friend std::ostream& operator<< (std::ostream& os, MyClass const& m)
    {
        os << m._id << "----" << m._name;
        return os;
    }
}; 

#endif