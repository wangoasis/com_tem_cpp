#ifndef _COORD_HPP
#define _COORD_HPP
#include <cstdlib>

class Coord
{
private:
    int _x, _y;

public:
    Coord(int x, int y) : _x(x), _y(y)
    {

    }

    Coord abs() 
    {
        return Coord(::abs(_x), ::abs(_y));
    }

    friend Coord operator- (Coord const& c1, Coord const& c2)
    {
        return Coord(::abs(c1._x - c2._x), ::abs(c1._y - c2._y));
    }
};
#endif // _COORD_HPP