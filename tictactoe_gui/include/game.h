#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "moves.h"

using namespace std;

/**
 * @brief gamecheck funkcja spr. czy ktos wygral
 *
 * Funkcja sprawdza czy w momencie jej wywołania nie sa spelnione
 * warunki wystarczajace do zwyciestwa gracza, ktory sie ostatnio ruszyl
 * @param y plansza (tablica) - nosnik informacji o stanie rozgrywki
 * @param z liczba znakow w linii wystarczajaca do wygranej w danej grze
 * @param zn znak, ktorym ostatnio byl wykonany ruch
 * @param n liczba wierszy/kolumn planszy
 * @return  zwraca czy koniec gry (wygrana) czy nie
 */
bool gamecheck(char **y,int z,char zn,int n);
/**
 * @brief gamewin zwraca liczbe znakow do ilu gra ma sie toczyc
 * @param N rozmiar planszy
 * @return
 */
int gamewin(int N);

#endif // GAME_H

