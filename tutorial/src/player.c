#include <game.h>

/* Crear jugador */
entity* create_player(position startpos)
{
  /* Alocar espacio en memoria para una nueva entidad
   * No es necesario usar calloc ya que vamos a asignar inmediatamente la memoria */
  entity* pnew_player = malloc(sizeof(entity));

  /* Error si ya no hay memoria */
  if (pnew_player == NULL)
  {
    close();
    fprintf(stderr, "Out of memory\n");
    exit(1);
  }

  entity player = *pnew_player;

  /* Asignar la posición del jugador y su caracter
   * a -> b es equivalente a (*a).b */
  player.pos.x = startpos.x;
  player.pos.y = startpos.y;
  player.ch = '@';
  player.color = COLOR_PAIR(VISIBLE_COLOR);

  (*pnew_player) = player;
  /* Devolver el jugador (su puntero en realidad) */
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
    clearfov(player);
    (*player).pos.y = npos.y;
    (*player).pos.x = npos.x;
    makefov(player);
  }
}
