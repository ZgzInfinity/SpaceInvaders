
#include "NaveEnemigo.h"


/*
 * Pre: <<rutaNave>> es el archivo que contiene la imagen de la nave; <<rutaBala>> es el archivo que contiene
 *      el tipo de bala que dispara; <<anchoBala>> y <<altoBala>> son las dimensiones de la bala;
 *      <<anchuraPersonaje>> y <<alturaPersonaje>> son las dimensiones de la nave;
 *      <<posNavX>> y <<posNavY>> son las coordenadas cartesianas de la nave
 *      <<tip>> es el tipo de nave y <<vid>> es el numero de vidas de la nave
 * Post: Ha creado una nave enemiga o de jugador a partir de los datos facilitados
 *       como parametros
 */
void NaveEnemigo::construirNave(char* rutaNave, char* rutaBala, char* rutaDisparo, char* rutaExplosion, int anchoBala, int altoBala, int anchoPersonaje, int altoPersonaje,
                         int posNavX, int posNavY, int direccionBala, int tip, int vid){

    // Asignacion de las coordenadas de la nave
    posNaveX = posNavX;
    posNaveY = posNavY;
    // Establecer el numero total de disparos de la nave y
    // cuantos se han disparado ya
    max_disp = 2;
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
    // Bitmaps con las imagenes de la nave del jugador y enemiga
    imgNave = load_bitmap(rutaNave, NULL);
    imgBala = load_bitmap(rutaBala, NULL);
    imgExplosion = load_bitmap("Imagenes/pum_enemigo.bmp", NULL);
    disparo = load_wav(rutaDisparo);
    explosivo = load_wav(rutaExplosion);
}




/*
 * Pre: <<buffer>> es un bitmap que almacena todas los bitmaps auxiliares a imprimir en pantalla;
 *      <<ix>> e <<iy>> son las coordenadas donde se va a pintar la nave
 * Post: Ha pintado la nave en las coordenadas <<ix>> e <<iy>>
 */
void NaveEnemigo::pintar(BITMAP* buffer, int ix, int iy){
    // Pintar la nave en bitmao buffer con toda su informacion
    masked_blit(imgNave, buffer, ix * ancho_p, iy * alto_p , posNaveX, posNaveY, ancho_p, alto_p);
}



/*
 * Pre: <<tiempo>> es un instante temporal que guarda cada cuanto tiempo
 *      se puede volver a dibujar una bala nueva
 * Post: Si ha transcurrido el tiempo <<tiempo>> ha resteado el contador temporal de
 *       la nave y ha devuelto <<true>>. En caso contrario ha devuelto <<fasle>>
 */
bool NaveEnemigo::temporizador(int tiempo){
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



/*
 * Pre: <<disparos>> es una tabla que almacena todas las balas disparadas por la nave y <buffer>> que
 *      guarda todas lo bitmaps auxiliares a imprimir por pantalla
 *      Ha guardado las balas de la tabla <<disparos>> en el bitmap <<buffer>> pora imprimirlas
 *      despues por pantalla
 */
void NaveEnemigo::disparar(Bala disparos[], BITMAP* buffer){
    // Si es una nave de tipo enemigo entonces dispara la bala
    if (tipo)
    if (crear_bala(nDisparos, max_disp, disparos, posNaveX, posNaveY, direccion)){
        play_sample(disparo, 255, 250, 1000, 0);
    }
    pintar_bala(nDisparos, max_disp, disparos, buffer, imgBala, ancho_b, alto_b);
    elimina_bala(nDisparos, max_disp, disparos, 600, 600);
}



void NaveEnemigo::explosion(BITMAP* buffer){
    play_sample(explosivo, 255, 250, 1000, 0);
    BITMAP *expMedio = create_bitmap(25, 20);
    clear_to_color(expMedio, 0x000000);
    blit(expMedio, buffer, 0, 0, posNaveX, posNaveY, 25, 20);
    masked_blit(imgExplosion, buffer, 0, 0, posNaveX - 10, posNaveY, 41, 34);
}




