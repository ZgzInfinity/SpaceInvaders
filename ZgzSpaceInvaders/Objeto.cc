/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */



#include "Objeto.h"
#include "windows.h"

Objeto::Objeto(int _x, int _y){
    x = _x;
    y = _y;
}

void Objeto::posicionarObjeto(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon,dwPos);
}
