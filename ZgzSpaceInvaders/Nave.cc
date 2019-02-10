/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */



#include "Nave.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

/*
 * Pre: x e y son dos enteros
 * Post: Coloca el cursor en la posicion x,y
 */

void gotoxyN(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon,dwPos);
}

Nave::Nave(int _x, int _y, int _vidas): x(_x), y(_y), vidas(_vidas) {}


void Nave::construir(){
    gotoxyN(x - 1,y); printf("#");
    gotoxyN(x,y); printf("#");
    gotoxyN(x + 1,y); printf("#");
}

void Nave::eliminar(){
    gotoxyN(x,y); printf(" ");
    gotoxyN(x - 1,y); printf(" ");
    gotoxyN(x + 1,y); printf(" ");
}

void Nave::desplazar(){
    if (kbhit()){
        char tecla = getch();
        eliminar();
        if (tecla == IZQUIERDA && x > 2){
            x--;
        }
        else if (tecla == DERECHA && x < 116){
            x++;
        }
        else if (tecla == ARRIBA && y > 1){
            y--;
        }
        else if (tecla == ABAJO && y < 27){
            y++;
        }
    }
    construir();
    pintarVidas();
}

void Nave::pintarVidas(){
    gotoxyN(90,29);
    printf(" Vidas ");
    gotoxyN(97,29);
    printf("       ");
    for (int i = 0; i < vidas; i++){
        gotoxyN(97 + i,29);
        printf("%c",169);
    }

}

void Nave::explotar(){
    eliminar();
    gotoxyN(x, y);
    printf("*****");
    Sleep(200);
    gotoxyN(x , y);
    printf("** **");
    Sleep(200);
    gotoxyN(x , y);
    printf("*   *");
    Sleep(200);
    gotoxyN(x , y);
    printf("     ");

}

int Nave::obtenerX(){
    return x;
}

int Nave::obtenerY(){
    return y;
}

void Nave::quitarVida(){
    vidas--;
    explotar();
}

int Nave::obtenerVidas(){
    return vidas;
    }

