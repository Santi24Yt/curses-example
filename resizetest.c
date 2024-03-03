/* gcc resizetest.c -lcurses -std=c89 -o ./bin/<n> */
#include <curses.h>

int main()
{

  initscr();

  resizeterm(40, 120);

  while (getch() != 'q')
  {
    int row, col;

    getmaxyx(stdscr, row, col);
    resize_term(row, col);
    getmaxyx(stdscr, row, col);

    getmaxyx(stdscr,row,col);
    mvprintw(0, 0, "Screen size: rows %d, columns %d", row, col);
    mvprintw(1, 0, "Texto largo lorem ipsum pero no me lo se solo estoy llenando de caracteres asadsdada");

    mvprintw(3, 0, "012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679012345679");

    refresh();
  }

  endwin();

  return 0;
}
