/*
 **********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 25-11-2019 *********************************
 **********************************************************
 */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Iniciador/Iniciador.h"
#include "Bala/Bala.h"
#include "NaveJugador/NaveJugador.h"
#include "NaveEnemigo/NaveEnemigo.h"
#include "Graficos/Graficos.h"
#include "Escudo/Escudo.h"
#include "Control/Control.h"


using namespace std;

// Constantes del modulo

const int MAX_DIM_ENEMIGOS = 60;
const int NUM_ENEMIGOS = 55;
const int MAX_BALAS = 8;
const int NIVEL_MAXIMO = 6;



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
    BITMAP *presenta = load_bitmap("images/presenta.bmp", NULL);
    BITMAP *licencia = load_bitmap("images/license.bmp", NULL);

    // Creacion de los bitmaps que muestran el menu principal con las
    // instrucciones y el fondo de pantalla durante el juego
    BITMAP *logo = load_bitmap("images/logo.bmp", NULL);
    BITMAP *p = load_bitmap("images/portada.bmp", NULL);
    BITMAP *fondo = load_bitmap("images/fondo.bmp", NULL);
    BITMAP *escudo = load_bitmap("images/escudos.bmp", NULL);
    BITMAP *victoria = load_bitmap("images/victoria.bmp", NULL);
    BITMAP *derrota = load_bitmap("images/GameOver.bmp", NULL);
    BITMAP *buffer = create_bitmap(600, 600);

    // Creacion de los bitmaps para las pantallas de opciones
    BITMAP *opcion1 = load_bitmap("images/optionsMenu1.bmp", NULL);
    BITMAP *opcion2 = load_bitmap("images/optionsMenu2.bmp", NULL);
    BITMAP *opcion3 = load_bitmap("images/optionsMenu3.bmp", NULL);

    // Creacion de los bitmaps para las pantallas de volver a jugar
    BITMAP *jugar1 = load_bitmap("images/again1.bmp", NULL);
    BITMAP *jugar2 = load_bitmap("images/again2.bmp", NULL);

    // Creacion de los bitmaps para presentar los niveles de juego
    BITMAP *presentacion = load_bitmap("images/PresentStage.bmp", NULL);
    BITMAP *nivel1 = load_bitmap("images/Stage1.bmp", NULL);
    BITMAP *nivel2 = load_bitmap("images/Stage2.bmp", NULL);
    BITMAP *nivel3 = load_bitmap("images/Stage3.bmp", NULL);


    // Creacion de los bitmaps para las pantallas de creditos
    BITMAP *cred1 = load_bitmap("images/cred1.bmp", NULL);
    BITMAP *cred2 = load_bitmap("images/cred2.bmp", NULL);
    BITMAP *cred3 = load_bitmap("images/cred3.bmp", NULL);
    BITMAP *cred4 = load_bitmap("images/cred4.bmp", NULL);

    // Creacion de los efectos de juego

    SAMPLE *start_pressed = load_sample("soundEffects/StartPressed.wav");
    SAMPLE *sonido_pausa = load_sample("soundEffects/Pausa.wav");
    SAMPLE *cambiar_modo = load_sample("soundEffects/ChangeMode.wav");
    SAMPLE *musica_victoria = load_sample("soundEffects/StageCleared.wav");
    SAMPLE *musica_derrota = load_sample("soundEffects/GameOver.wav");
    SAMPLE *musica_creditos = load_sample("soundtrack/Credits.wav");
    SAMPLE *musica_nivel = load_sample("soundEffects/Ready.wav");


    // Pista que siena durante el menu de opciones y de retorno de juego
    SAMPLE *musica_opciones = load_sample("soundtrack/Megaman.wav");
    SAMPLE *musica_retorno = load_sample("soundtrack/Nothingness.wav");

    // Bandas sonoras del juego
    SAMPLE *musica_portada = load_sample("soundtrack/MainTitle.wav");
    SAMPLE *musica_menu = load_sample("soundtrack/MainTitle2.wav");
    SAMPLE *primera_pista = load_sample("soundtrack/Alien3Stage2.wav");
    SAMPLE *segunda_pista = load_sample("soundtrack/Alien3Stage3.wav");
    SAMPLE *tercera_pista = load_sample("soundtrack/Alien3Stage5.wav");
    SAMPLE *cuarta_pista = load_sample("soundtrack/BeatnikOnTheShip.wav");
    SAMPLE *quinta_pista = load_sample("soundtrack/GoStraight.wav");
    SAMPLE *sexta_pista = load_sample("soundtrack/JungleBase.wav");
    SAMPLE *septima_pista = load_sample("soundtrack/MoonBeach.wav");
    SAMPLE *octava_pista = load_sample("soundtrack/TheLastSoul.wav");
    SAMPLE *novena_pista = load_sample("soundtrack/SpaceCombat.wav");


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
    play_sample(musica_menu, 255, 127, 1000, 1);
    portada(p, musica_menu, start_pressed);

    // Control de repeticion de partida
    bool repeticion = true;

    // Codigo de pista de reproduccion inicial
    int pistaInicial = 0;

    // Nivel actual de dificultad
    int nivel = 1;

    // Mientras el jugador desee repetir otra vez
    while (repeticion){

        // Vidas del jugador sin seleccionar
        int vidas = -1;

        // Seleccion de dificultad del juego en pantallas de opciones
        opciones(opcion1, opcion2, opcion3, musica_opciones, cambiar_modo, start_pressed, vidas);

        // Presentacion del nivel de juego
        presentarNivel(presentacion, nivel1, nivel2, nivel3, musica_nivel, nivel);

        // Dibujo de la nave del jugador en la posicion inferior del tablero con las vidas
        // pactadas en el menu de opciones
        NaveJugador n;
        n.construirNave((char*)"images/nave.bmp", (char*)"images/bala2.bmp",
                        (char*)"soundEffects/Bala.wav", (char*)"soundEffects/ExplosionJug.wav", 6, 12, 30, 20, 290, 500, -8, 0, vidas);

        // Codigo de la actual pista musical a repetir
        int pista = pistaInicial;

        // Control de vuelta de sonidos
        bool primeraVuelta = true;

        // Creacion y insercion de los enemigos con los que jugar
        NaveEnemigo e[MAX_DIM_ENEMIGOS];
        insertarEnemigos(e, nivel);

        // Maximo numero de disparos a efectuar por el jugador y los enemigos
        // Recomendado no cambiar porque se ralentiza
        Bala disparos[MAX_BALAS];
        Bala disparosEnem[MAX_BALAS];

        // Creacion del conjunto de escudos si estan habilitados
        Escudo escudos[30];
        construirEscudos(escudos);

        // Indice del primer enemigo a disparar
        int azarEnemigo = rand() % 55;
        // Determinacion del movimiento y direccion de los enemigos
        int mov = 0, dir = -5;

        // Tiempo de velocidad de movimiento
        int retardo = 10;

        // Control de finalizado de nivel
        bool terminado = false;

        // Control de las vidas de la nave del jugador
        bool muerto = false;

        // Contador de enemigos destruidos
        int enemigosDestruidos = 0;

        // El juego continua hasta que se presione la tecla ESCAPE
        while (!terminado && !muerto && !key[KEY_ESC]){
            // Controlar si el jugador presiona la tecla pausa
            controlJuegoEnPausa(primera_pista, segunda_pista, tercera_pista, cuarta_pista,
                                quinta_pista, sexta_pista, septima_pista, octava_pista,
                                novena_pista, sonido_pausa, pista);

            // Limpiar la pantalla de juego
            clear_to_color(buffer, 0x000000);

            // Pintar los escudos
            pintarEscudos(escudos, escudo, buffer);


            // Reproducir la banda actual de juego y verificar si se ha cambiado
            reproducirMusicaFondo(primera_pista, segunda_pista, tercera_pista, cuarta_pista,
                                  quinta_pista, sexta_pista, septima_pista, octava_pista,
                                  novena_pista, pista, primeraVuelta);

            // Controlar si los enemigos se deben mover
            if (e[0].temporizador(retardo)){
                // Tiempo transcurrido desde el movimiento anterior sobrepasado
                // Se vuelven a mover
                moverEnemigos(e, mov, dir);
            }

            // Pintar la nave del jugador en la pantalla de juego
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
                    // Contabilizar el enemigo destruido si sus vidas son cero
                    if (e[i].vidas == 0){
                        enemigosDestruidos++;
                        // Verificar si se acabo el nivel
                        if (enemigosDestruidos == NUM_ENEMIGOS){
                            terminado = true;
                        }
                    }
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
                n.explosion(buffer, fondo, muerto);
            }

            // Control de elimininacion de escudos si chocan balas de enemigos
            eliminar_bala_escudo(e[azarEnemigo], escudos, disparosEnem);

            // Imprimir todo en la pantalla de juego
            imprimir(fondo, buffer);
            blit(buffer, screen, 0, 0, 0, 0, 600, 600);
            // Detener la ejecucion 20 milisegundos para no sobrecargar
            rest(20);
        }
        // Detencion de todas las pistas para evitar posibles conflictos
        // Pistas que suenan durante la partida
        stop_sample(primera_pista);
        stop_sample(segunda_pista);
        stop_sample(tercera_pista);
        stop_sample(cuarta_pista);
        stop_sample(quinta_pista);
        stop_sample(sexta_pista);
        stop_sample(septima_pista);
        stop_sample(octava_pista);
        stop_sample(novena_pista);

        // Si se termino porque gano el jugador
        if (terminado){
            // mostrar pantalla de victoria
            pantallaVictoria(victoria, musica_victoria);

            // Incremento del nivel de dificultad maximo
            if (nivel == NIVEL_MAXIMO){
                // Reinicio
                nivel = 1;
            }
            else{
                // Incremento de la dificultad
                nivel++;
            }
        }
        // Si se termino porque le han quitado todas las vidas
        else if(muerto){
            // mostrar pantalla de derrota
            pantallaDerrota(derrota, musica_derrota);
        }
        // Preguntar al jugador si desea repetir la partida de nuevo
        pedirVolverJugar(jugar1, jugar2, start_pressed, musica_retorno, cambiar_modo, repeticion);

        // Guaardado de la pista actal para continuar reproduccion a partir de ella
        pistaInicial = pista - 1;
    }
    // Mostrar creditos finales del juego
    creditosFinales(cred1, cred2, cred3, cred4, musica_creditos);

    // Fin de la ejecucion del programa
    return 0;
}
END_OF_MAIN ()
