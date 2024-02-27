#include <game.h>

/* Crear jugador */
entity* create_player(position startpos)
{
  /* Alocar espacio en memoria para una nueva entidad
   * No es necesario usar calloc ya que vamos a asignar inmediatamente la memoria */
  entity* new_player = malloc(sizeof(entity));

  /* Error si ya no hay memoria */
  if (new_player == NULL)
  {
    printf("Out of memory");
    exit(0);
  }

  /* Asignar la posición del jugador y su caracter
   * a -> b es equivalente a (*a).b */
  (*new_player).pos.x = startpos.x;
  (*new_player).pos.y = startpos.y;
  (*new_player).ch = '@';

  /* Devolver el jugador (su puntero en realidad) */
  return new_player;
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
    (*player).pos.y = npos.y;
    (*player).pos.x = npos.x;
  }
}
