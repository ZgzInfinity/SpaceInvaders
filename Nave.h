#ifndef NAVE_H_INCLUDED
#define NAVE_H_INCLUDED


#include <allegro.h>

/*
 * Representacion del tipo de dato Nave
 */


struct Nave {
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

    /*
     * Pre: <<rutaNave>> es el archivo que contiene la imagen de la nave; <<rutaBala>> es el archivo que contiene
     *      el tipo de bala que dispara; <<anchoBala>> y <<altoBala>> son las dimensiones de la bala;
     *      <<anchuraPersonaje>> y <<alturaPersonaje>> son las dimensiones de la nave;
     *      <<posNavX>> y <<posNavY>> son las coordenadas cartesianas de la nave
     *      <<tip>> es el tipo de nave y <<vid>> es el numero de vidas de la nave
     * Post: Ha creado una nave enemiga o de jugador a partir de los datos facilitados
     *       como parametros
     */
    void construirNave(int anchoBala, int altoBala, int anchoPersonaje,
                       int altoPersonaje, int posNavX, int posNavY, int direccionBala, int tip, int vid);


    /*
     * Pre: <<tiempo>> es un instante temporal que guarda cada cuanto tiempo
     *      se puede volver a dibujar una bala nueva
     * Post: Si ha transcurrido el tiempo <<tiempo>> ha resteado el contador temporal de
     *       la nave y ha devuelto <<true>>. En caso contrario ha devuelto <<fasle>>
     */
     bool temporizador(int tiempo);


};

#endif // NAVE_H_INCLUDED
