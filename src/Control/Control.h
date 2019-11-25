/*
 **********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 25-11-2019 *********************************
 **********************************************************
 */


/*
 * Fichero de interfaz Control.h del modulo Control
 */


#include <conio.h>
#include <allegro.h>


#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED


const int VIDAS_MODO_FACIL = 5;
const int VIDAS_MODO_MEDIO = 3;
const int VIDAS_MODO_DIFICIL = 1;



/*
 * Pre: ---
 * Post: Ha limpiado el buffer del teclado y ha
 *       eliminado todas las interrupciones producidas durante
 *       <<tiempo>> milisegundos
 */
void limpiarBufferTeclado(const int tiempo);



/*
 * Pre: <<musica_fondo>> es la banda sonora que se va a reproducir
 *      durante la partida y <<pista>> es el indice de la pista musical actual
 * Post: Ha reproducido la pista musical <<musica_fondo>> y ha guardado en <<<pista>>
 *       el indice correspondiente a la siguiente pista a reproducir
 */
void reproducirMusicaFondo(SAMPLE* primera_pista, SAMPLE* segunda_pista, SAMPLE* tercera_pista,
                           SAMPLE* cuarta_pista, SAMPLE* quinta_pista, SAMPLE* sexta_pista,
                           SAMPLE* septima_pista, SAMPLE* octava_pista, int& pista, bool& primeraVuelta);



/*
 * Pre: <<primera_pista>> es la banda sonora correspondiente a la primera pista musical a reproducir
 *      durante la partida; <<segunda_pista>> es la banda sonora correspondiente a la segunda pista
 *      musical a reproducir durante la partida; <<tercera_pista>> es la banda sonora correspondiente
 *      a la tercera pista musical a reproducir durante la partida; <<cuarta_pista>> es la banda
 *      sonora correspondiente a la cuarta pista musical a reproducir durante la partida;
 *      <<quinta_pista>> es la banda sonora correspondiente a la quinta pista musical a reproducir
 *      durante la partida; <<sexta_pista>> es la banda sonora correspondiente a la sexta pista
 *      musical a reproducir durante la partida; <<septima_pista>> es la banda sonora correspondiente
 *      a la septima pista musical a reproducir durante la partida; <<octava_pista>> es la banda
 *      sonora correspondiente a la octava pista musical a reproducir durante la partida;
 *      <<sonido_pausa>> es el sonido a emitir al parar el juego y <<pista>> es el indice de la
 *      actual pista musical en reproduccion
 * Post: Ha parado el juego tras presionar la tecla tabulador, emitiendo el sonido <<sonido_pausa>>
 *       y parando la reproduccion de la pista musical <<pista>> hasta que se ha presionado de
 *       nuevo la tecla tabulador reanundando el juego y volviendo reproducir la pista musical <<pista>>
 */
void controlJuegoEnPausa(SAMPLE* primera_pista, SAMPLE* segunda_pista, SAMPLE* tercera_pista,
                         SAMPLE* cuarta_pista, SAMPLE* quinta_pista, SAMPLE* sexta_pista,
                         SAMPLE* septima_pista, SAMPLE* octava_pista, SAMPLE* sonido_pausa, int& pista);




/*
 * Pre: <<opcion1>> es la pantalla correspondiente al menu de opciones marcando el modo de
 *      juego facil; <<opcion2>> es la pantalla correspondiente al menu de opciones marcando
 *      el modo de juego medio; <<opcion3>> es la pantalla correspondiente al menu de opciones
 *      marcando el modo de juego dificil y <<vidas>> son las vidas del jugador sin todavia
 *      configurar.
 * Post: Si el usuario ha seleccionado el modo de dificultad facil su nave tiene un total
 *       de 5 vidas.
 *       Si el usuario ha seleccionado el modo de dificultad medio su nave tiene un total
 *       de 3 vidas.
 *       Si el usuario ha seleccionado el modo de dificultad dificil su nave tiene un total
 *       de 1 vidas.
 */
void opciones(BITMAP* opcion1, BITMAP* opcion2, BITMAP* opcion3,
              SAMPLE* musica_opciones, SAMPLE* cambiar_modo,
              SAMPLE* start_pressed, int& vidas);


/*
 * Pre: <<victoria>> es el bitmap que aparece en pantalla cuando el
 *       jugador gana y <<musica_victoria>> es el sonido a reproducir
 * Post: Ha mostrado en pantalla el bitmap de victoria ya que el jugador
 *       ha ganado y ha reproducido el sonido <<musica_victoria>>
 */
void pantallaVictoria(BITMAP* victoria, SAMPLE* musica_victoria);



/*
 * Pre: <<derrota>> es el bitmap que aparece en pantalla cuando el
 *       jugador gana y <<musica_derrota>> es el sonido a reproducir
 * Post: Ha mostrado en pantalla el bitmap de victoria ya que el jugador
 *       ha ganado y ha reproducido el sonido <<musica_derrota>>
 */
void pantallaDerrota(BITMAP* derrota, SAMPLE* musica_derrota);



/*
 * Pre: <<again1>> es el bitmap correspondiente a la pantalla a mostrar cuando el
 *      jugador quiere jugar de nuevo; <<again1>> es el bitmap correspondiente a
 *      la pantalla a mostrar cuando el no jugador quiere jugar de nuevo;
 *      <<start_pressed>> es el sonido a reproducir tras confirmar la eleccion del
 *      jugador; <<musica_retorno>> es la banda sonora a reproducir en el menu de
 *      retorno de juego y <<repeticion>> es el control de repeticion del juego
 * Post: Ha permitido gestionar al jugador si desea volver a jugar o no. Si desea
 *       volver a jugar <<repeticion>> toma valor <<true>>. En caso contrario
 *       toma valor <<false>>
 */
void pedirVolverJugar(BITMAP* again1, BITMAP* again2, SAMPLE* start_pressed,
                      SAMPLE* musica_retorno, SAMPLE* cambiar_modo, bool& repeticion);



# endif

