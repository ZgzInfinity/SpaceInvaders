/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */


#ifndef ASTEROIDE_H_INCLUDED
#define ASTEROIDE_H_INCLUDED

#include "Nave.h"

class Asteroide {
    private:
        int x, y;
    public:
        Asteroide(int _x, int _y);
        void crear();
        void mover();
        void colisionar(Nave& n);
        int obtenerX();
        int obtenerY();
};

#endif // ASTEROIDE_H_INCLUDED
