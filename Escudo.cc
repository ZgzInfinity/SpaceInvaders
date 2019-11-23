
#include "Escudo.h"



/*
 * Pre: <<escudo es una tabla vacia sin escudos
 * Post: Ha almacenado en la tabla <<escudos>> todos los escudos
 *       a dibujar en el tablero de juego
 */
void construirEscudos(struct Escudo escudos[]){

    // Matriz de dibujo de los escudos
    char posMuro[MAX_RANGO][NUM_ESCUDOS] = {
       "AEC   AEC   AEC   AEC",
       "B D   B D   B D   B D",
    };
    // Indice de recorrido de los escudos
    int r = 0;
    // Recorrido de todos los escudos
    for (int i = 0; i < NUM_ESCUDOS - 1; i++){
        for (int j = 0; j < MAX_RANGO - 1; j++){
            if (posMuro[j][i] != ' '){
                // Coordenadad x e y de cada escudo
                escudos[r].x = 90 + i * 20;
                escudos[r].y = 450 + j * 15;
                // Nivel de danyo inicial del escudo
                escudos[r].danyo = 0;

                // Niveles de danyo del escudo
                if (posMuro[j][i] == 'A'){
                    // Escudo sin danyo
                    escudos[r].tipo = 0;
                }
                if (posMuro[j][i] == 'B'){
                    // Escudo con un disparo
                    escudos[r].tipo = 1;
                }
                if (posMuro[j][i] == 'C'){
                    // Escudo con dos disparo
                    escudos[r].tipo = 2;
                }
                if (posMuro[j][i] == 'D'){
                    // Escudo con tres disparo
                    escudos[r].tipo = 3;
                }
                if (posMuro[j][i] == 'E'){
                    // Escudo destruido
                    escudos[r].tipo = 4;
                }
                // Aumento del indice de recorrido
                r++;
            }
        }
    }
}



/*
 * Pre: <escudo es una tabla vacia sin escudos; <<img_escudo>> es el
 *      bitmap asociado que representa los escudos y <<buffer>> es el bitmap
 *      que representa toda la pantalla del juego
 */
void pintarEscudos(struct Escudo ES[], BITMAP* img_escudo, BITMAP* buffer){
    // Recorrido de todos los escudos
    for (int i = 0; i < NUM_ESCUDOS - 2; i++){
        // Verificar si esta o no destruido
        if (ES[i].danyo != 3){
            // Si no esta destruido se dibuja en su posicion correcta
            masked_blit(img_escudo, buffer, ES[i].danyo * 20,
                        ES[i].tipo * 16, ES[i].x, ES[i]. y, 20, 16);
        }
    }
}

