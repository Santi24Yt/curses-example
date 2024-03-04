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
      map[y][x].transparent = true;
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
    map[c1.y][c1.x].transparent = true;

    /* Hacerlos más anchos si es posible */
    if (c1.y - 1 > 0)
    {
      map[c1.y - 1][c1.x].ch = '.';
      map[c1.y - 1][c1.x].walkable = true;
      map[c1.y - 1][c1.x].transparent = true;
    }
    if (c1.x - 1 > 0)
    {
      map[c1.y][c1.x - 1].ch = '.';
      map[c1.y][c1.x - 1].walkable = true;
      map[c1.y][c1.x - 1].transparent = true;
    }

  }
}

/* Generar caminos diagonales si es posible */
void diagonalconnectrooms(room r1, room r2)
{
  position c1 = r1.center;
  position c2 = r2.center;

  int y1;
  int y2;
  int x1;
  int x2;

  if (c2.x >= c1.x)
  {
    y2 = c2.y;
    x2 = c2.x;
    y1 = c1.y;
    x1 = c1.x;
  } else {
    y2 = c1.y;
    x2 = c1.x;
    y1 = c2.y;
    x1 = c2.x;
  }

  if (x2 - x1 == 0)
  {
    connectrooms(r1, r2);
    /* fprintf(stderr, "No diagnoal\n"); */
    return;
  }

  float m = (float)(y2 - y1)/(float)(x2 - x1);
  float b = (float)y2 - m*(float)x2;

  /* fprintf(stderr, "(x1: %d, y1: %d)\n", x1, y1);
  fprintf(stderr, "(x2: %d, y2: %d)\n", x2, y2); */

  int prevx = x1;
  int prevy = y1;

  int i;
  for (i = x1; i <= x2; i++)
  {
    int x = i;
    int y = (int)(m*(float)x + b);

    /* fprintf(stderr, "(%d, %d)\n", x, y); */

    map[y][x].ch = '.';
    map[y][x].walkable = true;
    map[y][x].transparent = true;

    if (y - 1 > 0)
    {
      map[y-1][x].ch = '.';
      map[y-1][x].walkable = true;
      map[y-1][x].transparent = true;
    }

    if (x - 1 > 0)
    {
      map[y][x-1].ch = '.';
      map[y][x-1].walkable = true;
      map[y][x-1].transparent = true;
    }


    if (x - prevx > 1)
    {
      int j;
      for (j = prevx; j <= x; j++)
      {
        map[y][j].ch = '.';
        map[y][j].walkable = true;
        map[y][j].transparent = true;

        if (y - 1 > 0)
        {
          map[y-1][x].ch = '.';
          map[y-1][x].walkable = true;
          map[y-1][x].transparent = true;
        }

        if (x - 1 > 0)
        {
          map[y][x-1].ch = '.';
          map[y][x-1].walkable = true;
          map[y][x-1].transparent = true;
        }
      }
    }

    if (y - prevy > 1)
    {
      int j;
      for (j = prevy; j <= y; j++)
      {
        map[j][x].ch = '.';
        map[j][x].walkable = true;
        map[j][x].transparent = true;

        if (y - 1 > 0)
        {
          map[y-1][x].ch = '.';
          map[y-1][x].walkable = true;
          map[y-1][x].transparent = true;
        }

        if (x - 1 > 0)
        {
          map[y][x-1].ch = '.';
          map[y][x-1].walkable = true;
          map[y][x-1].transparent = true;
        }
      }
    }

    if (prevy - y > 1)
    {
      int j;
      for (j = y; j <= prevy; j++)
      {
        map[j][x].ch = '.';
        map[j][x].walkable = true;
        map[j][x].transparent = true;

        if (y - 1 > 0)
        {
          map[y-1][x].ch = '.';
          map[y-1][x].walkable = true;
          map[y-1][x].transparent = true;
        }

        if (x - 1 > 0)
        {
          map[y][x-1].ch = '.';
          map[y][x-1].walkable = true;
          map[y][x-1].transparent = true;
        }
      }
    }

    prevx = x;
    prevy = y;
  }
}
