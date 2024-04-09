#ifndef COORD_H
#define COORD_H
#include <iostream>
class Coord
{
private:
	int x, y;
private:
    Coord(int nx, int ny): x(nx), y(ny){}
    Coord & operator=(const Coord & c);
    Coord operator+(const Coord& c);
	Coord operator-();
	bool operator==(const Coord& c) const;
	void View();
	friend class Pyton;
	friend class Map;
};
#endif
