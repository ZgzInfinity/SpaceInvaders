/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */

#include <stdio.h>
#include "Asteroide.h"
#include "Nave.h"
#include "stdlib.h"
#include <windows.h>

/*
 * Pre: x e y son dos enteros
 * Post: Coloca el cursor en la posicion x,y
 */
void gotoxyA(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon,dwPos);
}



Asteroide::Asteroide(int _x, int _y){
    x = _x;
    y = _y;
}

void Asteroide::crear(){
    gotoxyA(x, y);
    printf("%c", 184);
}


void Asteroide::mover(){
    gotoxyA(x, y);
    printf(" ");
    y++;
    if (y > 27){
        x = rand() % 118 + 1;
        y = 1;
    }
    crear();
}


void Asteroide::colisionar(Nave& n){
    int xN = n.obtenerX();
    int yN = n.obtenerY();

    if (x >= xN - 1 && x <= xN + 1 && y == yN){
        n.quitarVida();
        n.construir();
        n.pintarVidas();
        x = rand() % 118 + 1;
        y = 1;
    }
}


int Asteroide::obtenerX(){
    return x;
}

int Asteroide::obtenerY(){
    return y;
}

