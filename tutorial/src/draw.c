#include <game.h>

/* Dibujar el mapa */
void draw_map()
{
  int y;
  int x;

  for (y = 0; y < MAP1_HEIGHT; y++)
  {
    for (x = 0; x < MAP1_WIDTH; x++)
    {
      mvaddch(y, x, map[y][x].ch);
    }
  }
}

/* Dibujar entidad */
void draw_ent(entity* ent)
{
  mvaddch((*ent).pos.y, (*ent).pos.x, (*ent).ch);
}

/* Dibujar todo */
void draw()
{
  clear();
  draw_map();
  draw_ent(player);
}
