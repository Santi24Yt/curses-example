#include <game.h>

/* Instanciar cuarto */
room newroom(int y, int x, int h, int w)
{
  room nroom;

  nroom.pos.y = y;
  nroom.pos.x = x;
  nroom.height = h;
  nroom.width = w;
  nroom.center.y = y + h/2;
  nroom.center.x = x + w/2;

  return nroom;
}

/* Dibujar cuarto en el mapa */
void addroom_tomap(room r)
{
  int y;
  for (y = r.pos.y; y < r.pos.y + r.height; y++)
  {
    int x;
    for (x = r.pos.x; x < r.pos.x + r.width; x++)
    {
      map[y][x].ch = '.';
      map[y][x].walkable = true;
    }
  }
}
