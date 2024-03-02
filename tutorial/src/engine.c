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
}

void loop()
{
  /* Almacenar caracter leido */
  char ch;
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

  /* Nótese que podemos usar printf sin importar stdio ya que posiblemente curses la importa, por lo que ya estaría importada */
  printf("Goodbye\n");
}
