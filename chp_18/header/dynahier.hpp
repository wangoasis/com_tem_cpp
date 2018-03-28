#ifndef _DYNAHIER_HPP
#define _DYNAHIER_HPP
#include "coord.hpp"
#include <iostream>

class GeoObj
{
public:
    virtual void draw() const = 0;
    virtual Coord center_of_gravity() const = 0;
    virtual ~GeoObj() = default;
};

class Circle : public GeoObj
{
public:
    Circle() 
    {

    }
    virtual void draw() const override 
    {
        std::cout << "draw a Circle" << std::endl;
    }
    virtual Coord center_of_gravity() const override
    {
        return Coord(0, 0);
    }
};

class Rectangle : public GeoObj
{
public:
    Rectangle() 
    {

    }
    virtual void draw() const override
    {
        std::cout << "draw a Rectangle" << std::endl;
    }
    virtual Coord center_of_gravity() const override
    {
        return Coord(0, 0);
    }
};

#endif // _DYNAHIER_HPP