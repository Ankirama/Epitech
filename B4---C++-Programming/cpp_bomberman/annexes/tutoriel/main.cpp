//
// main.cpp for  in /home/viterb_c/tuto_lib_bomberman
// 
// Made by CHARLES VITERBO
// Login   <viterb_c@epitech.net>
// 
// Started on  Tue May 12 15:51:22 2015 CHARLES VITERBO
// Last update Mon May 18 17:15:51 2015 CHARLES VITERBO
//

#include <cstdlib>

#include <unistd.h>
#include "GameEngine.hpp"

int	main()	{
  GameEngine	engine;

  if (engine.initialize() == false)
    {
      std::cout << "Oups i did it again" << std::endl;
      return (EXIT_FAILURE);
    }
  while (engine.update() == true)
    engine.draw();
  return (0);
}
