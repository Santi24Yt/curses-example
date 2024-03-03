/* gcc io.c -lcurses -std=c89 -o ./bin/<n> */
#include <curses.h>

int main()
{
  
  initscr();

  addstr("Long long long long text, Name? ");

  char respuesta[5];
  /* overflow
  getstr(respuesta); */
  /* no overflow */
  getnstr(respuesta, 5);

  move(0, 0);
  clrtoeol();

  mvprintw(0, 0, "Welcome to curses %s\n", respuesta);

  addstr("Password? (max. 10 chars)");
  addstr("\n");
  noecho();

  char notsafe[10];
  getnstr(notsafe, 10);

  int cy, cx;
  getsyx(cy, cx);
  move(cy-1, 0);
  clrtoeol();

  addstr("Done\n");
  echo();

  char extra[100];
  getnstr(extra, 100);

  getch();
  endwin();

  return 0;
}
