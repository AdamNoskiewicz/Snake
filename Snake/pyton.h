#ifndef PYTON_H
#define PYTON_H
#include "coord.h"
#include <deque>
class Pyton
{
private:
	Pyton(Coord wsp);
	std::deque<Coord> cialo;
	Coord kierunek;
	friend class Map;
};

#endif
