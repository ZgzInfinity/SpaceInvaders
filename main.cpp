/**********************************************************
 ****** JUEGO DE MARCIANITOS -- SPACEINVADERS *************
 ****** Autor: Rubén Rodríguez Esteban -- ZgzInfinity *****
 ****** Fecha: 10-2-2019 **********************************
 **********************************************************
 */


#include "inicia.h"
#include "disparos.h"


using namespace std;


struct Nave {
    int posNaveX;
    int posNaveY;
    int nDisparos;
    int max_disp;
    int tick;

    BITMAP *imgNave;
    BITMAP *imgBala;

    void inicia(char* rutaNave, char* rutaBala);
    void pintar(BITMAP* buffer);
    void mover();
    bool temporizador();
};


void Nave::inicia(char* rutaNave, char* rutaBala){
    posNaveX = 350;
    posNaveY = 340;
    max_disp = 4;
    nDisparos = 0;
    imgBala = load_bitmap(rutaBala, NULL);
    imgNave = load_bitmap(rutaNave, NULL);
    tick = 0;
}


void Nave::pintar(BITMAP* buffer){
    masked_blit(imgNave, buffer,0, 0, posNaveX, posNaveY, 30, 20);
}

void Nave::mover(){
    if(key[KEY_LEFT]){
        posNaveX -= 5;
    }
    if (key[KEY_RIGHT]){
        posNaveX += 5;
    }
}


bool Nave::temporizador(){
    tick++;
    if (tick == 5){
        tick = 0;
        return true;
    }
    else {
        return false;
    }
}


int main(){

    inicia_allegro(700, 390);
    inicia_audio(70,70);
    install_mouse();

    BITMAP *buffer = create_bitmap(700, 390);
    BITMAP *menuReposo = load_bitmap("Imagenes/menuReposo.bmp", NULL);
    BITMAP *menuComenzar = load_bitmap("Imagenes/menuComenzar.bmp", NULL);
    BITMAP *menuOpciones = load_bitmap("Imagenes/menuOpciones.bmp", NULL);
    BITMAP *cursor = load_bitmap("Imagenes/cursor.bmp", NULL);


    bool comenzarJuego = false;
    bool entrarOpciones = false;

    while (!comenzarJuego && !entrarOpciones){
        if (mouse_x > 125 && mouse_x < 303 && mouse_y > 260 && mouse_y < 291){
            blit(menuComenzar, buffer, 0, 0, 0, 0, 700, 390);
            if (mouse_b & 1){
                comenzarJuego = true;
            }
        }
        else if (mouse_x > 374 && mouse_x < 535 && mouse_y > 260 && mouse_y < 291){
            blit(menuOpciones, buffer, 0, 0, 0, 0, 700, 390);
            if (mouse_b & 1){
                entrarOpciones = true;
            }
        }
        else {
            blit(menuReposo, buffer, 0, 0, 0, 0, 700, 390);
        }

        masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13, 22);
        blit(buffer, screen, 0, 0, 0, 0, 700, 390);

    }

    Nave n;
    n.inicia("Imagenes/nave.bmp", "Imagenes/bala2.bmp");
    Balas disparos[n.max_disp];

    while (!key[KEY_ESC]){
         clear_to_color(buffer, 0x000000);
         n.pintar(buffer);
         n.mover();


         if (key[KEY_SPACE] && n.temporizador()){
            crear_bala(n.nDisparos, n.max_disp, disparos, n.posNaveX, n.posNaveY, -8);
         }

         pintar_bala(n.nDisparos, n.max_disp, disparos, buffer, n.imgBala);
         elimina_bala(n.nDisparos, n.max_disp, disparos, 700, 390);

         blit(buffer, screen, 0, 0, 0, 0, 700, 390);
         rest(20);
    }

    return 0;
}
END_OF_MAIN ()
