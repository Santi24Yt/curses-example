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
  /* Propiedades de los cuartos */
  int y;
  int x;
  int h;
  int w;

  /* Número de cuartos */
  int n = (rand() % 11) + 5;

  /* Cuartos */
  room* rooms = calloc(n, sizeof(room));

  int i;
  for (i = 0; i < n; i++)
  {
    /* Generar los parámetros aleatoriamente */
    y = (rand() % (MAP1_HEIGHT - 10)) + 1;
    x = (rand() % (MAP1_WIDTH - 30)) + 1;
    h = (rand() % 7) + 3;
    w = (rand() % 15) + 10;

    rooms[i] = newroom(y, x, h, w);
    addroom_tomap(rooms[i]);

    /* Conectar los cuartos */
    if (i > 0)
    {
      connectrooms(rooms[i-1], rooms[i]);
    }
  }

  /* Posicion inicial del jugador en este mapa */
  position start_pos = { rooms[0].center.y, rooms[0].center.x };

  /* Liberar la memoria ya que ya fueron dibujadas */
  free(rooms);

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
