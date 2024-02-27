#include <game.h>

/* Funcion para alocar los tiles del mapa */
tile** create_maptiles()
{
  int y = 0;
  int x = 0;
  /* Alocar la memoria para las columnas del mapa */
  tile** tiles = calloc(MAP1_HEIGHT, sizeof(tile*));

  for (y = 0; y < MAP1_HEIGHT; y++)
  {
    /* Alocar la memoria para los tiles del mapa */
    tiles[y] = calloc(MAP1_WIDTH, sizeof(tile));
    for (x = 0; x < MAP1_WIDTH; x++)
    {
      tiles[y][x].ch = '#';
      tiles[y][x].walkable = false;
    }
  }

  return tiles;
}

/* Un mapa con espacio para moverse */
position map1()
{
  int y;
  int x;
  /* Posicion inicial del jugador en este mapa */
  position start_pos = { 10, 50 };

  for (y = 5; y < 15; y++)
  {
    for (x = 40; x < 60; x++)
    {
      map[y][x].ch = '.';
      map[y][x].walkable = true;
    }
  }

  return start_pos;
}

/* Liberar la memoria alocada dinámicamente para el mapa */
void freeMap()
{
  int y;

  /* Como el mapa es un arreglo de punteros no podemos solo liberar el mapa
   * tenemos que liberar cada columna por separado */
  for (y = 0; y < MAP1_HEIGHT; y++)
  {
    free(map[y]);
  }

  /* Finalmente liberamos el arreglo de apuntadores */
  free(map);
}
