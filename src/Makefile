#**********************************************************************
# Archivo: Makefile Problema_3
# Author:  Ruben Rodriguez Esteban 737215
# Fecha:   2 de noviembre de 2019
# Coms:    Fichero MakeFile para compilar el problema de algoritmis
#          para problemas dificiles
#          Para compilar y ejecutar seguir estos pasos en terminal
#          1 - Make clean
#          2 - Make
#          3 - Para ejecutar ./Test
#*********************************************************************

# Seleccion del compilador
CC=g++ -O3
INCLUDE=-L"/include/"

# Expansion de variables
BALA_DIR=Bala
CONTROL_DIR=Control
ESCUDO_DIR=Escudo
GRAFICOS_DIR=Graficos
INICIADOR_DIR=Iniciador
NAVE_DIR=Nave
NAVE_ENEMIGO_DIR=NaveEnemigo
NAVE_JUGADOR_DIR=NaveJugador

ALLEGRO=${ALLEGRO_DIR}/Allegro
BALA=${BALA_DIR}/Bala
CONTROL=${CONTROL_DIR}/Control
ESCUDO=${ESCUDO_DIR}/Escudo
GRAFICOS=${GRAFICOS_DIR}/Graficos
INICIADOR=${INICIADOR_DIR}/Iniciador
NAVE=${NAVE_DIR}/Nave
NAVE_ENEMIGO=${NAVE_ENEMIGO_DIR}/NaveEnemigo
NAVE_JUGADOR=${NAVE_JUGADOR_DIR}/NaveJugador


SPACEINVADERS=SpaceInvaders

# Flags de compilacion
CPPFLAGS=-O3 -std=c++11 -Wall
CLEANC=del *.o

# Regla para compilar el programa principal
all: ${SPACEINVADERS} 

# INICIADOR
# Compilacion
${INICIADOR}.o: ${INICIADOR}.h  ${INICIADOR}.cc
	${CC} ${INCLUDE} -c ${CPPFLAGS} ${INICIADOR}.cc -o ${INICIADOR}.o
#----------------------------------------------------------------

# NAVE
# Compilacion
${NAVE}.o: ${NAVE}.h  ${NAVE}.cc
	${CC} -c ${CPPFLAGS} ${NAVE}.cc -o ${NAVE}.o
#----------------------------------------------------------------

# NAVE_JUGADOR
# Compilacion
${NAVE_JUGADOR}.o: ${NAVE_JUGADOR}.h  ${NAVE_JUGADOR}.cc
	${CC} -c ${CPPFLAGS} ${NAVE_JUGADOR}.cc -o ${NAVE_JUGADOR}.o
#----------------------------------------------------------------

# NAVE_ENEMIGO
# Compilacion
${NAVE_ENEMIGO}.o: ${NAVE_ENEMIGO}.h  ${NAVE_ENEMIGO}.cc
	${CC} -c ${CPPFLAGS} ${NAVE_ENEMIGO}.cc -o ${NAVE_ENEMIGO}.o
#----------------------------------------------------------------

# BALA
# Compilacion
${BALA}.o: ${BALA}.h  ${BALA}.cc
	${CC} -c ${CPPFLAGS} ${BALA}.cc -o ${BALA}.o
#----------------------------------------------------------------

# ESCUDO
# Compilacion
${ESCUDO}.o: ${ESCUDO}.h  ${ESCUDO}.cc
	${CC} -c ${CPPFLAGS} ${ESCUDO}.cc -o ${ESCUDO}.o
#----------------------------------------------------------------

# GRAFICOS
# Compilacion
${GRAFICOS}.o: ${GRAFICOS}.h  ${GRAFICOS}.cc
	${CC} -c ${CPPFLAGS} ${GRAFICOS}.cc -o ${GRAFICOS}.o
#----------------------------------------------------------------

# PRUEBAS
# Compilacion
${SPACEINVADERS}.o: ${SPACEINVADERS}.cpp
	${CC} -c ${CPPFLAGS} ${SPACEINVADERS}.cpp

# Linkado
${SPACEINVADERS}: ${INICIADOR}.o ${BALA}.o ${NAVE_JUGADOR}.o ${NAVE_ENEMIGO}.o ${GRAFICOS}.o ${ESCUDO}.o ${CONTROL}.o ${PRUEBAS}.o  
	${CC} ${INICIADOR}.o ${BALA}.o ${NAVE_JUGADOR}.o ${NAVE_ENEMIGO}.o ${GRAFICOS}.o ${ESCUDO}.o ${CONTROL}.o ${PRUEBAS}.o -o ${PRUEBAS}
#---------------------------------------------------------------

# LIMPIEZA
clean:
	$(CLEANC)
