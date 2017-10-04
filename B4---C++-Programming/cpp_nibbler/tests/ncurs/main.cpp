//
// main.cpp for  in /home/teyssa_r/rendu/cpp_nibbler/tests/ncurs
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Fri Mar 27 01:39:13 2015 Raphael Teyssandier
// Last update Fri Mar 27 01:46:38 2015 Raphael Teyssandier
//

#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int	main(int argc, char *argv[]) {
  int	x = 0, y = 0;
  int	max_y = 0, max_x = 0;
  int	next_x = 0;
  int	direction = 1;

  initscr();
  noecho();
  curs_set(FALSE);
  // Global var `stdscr` is created by the call to `initscr()`
  getmaxyx(stdscr, max_y, max_x);
  while(1) {
    clear();
    mvprintw(y, x, "o");
    refresh();
    usleep(DELAY);
    next_x = x + direction;
    if (next_x >= max_x || next_x < 0) {
      direction*= -1;
    } else {
      x+= direction;
    }
  }
  endwin();
}
