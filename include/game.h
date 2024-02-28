/* Checar si ya fue compilado el archivo para no tener que compilarlo denuevo */
#ifndef STRUCTURES_H
/* Definir que ya fue compilado el archivo */
#define STRUCTURES_H

#include <curses.h>
#include <stdlib.h>

/* Define la posición de algo */
typedef struct
{
  int y;
  int x;
} position;

/* Una entidad, tiene posición y un caracter que la representa */
typedef struct
{
  position pos;
  char ch;
} entity;

/* Un tile, puede ser suelo o no */
typedef struct
{
  char ch;
  /* stdbool posiblemente viene incluido en curses */
  bool walkable;
} tile;


/* Definir la firma de las funciones de engine.c */
void setup();
void loop();
void close();

/* Definir la firma de las funciones de player.c */
entity* create_player(position startpos);
void handle_input(char in);
void move_player(position pos);

/* Definir la firma de las funciones de draw.c */
void draw_map();
void draw_ent(entity* ent);
void draw();

/* Definir la firma de las funciones de map.c */
tile** create_maptiles();
position map1();
void freemap();

/* Variables externas / globales */
/* Incluir a la variable que va a ser el jugador principal
 * extern hace que se pueda usar en varios archivos */
extern entity* player;
/* Constantes del tamaño del mapa */
extern const int MAP1_HEIGHT;
extern const int MAP1_WIDTH;
/* Un puntero de punteros que incluya los tiles del mapa, aka. un arreglo de arreglos de tile */
extern tile** map;

/* Acaba el if que checa si ya fue compilado */
#endif
