

/*
 * Fichero de interfaz Graficos.h del modulo Graficos
 */


#ifndef GRAFICOS_H_INCLUDED
#define GRAFICOS_H_INCLUDED

#include <allegro.h>



/*
 * Pre: <<p>> es el bitmap que guarda el fondo del menu con las intrucciones;
 *      <<menu_portada>> es la banda a reproducir en el menu principal y
 *      << startPressed>> es el sonido a reproducir cuando el usuario presiona
 *      la tecla ENTER para empezar a jugar
 * Post: Ha mostrado en el buffer la pantalla con el menu de inicio y las instrucciones,
 *       ha reproducido la pista <<menu_portada>> hasta que el usuario ha presionado la tecla
 *       ENTER deteniendola y reproduciendo el sonido <<startPressed>>
 */
void portada(BITMAP *p, SAMPLE* menu_portada, SAMPLE* startPressed);



/*
 * Pre: <<fondo>> es el bitmap que almacena la pantalla de juego a mostrar y
 *      <<buffer>> es el bitmap que guarda toda la interfaz del juego y el usuario
 * Post: Ha cargado la pantalla de juego en buffer para ser visible por el usuario
 */
void imprimir(BITMAP *fondo, BITMAP *buffer);



/*
 * Pre: ---
 * Post: Ha imprimido el fondo de partida por pantalla
 */
void imprimirFondoPartida(BITMAP* fondo, BITMAP* buffer);


#endif
