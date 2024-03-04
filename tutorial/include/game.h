/* Checar si ya fue compilado el archivo para no tener que compilarlo denuevo */
#ifndef STRUCTURES_H
/* Definir que ya fue compilado el archivo */
#define STRUCTURES_H

#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Identificador de colores */
#define VISIBLE_COLOR 1
#define SEEN_COLOR 2

/* Usamos typedef para no tener que poner struct cada que queremos referenciar, puede ser mala práctica */
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
  int color;
} entity;

/* Un tile, puede ser suelo o no, puede seer visible o haber sido visitado */
typedef struct
{
  char ch;
  int color;
  /* stdbool posiblemente viene incluido en curses */
  bool walkable;
  bool transparent;
  bool visible;
  bool seen;
} tile;

/* Cuartos */
typedef struct
{
  int height;
  int width;
  position pos;
  position center;
} room;


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

/* Definir la firma de las funciones de room.c */
room newroom(int y, int x, int height, int width);
void addroom_tomap(room room);
void connectrooms(room room1, room room2);
void diagonalconnectrooms(room room1, room room2);

/* Definir la firma de las funciones de fov.c */
void makefov(entity* pplayer);
void clearfov(entity* pplayer);
int getdis(position origin, position target);
bool isinmap(int y, int x);
bool lineofsight(position origin, position target);
int getsign(int n);

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
