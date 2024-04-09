#ifndef MAP_H
#define MAP_H
#include <vector>
#include <windows.h>
#include "coord.h"
#include "pyton.h"

class Map
{
protected:
    bool koniec_gry = false;////////////////////
    int dlugosc, szerokosc;
    bool japko_exist=false;
    Pyton gracz;
	std::vector<char> obszarGry;

	const char granicaCh = '*';
	const char pustyCh = ' ';
	const char graczCh = '#';
	const char japkoCh = '@';

    char& Pozycja(Coord pozycja);
	Map(int ndl, int nsz);
	void Wypisz();
	void japko();
    bool czy_wygrana();
    void Ruch();
    void MainFunction();
    friend class Gametxt;
    };
#endif
