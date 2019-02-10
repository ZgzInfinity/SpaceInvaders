/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */



#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED

class Objeto {
    private:
        int x, y;
    public:
        Objeto(int _x, int _y);
        virtual void posicionarObjeto();
};

#endif // OBJETO_H_INCLUDED
