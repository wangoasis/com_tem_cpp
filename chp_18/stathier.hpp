#include <iostream>
#include "coord.hpp"

class Circle
{
public:
    void draw() const { std::cout << "Draw a circle" << std::endl; }
    Coord center_of_gravity() const { return Coord(0, 0); }
};

class Line
{
public:
    void draw() const { std::cout << "Draw a line" << std::endl; }
    Coord center_of_gravity() const { return Coord(0, 0); }
};