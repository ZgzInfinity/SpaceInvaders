#include "Bala.h"


/*
 * Pre: <<x1>> es la coordenada x de la nave enemiga; <<y1>> es la coordenada y de la nave; w1 y h1 son
 *      las dimensiones de anchura y altura de la nave enemiga; <<x2>> es la coordenada x de una bala
 *      <<y2>> es la coordenada y de una bala; w2 y h2 son la dimensiones de anchura y altura de la bala
 * Post: Ha devuelto <<true>> si y solo si ha habido colision entre la nave enemiga y la bala.
 *       En caso contrario ha devuelto <<false>>.
 */
bool choque(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2){
    // Verificacion de choque entre una nave enemiga y una bala disparada por el jugador
    return ((x1 < x2 + w2) && (x2 < x1 + w1) &&
            (y1 < y2 + h2) && (y2 < y1 + h1));
}



/*
 * Pre: <n_disparos>> es el numero de disparos realizados por la nave; <<max_disparos>> es el
 *      numero maximo de disparos permtidos para la nave; la tabla <<disparos>> almacena todas
 *      las balas disparadas hasta el momento; <<X>> e <<Y>> son las coordenadas de la bala
 *      donde se debe crear y <<dy>> es la anchura de la bala.
 * Post: Si el numero de disparos efectuados por la nave <<n_disparos>> no supera el limite
 *       maximo de disparos <<max_disparos>> entonces crea una bala en las coordenadas cartesianas
 *       <<x>> e <<y>> con una anchura <<dy>>.
 */
bool crear_bala(int& n_disparos, const int max_disparos ,Bala disparos[] ,
                const int X, const int Y , const int dy){
    // Comprobar el numero de disparos efectuados
    if( n_disparos < max_disparos-1){
        // Aumentar el numero de disparos de la nave
        n_disparos++;
        // Dibujar la bala que ha disparado la nave
        disparos[n_disparos].x  = X+11;
        disparos[n_disparos].y  = Y;
        disparos[n_disparos].dx = 0;
        disparos[n_disparos].dy = dy;
        return true;
    }
    else {
        return false;
    }
}



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
                 BITMAP* buffer, BITMAP* bala, int ancho, int alto){
      // Comprobar el numero de disparos efectuados
     if ( n_disparos > 0 && n_disparos < max_disparos){
            // Si no se supera recorrrer tabla de balas de la nave
            for ( int cont = 1; cont <= n_disparos; cont++){
                // Colocar bala en la nueva posicion tras avanzar
                disparos[cont].x += disparos[cont].dx;
                disparos[cont].y += disparos[cont].dy;
                // Imprimir el bitmap de la bala en el bitmao del tablero
                masked_blit( bala, buffer, 0, 0, disparos[cont].x, disparos[cont].y, ancho, alto);
            }
     }
}



/*
 * Pre: la tabla <<disparos>> almacena todas las balas disparadas por la nave; <<nDisparos>>
 *      contiene el numero de disparos efectuados por la nave y <<cont>> es el indice de la bala
 *      recogida en la tabla <<disparos>> a comprobar; 0 < cont <= max_disparos.
 * Post: Ha borrada la bala localizada en el indice <<cont>> de la tabla.
 */
void eliminar(Bala disparos[], int& n_disparos, int cont){
    // Actualizacion de las balas
    Bala Btemp;
    Btemp = disparos[cont];
    disparos[cont] = disparos[n_disparos];
    disparos[n_disparos] = Btemp;
    // Reducir los disparos
    n_disparos--;
    if ( n_disparos < 0 ) {
        // Reiniciar contador de disparos a cero si queda negativo
        n_disparos=0;
    }
}



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
                  const int ANCHO, const int ALTO){
      // Comprobar el numero de disparos efectuados
      if ( n_disparos > 0 && n_disparos < max_disparos){
        // Si no se supera recorrrer tabla de balas de la nave
        for ( int cont = 1; cont <= n_disparos; cont++){
            // Comprobr que la bala no ha salido de los limites del tablero
            if ( disparos[cont].y > ALTO || disparos[cont].y < 0 ||
                disparos[cont].x > ANCHO|| disparos[cont].x < 0  ){
                // Si sale se borra
                eliminar(disparos, n_disparos, cont);
            }
        }
    }
}



/*
 * Pre: <<n>> es el nave correspondiente al jugador, <<e>> es el la nave correspondiente a la nave
 *      enemigo y <<b>> es una tabla que guarda el numero de balas disparadas por la nave del jugador.
 * Post: Ha recorrido todas las balas guardadas en la tabla <<b>> y si la posicion de la bala coincide
 *       con la posicion de la nave <<e>> entonces ha habido colision y se borra la nave enemigo con la
 *       bala con la que ha colisionado.
 */
