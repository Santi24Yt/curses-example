#include <game.h>

/* Crear jugador */
entity* create_player(position startpos)
{
  /* Alocar espacio en memoria para una nueva entidad
   * No es necesario usar calloc ya que vamos a asignar inmediatamente la memoria */
  debug3("Allocate meory for player");
  entity* pnew_player = malloc(sizeof(entity));

  /* Error si ya no hay memoria */
  if (pnew_player == NULL)
  {
    debug3("Out of memory for player");
    close();
    printf("Out of memory\n");
    exit(1);
  }

  /* Asignar la posición del jugador y su caracter
   * a -> b es equivalente a (*a).b */
  (*pnew_player).pos.x = startpos.x;
  (*pnew_player).pos.y = startpos.y;
  (*pnew_player).ch = '@';
  (*pnew_player).color = COLOR_PAIR(VISIBLE_COLOR);

  /* Devolver el jugador (su puntero en realidad) */
  debug2("New player created");
  return pnew_player;
}

/* Manejar las entradas del teclado */
void handle_input(char in)
{
  /* Nueva posición */
  position newpos = (*player).pos;

  switch (in)
  {
    /* Moverse hacia arriba */
    case 'k':
      newpos.y--;
      break;
    /* Moverse hacia abajo */
    case 'j':
      newpos.y++;
      break;
    /* Moverse hacia izquierda */
    case 'h':
      newpos.x--;
      break;
    /* Moverse hacia derecha */
    case 'l':
      newpos.x++;
      break;

    default:
      break;
  }

  move_player(newpos);
}

/* Mover al jugador si es posible */
void move_player(position npos)
{
  if (map[npos.y][npos.x].walkable)
  {
    debug3("Moving player to y: %d, x: %d", npos.y, npos.x);
    clearfov(player);
    (*player).pos.y = npos.y;
    (*player).pos.x = npos.x;
    makefov(player);
  }
}
