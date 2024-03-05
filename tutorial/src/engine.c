#include <game.h>

void setup()
{
  debug2("Initializing screen");
  /* Inicializar ventana */
  initscr();
  debug2("Screen initialized");

  /* No imprimir los caracteres que se escriben */
  noecho();
  debug3("No echo active");

  /* Cambia la visibilidad del cursor
   * 0 -> invisible
   * 1 -> subrayado
   * 2 -> bloque */
  curs_set(0);
  debug3("Cursor mode set to 0");

  debug1("Checking for colors");
  /* Inicializar colores o salir si no están disponibles */
  if (has_colors() == FALSE)
  {
    debug1("No color, exiting");
    close();
    printf("Colors are not supported by your terminal\n");
    exit(1);
  }

  start_color();
  debug1("Colors initialized");

  init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
  init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK);
  debug3("Color pairs initialized");
}

void loop()
{
  /* Almacenar caracter leido */
  char ch;
  /* Crear fov */
  debug2("Making fov");
  makefov(player);
  /* Dibujar los caracteres */
  debug1("Drawing everything");
  draw();

  /* Ciclo principal */
  while (1)
  {
    /* Obtener caracter */
    ch = getch();
    /* Salir del ciclo si se presiona 'q' */
    if (ch == 'q')
    {
      debug1("Exiting");
      break;
    }

    /* Manejar el caracter introducido */
    debug1("Handle input (key: %c)", ch);
    handle_input(ch);

    /* Dibujar los caracteres */
    debug1("Drawing everything");
    draw();
  }
}

void close()
{
  /* Cerrar la ventana */
  endwin();

  /* Liberar la memoria alocada dinámicamente */
  free(player);
  freemap();

  /* Nótese que podemos usar printf sin importar stdio ya que posiblemente curses la importa, por lo que ya estaría importada */
  printf("Goodbye\n");
}
