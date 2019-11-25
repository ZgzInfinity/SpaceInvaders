/*
 **********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 25-11-2019 *********************************
 **********************************************************
 */


/*
 * Fichero de implementacion Iniciador.cc del modulo Iniciador
 */

#include "Iniciador.h"



/*
 * Pre: <<ANCHO_>> y <<ALTO_>> son las dimensiones de
 *      de anchura y altura del bitmap principal de Allegro
 * Post: Ha creado el bitmap principal y ha iniciado
 *       correctamente la libreria
 */
void inicia_allegro(int ANCHO_ , int ALTO_){
   // Inicio de la libreria Allegro
   allegro_init();
   // Habilitar interrupciones del teclado
   install_keyboard();
   // Establecer calibrado de color y creacion del bitmap principal
   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO_, ALTO_, 0, 0);
}



/*
 * Pre: <<izquierda>> y <<derecha>> son los niveles de intensidad
 *      de los archivos de sonido a reproducir por los altavoces
 * Post: Ha iniciado el servicio de gestion de audios de la libreria
 *       Allegro
 */
int inicia_audio(int izquierda, int derecha){
    // Si se ha podido instalar el sistema de sonido bien
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }
    // Calibrado de los niveles de sonido
	set_volume(izquierda, derecha);
    return 0;
}

