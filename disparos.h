#include <allegro.h>

#ifndef DISPAROS_H_INCLUDED
#define DISPAROS_H_INCLUDED

struct Balas{
    int x , y;
    int dx , dy;

};

void crear_bala(int& n_disparos, const int max_disparos,struct Balas disparos[],
                const int X, const int Y ,const int dy);

void pintar_bala(int& n_disparos, const int max_disparos,struct Balas disparos[],
                 BITMAP* buffer, BITMAP* bala);

void elimina_bala(int& n_disparos, const int max_disparos,struct Balas disparos[],
                  const int ANCHO, const int ALTO);

#endif // DISPAROS_H_INCLUDED
