

/*
 * Fichero de interfaz Graficos.cc del modulo Graficos
 */


#ifndef GRAFICOS_H_INCLUDED
#define GRAFICOS_H_INCLUDED

#include <allegro.h>


/*
 *  Pre: ---
 *  Post: Ha imprimidp el menu inicial del juego
 */
void imprimirFondoInicial(BITMAP *buffer);


/*
 * Pre: ---
 * Post: Ha imprimido el fondo de partida por pantalla
 */
void imprimirFondo(BITMAP* fondo, BITMAP* buffer);


#endif // GRAFICOS_H_INCLUDED
