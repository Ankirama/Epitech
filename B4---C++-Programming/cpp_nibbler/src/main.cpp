//
//  main.cpp
//  cpp_nibbler
//
//  Created by Fabien Martinez on 23/03/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "GameLogic.hh"
#include "DLLoader.hh"
#include "Error.hh"

static int	_usage() {
  std::cout << "Usage : ./nibbler WIDTH HEIGHT LIB.SO [SPEED]" << std::endl;
  return (1);
}

static int		_checkInt(char *str) {
  int			nb;
  std::stringstream	stream;

  stream << str;
  if (!(stream >> nb)) {
    std::cerr << "Error: " << str << "isn't a valid integer" << std::endl;
    _usage();
    return (-1);
  }
  return (nb);
}

int		main(int argc, char **argv) {
  GameLogic	*game;
  int		width;
  int		height;
  int		speed;
  DLLoader	*dlloader;
  IGraphLib	*libGraph;

  if (argc < 4)
    return (_usage());
  if ((width = _checkInt(argv[1])) == -1 || (height = _checkInt(argv[2])) == -1)
    return (1);
  if (width < 5 || height < 5 || width > 50 || height > 50) {
    std::cerr << "Limits : 5 >= size <= 50" << std::endl;
    return (1);
  }
  if (argc == 5)
    {
      if ((speed = _checkInt(argv[4])) == -1 || speed <= 0)
	return (1);
    }
  else
    speed = 1;
  game = new GameLogic(width, height);
  try {
    dlloader = new DLLoader(argv[3], "create_lib");
  }
  catch (ErrorLib const& e) {
    std::cerr << "Error in " << e.getComponent() << ": " << e.what() << std::endl;
  }
  try {
    libGraph = dlloader->getInstance(800, 640, speed, game);
  }
  catch (ErrorLib const& e) {
    std::cerr << "Error in " << e.getComponent() << ": " << e.what() << std::endl;
  }
  (void)libGraph->game();
  std::cout << "Score : " << game->getScore() << std::endl;
  delete game;
  delete dlloader;
  return (0);
}
