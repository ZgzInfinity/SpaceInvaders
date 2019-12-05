

/*
 * Fichero de interfaz NaveEnemigo.h del modulo Nave
 */

#ifndef NAVEENEMIGO_H_INCLUDED
#define NAVEENEMIGO_H_INCLUDED

#include <allegro.h>
#include "../Bala/Bala.h"

/*
 * Representacion del tipo de dato Nave
 */

struct NaveEnemigo {
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

    SAMPLE *disparo;
    SAMPLE *escudo;
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
    void construirNave(char* rutaNave, char* rutaBala, char* rutaDisparo, char* rutaEscudo, char* rutaExplosion,
                       int anchoBala, int altoBala, int anchoPersonaje, int altoPersonaje, int posNavX,
                       int posNavY, int direccionBala, int tip, int vid);



    /*
     * Pre: <<buffer>> es un bitmap que almacena todas los bitmaps auxiliares a imprimir en pantalla;
     *      <<ix>> e <<iy>> son las coordenadas donde se va a pintar la nave
     * Post: Ha pintado la nave en las coordenadas <<ix>> e <<iy>>
     */
    void pintar(BITMAP* buffer, int ix, int iy);



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
     * Pre: <<buffer>> es el bitmap que almacena toda la ejecucion de la partida
     * Post: Ha mostrado por pantalla la explosion de una nave enemiga tras chocar
     *       con una bala del jugador
     */
    void explosion(BITMAP* buffer);


};


/*
 * Pre: <<e>> es una lista con todos los enemigos naves del juego;
 *      <<mov>> es indica cuanto deben desplazarse los enemigos y <<dir>>
 *      la direccion en la que deben hacerlo
 * Post: Ha desplazado a todas las naves enemigas en la direccion <<dir>>
 *       efectuando el movimiento <<mov>>
 */
void moverEnemigos(NaveEnemigo e[], int& mov, int& dir);



/*
 * Pre: <<e>> es una lista con todos los enemigos naves del juego
 *      y <<vidas>> son las vidas de los enemigos que varian con la
 *      dificultad de la partida
 * Post: Ha guardado en la tabla <<e>> todas las naves enemigas que van
 *       a jugar
 */
void insertarEnemigos(NaveEnemigo e[], int& vidas);



/*
 * Pre: <<e>> es una lista con todos los enemigos naves del juego;
 *      <<buffer>> es el bitmap que guarda toda la informacion a mostrar en pantalla
 *      y <<mov>> es el tipo de movimiento que sigue cada enemigo
 * Post: Ha pintado todos las naves enemigas en sus correspondientes posiciones despues
 *       de que todas se han movido
 */
void pintarEnemigo(NaveEnemigo e[], BITMAP * buffer, int mov);



#endif // NAVEENEMIGO_H_INCLUDED