bool eliminar_bala_choque(struct NaveJugador& n, struct NaveEnemigo& e, Bala b[]){
     // Comprobar el numero de disparos efectuados
     if ( n.nDisparos > 0 && n.nDisparos < n.max_disp){
        // Si no se supera recorrrer tabla de balas de la nave
        for ( int cont = 1; cont <= n.nDisparos; cont++){
            // Comprobar choque de la nave enemiga con la bala actual
            if (choque(e.posNaveX, e.posNaveY, e.ancho_p, e.alto_p, b[cont].x, b[cont].y, n.ancho_b, n.ancho_p) && e.vidas > 0){
                // Si hay choque eliminar la bala y decrementar una vida de la nave
                eliminar(b, n.nDisparos, cont);
                e.vidas--;
                return true;
            }
        }
        return false;
    }
}




/*
 * Pre: <<n>> es el nave correspondiente al jugador, <<e>> es el la nave correspondiente a la nave
 *      enemigo y <<b>> es una tabla que guarda el numero de balas disparadas por la nave del jugador.
 * Post: Ha recorrido todas las balas guardadas en la tabla <<b>> y si la posicion de la bala coincide
 *       con la posicion de la nave <<e>> entonces ha habido colision y se borra la nave enemigo con la
 *       bala con la que ha colisionado.
 */
bool eliminar_bala_choque(struct NaveEnemigo& n, struct NaveJugador& e, Bala b[]){
     // Comprobar el numero de disparos efectuados
     if ( n.nDisparos > 0 && n.nDisparos < n.max_disp){
        // Si no se supera recorrrer tabla de balas de la nave
        for ( int cont = 1; cont <= n.nDisparos; cont++){
            // Comprobar choque de la nave enemiga con la bala actual
            if (choque(e.posNaveX, e.posNaveY, e.ancho_p, e.alto_p, b[cont].x, b[cont].y, n.ancho_b, n.ancho_p) && e.vidas > 0){
                // Si hay choque eliminar la bala y decrementar una vida de la nave
                eliminar(b, n.nDisparos, cont);
                e.vidas--;
                return true;
            }
        }
        return false;
     }
}



/*
 * Pre: <<n>> es la nave correspondiente al jugador, <<ES>> es la tabla que almacena todos los
 *      escudos generados en la partida y <<b>> es una tabla que guarda el numero de balas
 *      disparadas por la nave del jugador
 * Post: Ha recorrido todas las balas guardadas en la tabla <<b>> y si la posicion de la bala coincide
 *       con la posicion de algun escudo de la tabla <<ES>> entonces ha habido colision, se aumenta
 *       el danyo infligido al escudo y se borra bala con la que ha colisionado.
 */
void eliminar_bala_escudo(struct NaveJugador& n, struct Escudo ES[], Bala b[]){
     // Comprobar el numero de disparos efectuados
     if ( n.nDisparos > 0 && n.nDisparos < n.max_disp){
        // Si no se supera recorrrer tabla de balas de la nave
        for (int cont = 1; cont <= n.nDisparos; cont++){
            // Recorrido de todos los escudos
            for (int i = 0; i < NUM_ESCUDOS - 2; i ++){
                // Verificacion de la colision entre bala y escudo i-seimo
                if (choque(ES[i].x, ES[i].y, 20, 16, b[cont].x , b[cont].y, n.ancho_b, n.alto_b && ES[i].danyo < 3)){
                    // Eliminacion de la bala
                    eliminar(b, n.nDisparos, cont);
                    // Aumento del danyo causado
                    ES[i].danyo++;
                }
            }
        }
     }
}



/*
 * Pre: <<n>> es la nave correspondiente al enemigo, <<ES>> es la tabla que almacena todos los
 *      escudos generados en la partida y <<b>> es una tabla que guarda el numero de balas
 *      disparadas por la nave del jugador
 * Post: Ha recorrido todas las balas guardadas en la tabla <<b>> y si la posicion de la bala coincide
 *       con la posicion de algun escudo de la tabla <<ES>> entonces ha habido colision, se aumenta
 *       el danyo infligido al escudo y se borra bala con la que ha colisionado.
 */
void eliminar_bala_escudo(struct NaveEnemigo& n, struct Escudo ES[], Bala b[]){
     // Comprobar el numero de disparos efectuados
     if ( n.nDisparos > 0 && n.nDisparos < n.max_disp){
        // Si no se supera recorrrer tabla de balas de la nave
        for (int cont = 1; cont <= n.nDisparos; cont++){
            // Recorrido de todos los escudos
            for (int i = 0; i < NUM_ESCUDOS - 2; i ++){
                // Verificacion de la colision entre bala y escudo i-seimo
                if (choque(ES[i].x, ES[i].y, 20, 16, b[cont].x , b[cont].y, n.ancho_b, n.alto_b && ES[i].danyo < 3)){
                    // Eliminacion de la bala
                    eliminar(b, n.nDisparos, cont);
                    // Aumento del danyo causado
                    ES[i].danyo++;
                }
            }
        }
     }
}
