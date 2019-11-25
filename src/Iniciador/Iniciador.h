/*
 **********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 25-11-2019 *********************************
 **********************************************************
 */


/*
 * Fichero de interfaz Iniciador.h del modulo Iniciador
 */


#ifndef INICIA_H_INCLUDED
#define INICIA_H_INCLUDED

#include <allegro.h>



/*
 * Pre: <<ANCHO_>> y <<ALTO_>> son las dimensiones de
 *      de anchura y altura del bitmap principal de Allegro
 * Post: Ha creado el bitmap principal y ha iniciado
 *       correctamente la libreria
 */
void inicia_allegro(int ANCHO_ , int ALTO_);



/*
 * Pre: <<izquierda>> y <<derecha>> son los niveles de intensidad
 *      de los archivos de sonido a reproducir por los altavoces
 * Post: Ha iniciado el servicio de gestion de audios de la libreria
 *       Allegro
 */
int inicia_audio(int izquierda, int derecha);



#endif // INICIA_H_INCLUDED
