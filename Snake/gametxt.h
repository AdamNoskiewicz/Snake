#ifndef GAMETXT_H
#define GAMETXT_H
#include "game.h"
#include "map.h"
class Gametxt : public Game
{
private:
	Gametxt( const Gametxt & re);
    Gametxt & operator=(const Gametxt & re);
public:
    Gametxt(){}
    ~Gametxt() {}
    virtual void View();
};
#endif
