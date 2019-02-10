/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */

#include "Bala.h"
#include <windows.h>
#include <stdio.h>

/*
 * Pre: x e y son dos enteros
 * Post: Coloca el cursor en la posicion x,y
 */
void gotoxyB(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon,dwPos);
}


Bala::Bala(int _x, int _y): x(_x), y(_y) {}

void Bala::modificar(){
    gotoxyB(x, y);
    printf(" ");
    y--;
    gotoxyB(x, y);
    printf("*");
}

bool Bala::fuera(){
    return y == 1;
}

int Bala::obtenerX(){
    return x;
}

int Bala::obtenerY(){
    return y;
}


