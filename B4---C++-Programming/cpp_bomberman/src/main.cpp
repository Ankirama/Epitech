//
// main.cpp for  in /home/teyssa_r/rendu/cpp_bomberman
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Fri May  8 02:15:55 2015 Raphael Teyssandier
// Last update Sun Jun 14 17:42:51 2015 Raphael Teyssandier
//

#include "GameEngine.hh"
#include "GenerateMaze.hh"
#include "Score.hh"
#include "IntroState.hh"
#include "Bomb.hh"
#include "Error.hpp"
#include <pthread.h>

// int	main(int, char **){
//   //GameEngine	game;
//   Score::getInstance().addScore("ankirama", 5000);
//   Score::getInstance().addScore("Ankirama", 5000);
//   Score::getInstance().addScore("louise", 10000);
//   Score::getInstance().showScore();
//   Score::getInstance().addScore("Fabien", 50000);
//   Score::getInstance().addScore("Zero", 5);
//   std::cout << "_______" << std::endl;
//   Score::getInstance().showScore();
//   GenerateMaze::getInstance().create(100, 100);
//   unsigned char *test = GenerateMaze::getInstance().getMap();
//   for (int i = 0; i < 10000; ++i) {
//     std::cout << (int(test[i])) << "|";
//     if (i % 100 == 99)
//       std::cout << std::endl;
//   }
//   return (0);
// }


int	main(int, char **){
  GameEngine	*game = new GameEngine();

  try {
    if (!game->initialize())
      throw ErrorBomberman("Game fail initialisation", "main");
    game->getMusic().setVolume(70.0);
    game->getMusic().play();
    game->ChangeState(IntroState::Instance());
    while (game->Running()){
      game->update();
      game->draw();
    }
    game->Cleanup();
  } catch (ErrorBomberman const &e) {
    std::cerr << "Error caught in " << e.getComponent() << ": " << e.what() << std::endl;
  }
  return (EXIT_SUCCESS);
}
