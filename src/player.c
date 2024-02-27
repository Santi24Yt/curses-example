#include <game.h>

// Crear jugador
entity* create_player(position startpos)
{
  // Alocar espacio en memoria para una nueva entidad
  // No es necesario usar calloc ya que vamos a asignar inmediatamente la memoria
  entity* new_player = malloc(sizeof(entity));

  // Error si ya no hay memoria
  if (new_player == NULL)
  {
    printf("Out of memory");
    exit(0);
  }

  // Asignar la posición del jugador y su caracter
  // a -> b es equivalente a (*a).b
  (*new_player).pos.x = startpos.x;
  (*new_player).pos.y = startpos.y;
  (*new_player).ch = '@';

  // Devolver el jugador (su puntero en realidad)
  return new_player;
}

// Manejar las entradas del teclado
void handle_input(char in)
{
  switch (in)
  {
    // Moverse hacia arriba
    case 'k':
      (*player).pos.y--;
      break;
    // Moverse hacia abajo
    case 'j':
      (*player).pos.y++;
      break;
    // Moverse hacia izquierda
    case 'h':
      (*player).pos.x--;
      break;
    // Moverse hacia derecha
    case 'l':
      (*player).pos.x++;
      break;

    default:
      break;
  }
}
