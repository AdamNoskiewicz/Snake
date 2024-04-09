#ifndef GAME_H
#define GAME_H
#include "map.h"
class Game
{
private:
	Game( const Game & re);
    Game & operator=(const Game & re);
public:
    Game(){};
    ~Game(){};

    virtual void View()=0;
    void Play();
};
#endif
