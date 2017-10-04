//
// main.cpp for  in /home/tang_i/rendu/PSU_2014_zappy/annexes/sfml2d
// 
// Made by David Tang
// Login   <tang_i@epitech.net>
// 
// Started on  Fri Jun 19 14:29:26 2015 David Tang
// Last update Sun Jul  5 18:12:51 2015 Raphael Teyssandier
//

#include "Error.hpp"
#include "GameEngine.hh"
#include "Music.hh"

int		main(int ac, char **av)
{
  GameEngine	*game = 0;
  Music		*music = 0;
  if (ac < 3){
    std::cout << USAGE << std::endl;
    return 0;
  }
  try
    {
      game = new GameEngine(ac, av);
      music = new Music;
      game->init(1280, 720);
      music->loadMusic(DOFUS);
      music->playMusic();
      game->game();
      music->stopMusic();
      delete game;
      delete music;
    }
  catch (ErrorClient const &e){
    if (e.what() == USAGE)
      std::cout << USAGE << std::endl;
    else
      std::cerr << "Error caught in " << e.getComponent() << ": " << e.what()
	      << std::endl;
    delete game;
    delete music;
    return (1);
  }
  return (0);
}
