
#include "Nave.h"


/*
 * Pre: <<rutaNave>> es el archivo que contiene la imagen de la nave; <<rutaBala>> es el archivo que contiene
 *      el tipo de bala que dispara; <<anchoBala>> y <<altoBala>> son las dimensiones de la bala;
 *      <<anchuraPersonaje>> y <<alturaPersonaje>> son las dimensiones de la nave;
 *      <<posNavX>> y <<posNavY>> son las coordenadas cartesianas de la nave
 *      <<tip>> es el tipo de nave y <<vid>> es el numero de vidas de la nave
 * Post: Ha creado una nave enemiga o de jugador a partir de los datos facilitados
 *       como parametros
 */
Nave::Nave(int anchoBala, int altoBala, int anchoPersonaje,
                         int altoPersonaje, int posNavX, int posNavY, int direccionBala, int tip, int vid){

    // Asignacion de las coordenadas de la nave
    posNaveX = posNavX;
    posNaveY = posNavY;
    // Establecer el numero total de disparos de la nave y
    // cuantos se han disparado ya
    max_disp = 4;
    nDisparos = 0;
    // Contador de tiempo de la nave
    tick = 0;
    // Dimensiones del tipo de bala que dispara
    ancho_b = anchoBala;
    alto_b = altoBala;
    // Dimensiones del tipo de la nave
    ancho_p = anchoPersonaje;
    alto_p = altoPersonaje;
    // Direccion de disparo de la bala
    direccion = direccionBala;
    // Tipo de nave y numero de vidas
    tipo = tip;
    vidas = vid;
}



/*
 * Pre: <<tiempo>> es un instante temporal que guarda cada cuanto tiempo
 *      se puede volver a dibujar una bala nueva
 * Post: Si ha transcurrido el tiempo <<tiempo>> ha resteado el contador temporal de
 *       la nave y ha devuelto <<true>>. En caso contrario ha devuelto <<fasle>>
 */
bool Nave::temporizador(int tiempo){
    // Aumentar el contador temporal de la nave
    tick++;
    // Si pasa el tiempo se resetea el contador
    if (tick == tiempo){
        tick = 0;
        return true;
    }
    else {
        return false;
    }
}



