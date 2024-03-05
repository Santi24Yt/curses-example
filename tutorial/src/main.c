/* Importar curses (ncurses -> ncurses.h / pdcurses -> curses.h) */
#include <game.h>

const int MAP1_HEIGHT = 25;
const int MAP1_WIDTH = 100;

entity* player;
tile** map;

int main()
{
  /* Debug log */
  debug1("Starting setup");

  setup();
  debug1("Setup finished");

  /* Semilla aleatoria */
  time_t seed = time(NULL);
  srand(seed);
  debug1("Seed: %ld", seed);

  debug1("Setting up map");
  /* Posición inicial, **(y, x)** */
  position startpos;
  /* Crear el mapa */
  debug2("Create tiles");
  map = create_maptiles();
  debug2("Create map1");
  startpos = map1();
  /* Crear al jugador principal */
  debug2("Create player");
  player = create_player(startpos);

  debug1("Starting game loop");
  loop();

  debug1("Closing");
  close();

  return 0;
}
