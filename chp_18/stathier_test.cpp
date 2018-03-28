#include "header/stathier.hpp"
#include <vector>

template<typename GeoObj>
void myDraw (GeoObj const& obj)
{
    obj.draw();    
}

template<typename GeoObj>
void drawElems (std::vector<GeoObj> const& elems)
{
    for (unsigned i=0; i<elems.size(); ++i) {
        elems[i].draw();    
    }
}

int main()
{
    Line l;
    Circle c;

    myDraw(l);        // myDraw<Line>(GeoObj\&) => Line::draw()
    myDraw(c);        // myDraw<Circle>(GeoObj\&) => Circle::draw()

    std::vector<Line> coll;   // OK: homogeneous collection possible
    coll.push_back(l);        // insert line
    
    // compilation error, cannot append a Circle to a vector of Line
    // coll.push_back(c);
    
    drawElems(coll);          // draw all lines
}
