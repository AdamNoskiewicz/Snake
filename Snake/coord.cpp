#include "coord.h"
Coord & Coord::operator=(const Coord & c)
{
    x = c.x;
    y = c.y;
    return * this;
}
Coord Coord::operator+(const Coord& c)
{
    return { x + c.x, y + c.y };
}
Coord Coord::operator-()
{
    return { -x, -y };
}
bool Coord::operator==(const Coord& c) const
{
    return x == c.x and y == c.y;
}
void Coord::View()
{
    std::cout<<x<<y;
}
