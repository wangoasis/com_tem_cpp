#include <gtest/gtest.h>
#include "dynahier.hpp"
#include "coord.hpp"

TEST(chp_18, dynahier)
{
    Circle c1;
    Rectangle r1;

    GeoObj const& g1 = c1;
    GeoObj const& g2 = r1;
    GeoObj* pg = new Rectangle();

    g1.draw();
    g2.draw();
    pg->draw();
}