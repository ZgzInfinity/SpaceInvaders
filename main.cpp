/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <conio.h>
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
            e[indice].construirNave((char*)"Imagenes/enemigos.bmp", (char*)"Imagenes/Bala_enem.bmp",
                                    (char*)"SoundEffects/Disparo.wav", (char*)"SoundEffects/Explosion.wav",
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
void reproducirMusicaFondo(SAMPLE* primera_pista, SAMPLE* segunda_pista, SAMPLE* tercera_pista,
                           SAMPLE* cuarta_pista, SAMPLE* quinta_pista, SAMPLE* sexta_pista,
                           SAMPLE* septima_pista, SAMPLE* octava_pista, int& pista, bool& primeraVuelta){

    cout << "La pista actual es " << pista << endl;
    // Si durante el juego el jugador presionar ENTER
    if (key[KEY_PLUS_PAD]){
         // Capturar la tecla ya pulsada
        while (kbhit()){
            // Limpiar el buffer del teclado para coger nuevas teclas
            getche();
        }
        // Incremento de la pista
        pista++;
        // Detener ejecucion 500 milisegundos para
        // ignorar las posibles interrupciones de teclado siguientes
        rest(500);
        // Control de desbordamiento de pistas ya que solo hay 9
        if (pista == 9){
            // Se completa la vuelta
            primeraVuelta = false;
            // Reinicio de la pista
            pista = 0;
        }
        // Determinacion de que pista se debe tocar en funcion de la actual
        switch(pista){
            case 1:
                // Comprobar que es la primera vuelta de sonidos
                if(!primeraVuelta){
                    // Se han reproducido todos se para el ulitmo
                    stop_sample(octava_pista);
                }
                // Detecion de la pista 0 y reproduccion de la pista 1
                play_sample(primera_pista, 255, 127, 1000, 0);
                break;
            case 2:
                // Detecion de la pista 1 y reproduccion de la pista 2
                stop_sample(primera_pista);
                play_sample(segunda_pista, 255, 127, 1000, 0);
                break;
            case 3:
                // Detecion de la pista 2 y reproduccion de la pista 3
                stop_sample(segunda_pista);
                play_sample(tercera_pista, 255, 127, 1000, 0);
                break;
            case 4:
                // Detecion de la pista 3 y reproduccion de la pista 4
                stop_sample(tercera_pista);
                play_sample(cuarta_pista, 255, 127, 1000, 0);
                break;
            case 5:
                // Detecion de la pista 4 y reproduccion de la pista 5
                stop_sample(cuarta_pista);
                play_sample(quinta_pista, 255, 127, 1000, 0);
                break;
            case 6:
                // Detecion de la pista 5 y reproduccion de la pista 6
                stop_sample(quinta_pista);
                play_sample(sexta_pista, 255, 127, 1000, 0);
                break;
            case 7:
                // Detecion de la pista 6 y reproduccion de la pista 7
                stop_sample(sexta_pista);
                play_sample(septima_pista, 255, 127, 1000, 0);
                break;
            case 8:
                // Detecion de la pista 7 y reproduccion de la pista 8
                stop_sample(septima_pista);
                play_sample(octava_pista, 255, 127, 1000, 0);
                break;
        }
    }
}



/*
 * Pre:
 * Post:
 */
void controlJuegoEnPausa(SAMPLE* musica_fondo, SAMPLE* sonido_pausa){
    // Control de si el jugador ha parado el juego
    if (key[KEY_TAB]){
        // Tecla de modo pausa pulsada
        // Detener la musica de fondo de la partida
        stop_sample(musica_fondo);
        rest(200);
        // Emitir sonido del modo pausa
        play_sample(sonido_pausa, 255, 127, 1000, 0);
        // Bucle infinito que espera a que la tecla sea pulsada de nuevo

        // Capturar la tecla ya pulsada
        while (kbhit()){
            // Limpiar el buffer del teclado para coger nuevas teclas
            getche();
        }
        // Detener ejecucion 200 milisegundos
        rest(200);
        // Bucle infinito hasta que se pulse de nuevo la tecla
        while (1){
            // Verificar si la tecla ha sido pulsada de nuevo
            if (key[KEY_TAB]){
                // Tiempo para capturar la tecla y reanudar la partida bien
                rest(200);
                // Salida del bucle infinito
                break;
            }
        }
        // Reproduce de nuevo la banda sonora de la partida
        play_sample(musica_fondo, 255, 127, 1000, 0);
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
    SAMPLE *start_pressed = load_sample("SoundEffects/StartPressed.wav");
    SAMPLE *sonido_pausa = load_sample("SoundEffects/Pausa.wav");

    // Pistas que suenan durante la partida
    SAMPLE *primera_pista = load_sample("Soundtrack/Alien3Stage2.wav");
    SAMPLE *segunda_pista = load_sample("Soundtrack/Alien3Stage3.wav");
    SAMPLE *tercera_pista = load_sample("Soundtrack/Alien3Stage5.wav");
    SAMPLE *cuarta_pista = load_sample("Soundtrack/BeatnikOnTheShip.wav");
    SAMPLE *quinta_pista = load_sample("Soundtrack/GoStraight.wav");
    SAMPLE *sexta_pista = load_sample("Soundtrack/JungleBase.wav");
    SAMPLE *septima_pista = load_sample("Soundtrack/MoonBeach.wav");
    SAMPLE *octava_pista = load_sample("Soundtrack/TheLastSoul.wav");

    // Reproducir sonido de menu del juego y mostrar la portada del juego
    play_sample(musica_portada, 255, 127, 1000, 0);

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
    play_sample(musica_menu, 255, 127, 1000, 0);
    portada(p, musica_menu, start_pressed);

    // Dibujo de la nave del enemigo en la posicion inferior del tablero
    NaveJugador n;
    n.construirNave((char*)"Imagenes/nave.bmp", (char*)"Imagenes/bala2.bmp",
                    (char*)"SoundEffects/Bala.wav", (char*)"SoundEffects/ExplosionJug.wav", 6, 12, 30, 20, 290, 500, -8, 0, 3);

    // Codigo de la actual pista musical a repetir
    int pista = 0;

    // Control de vuelta de sonidos
    bool primeraVuelta = true;

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
        // Controlar si el jugador presiona la tecla pausa
        controlJuegoEnPausa(NULL, sonido_pausa);

        // Limpiar la pantalla de juego
        clear_to_color(buffer, 0x000000);

        // Pintar los escudos
        pintarEscudos(escudos, escudo, buffer);

        // Reproducir la banda actual de juego y verificar si se ha cambiado
        reproducirMusicaFondo(primera_pista, segunda_pista, tercera_pista,
                              cuarta_pista, quinta_pista, sexta_pista,
                              septima_pista, octava_pista, pista, primeraVuelta);

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
