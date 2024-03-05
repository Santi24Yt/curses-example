#include <game.h>

/* Funcion para alocar los tiles del mapa */
tile** create_maptiles()
{
  debug3("Allocating memory for tiles");
  /* Alocar la memoria para las columnas del mapa */
  tile** tiles = calloc(MAP1_HEIGHT, sizeof(tile*));

  if (tiles == NULL)
  {
    debug3("Out of memory for tiles");
    close();
    printf("Out of memory\n");
    exit(1);
  }

  int y;
  int x;

  for (y = 0; y < MAP1_HEIGHT; y++)
  {
    /* Alocar la memoria para los tiles del mapa */
    tiles[y] = calloc(MAP1_WIDTH, sizeof(tile));

    if (tiles[y] == NULL)
    {
      debug3("Out of memory for tiles");
      close();
      printf("Out of memory\n");
      exit(1);
    }

    for (x = 0; x < MAP1_WIDTH; x++)
    {
      tiles[y][x].ch = '#';
      tiles[y][x].color = COLOR_PAIR(VISIBLE_COLOR);
      tiles[y][x].walkable = false;
      tiles[y][x].transparent = false;
      tiles[y][x].visible = false;
      tiles[y][x].seen = false;
    }
  }

  debug3("Tiles allocated");

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
  debug3("Allocating memory for rooms");
  room* rooms = calloc(n, sizeof(room));

  if (rooms == NULL)
  {
    debug3("Out of memory for rooms");
    close();
    printf("Out of memory\n");
    exit(1);
  }

  /* fprintf(stderr, "Generating rooms\n"); */

  debug2("Generating rooms");
  int i;
  for (i = 0; i < n; i++)
  {
    /* Generar los parámetros aleatoriamente */
    y = (rand() % (MAP1_HEIGHT - 10)) + 1;
    x = (rand() % (MAP1_WIDTH - 30)) + 1;
    h = (rand() % 7) + 3;
    w = (rand() % 15) + 10;

    debug3("Generating room %d", i+1);

    rooms[i] = newroom(y, x, h, w);
    debug3("Adding room to map");
    addroom_tomap(rooms[i]);

    /* Conectar los cuartos */
    if (i > 0)
    {
      debug3("Connecting room%d and room%d", i, i+1);
      diagonalconnectrooms(rooms[i-1], rooms[i]);
    }
  }

  /* Posicion inicial del jugador en este mapa */
  position start_pos = { rooms[0].center.y, rooms[0].center.x };
  debug2("Player startpos y: %d, x: %d", start_pos.y, start_pos.x);

  /* Liberar la memoria ya que ya fueron dibujadas */
  free(rooms);
  debug3("Room memory freed");
  debug2("map1 created");

  return start_pos;
}

/* Liberar la memoria alocada dinámicamente para el mapa */
void freemap()
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
