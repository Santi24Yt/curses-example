/* gcc helloworld.c -lcurses -std=c89 -o ./bin/<n> */
#include <curses.h>

int main()
{

  initscr();

  printw("Hello world!");

  refresh();
  getch();

  endwin();

  return 0;
}
