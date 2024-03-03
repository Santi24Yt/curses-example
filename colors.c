/* gcc colors.c -lcurses -std=c89 -o ./bin/<n> */
#include <curses.h>

int main()
{
  
  initscr();

  if (has_colors() == FALSE)
  {
    endwin();
    printf("Colors are not supported by your terminal\n");
    return 1;
  }

  start_color();

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  init_pair(3, COLOR_CYAN, COLOR_BLACK);

  attron(COLOR_PAIR(1));
  addstr("Hello world!\n");
  attroff(COLOR_PAIR(1));
  attron(COLOR_PAIR(2));
  addstr("Inverted text\n");
  attroff(COLOR_PAIR(2));

  refresh();

  addstr("A example string\n");
  int cy, cx;
  getsyx(cy, cx);
  mvchgat(cy, 0, -1, A_BLINK, 3, NULL);

  mvprintw(++cy,0,"Another example string");

  mvprintw(++cy,0,"Yet another example string");
  mvchgat(cy, 0, 6, A_BLINK, 3, NULL);

  getch();
  endwin();

  return 0;
}
