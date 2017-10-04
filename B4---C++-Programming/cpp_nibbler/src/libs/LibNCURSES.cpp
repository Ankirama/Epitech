//
// LibNCURSES.cpp for  in /home/teyssa_r/rendu/cpp_nibbler/libs
//
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
//
// Started on  Thu Mar 26 20:09:19 2015 Raphael Teyssandier
// Last update Sun Apr  5 17:37:41 2015 Raphael Teyssandier
//

#include <ncurses.h>
#include <unistd.h>
#include "LibNCURSES.hh"
#include "Error.hh"

LibNCURSES::LibNCURSES(int width, int height, int speed, GameLogic* gameLogic) {
  int		max_y(0), max_x(0);

  try {
    initscr();
    noecho();
    start_color();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_BLACK, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    refresh();
    getmaxyx(stdscr, max_y, max_x);
  }
  catch (ErrorNCURSES const& e) {
    this->close();
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorNCURSES("LibNCURSES");
  }
  this->m_gameLogic = gameLogic;
  this->m_width = this->m_gameLogic->getWidth();
  this->m_height = this->m_gameLogic->getHeight();
  this->m_x_velocity = 1;
  this->m_y_velocity = 0;
  if (max_y < this->m_height || max_x < this->m_width)
    {
      this->close();
      printf("Error: resize the terminal please x : %d | y : %d\n", max_x, max_y);
      exit(EXIT_FAILURE);
    }
  this->m_win = newwin(this->m_height + 2, this->m_width + 2, 1, 1);
  this->m_x_velocity = 1;
  this->m_y_velocity = 0;
  try {
    nodelay(stdscr, TRUE);
    box(this->m_win, 0, 0);
    wrefresh(this->m_win);
    this->draw();
  }
  catch (ErrorNCURSES const& e) {
    this->close();
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorNCURSES("LibNCURSES");
  }
}

bool	LibNCURSES::draw() {
  int	i(0), j(1), line(1);
  char	*map;

  map = this->m_gameLogic->getMap();
  while (i < this->m_height * this->m_width){
    if (j == this->m_height + 1)
      {
    	j = 1;
    	line += 1;
      }
    switch (map[i])
      {
      case ID_FOOD:
	try {
	  wattron(this->m_win, COLOR_PAIR(2));
	  mvwprintw(this->m_win, line, j, " ");
        }
	catch (ErrorNCURSES const& e) {
	  this->close();
	  std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
	  throw ErrorNCURSES("LibNCURSES");
	}
	j++;
	break;
      case ID_SNAKE:
	try {
	  wattron(this->m_win, COLOR_PAIR(1));
	  mvwprintw(this->m_win, line, j, " ");
	}
	catch (ErrorNCURSES const& e) {
	  this->close();
	  std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
	  throw ErrorNCURSES("LibNCURSES");
	}
	j++;
	break;
      case ID_FREE:
	try {
	  wattron(this->m_win, COLOR_PAIR(3));
	  mvwprintw(this->m_win, line, j, " ");
	}
	catch (ErrorNCURSES const& e) {
	  this->close();
	  std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
	  throw ErrorNCURSES("LibNCURSES");
	}
	j++;
	break;
      }
    i++;
  }
  try {
    wrefresh(this->m_win);
  }
  catch (ErrorNCURSES const& e) {
    this->close();
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorNCURSES("LibNCURSES");
  }
  return (true);
}

void	LibNCURSES::close(){
  try {
    curs_set(TRUE);
    delwin(this->m_win);
    endwin();
  }
  catch (ErrorNCURSES const& e) {
    exit(EXIT_FAILURE);
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    throw ErrorNCURSES("LibNCURSES");
  }
}

bool	LibNCURSES::update(){
  switch (getch()){
  case KEY_LEFT:
    this->changeVelocity(ID_LEFT);
    break;
  case KEY_RIGHT:
    this->changeVelocity(ID_RIGHT);
    break;
  case 27:
    this->close();
    return (false);
    break;
  case ERR:
    break;
  }
  return (this->m_gameLogic->update(this->m_x_velocity, this->m_y_velocity));
}

bool	LibNCURSES::game(){
  while (1){
    usleep(200000);
    if (!this->update()){
      this->close();
      return (false);
    }
    if (!this->draw()){
      this->close();
      return (false);
    }
  }
  return (true);
}

void	LibNCURSES::changeVelocity(int power) {
  if (this->m_x_velocity == 0) {
    this->m_x_velocity = this->m_y_velocity == 1 ? -1 * power : power;
    this->m_y_velocity = 0;
  }
  else {
    this->m_y_velocity = this->m_x_velocity == 1 ? power : -1 * power;
    this->m_x_velocity = 0;
  }
}

extern "C"
{
  IGraphLib *create_lib(int width, int height, int speed, GameLogic *gameLogic) {
    return new LibNCURSES(width, height, speed, gameLogic);
  }
}
