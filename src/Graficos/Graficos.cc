/*
 **********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 25-11-2019 *********************************
 **********************************************************
 */


/*
 * Fichero de implementacion Graficos.cc del modulo Graficos
 */

#include "Graficos.h"



/*
 * Pre: <<p>> es el bitmap que guarda el fondo del menu con las intrucciones;
 *      <<menu_portada>> es la banda a reproducir en el menu principal y
 *      << startPressed>> es el sonido a reproducir cuando el usuario presiona
 *      la tecla ENTER para empezar a jugar
 * Post: Ha mostrado en el buffer la pantalla con el menu de inicio y las instrucciones,
 *       ha reproducido la pista <<menu_portada>> hasta que el usuario ha presionado la tecla
 *       ENTER deteniendola y reproduciendo el sonido <<startPressed>>
 */
void portada(BITMAP *p, SAMPLE* menu_portada, SAMPLE* startPressed){
    // Variables de la rutina
    int parpadeo = 0;
    int y = 0;
    int cont = 0;
    bool salida = false;
    bool cargando = false;
    // Mientras se esta en la pantalla de inicio de juego
    // o de instrucciones
    while (!salida){
        // Control de parpadeo para cambiar imagen
        // de color amarillo a rojo y a viceversa
        if (parpadeo < 25){
            // Mostrar subimagen izquierda
            blit(p, screen, 0, y, 0, 100, 600, 400);
        }
        else {
            // Mostrar subimagen inferior
            blit(p, screen, 600, y, 0, 100, 600, 400);
        }
        // Si se presiona la tecla ENTER
        if (key[KEY_ENTER]){
            // Detecion de la musica del menu principal
            stop_sample(menu_portada);
            // Reproducir sonido del boton START
            play_sample(startPressed, 125, 127, 1000, 0);
            y = 400;
            // Entrar en pantalla de instrucciones
            cargando = true;
        }
        // Si esta la pantalla de opciones activa
        if (cargando) {
            // Contar el tiempo que lleva
            cont++;
        }
        if (cont > 400){
            // Cuando lleva 400 milisegundos desaparece
            salida = true;
        }
        // Detencion de 5 milisegundos
        rest(5);
        // Control del parpadeo para volver a cambiar de color
        if (++parpadeo == 50){
            parpadeo = 0;
        }
    }
    // Se sale de la pantalla de instrucciones y se borra la pantalla
    clear_to_color(screen, 0x000000);
}



/*
 * Pre: <<fondo>> es el bitmap que almacena la pantalla de juego a mostrar y
 *      <<buffer>> es el bitmap que guarda toda la interfaz del juego y el usuario
 * Post: Ha cargado la pantalla de juego en buffer para ser visible por el usuario
 */
void imprimir(BITMAP *fondo, BITMAP *buffer){
    // Mostrar todo el contenido del buffer
    masked_blit(fondo, buffer, 0, 0, 0, 0, 600, 600);
}



/*
 * Pre: ---
 * Post: Ha imprimido el fondo de partida por pantalla
 */
void imprimirFondoPartida(BITMAP *fondo, BITMAP *buffer){
    // Impresion del menu de la paritda
    masked_blit(fondo, buffer, 0, 0, 0, 0, 600, 600);
    blit(buffer, screen, 0, 0, 0, 0, 600, 600);
}



/*
 * Pre: <<e>> es la tabla que contiene todos los enemigos del juego y
 *      <<direccion>> es la direccion en la que se mueven los enemigos
 *      derecha o izquierda
 * Post: Ha devuelto <<true>> si los enemigos han tocado con el borde del tablero,
 *       si su direccion original era derecha cambian a izquierda pero si su direccion
 *       original era la izquierda ahora es la derecha. En caso de no tocar el borde
 *       del tablero la direccion de los enemigos no cambia y devuelve <<false>>
 */
bool bordeTablero(NaveEnemigo e[], int& direccion){
    // Para cada uno de los enemigos
    for (int i = 0; i < 55; i++){
        // Si chocan con el limite del tablero por izquierda o derecha
        if (e[i].posNaveX > 520 || e[i].posNaveX < 50){
            // Cambio del sentido de movimiento
            direccion = -1 * direccion;
            return true;
        }
    }
    // No ha habido contacto con el borde del tablero
    return false;
}




