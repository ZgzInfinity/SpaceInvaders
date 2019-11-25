/*
 **********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 25-11-2019 *********************************
 **********************************************************
 */


/*
 * Fichero de implementacion NaveEnemigo.cc del modulo NaveEnemigo
 */


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
    imgExplosion = load_bitmap("images/pum_enemigo.bmp", NULL);
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
    // Creacion de la bala del enemigo
    if (crear_bala(nDisparos, max_disp, disparos, posNaveX, posNaveY, direccion)){
        // Reproducir sonido de disparo
        play_sample(disparo, 175, 127, 1000, 0);
    }
    // Pintar la bala y eliminarla en caso de chocar con la nave jugador
    pintar_bala(nDisparos, max_disp, disparos, buffer, imgBala, ancho_b, alto_b);
    elimina_bala(nDisparos, max_disp, disparos, 600, 600);
}



/*
 * Pre: <<buffer>> es el bitmap que almacena toda la ejecucion de la partida
 * Post: Ha mostrado por pantalla la explosion de una nave enemiga tras chocar
 *       con una bala del jugador
 */
void NaveEnemigo::explosion(BITMAP* buffer){
    // Reproducir sonido de explosion de nave enemiga
    play_sample(explosivo, 175, 127, 1000, 0);
    // Bitmap de la nave enemiga
    BITMAP *expMedio = create_bitmap(25, 20);
    // Mostrar la explosion de la nave enemiga
    clear_to_color(expMedio, 0x000000);
    blit(expMedio, buffer, 0, 0, posNaveX, posNaveY, 25, 20);
    masked_blit(imgExplosion, buffer, 0, 0, posNaveX - 10, posNaveY, 41, 34);
}



/*
 * Pre: <<e>> es una lista con todos los enemigos naves del juego;
 *      <<mov>> es indica cuanto deben desplazarse los enemigos y <<dir>>
 *      la direccion en la que deben hacerlo
 * Post: Ha desplazado a todas las naves enemigas en la direccion <<dir>>
 *       efectuando el movimiento <<mov>>
 */
void moverEnemigos(NaveEnemigo e[], int& mov, int& dir){
    // Recorrido dde las naves enemigas
    for (int i = 0; i < 55; i++) {
        // Incrementa la posicion x de la nave en dir unidades
        e[i].posNaveX += dir;
    }
    // Control del tipo de movimiento
    if (++mov == 2){
        // Hacia abajo
        mov = 0;
    }
    // Control de si las naves llega al borde del tablero
    if (bordeTablero(e, dir)){
        for (int i = 0; i < 55; i++){
            // Descienden una fila hacia abajo y continuan hacia el otro lado
            e[i].posNaveY += 10;
        }
    }
}



/*
 * Pre: <<e>> es una lista con todos los enemigos naves del juego
 * Post: Ha guardado en la tabla <<e>> todas las naves enemigas que van
 *       a jugar
 */
void insertarEnemigos(NaveEnemigo e[]){
    // Indice de recorrido
    int indice = -1;
    // Tipo de nave enemiga
    int tipo = 0;
    for (int i = 0; i < 5; i++){
        // Insercion de 11 naves de cada tipo
        tipo++;
        if (tipo == 4){
            // Control de desbordamiento del tipo de nave
            tipo = 1;
        }
        for (int j = 0; j < 11; j++){
            // Inserta una nave con el tipo adecuado y en sus correspondientes posiciones x e y
            // Se guarda de tal forma que puede efectuar los disparos con sonido
            indice++;
            e[indice].construirNave((char*)"images/enemigos.bmp", (char*)"images/Bala_enem.bmp",
                                    (char*)"soundEffects/Disparo.wav", (char*)"soundEffects/Explosion.wav",
                                    6, 12, 25, 20, 140 + j * 30, 130 + i * 24, 8, tipo, 1);
        }
    }
}



/*
 * Pre: <<e>> es una lista con todos los enemigos naves del juego;
 *      <<buffer>> es el bitmap que guarda toda la informacion a mostrar en pantalla
 *      y <<mov>> es el tipo de movimiento que sigue cada enemigo
 * Post: Ha pintado todos las naves enemigas en sus correspondientes posiciones despues
 *       de que todas se han movido
 */
void pintarEnemigo(NaveEnemigo e[], BITMAP * buffer, int mov){
    // Indice de la primera nave
    int indice = -1;
    // Recorrido de los tipos posibles de naves
    for (int i = 0; i < 5; i++){
        // Recorrido de las naves de cada tipo
        for (int j = 0; j < 11; j++){
            // Incremento del indice
            indice++;
            // Control de si la nave tiene vidas o no
            if (e[indice].vidas > 0){
                // La nave no ha sido derrotada y se pinta de nuevo
                e[indice].pintar(buffer, mov, e[indice].tipo - 1);
            }
        }
    }
}



