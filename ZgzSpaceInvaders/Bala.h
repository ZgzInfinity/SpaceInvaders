/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */



#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED

class Bala {
    private:
        int x, y;
    public:
        Bala(int _x, int _y);
        void modificar();
        bool fuera();
        int obtenerX();
        int obtenerY();
};

#endif // BALA_H_INCLUDED
