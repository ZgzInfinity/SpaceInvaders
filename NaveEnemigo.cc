
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
void NaveEnemigo::construirNave(char* rutaNave, char* rutaBala, int anchoBala, int altoBala,
                  int anchoPersonaje, int altoPersonaje, int posNavX, int posNavY, int direccionBala, int tip, int vid){

    // Invocacion al constructor de la clase padre
    Nave::construirNave(anchoBala, altoBala, anchoPersonaje, altoPersonaje,
                        posNavX, posNavY, direccionBala, tip, vid);

    // Bitmaps con las imagenes de la nave del jugador y enemiga
    imgNave = load_bitmap(rutaNave, NULL);
    imgBala = load_bitmap(rutaBala, NULL);
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
    crear_bala(nDisparos, max_disp, disparos, posNaveX, posNaveY, direccion);
    pintar_bala(nDisparos, max_disp, disparos, buffer, imgBala, ancho_b, alto_b);
    elimina_bala(nDisparos, max_disp, disparos, 700, 390);
}
