/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */

#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>
#include "Asteroide.h"
#include "Bala.h"


using namespace std;


void presentarMenu(){
    cout << " ************************************************************************ " << endl;
    cout << " ************************** SPACE INVADERS ****************************** " << endl;
    cout << " ************************************************************************ " << endl;
}

/*
 * Pre: x e y son dos enteros
 * Post: Coloca el cursor en la posicion x,y
 */
void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon,dwPos);
}

// Funcion para ocultar el cursor
void ocultarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50;
    cci.bVisible = false;

    SetConsoleCursorInfo(hCon,&cci);
}

// funcion para mostrar el tablero
void pintarTablero(){
    for (int i = 1; i < 118; i++){
        gotoxy(i,0);
        printf("%c",205);
        gotoxy(i,28);
        printf("%c",205);
    }
    for (int i = 1; i < 28; i++){
        gotoxy(0,i);
        printf("%c",186);
        gotoxy(118,i);
        printf("%c",186);
    }
    gotoxy(0,0); printf("%c", 201);
    gotoxy(118,0); printf("%c", 187);
    gotoxy(0,28); printf("%c", 200);
    gotoxy(118,28); printf("%c", 188);
}

int main(){

    system("color 1E");

    presentarMenu();
    cout << endl << endl;

    int retardo, vidas;
    cout << " Introduzca las vidas de la nave --> " << flush;
    cin >> vidas;
    cout << endl << endl;

    cout << " Introducir el nivel de dificultad (10..100) --> " << flush;
    cin >> retardo;
    cout << endl << endl;

    gotoxy(1,25);
    cout << "CARGANDO";

    for (int i = 0; i < 118; i++){
        cout << ". ";
    }

    system("cls");

    pintarTablero();

    ocultarCursor();


    Nave n(59,27,3);


    bool fin = false;
    int puntos = 0;

    n.construir();
    n.pintarVidas();

    list<Asteroide*> A;
    list<Asteroide*>::iterator itA;

    for (int i = 0; i < 5; i++){
        A.push_back(new Asteroide(rand() % 117 + 1,1));
    }

    list<Bala*> B;
    list<Bala*>::iterator it;


    while (!fin){
        gotoxy(30,29);
        printf("Puntos %d", puntos);

        if (kbhit()){
            if (GetAsyncKeyState(0x20)){
                B.push_back(new Bala(n.obtenerX(), n.obtenerY()));
            }
        }

        for(it = B.begin(); it != B.end(); it++){
            (*it)->modificar();
            if ((*it)->fuera()){
                gotoxy((*it)->obtenerX(),(*it)->obtenerY());
                printf(" ");
                delete (*it);
                it = B.erase(it);
            }
        }

        n.desplazar();
        for(itA = A.begin(); itA != A.end(); itA++){
            (*itA)->mover();
            (*itA)->colisionar(n);
        }

        for(itA = A.begin(); itA != A.end(); itA++){
            for (it = B.begin(); it != B.end(); it++){
               if (((*it)->obtenerX() == (*itA)->obtenerX())
                    && ((*it)->obtenerY() == (*itA)->obtenerY() + 1
                    || (*it)->obtenerY() == (*itA)->obtenerY())){

                    gotoxy((*it)->obtenerX(),(*it)->obtenerY());
                    printf(" ");
                    delete (*it);
                    it = B.erase(it);

                    A.push_back(new Asteroide(rand() % 117 + 1,1));
                    gotoxy((*itA)->obtenerX(),(*itA)->obtenerY());
                    delete (*itA);
                    itA = A.erase(itA);

                    puntos++;
                }
            }

            if (n.obtenerVidas() == 0){
                fin = true;
            }

            (*itA)->mover();
            (*itA)->colisionar(n);
        }
        Sleep(retardo);
    }


    return 0;
}
