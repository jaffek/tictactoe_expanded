#ifndef MOVES_H
#define MOVES_H
#include <iostream>
#include "board.h"
using namespace std;
/**
 * @brief movesAI_2  funckja pomocnicza aby skrocic dlugosc funkcji movesAI
 *
 * odpowiada za sprawdzanie ciagow znakow z pustymi polami w srodku
 * @param x plansza (tablica) - nosnik informacji o stanie rozgrywki
 * @param n liczba kolumn/wierszy planszy
 * @param il ile znakow w linii potrzeba do wygranej
 * @param x_AI wpolrzedne po osi x ruchu komputera
 * @param y_AI wpolrzedne po osi y ruchu komputera
 * @return
 */
bool movesAI_2(char **x,int n,int il,int &x_AI,int &y_AI);
/**
 * @brief movesAI
 *
 * Komputer w przypadku dluzszych linii znakow przeciwnika stara sie je
 * przeciac, a jezeli nie ma zagrozenia (przeciwnik ma krótkie linie znakow)
 * to stara sie ulozyc jak najdluzsza linie wlasnych znakow.
 * @param x plansza (tablica) - nosnik informacji o stanie rozgrywki
 * @param n liczba kolumn/wierszy planszy
 * @param il ile znakow w linii potrzeba do wygranej
 * @param x_AI wpolrzedne po osi x ruchu komputera
 * @param y_AI wpolrzedne po osi y ruchu komputera
 */
void movesAI(char **x,int n,int il,int &x_AI,int &y_AI);

#endif // MOVES_H

