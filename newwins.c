/* gcc spawnwins.c -lcurses -std=c89 -o ./bin/<n> */
#include <curses.h>


WINDOW *spawnwin(int h, int w, int sy, int sx);
void destrwin(WINDOW *win);


int main()
{

  initscr();

  WINDOW *win;

  printw("Hello World !!!");

  mvaddstr(6, 32, "Test %d");
  mvprintw(7, 32, "Test %d", 10);

  refresh();

  win = spawnwin(10, 15, 5, 5);

  mvwprintw(win, 1, 1, "123");
  wrefresh(win);

  getch();
  wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wrefresh(win);
  mvwin(win, 3, 3);
  wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(win);
  refresh();

  getch();
  destrwin(win);

  getch();
  endwin();

  return 0;
}



WINDOW *spawnwin(int h, int w, int sy, int sx)
{	
  WINDOW *win;

  win = newwin(h, w, sy, sx);
  wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(win);

  return win;
}


void destrwin(WINDOW *win)
{	
  wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wclear(win);
  wrefresh(win);
  delwin(win);
}
