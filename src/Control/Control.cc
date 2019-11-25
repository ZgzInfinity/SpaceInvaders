/*
 **********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 25-11-2019 *********************************
 **********************************************************
 */



/*
 * Fichero de implementacion Control.cc del modulo Control
 */


#include "Control.h"


/*
 * Pre: ---
 * Post: Ha limpiado el buffer del teclado y ha
 *       eliminado todas las interrupciones producidas durante
 *       <<tiempo>> milisegundos
 */
void limpiarBufferTeclado(const int tiempo){
    // Capturar la tecla ya pulsada
    while (kbhit()){
        // Limpiar el buffer del teclado para coger nuevas teclas
        getche();
    }
    // Detener ejecucion 500 milisegundos
    rest(tiempo);
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
    // Si durante el juego el jugador presionar ENTER
    if (key[KEY_PLUS_PAD]){
        // Limpiar buffer de teclado e incrementar pista
        limpiarBufferTeclado(500);
        pista++;
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
                         SAMPLE* septima_pista, SAMPLE* octava_pista, SAMPLE* sonido_pausa, int& pista){
    // Control de si el jugador ha parado el juego
    if (key[KEY_TAB]){
        // Tecla de modo pausa pulsada
        // Detener la musica de fondo de la partida en base a la pista
        switch(pista){
            case 1:
                // Se detiene la primera pista
                stop_sample(primera_pista);
                break;
            case 2:
                // Se detiene la segunda pista
                stop_sample(segunda_pista);
                break;
            case 3:
                // Se detiene la tercera pista
                stop_sample(tercera_pista);
                break;
            case 4:
                // Se detiene la cuarta pista
                stop_sample(cuarta_pista);
                break;
            case 5:
                // Se detiene la quinta pista
                stop_sample(quinta_pista);
                break;
            case 6:
                // Se detiene la sexta pista
                stop_sample(sexta_pista);
                break;
            case 7:
                // Se detiene la septima pista
                stop_sample(septima_pista);
                break;
            case 8:
                // Se detiene la octava pista
                stop_sample(octava_pista);
        }
        rest(200);
        // Emitir sonido del modo pausa
        play_sample(sonido_pausa, 255, 127, 1000, 0);
        // Limpieza de buffer del teclado
        limpiarBufferTeclado(200);
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
        // Reproduce de nuevo la banda sonora de la partida en base a la pista
        switch(pista){
            case 1:
                // Se detiene la primera pista
                play_sample(primera_pista, 255, 127, 1000, 0);
                break;
            case 2:
                // Se detiene la segunda pista
                play_sample(segunda_pista, 255, 127, 1000, 0);
                break;
            case 3:
                // Se detiene la tercera pista
                play_sample(tercera_pista, 255, 127, 1000, 0);
                break;
            case 4:
                // Se detiene la cuarta pista
                play_sample(cuarta_pista, 255, 127, 1000, 0);
                break;
            case 5:
                // Se detiene la quinta pista
                play_sample(quinta_pista, 255, 127, 1000, 0);
                break;
            case 6:
                // Se detiene la sexta pista
                play_sample(sexta_pista, 255, 127, 1000, 0);
                break;
            case 7:
                // Se detiene la septima pista
                play_sample(septima_pista, 255, 127, 1000, 0);
                break;
            case 8:
                // Se detiene la octava pista
                play_sample(octava_pista, 255, 127, 1000, 0);
                break;
        }
    }
}




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
              SAMPLE* start_pressed, int& vidas){
    // Reproducir musica de opciones
    play_sample(musica_opciones, 255, 127, 1000, 1);
    // Mientras no se haya seleccionado dificultad
    // presionando la tecla ENTER
    while (!key[KEY_ENTER]){
        // Vidas sin seleccionar todavia
        if (vidas == -1){
            // Pintar pantalla en negro
            clear_to_color(screen, 0x000000);
            // Imprimir la pantalla de modo facil seleccionado
            masked_blit(opcion1, screen, 0, 0, 0, 0, 600, 600);
            // Vidas en modo facil
            vidas = VIDAS_MODO_FACIL;
        }
        // Ver si se presiona una de las teclas del cursor arriba o abajo
        if (key[KEY_UP]){
            // Limpiar buffer del teclado
            limpiarBufferTeclado(500);
            // Presiona la tecla del cursor flecha arriba
            if (vidas == VIDAS_MODO_MEDIO){
                // En modo medio y se cambia a modo facil
                vidas = VIDAS_MODO_FACIL;
                // Pintar pantalla en negro
                clear_to_color(screen, 0x000000);
                // Imprimir la pantalla de modo medio seleccionado
                masked_blit(opcion1, screen, 0, 0, 0, 0, 600, 600);
                // Reproducir sonido de cambio de modo
                play_sample(cambiar_modo, 255, 127, 1000, 0);
            }
            else if (vidas == VIDAS_MODO_DIFICIL){
                // En modo dificil y se cambia a modo medio
                vidas = VIDAS_MODO_MEDIO;
                // Pintar pantalla en negro
                clear_to_color(screen, 0x000000);
                // Imprimir la pantalla de modo medio seleccionado
                masked_blit(opcion2, screen, 0, 0, 0, 0, 600, 600);
                // Reproducir sonido de cambio de modo
                play_sample(cambiar_modo, 255, 127, 1000, 0);
            }
            // Imposible cambiar si es en modo facil
        }
        else if (key[KEY_DOWN]){
            // Limpiar buffer del teclado
            limpiarBufferTeclado(500);
            // Presiona la tecla del cursor flecha abajo
            if (vidas == VIDAS_MODO_FACIL){
                // En modo facil y se cambia a modo medio
                vidas = VIDAS_MODO_MEDIO;
                // Pintar pantalla en negro
                clear_to_color(screen, 0x000000);
                // Imprimir la pantalla de modo medio seleccionado
                masked_blit(opcion2, screen, 0, 0, 0, 0, 600, 600);
                // Reproducir sonido de cambio de modo
                play_sample(cambiar_modo, 255, 127, 1000, 0);
            }
            else if (vidas == VIDAS_MODO_MEDIO){
                // En modo medio y se cambia a modo dificil
                vidas = VIDAS_MODO_DIFICIL;
                // Pintar pantalla en negro
                clear_to_color(screen, 0x000000);
                // Imprimir la pantalla de modo medio seleccionado
                masked_blit(opcion3, screen, 0, 0, 0, 0, 600, 600);
                // Reproducir sonido de cambio de modo
                play_sample(cambiar_modo, 255, 127, 1000, 0);
            }
            // Imposible cambiar si es en modo dificil
        }
    }
    // Detener musica del menu de opciones
    stop_sample(musica_opciones);
    play_sample(start_pressed, 255, 127, 1000, 0);
    // Limpiar buffer del teclado
    limpiarBufferTeclado(1000);
}



