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
      if (map[y][x].visible)
      {
        mvaddch(y, x, map[y][x].ch | map[y][x].color);
      }
      else if (map[y][x].seen)
      {
        mvaddch(y, x, map[y][x].ch | COLOR_PAIR(SEEN_COLOR));
      }
      else
      {
        mvaddch(y, x, ' ');
      }
    }
  }
}

/* Dibujar entidad */
void draw_ent(entity* pent)
{
  entity ent = *pent;
  mvaddch(ent.pos.y, ent.pos.x, ent.ch | ent.color);
}

/* Dibujar todo */
void draw()
{
  debug3("Clearing screen");
  clear();
  debug2("Drawing map");
  draw_map();
  debug2("Drawing player");
  draw_ent(player);
}
