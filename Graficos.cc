
/*
 * Fichero de implementacion Graficos.cc del modulo Graficos
 */

#include "Graficos.h"


/*
 *  Pre: ---
 *  Post: Ha imprimidp el menu inicial del juego
 */
void imprimirFondoInicial(BITMAP *buffer){

    // BITMAP *fondoEspacio = load_bitmap("Imagenes/espacio.bmp", NULL);
    BITMAP *menuReposo = load_bitmap("Imagenes/menuReposo.bmp", NULL);
    BITMAP *menuComenzar = load_bitmap("Imagenes/menuComenzar.bmp", NULL);
    BITMAP *menuOpciones = load_bitmap("Imagenes/menuOpciones.bmp", NULL);
    BITMAP *cursor = load_bitmap("Imagenes/cursor.bmp", NULL);


    bool comenzarJuego = false;
    bool entrarOpciones = false;

    while (!comenzarJuego && !entrarOpciones){
        if (mouse_x > 125 && mouse_x < 303 && mouse_y > 260 && mouse_y < 291){
            blit(menuComenzar, buffer, 0, 0, 0, 0, 700, 390);
            if (mouse_b & 1){
                comenzarJuego = true;
            }
        }
        else if (mouse_x > 374 && mouse_x < 535 && mouse_y > 260 && mouse_y < 291){
            blit(menuOpciones, buffer, 0, 0, 0, 0, 700, 390);
            if (mouse_b & 1){
                entrarOpciones = true;
            }
        }
        else {
            blit(menuReposo, buffer, 0, 0, 0, 0, 700, 390);
        }

        masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22);
        blit(buffer, screen, 0, 0, 0, 0, 700, 390);

    }
}


/*
 * Pre: ---
 * Post: Ha imprimido el fondo de partida por pantalla
 */
void imprimirFondoPartida(BITMAP *fondo, BITMAP *buffer){
    masked_blit(fondo, buffer, 0, 0, 0, 0, 600, 600);
    blit(buffer, screen, 0, 0, 0, 0, 700, 390);
}

