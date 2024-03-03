/* gcc mouse.c -lcurses -std=c89 -o ./bin/<n> */
#include <curses.h>

int main()
{
  
  initscr();

  raw();
  noecho();
  keypad(stdscr, TRUE);
  
  mmask_t old;
  mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, &old);

  mouseinterval(200);

    /*
    BUTTON1_PRESSED          mouse button 1 down
    BUTTON1_RELEASED         mouse button 1 up
    BUTTON1_CLICKED          mouse button 1 clicked
    BUTTON1_DOUBLE_CLICKED   mouse button 1 double clicked
    BUTTON1_TRIPLE_CLICKED   mouse button 1 triple clicked
    BUTTON2_PRESSED          mouse button 2 down
    BUTTON2_RELEASED         mouse button 2 up
    BUTTON2_CLICKED          mouse button 2 clicked
    BUTTON2_DOUBLE_CLICKED   mouse button 2 double clicked
    BUTTON2_TRIPLE_CLICKED   mouse button 2 triple clicked
    BUTTON3_PRESSED          mouse button 3 down
    BUTTON3_RELEASED         mouse button 3 up
    BUTTON3_CLICKED          mouse button 3 clicked
    BUTTON3_DOUBLE_CLICKED   mouse button 3 double clicked
    BUTTON3_TRIPLE_CLICKED   mouse button 3 triple clicked
    BUTTON4_PRESSED          mouse button 4 down
    BUTTON4_RELEASED         mouse button 4 up
    BUTTON4_CLICKED          mouse button 4 clicked
    BUTTON4_DOUBLE_CLICKED   mouse button 4 double clicked
    BUTTON4_TRIPLE_CLICKED   mouse button 4 triple clicked
    BUTTON_SHIFT             shift was down during button state change
    BUTTON_CTRL              control was down during button state change
    BUTTON_ALT               alt was down during button state change
    ALL_MOUSE_EVENTS         report all button state changes
    REPORT_MOUSE_POSITION    report mouse movement
    */

  MEVENT event;
  int ch = 0;

  while (ch != 'q')
  {
    ch = getch();

    move(0, 0);
    clrtoeol();
    mvprintw(0,0, "key no. %d pressed", ch);
    mvprintw(2,0, "'q' to quit");
    refresh();

    if (ch == KEY_MOUSE)
    {
      if (getmouse(&event) == OK)
      {
        if (event.bstate & BUTTON1_PRESSED)
        {
          mvprintw(3,0, "Left Click Press , x: %d y: %d\n", event.x, event.y);
        }
        if (event.bstate & BUTTON2_PRESSED)
        {
          mvprintw(4,0, "Middle Click Press , x: %d y: %d\n", event.x, event.y);
        }
        if (event.bstate & BUTTON3_PRESSED)
        {
          mvprintw(5,0, "Right Click Press, x: %d y: %d\n", event.x, event.y);
        }
        if (event.bstate & BUTTON1_RELEASED)
        {
          mvprintw(6,0, "Left Click Release , x: %d y: %d\n", event.x, event.y);
        }
        if (event.bstate & BUTTON2_RELEASED)
        {
          mvprintw(7,0, "Middle Click Release , x: %d y: %d\n", event.x, event.y);
        }
        if (event.bstate & BUTTON3_RELEASED)
        {
          mvprintw(8,0, "Right Click Release, x: %d y: %d\n", event.x, event.y);
        }
        if ((event.bstate & BUTTON1_DOUBLE_CLICKED) || (event.bstate & BUTTON2_DOUBLE_CLICKED) || (event.bstate & BUTTON3_DOUBLE_CLICKED))
        {
          mvprintw(9,0, "Double click , x: %d y: %d\n", event.x, event.y);
        }
        if (event.bstate & BUTTON1_CLICKED)
        {
          mvprintw(10,0, "Left Click , x: %d y: %d\n", event.x, event.y); 
        }
        if (event.bstate & BUTTON2_CLICKED)
        {
          mvprintw(11,0, "Middle Click , x: %d y: %d\n", event.x, event.y); 
        }
        if (event.bstate & BUTTON3_CLICKED)
        {
          mvprintw(12,0, "Right Click , x: %d y: %d\n", event.x, event.y); 
        }
        move(1,0);
        refresh();
      }
    }
  }

  endwin();

  return 0;
}
