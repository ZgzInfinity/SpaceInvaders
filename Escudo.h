

/*
 * Fichero de interfaz Bala.h del modulo Bala
 */


#include <allegro.h>



#ifndef ESCUDO_H_INCLUDED
#define ESCUDO_H_INCLUDED


const int MAX_RANGO = 3;
const int NUM_ESCUDOS = 22;

/*
 * Representacion del tipo de dato Bala
 */
struct Escudo{
    // Coordenadas cartesianas del escudo
    int x , y;
    // Nivel de danyo del escudo
    int danyo;
    // Tipo de escudo a dibujar en funcion del danyo
    int tipo;
};


/*
 * Pre: <<escudo es una tabla vacia sin escudos
 * Post: Ha almacenado en la tabla <<escudos>> todos los escudos
 *       a dibujar en el tablero de juego
 */
void construirEscudos(struct Escudo escudos[]);



/*
 * Pre: <escudo es una tabla vacia sin escudos; <<img_escudo>> es el
 *      bitmap asociado que representa los escudos y <<buffer>> es el bitmap
 *      que representa toda la pantalla del juego
 */
void pintarEscudos(struct Escudo ES[], BITMAP* img_escudo, BITMAP* buffer);

# endif

