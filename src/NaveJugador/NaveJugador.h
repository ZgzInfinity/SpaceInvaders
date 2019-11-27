/*
 **********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 25-11-2019 *********************************
 **********************************************************
 */



/*
 * Fichero de interfaz NavJugador.h del modulo NavJugador
 */

#ifndef NAVEJUGADOR_H_INCLUDED
#define NAVEJUGADOR_H_INCLUDED

#include <iostream>
#include <allegro.h>
#include "../Bala/Bala.h"
#include "../Nave/Nave.h"


using namespace std;

/*
 * Representacion del tipo de dato Nave
 */

struct NaveJugador {
    // Coordenadas x e y de la nave
    int posNaveX;
    int posNaveY;
    // Numero de disparos hechos oor la nave
    int nDisparos;
    // Numero maximo de disparos a efectuar
    int max_disp;
    int tick;
    // Dimensiones de anchura y altura de la bala
    int ancho_b;
    int alto_b;
    // Dimension de anchura y altura de la nave
    int ancho_p;
    int alto_p;
    // Sentido de propagacion de la nave
    int direccion;
    // Tipo de la nave
    int tipo;
    // Numero de vidas de la nave
    int vidas;

    // Bitmaps con las imagenes de la nave del jugador y enemiga
    BITMAP *imgNave;
    BITMAP *imgBala;
    BITMAP *imgExplosion;

    // Sonidos de disparo y explosion de la nave del jugador
    SAMPLE *disparo;
    SAMPLE *explosivo;


    /*
     * Pre: <<rutaNave>> es el archivo que contiene la imagen de la nave; <<rutaBala>> es el archivo que contiene
     *      el tipo de bala que dispara; <<anchoBala>> y <<altoBala>> son las dimensiones de la bala;
     *      <<anchuraPersonaje>> y <<alturaPersonaje>> son las dimensiones de la nave;
     *      <<posNavX>> y <<posNavY>> son las coordenadas cartesianas de la nave
     *      <<tip>> es el tipo de nave y <<vid>> es el numero de vidas de la nave
     * Post: Ha creado una nave enemiga o de jugador a partir de los datos facilitados
     *       como parametros
     */
     void construirNave(char* rutaNave, char* rutaBala, char* rutaDisparo, char* rutaExplosion, int anchoBala, int altoBala, int anchoPersonaje,
                       int altoPersonaje, int posNavX, int posNavY, int direccionBala, int tip, int vid);



    /*
     * Pre: <<buffer>> es un bitmap que almacena todas los bitmaps auxiliares a imprimir en pantalla;
     *      <<ix>> e <<iy>> son las coordenadas donde se va a pintar la nave
     * Post: Ha pintado la nave en las coordenadas <<ix>> e <<iy>>
     */
    void pintar(BITMAP* buffer, int ix, int iy);



    /*
     * Pre: ---
     * Post: Haactulizado la posicion de la nave
     */
    void mover();



    /*
     * Pre: <<tiempo>> es un instante temporal que guarda cada cuanto tiempo
     *      se puede volver a dibujar una bala nueva
     * Post: Si ha transcurrido el tiempo <<tiempo>> ha resteado el contador temporal de
     *       la nave y ha devuelto <<true>>. En caso contrario ha devuelto <<fasle>>
     */
    bool temporizador(int tiempo);



    /*
     * Pre: <<disparos>> es una tabla que almacena todas las balas disparadas por la nave y <buffer>> que
     *      guarda todas lo bitmaps auxiliares a imprimir por pantalla
     *      Ha guardado las balas de la tabla <<disparos>> en el bitmap <<buffer>> pora imprimirlas
     *      despues por pantalla
     */
    void disparar(Bala disparos[], BITMAP* buffer);



    /*
     * Pre: <<buffer>> es el bitmap que guarda toda la accion del juego;
     *      <<fondo>> es el bitmap que guarda toda los datos referentes a la
     *      partida y <<muerto>> es un booleano que determina si la nave del
     *      jugador sigue viva o no.
     * Post: Ha pintado la nave de la explosion de la nave del jugador
     *       tras colisionar una bala enemiga con ella y si tras impactar
     *       a la nave le quedan mas vidas <<muerto>> toma valor falso.
     *       En caso contrario toma valor <<true>>
     */
    void explosion(BITMAP* buffer, BITMAP* fondo, bool& muerto);



    /*
     * Pre: <<disparos>> es una tabla que guarda que guarda todas las balas
     *      disparadas por la nave del jugador
     * Post: Ha creado una nueva bala a disparar po el jugador
     */
    void crear_bala_jugador(Bala disparos[]);

};

#endif // NAVEJUGADOR_H_INCLUDED