/*
 * Pre: <<victoria>> es el bitmap que aparece en pantalla cuando el
 *       jugador gana y <<musica_victoria>> es el sonido a reproducir
 * Post: Ha mostrado en pantalla el bitmap de victoria ya que el jugador
 *       ha ganado y ha reproducido el sonido <<musica_victoria>>
 */
void pantallaVictoria(BITMAP* victoria, SAMPLE* musica_victoria){
    clear_to_color(screen, 0x000000);
    masked_blit(victoria, screen, 0, 0, 35, 200, 532, 199);
    play_sample(musica_victoria, 255, 127, 1000, 0);
    rest(7000);
}



/*
 * Pre: <<derrota>> es el bitmap que aparece en pantalla cuando el
 *       jugador gana y <<musica_derrota>> es el sonido a reproducir
 * Post: Ha mostrado en pantalla el bitmap de victoria ya que el jugador
 *       ha ganado y ha reproducido el sonido <<musica_derrota>>
 */
void pantallaDerrota(BITMAP* derrota, SAMPLE* musica_derrota){
    clear_to_color(screen, 0x000000);
    masked_blit(derrota, screen, 0, 0, 0, 0, 600, 600);
    play_sample(musica_derrota, 255, 127, 1000, 0);
    rest(10000);
}



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
                      SAMPLE* musica_retorno, SAMPLE* cambiar_modo, bool& repeticion){
    // Reproducir musica de opciones
    play_sample(musica_retorno, 255, 127, 1000, 1);
    // Mientras no se haya seleccionado volver a jugar o no presionando la tecla ENTER
    // Pintar pantalla en negro
    clear_to_color(screen, 0x000000);
    // Imprimir la pantalla de modo facil seleccionado
    masked_blit(again1, screen, 0, 0, 0, 0, 600, 600);
    // Vidas en modo facil
    while (!key[KEY_ENTER]){
        // Ver si se presiona una de las teclas del cursor arriba o abajo
        if (key[KEY_UP]){
            // Limpiar buffer del teclado
            limpiarBufferTeclado(500);
            // Presiona la tecla del cursor flecha arriba
            if (!repeticion){
                // El usuario quiere volver a jugar
                repeticion = true;
                // Pintar pantalla en negro
                clear_to_color(screen, 0x000000);
                // Imprimir la pantalla de modo medio seleccionado
                masked_blit(again1, screen, 0, 0, 0, 0, 600, 600);
                // Reproducir sonido de cambio de modo
                play_sample(cambiar_modo, 255, 127, 1000, 0);
            }
            // Imposible cambiar si esta en modo de volver a jugar
        }
        else if (key[KEY_DOWN]){
            // Limpiar buffer del teclado
            limpiarBufferTeclado(500);
            // Presiona la tecla del cursor flecha abajo
            if (repeticion){
                // El usuario quiere volver a jugar
                repeticion = false;
                // Pintar pantalla en negro
                clear_to_color(screen, 0x000000);
                // Imprimir la pantalla de modo medio seleccionado
                masked_blit(again2, screen, 0, 0, 0, 0, 600, 600);
                // Reproducir sonido de cambio de modo
                play_sample(cambiar_modo, 255, 127, 1000, 0);
            }
            // Imposible cambiar si esta en modo de no volver a jugar
        }
    }
    // Detener musica del menu de volver a jugar
    stop_sample(musica_retorno);
    play_sample(start_pressed, 255, 127, 1000, 0);
    // Limpiar buffer del teclado
    limpiarBufferTeclado(1000);
}




