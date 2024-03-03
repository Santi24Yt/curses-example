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

void connectrooms(room r1, room r2)
{
  position c1 = r1.center;
  position c2 = r2.center;

  while (true)
  { 
    /* Checar en que dirección nos acercamos y avanzar hacia ella */
    if (abs((c1.x - 1) - c2.x) < abs(c1.x - c2.x))
      c1.x--;
    else if (abs((c1.x + 1) - c2.x) < abs(c1.x - c2.x))
      c1.x++;
    else if (abs((c1.y + 1) - c2.y) < abs(c1.y - c2.y))
      c1.y++;
    else if (abs((c1.y - 1) - c2.y) < abs(c1.y - c2.y))
      c1.y--;
    else
      break;

    map[c1.y][c1.x].ch = '.';
    map[c1.y][c1.x].walkable = true;

    /* Hacerlos más anchos si es posible */
    if (c1.y - 1 > 0)
    {
      map[c1.y - 1][c1.x].ch = '.';
      map[c1.y - 1][c1.x].walkable = true;
    }
    if (c1.x - 1 > 0)
    {
      map[c1.y][c1.x - 1].ch = '.';
      map[c1.y][c1.x - 1].walkable = true;
    }

  }
}
