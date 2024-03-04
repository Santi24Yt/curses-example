#include <game.h>

/* Calcular el fov */
void makefov(entity* pplayer)
{
  int distance;
  int radius = 15;

  position target;
  position playpos = (*pplayer).pos;

  map[playpos.y][playpos.x].visible = true;
  map[playpos.y][playpos.x].seen = true;

  int y;
  int x;

  for (y = playpos.y - radius; y < playpos.y + radius; y++)
  {
    for (x = playpos.x - radius; x < playpos.x + radius; x++)
    {
      target.y = y;
      target.x = x;
      distance = getdis(playpos, target);

      if (distance < radius && isinmap(y, x) && lineofsight(playpos, target))
      { 
        map[y][x].visible = true;
        map[y][x].seen = true;
      } 

    }
  }
}

/* Limpiar el fov */
void clearfov(entity* pplayer)
{ 
  int radius = 15;

  position playpos = (*pplayer).pos;

  int y;
  int x;

  for (y = playpos.y - radius; y < playpos.y + radius; y++)
  { 
    for (x = playpos.x - radius; x < playpos.x + radius; x++)
    {
      if (isinmap(y, x))
      {
        map[y][x].visible = false;
      }
    }
  } 
}

/* obtener distancia */
int getdis(position origin, position target)
{ 
  float dy;
  float dx;
  int distance;

  dx = target.x - origin.x;
  dy = target.y - origin.y;

  distance = floor(sqrt((dx * dx) + (dy * dy)));

  return distance;
}

/* Checar si está en el mapa */
bool isinmap(int y, int x)
{ 
  return (y >= 0 && y < MAP1_HEIGHT - 1) && (x >= 0 && x < MAP1_WIDTH - 1);
}

/* Checar si algo se alcanza a ver sin chocar con nada */
bool lineofsight(position origin, position target)
{
  int t, x, y, abs_delta_x, abs_delta_y, sign_x, sign_y, delta_x, delta_y;

  delta_x = origin.x - target.x;
  delta_y = origin.y - target.y;

  abs_delta_x = abs(delta_x);
  abs_delta_y = abs(delta_y);

  sign_x = getsign(delta_x);
  sign_y = getsign(delta_y);

  x = target.x;
  y = target.y;

  if (abs_delta_x > abs_delta_y)
  {
    t = abs_delta_y * 2 - abs_delta_x;

    do
    {
      if (t >= 0)
      {
        y += sign_y;
        t -= abs_delta_x * 2;
      }

      x += sign_x;
      t += abs_delta_y * 2;

      if (x == origin.x && y == origin.y)
      {
        return true;
      }
    }
    while (map[y][x].transparent);

    return false;
  }
  else
  {
    t = abs_delta_x * 2 - abs_delta_y;

    do
    {
      if (t >= 0)
      {
        x += sign_x;
        t -= abs_delta_y * 2;
      }

      y += sign_y;
      t += abs_delta_x * 2;

      if (x == origin.x && y == origin.y)
      {
        return true;
      }
    }
    while (map[y][x].transparent);

    return false;
  }
}

int getsign(int n)
{
  return (n < 0) ? -1 : 1;
}
