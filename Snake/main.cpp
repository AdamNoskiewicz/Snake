#include <iostream>
#include "gametxt.h"
using namespace std;
int main()
{
    Gametxt G;
    G.Play();
    return 0;
}
/*
Po uruchomieniu programu na konsoli pojawia sie plansza
ograniczona obwodem o wymiarach stalych (15 na 20) zlozony z 'X' oraz jablko
w postaci znaku '@' a takze waz w postaci jednego znaku '*'.
Gra polega na sterowaniu wezem za pomoca strzalek i zbieraniu jablek ('@'),
po kazdym zebraniu waz zwieksza swoja dlugosc o 1.
Nalezy unikac zderzenia z krawedzia planszy oraz wlasnym cialem.
Uzywamy funkcji Play(), ktora korzysta z wirtualnej funkcji View(), ktora odpowiada za
konsolowe wyswietlanie gry. W niej:
tworzymy mape 15x20 na podstawie klasy Mapa i przy tym gracza
(ktorego tworzymy na podstawie klas Pyton oraz Coord i ktorego tworzymy jako kolejke dwustronna)
Gra toczy sie wokol warunku czy gracz wygral (a nie czy przegral)
czyli czy cala plansza zostala wypelniona graczem.
Gra sprawdza tez czy jablko istnieje (wtedy dodaje je losowo w miejscu gdzie nie ma gracza)
Funkcja Ruch() steruje ruchem i zachowaniem weza w zaleznosci od kliknietej strzalki i
od elementu bezposrednio przed graczem:
Kazde nacisniecie strzalki zmieni zmieni wektor kierunku poruszania sie weza
(chyba ze waz jest dluzszy niz 1 i nacisnie sie strzalke o zwrocie przeciwnym do kierunku poruszania sie)
Funkcja wypisz wypisuje cala plansze od nowa (z drobna pomoca polecenia czyszczenia konsoli cls)
*/
