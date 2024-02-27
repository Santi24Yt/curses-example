// Importar curses (ncurses -> ncurses.h / pdcurses -> curses.h)
#include <game.h>

entity* player;

int main()
{
  // Inicializar ventana
  initscr();

  // No imprimir los caracteres que se escriben
  noecho();

  // Cambia la visibilidad del cursor
  // 0 -> invisible
  // 1 -> subrayado
  // 2 -> bloque
  curs_set(0);

  // Almacenar caracter leido
  char ch;
  // Posición inicial, **(y, x)**
  position startpos = { 10, 20 };
  // Crear al jugador principal
  player = create_player(startpos);
  // Escribir el caracter del jugador principal
  mvaddch((*player).pos.y, (*player).pos.x, (*player).ch);

  // Ciclo principal
  while (1)
  {
    // Obtener caracter
    ch = getch();
    // Salir del ciclo si se presiona 'q'
    if (ch == 'q')
    {
      break;
    }

    // Manejar el caracter introducido
    handle_input(ch);

    // Limpiar pantalla
    clear();
    // Dibujar nuevamente el caracter del jugador en (y, x)
    mvaddch((*player).pos.y, (*player).pos.x, (*player).ch);
  }

  // Cerrar la ventana
  endwin();

  return 0;
}
