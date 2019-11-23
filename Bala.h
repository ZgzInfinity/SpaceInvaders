

/*
 * Fichero de interfaz Bala.h del modulo Bala
 */


#include <allegro.h>
#include "NaveJugador.h"
#include "NaveEnemigo.h"
#include "Escudo.h"

#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED


/*
 * Representacion del tipo de dato Bala
 */
struct Bala{
    // Coordenadas cartesianas de la bala
    int x , y;
    // Anchura de la bala
    int dx , dy;
};



/*
 * Pre: <<x1>> es la coordenada x de la nave enemiga; <<y1>> es la coordenada y de la nave; w1 y h1 son
 *      las dimensiones de anchura y altura de la nave enemiga; <<x2>> es la coordenada x de una bala
 *      <<y2>> es la coordenada y de una bala; w2 y h2 son la dimensiones de anchura y altura de la bala
 * Post: Ha devuelto <<true>> si y solo si ha habido colision entre la nave enemiga y la bala.
 *       En caso contrario ha devuelto <<false>>.
 */
bool choque(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);



/*
 * Pre: <n_disparos>> es el numero de disparos realizados por la nave; <<max_disparos>> es el
 *      numero maximo de disparos permtidos para la nave; la tabla <<disparos>> almacena todas
 *      las balas disparadas hasta el momento; <<X>> e <<Y>> son las coordenadas de la bala
 *      donde se debe crear y <<dy>> es la anchura de la bala.
 * Post: Si el numero de disparos efectuados por la nave <<n_disparos>> no supera el limite
 *       maximo de disparos <<max_disparos>> entonces crea una bala en las coordenadas cartesianas
 *       <<x>> e <<y>> con una anchura <<dy>>.
 */
bool crear_bala(int& n_disparos, const int max_disparos, Bala disparos[],
                const int X, const int Y ,const int dy);



/*
 * Pre: <n_disparos>> es el numero de disparos realizados por la nave; <<max_disparos>> es el
 *      numero maximo de disparos permtidos para la nave; la tabla <<disparos>> almacena todas
 *      las balas disparadas hasta el momento; <<buffer>> es un bitmap que almacena el conjunto de
 *      bitmaps auxiliares a imprimir por pantalla; <<bala>> es un bitmap que contiene la imagen de
 *      la bala; <<ancho>> y <<alto>> son la anchura y altura del bitmap de la bala
 *      donde se debe crear y <<dy>> es la anchura de la bala.
 * Post: Si el numero de disparos efectuados por la nave <<n_disparos>> no supera el limite
 *       maximo de disparos <<max_disparos>> entonces pinta para cada una de las balas disparadas por
 *       la nave, recogidas en la tabla <<disparos>> en las coordenadas correspondientes con un ancho
 *       igual a <<ancho>> y una altura igual a <<altura>>.
 */
void pintar_bala(int& n_disparos, const int max_disparos, Bala disparos[],
                 BITMAP* buffer, BITMAP* bala, int ancho, int alto);


/*
 * Pre: la tabla <<disparos>> almacena todas las balas disparadas por la nave; <<nDisparos>>
 *      contiene el numero de disparos efectuados por la nave y <<cont>> es el indice de la bala
 *      recogida en la tabla <<disparos>> a comprobar; 0 < cont <= max_disparos.
 * Post: Ha borrada la bala localizada en el indice <<cont>> de la tabla.
 */
void eliminar(Bala disparos[], int& nDiparos, int cont);



/*
 * Pre: <n_disparos>> es el numero de disparos realizados por la nave; <<max_disparos>> es el
 *      numero maximo de disparos permtidos para la nave; la tabla <<disparos>> almacena todas
 *      las balas disparadas hasta el momento; <<ANCHO>> es la anchura del tablero de juego
 *      y <<ALTO>> es la altura.
 * Post: Si el numero de disparos efectuados por la nave <<n_disparos>> no supera el limite
 *       maximo de disparos <<max_disparos>> entonces ha recorrido la tabla de las balas <<disparos>>
 *       y ha procedido a borrar todas aquellas balas cuyas coordenadas cartesianas <<x>> e <<y>>
 *       estan fuera del tablero de juego.
 */
void elimina_bala(int& n_disparos, const int max_disparos, Bala disparos[],
                  const int ANCHO, const int ALTO);



/*
 * Pre: <<n>> es la nave correspondiente al jugador, <<e>> es el la nave correspondiente a la nave
 *      enemigo y <<b>> es una tabla que guarda el numero de balas disparadas por la nave del jugador.
 * Post: Ha recorrido todas las balas guardadas en la tabla <<b>> y si la posicion de la bala coincide
 *       con la posicion de la nave <<e>> entonces ha habido colision y se borra la nave enemigo con la
 *       bala con la que ha colisionado.
 */
bool eliminar_bala_choque(struct NaveJugador& n, struct NaveEnemigo& e, Bala b[]);


/*
 * Pre: <<n>> es la nave correspondiente al jugador, <<e>> es el la nave correspondiente a la nave
 *      enemigo y <<b>> es una tabla que guarda el numero de balas disparadas por la nave del jugador.
 * Post: Ha recorrido todas las balas guardadas en la tabla <<b>> y si la posicion de la bala coincide
 *       con la posicion de la nave <<e>> entonces ha habido colision y se borra la nave enemigo con la
 *       bala con la que ha colisionado.
 */
bool eliminar_bala_choque(struct NaveEnemigo& n, struct NaveJugador& e, Bala b[]);



/*
 * Pre: <<n>> es la nave correspondiente al jugador, <<ES>> es la tabla que almacena todos los
 *      escudos generados en la partida y <<b>> es una tabla que guarda el numero de balas
 *      disparadas por la nave del jugador
 * Post: Ha recorrido todas las balas guardadas en la tabla <<b>> y si la posicion de la bala coincide
 *       con la posicion de algun escudo de la tabla <<ES>> entonces ha habido colision, se aumenta
 *       el danyo infligido al escudo y se borra bala con la que ha colisionado.
 */
void eliminar_bala_escudo(struct NaveJugador& n, struct Escudo ES[], Bala b[]);



/*
 * Pre: <<n>> es la nave correspondiente al enemigo, <<ES>> es la tabla que almacena todos los
 *      escudos generados en la partida y <<b>> es una tabla que guarda el numero de balas
 *      disparadas por la nave del jugador
 * Post: Ha recorrido todas las balas guardadas en la tabla <<b>> y si la posicion de la bala coincide
 *       con la posicion de algun escudo de la tabla <<ES>> entonces ha habido colision, se aumenta
 *       el danyo infligido al escudo y se borra bala con la que ha colisionado.
 */
void eliminar_bala_escudo(struct NaveEnemigo& n, struct Escudo ES[], Bala b[]);



#endif
