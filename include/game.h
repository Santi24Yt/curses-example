// Checar si ya fue compilado el archivo para no tener que compilarlo denuevo
#ifndef STRUCTURES_H
// Definir que ya fue compilado el archivo
#define STRUCTURES_H

#include <curses.h>
#include <stdlib.h>

// Define la posición de algo
typedef struct
{
  int x;
  int y;
} position;

// Una entidad, tiene posición y un caracter que la representa
typedef struct
{
  position pos;
  char ch;
} entity;


// Definir la firma de las funciones de player.c
entity* create_player(position startpos);
void handle_input(char in);

// Incluir a la variable que va a ser el jugador principal
// extern hace que se pueda usar en varios archivos
extern entity* player;

// Acaba el if que checa si ya fue compilado
#endif
