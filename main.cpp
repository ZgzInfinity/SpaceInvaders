/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Iniciador.h"
#include "Bala.h"
#include "NaveJugador.h"
#include "NaveEnemigo.h"
#include "Graficos.h"
#include "Escudo.h"


using namespace std;

// Constantes del modulo

const int MAX_ENEMIGOS = 60;
const int MAX_BALAS = 4;


bool bordeTablero(NaveEnemigo e[], int& direccion){
    for (int i = 0; i < 55; i++){
        if (e[i].posNaveX > 520 || e[i].posNaveX < 50){
            direccion = -1 * direccion;
            return true;
        }
    }
    return false;
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
            e[indice].construirNave("Imagenes/enemigos.bmp", "Imagenes/Bala_enem.bmp",
                                    "SoundEffects/Disparo.wav", "SoundEffects/Explosion.wav",
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



/*
 * Pre: <<e>> es una lista con todos los enemigos naves del juego
 *      y <<azarEnemigo>> es el indice del enemigo que va a efectuar el disparo
 *      contra la nave del jugador
 * Post: Ha creado la bala con la que la nave con indice <<azarEnemigo>> dispara
 *       a la nave del jugador
 */
void crear_bala_enemigo(NaveEnemigo e[], int& azarEnemigo){
    // Si ese enemigo no tiene ninguna bala en juego
    if (e[azarEnemigo].nDisparos == 0){
        // Se selecciona un nuevo enemigo a disparar
        azarEnemigo = rand() % 55;
        while (e[azarEnemigo].vidas == 0){
            // Verificacion de que la nave a disparar no esta muerta
            azarEnemigo = rand() % 55;
        }
    }
}



/*
 * Pre: <<musica_fondo>> es la banda sonora que se va a reproducir
 *      durante la partida y <<pista>> es el indice de la pista musical actual
 * Post: Ha reproducido la pista musical <<musica_fondo>> y ha guardado en <<<pista>>
 *       el indice correspondiente a la siguiente pista a reproducir
 */
void reproducirMusicaFondo(SAMPLE *musica_fondo, int& pista){
    // Si durante el juego el jugador presionar ENTER
    if (key[KEY_ENTER]){
        // Incremento de la pista
        pista++;
        // Control de desbordamiento de pistas ya que solo hay 9
        if (pista == 9){
            // Reinicio de la pista
            pista = 0;
        }
        // Determinacion de que pista se debe tocar en funcion de la actual
        switch(pista){
            case 1:
                    // Detecion de la pista 0 y reproduccion de la pista 1
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/Alien3Stage2.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 2:
                    // Detecion de la pista 1 y reproduccion de la pista 2
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/Alien3Stage3.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 3:
                    // Detecion de la pista 2 y reproduccion de la pista 3
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/Alien3Stage5.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 4:
                    // Detecion de la pista 3 y reproduccion de la pista 4
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/GoStraight.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 5:
                    // Detecion de la pista 4 y reproduccion de la pista 5
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/JungleBase.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 6:
                    // Detecion de la pista 5 y reproduccion de la pista 6
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/MoonBeach.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            case 7:
                    // Detecion de la pista 6 y reproduccion de la pista 7
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/BeatnikOnTheShip.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
            default:
                    // Detecion de la pista 7 y reproduccion de la pista 8
                    stop_sample(musica_fondo);
                    musica_fondo = load_sample("Soundtrack/TheLastSoul.wav");
                    play_sample(musica_fondo, 255, 250, 1000, 0);
                    break;
        }
    }
}



/*
 * Programa del mitico juego del SpaceInvaders
 */
int main(){

    // Inicio de numeros pseudoaleatorios para control de disparos enemigos
    srand(time(NULL));
    // Creacion de la pantalla de juego principal
    inicia_allegro(600, 600);
    // Habilitar la reproduccion de sonidos
    inicia_audio(70,70);
    // Habilitar interrupciones del raton
    install_mouse();

    // Creacion de los bitmaps que muestran los creditos iniciales del juego
    BITMAP *presenta = load_bitmap("Imagenes/presenta.bmp", NULL);
    BITMAP *licencia = load_bitmap("Imagenes/license.bmp", NULL);

    // Creacion de los bitmaps que muestran el menu principal con las
    // instrucciones y el fondo de pantalla durante el juego
    BITMAP *logo = load_bitmap("Imagenes/logo.bmp", NULL);
    BITMAP *p = load_bitmap("Imagenes/portada.bmp", NULL);
    BITMAP *fondo = load_bitmap("Imagenes/fondo.bmp", NULL);
    BITMAP *escudo = load_bitmap("Imagenes/escudos.bmp", NULL);
    BITMAP *buffer = create_bitmap(600, 600);

    // Creacion de las pistas de juego
    SAMPLE *musica_portada = load_sample("Soundtrack/MainTitle.wav");
    SAMPLE *musica_menu = load_sample("Soundtrack/MainTitle2.wav");
    SAMPLE *musica_fondo = load_sample("Soundtrack/Alien3Stage2.wav");
    SAMPLE *start_pressed = load_sample("SoundEffects/StartPressed.wav");

    // Reproducir sonido de menu del juego y mostrar la portada del juego
    play_sample(musica_portada, 255, 250, 1000, 0);

    // Imprimir logo inicial en pantalla
    masked_blit(logo, screen, 0, 0, 69, 69, 462, 461);

    // Esperar 200 milisegundos y limpiar pantalla
    rest(5500);
    clear_to_color(screen, 0x000000);
    rest(2000);
    masked_blit(presenta, screen, 0, 0, 69, 69, 462, 461);

    rest(5000);
    clear_to_color(screen, 0x000000);
    rest(4000);
    masked_blit(licencia, screen, 0, 0, 69, 69, 462, 461);

    // Esperar 2000 milisegundos
    rest(5500);
    clear_to_color(screen, 0x000000);
    stop_sample(musica_portada);

    // Reproducir sonido de menu del juego y mostrar la portada del juego
    play_sample(musica_menu, 255, 250, 1000, 0);
    portada(p, musica_menu, start_pressed);

    // Dibujo de la nave del enemigo en la posicion inferior del tablero
    NaveJugador n;
    n.construirNave("Imagenes/nave.bmp", "Imagenes/bala2.bmp",
                    "SoundEffects/Bala.wav", "SoundEffects/ExplosionJug.wav", 6, 12, 30, 20, 290, 500, -8, 0, 3);

    // Codigo de la actual pista musical a repetir
    int pista = 0;

    // Creacion y insercion de los enemigos con los que jugar
    NaveEnemigo e[MAX_ENEMIGOS];
    insertarEnemigos(e);

    // Maximo numero de disparos a efectuar por el jugador y los enemigos
    // Recomendado no cambiar porque se ralentiza
    Bala disparos[MAX_BALAS];
    Bala disparosEnem[MAX_BALAS];

    // Creacion del conjunto de escudos
    Escudo escudos[30];
    construirEscudos(escudos);

    // Indice del primer enemigo a disparar
    int azarEnemigo = rand() % 55;
    // Determinacion del movimiento y direccion de los enemigos
    int mov = 0, dir = -5;

    // Tiempo de velocidad de movimiento
    int retardo = 10;

    // El juego continua hasta que se presione la tecla ESCAPE
    while (!key[KEY_ESC]){
         // Limpiar la pantalla de juego
         clear_to_color(buffer, 0x000000);

         // Pintar los escudos
         pintarEscudos(escudos, escudo, buffer);

         // Reproducir la banda actual de juego y verificar si se ha cambiado
         reproducirMusicaFondo(musica_fondo, pista);

         // Controlar si los enemigos se deben mover
         if (e[0].temporizador(retardo)){
            // Tiempo transcurrido desde el movimiento anterior sobrepasado
            // Se vuelven a mover
            moverEnemigos(e, mov, dir);
         }

         // Pintar la nave del jgador en la pantalla de juego
         n.pintar(buffer, 0, 0);
         // Mover la nave si el usuario lo desea
         n.mover();

         // Crear bala del jugador y efectuar disparos
         n.crear_bala_jugador(disparos);
         n.disparar(disparos, buffer);

         // Para cada una de las naves enemigas se comprueba si
         // las disparadas por el jugador han chocado con alguna de ellas
         for (int i = 0; i < 55; i++){
            // Si ha habido choque destruir la nave enemiga
            if (eliminar_bala_choque(n, e[i], disparos)){
                e[i].explosion(buffer);
            }
         }

         // Control de eliminacion de escudos al chocar las balas de la nave
         eliminar_bala_escudo(n, escudos, disparos);

         // Controlar si los enemigos se deben mover
         if (e[0].temporizador(retardo)){
            // Tiempo transcurrido desde el movimiento anterior sobrepasado
            // Se vuelven a mover
            moverEnemigos(e, mov, dir);
         }

         // Pintar los enemigos en las nuevas posiciones
         pintarEnemigo(e, buffer, mov);
         // Crear balas con las qeue van a disparar los enemigos
         crear_bala_enemigo(e, azarEnemigo);
         // Seleccion de que enemigo dispara
         e[azarEnemigo].disparar(disparosEnem, buffer);

         // Si la bala disparada por un enemigo choca con el jugador
         if (eliminar_bala_choque(e[azarEnemigo], n, disparosEnem)){
                // Destruir la nave del jugador
                n.explosion(buffer, fondo);
         }

         // Control de elimininacion de escudos si chocan balas de enemigos
         eliminar_bala_escudo(e[azarEnemigo], escudos, disparosEnem);

         // Imprimir todo en la pantalla de juego
         imprimir(fondo, buffer);
         blit(buffer, screen, 0, 0, 0, 0, 600, 600);
         // Detener la ejecucion 20 milisegundos para no sobrecargar
         rest(20);
    }
    // Fin de la ejecucion del programa
    return 0;
}
END_OF_MAIN ()
