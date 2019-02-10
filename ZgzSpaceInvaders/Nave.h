/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */



#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED


const int ARRIBA = 72;
const int ABAJO = 80;
const int DERECHA = 77;
const int IZQUIERDA = 75;

class Nave {
private:
    int x, y;
    int vidas;
public:
    Nave(int _x, int _y, int _vidas);
    void construir();
    void eliminar();
    void desplazar();
    void pintarVidas();
    void explotar();
    int obtenerX();
    int obtenerY();
    void quitarVida();
    int obtenerVidas();
};

#endif // NAVE_H_INCLUDED
