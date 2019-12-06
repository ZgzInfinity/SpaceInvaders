/*
 **********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 25-11-2019 *********************************
 **********************************************************
 */



/*
 * Fichero de interfaz Graficos.h del modulo Graficos
 */


#ifndef GRAFICOS_H_INCLUDED
#define GRAFICOS_H_INCLUDED

#include <allegro.h>
#include "../NaveEnemigo/NaveEnemigo.h"



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



/*
 * Pre: <<e>> es la tabla que contiene todos los enemigos del juego y
 *      <<direccion>> es la direccion en la que se mueven los enemigos
 *      derecha o izquierda
 * Post: Ha devuelto <<true>> si los enemigos han tocado con el borde del tablero,
 *       si su direccion original era derecha cambian a izquierda pero si su direccion
 *       original era la izquierda ahora es la derecha. En caso de no tocar el borde
 *       del tablero la direccion de los enemigos no cambia y devuelve <<false>>
 */
bool bordeTablero(NaveEnemigo e[], int& direccion);



/*
 * Pre: <<credit1>> es el bitmap correspondiente a la primera pantalla de creditos
 *      del juego; <<credit2>> es el bitmap correspondiente a la segunda pantalla de
 *      creditos del juego; <<credit3>> es el bitmap correspondiente a la tercera
 *      pantalla de creditos del juego; <<credit4>> es el bitmap correspondiente
 *      a la cuarta pantalla de creditos del juego y <<musica_creditos>> es la
 *      musica a reproducir durante los creditos
 * Post: Ha mostrado las pantalla de creditos finales del juego
 */
void creditosFinales(BITMAP* credit1, BITMAP* credit2,
                     BITMAP* credit3, BITMAP* credit4, SAMPLE* musica_creditos);



/*
 * Pre: <<presentacion>> es el bitmap que muestra el cambio de nivel;
 *      <<nivel1>> es un bitmap que muestra el primer nivel de juego;
 *      <<nivel2>> es un bitmap que muestra el segundo nivel de juego;
 *      <<nivel3>> es un bitmap que muestra el tercer nivel de juego;
 *      <<nivel4>> es un bitmap que muestra el cuarto nivel de juego;
 *      <<nivel5>> es un bitmap que muestra el quinto nivel de juego;
 *      <<nivel6>> es un bitmap que muestra el sexto nivel de juego;
 *      <<nivel7>> es un bitmap que muestra el septimo nivel de juego;
 *      <<nivel8>> es un bitmap que muestra el octavo nivel de juego;
 *      <<musica_nivel>> es la musica a reproducir al presentar el nivel y
 *      <<nivel>> es el nivel actual de dificultad de juego
 * Post: Ha mostrado el nivel de dificultad actual en el que se va a jugar
 *       reproducciendo el sonido de cambio de nivel
 */
void presentarNivel(BITMAP* presentacion, BITMAP* nivel1, BITMAP* nivel2, BITMAP* nivel3,
                    BITMAP* nivel4, BITMAP* nivel5, BITMAP* nivel6, BITMAP* nivel7,
                    BITMAP* nivel8, SAMPLE* musica_nivel, int& nivel);


#endif
