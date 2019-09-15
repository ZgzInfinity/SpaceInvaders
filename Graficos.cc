
/*
 * Fichero de implementacion Graficos.cc del modulo Graficos
 */

#include "Graficos.h"


void portada(BITMAP *p){
    int parpadeo = 0;
    int y = 0;
    int cont = 0;
    bool salida = false;
    bool cargando = false;
    while (!salida){
        if (parpadeo < 25){
            blit(p, screen, 0, y, 0, 100, 600, 400);
        }
        else {
            blit(p, screen, 600, y, 0, 100, 600, 400);
        }

        if (key[KEY_ENTER]){
            y = 400;
            cargando = true;
        }
        if (cargando) {
            cont++;
        }
        if (cont > 400){
            salida = true;
        }

        rest(5);
        if (++parpadeo == 50){
            parpadeo = 0;
        }
    }

    clear_to_color(screen, 0x000000);

}


void imprimir(BITMAP *fondo, BITMAP *buffer){
    masked_blit(fondo, buffer, 0, 0, 0, 0, 600, 600);
}


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
            blit(menuComenzar, buffer, 0, 0, 0, 0, 600, 600);
            if (mouse_b & 1){
                comenzarJuego = true;
            }
        }
        else if (mouse_x > 374 && mouse_x < 535 && mouse_y > 260 && mouse_y < 291){
            blit(menuOpciones, buffer, 0, 0, 0, 0, 600, 600);
            if (mouse_b & 1){
                entrarOpciones = true;
            }
        }
        else {
            blit(menuReposo, buffer, 0, 0, 0, 0, 600, 600);
        }

        masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22);
        blit(buffer, screen, 0, 0, 0, 0, 600, 600);

    }
}


/*
 * Pre: ---
 * Post: Ha imprimido el fondo de partida por pantalla
 */
void imprimirFondoPartida(BITMAP *fondo, BITMAP *buffer){
    masked_blit(fondo, buffer, 0, 0, 0, 0, 600, 600);
    blit(buffer, screen, 0, 0, 0, 0, 600, 600);
}

