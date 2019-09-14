/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */

#include <ctime>
#include <cstdlib>
#include "Iniciador.h"
#include "Bala.h"
#include "NaveJugador.h"
#include "NaveEnemigo.h"
#include "Graficos.h"


using namespace std;


void insertarEnemigos(NaveEnemigo e[]){
    int indice = -1;
    int tipo = 0;
    for (int i = 0; i < 5; i++){
        tipo++;
        if (tipo == 4){
            tipo = 1;
        }
        for (int j = 0; j < 11; j++){
            indice++;
            e[indice].construirNave("Imagenes/enemigos.bmp", "Imagenes/Bala_enem.bmp", 6, 12, 25, 20, 140 + j * 30, 100 + i * 24, 8, tipo, 1);
        }
    }
}


void pintarEnemigo(NaveEnemigo e[], BITMAP * buffer, int mov){
    int indice = -1;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 11; j++){
            indice++;
            if (e[indice].vidas > 0){
                e[indice].pintar(buffer, mov, e[indice].tipo - 1);
            }
        }
    }
}


int main(){

    srand(time(NULL));

    inicia_allegro(700, 390);
    inicia_audio(70,70);
    install_mouse();

    BITMAP *buffer = create_bitmap(700, 390);

    imprimirFondoInicial(buffer);

    NaveJugador n;
    n.construirNave("Imagenes/nave.bmp", "Imagenes/bala2.bmp", 6, 12, 30, 20, 350, 340, -8, 0, 3);

    NaveEnemigo e[60];
    insertarEnemigos(e);

    Bala disparos[4];

    Bala disparosEnem[4];


    int azarEnemigo = rand() % 55;
    int mov = 0;



    while (!key[KEY_ESC]){
         clear_to_color(buffer, 0x000000);
         n.pintar(buffer, 0, 0);
         n.mover();


         if (key[KEY_SPACE] && n.temporizador(5))
         crear_bala(n.nDisparos, n.max_disp, disparos, n.posNaveX, n.posNaveY, n.direccion);
         n.disparar(disparos, buffer);


         for (int i = 0; i < 55; i++){
            eliminar_bala_choque(n, e[i], disparos);
         }

         pintarEnemigo(e, buffer, mov);

         if (e[azarEnemigo].nDisparos == 0){
            azarEnemigo = rand() % 55;
         }

         e[azarEnemigo].disparar(disparosEnem, buffer);
         if (e[0].temporizador(30)){
            if (++mov == 2){
                mov = 0;
            }
         }

         // imprimirFondo(fondoEspacio, buffer);
         blit(buffer, screen, 0, 0, 0, 0, 700, 390);
         rest(20);
    }

    return 0;
}
END_OF_MAIN ()
