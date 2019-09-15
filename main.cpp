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


bool bordeTablero(NaveEnemigo e[], int& direccion){
    for (int i = 0; i < 55; i++){
        if (e[i].posNaveX > 520 || e[i].posNaveX < 50){
            direccion = -1 * direccion;
            return true;
        }
    }
    return false;
}


void moverEnemigos(NaveEnemigo e[], int& mov, int& dir){
    for (int i = 0; i < 55; i++) {
        e[i].posNaveX += dir;
    }
    if (++mov == 2){
        mov = 0;
    }
    if (bordeTablero(e, dir)){
        for (int i = 0; i < 55; i++){
            e[i].posNaveY += 10;
        }
    }

}

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
            e[indice].construirNave("Imagenes/enemigos.bmp", "Imagenes/Bala_enem.bmp",
                                    "SoundEffects/Disparo.wav", "SoundEffects/Explosion.wav", 6, 12, 25, 20, 140 + j * 30, 130 + i * 24, 8, tipo, 1);
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



void crear_bala_enemigo(NaveEnemigo e[], int& azarEnemigo){
    if (e[azarEnemigo].nDisparos == 0){
        azarEnemigo = rand() % 55;
        while (e[azarEnemigo].vidas == 0){
            azarEnemigo = rand() % 55;
        }
    }
}


void reproducirMusicaFondo(SAMPLE *musica_fondo, int& pista){
    if (key[KEY_ENTER]){
        pista++;
        if (pista == 9){
            pista = 0;
        }
        switch(pista){
            case 1:
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/Alien3Stage2.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 2:
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/Alien3Stage3.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 3:
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/Alien3Stage5.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 4:
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/GoStraight.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 5:
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/JungleBase.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 6:
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/MoonBeach.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 7:
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/BeatnikOnTheShip.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            default:
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/TheLastSoul.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;

        }
    }
}


int main(){

    srand(time(NULL));

    inicia_allegro(600, 600);
    inicia_audio(70,70);
    install_mouse();

    BITMAP *buffer = create_bitmap(600, 600);
    BITMAP *p = load_bitmap("Imagenes/portada.bmp", NULL);
    BITMAP *fondo = load_bitmap("Imagenes/fondo.bmp", NULL);


    // imprimirFondoInicial(buffer);

    SAMPLE *musica_portada = load_sample("Soundtrack/MainTitle.wav");
    SAMPLE *musica_fondo = load_sample("Soundtrack/Alien3Stage2.wav");


    play_sample(musica_portada, 255, 250, 1000, 0);
    portada(p);
    stop_sample(musica_portada);


    NaveJugador n;
    n.construirNave("Imagenes/nave.bmp", "Imagenes/bala2.bmp",
                    "SoundEffects/Bala.wav", "SoundEffects/ExplosionJug.wav", 6, 12, 30, 20, 290, 500, -8, 0, 3);

    int pista = 0;

    NaveEnemigo e[60];
    insertarEnemigos(e);

    Bala disparos[4];

    Bala disparosEnem[4];


    int azarEnemigo = rand() % 55;
    int mov = 0, dir = -5;
    int retardo = 10;

    while (!key[KEY_ESC]){
         clear_to_color(buffer, 0x000000);

         reproducirMusicaFondo(musica_fondo, pista);

         if (e[0].temporizador(retardo)){
            moverEnemigos(e, mov, dir);
         }


         n.pintar(buffer, 0, 0);
         n.mover();

         n.crear_bala_jugador(disparos);
         n.disparar(disparos, buffer);


         for (int i = 0; i < 55; i++){
            if (eliminar_bala_choque(n, e[i], disparos)){
                e[i].explosion(buffer);
            }
         }

         if (e[0].temporizador(10)){
            moverEnemigos(e, mov, dir);
         }

         pintarEnemigo(e, buffer, mov);
         crear_bala_enemigo(e, azarEnemigo);
         e[azarEnemigo].disparar(disparosEnem, buffer);

         if (eliminar_bala_choque(e[azarEnemigo], n, disparosEnem)){
                n.explosion(buffer, fondo);
         }

         imprimir(fondo, buffer);
         blit(buffer, screen, 0, 0, 0, 0, 600, 600);
         rest(20);
    }

    return 0;
}
END_OF_MAIN ()
