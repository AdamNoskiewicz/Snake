#include "map.h"
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <windows.h>
#include <chrono>
#include <thread>
Map::Map(int ndl, int nsz) :
	dlugosc(ndl), szerokosc(nsz), gracz({ndl/2,nsz/2})
{
	obszarGry.resize(dlugosc * szerokosc, granicaCh);
	for (int i = 1; i < szerokosc - 1; i++)
	{
		for (int j = 1; j < dlugosc - 1; j++)
		{
			Pozycja({ i,j }) = pustyCh;
		}
	}

	for (const Coord& pos : gracz.cialo)
	{
		Pozycja(pos) = graczCh;
	}
}
bool Map::czy_wygrana()
{
	for (int i = 0; i < dlugosc-1; i++)
	{
		for (int j = 0; j < szerokosc-1; j++)
		{
			if (Pozycja({ j,i }) != graczCh)
			{
				return false;
			}
		}
	}
	return true;
}
char& Map::Pozycja(Coord pozycja)
{
	int pos = pozycja.x + pozycja.y * szerokosc;
	if (pos < 0)
	{
		pos = 0;
	}
	else if (pos >= (int)obszarGry.size())
	{
		pos = obszarGry.size() - 1;
	}
	return obszarGry[pos];
}
void Map::Wypisz()
{
	for (int i = 0; i < dlugosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			std::cout << Pozycja({ j,i });
		}
		std::cout << std::endl;
	}
}
void Map::japko()
{
	int xjap, yjap;
	do
	{
		xjap = (rand() % (szerokosc - 2)) + 1;
		yjap = (rand() % (dlugosc - 2)) + 1;
	} while (Pozycja({ xjap,yjap }) == graczCh);
	Pozycja({ xjap,yjap }) = japkoCh;
}
void Map::Ruch()
{
	Coord wektor_kier = gracz.kierunek;
	if (GetAsyncKeyState(VK_LEFT))
	{
		gracz.kierunek = { -1, 0 };
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		gracz.kierunek = { 1, 0 };
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		gracz.kierunek = { 0, -1 };
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		gracz.kierunek = { 0, 1 };
	}
	if (wektor_kier == -gracz.kierunek and gracz.cialo.size()>1)
	{
		gracz.kierunek = wektor_kier;
	}

	gracz.cialo.push_front(gracz.cialo.front() + gracz.kierunek);
	if (Pozycja(gracz.cialo.front()) == japkoCh)
	{
		gracz.cialo.push_back(gracz.cialo.back());
		japko_exist = false;
	}
	if (Pozycja(gracz.cialo.front()) == graczCh)
	{
		if(gracz.cialo.size() >3) koniec_gry = true;
	}
	Pozycja(gracz.cialo.front()) = graczCh;
	if (gracz.cialo.size() > 1)
	{
		Pozycja(gracz.cialo.back()) = pustyCh;
	}
	gracz.cialo.pop_back();
	if(gracz.cialo.front().x <1 or gracz.cialo.front().y >= dlugosc-1 or gracz.cialo.front().y < 1 or gracz.cialo.front().x >= szerokosc-1 )
	{
		koniec_gry = true;
	}
}
void Map::MainFunction()
{
    system("");
	srand(time(NULL));
    japko_exist = false;
	std::cout << "\033[?25l";	//chowa kursor
	while (!koniec_gry)
	{
		if (czy_wygrana())
		{
			koniec_gry = true;
			system("cls");
			std::cout << "You won";
			break;
		}
		if (!japko_exist)
		{
			japko_exist = true;
			japko();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(90));
        //sleep(0.9);
		Ruch();
		std::cout << "\033[0;0H"; //przenosi kursor na poczatek
		system("cls");  //czysci ekran
		Wypisz();
	}
	system("cls");
	std::cout << "You lost";
}
