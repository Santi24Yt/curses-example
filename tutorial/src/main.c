/* Importar curses (ncurses -> ncurses.h / pdcurses -> curses.h) */
#include <game.h>

const int MAP1_HEIGHT = 25;
const int MAP1_WIDTH = 100;

entity* player;
tile** map;

int main()
{
  setup();

  /* Posición inicial, **(y, x)** */
  position startpos;
  /* Crear el mapa */
  map = create_maptiles();
  startpos = map1();
  /* Crear al jugador principal */
  player = create_player(startpos);

  loop();

  close();

  return 0;
}