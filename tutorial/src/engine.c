#include <game.h>

void setup()
{
  /* Inicializar ventana */
  initscr();

  /* No imprimir los caracteres que se escriben */
  noecho();

  /* Cambia la visibilidad del cursor
   * 0 -> invisible
   * 1 -> subrayado
   * 2 -> bloque */
  curs_set(0);

  /* Inicializar colores o salir si no están disponibles */
  if (has_colors() == FALSE)
  {
    close();
    printf("Colors are not supported by your terminal\n");
    exit(1);
  }

  start_color();

  init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
  init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK);
}

void loop()
{
  /* Almacenar caracter leido */
  char ch;
  /* Crear fov */
  makefov(player);
  /* Dibujar los caracteres */
  draw();

  /* Ciclo principal */
  while (1)
  {
    /* Obtener caracter */
    ch = getch();
    /* Salir del ciclo si se presiona 'q' */
    if (ch == 'q')
    {
      break;
    }

    /* Manejar el caracter introducido */
    handle_input(ch);

    /* Dibujar los caracteres */
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
