//
// main.cpp for  in /home/teyssa_r/rendu/PSU_2014_zappy/src/client
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Wed Jun 17 16:33:15 2015 Raphael Teyssandier
// Last update Sun Jul  5 19:07:25 2015 Raphael Teyssandier
//

#include "Parser.hh"
#include "ClientAI.hh"
#include "Error.hpp"

int	main(int ac, char **av)
{
  try {
    if (ac < 5){
      std::cout << USAGE << std::endl;
      return 0;
    }
    ClientAI	*client = new ClientAI(ac, av);

    client->init();
    client->cycle();
  } catch (ErrorClient const &e) {
    if (e.what() == USAGE)
      std::cout << USAGE << std::endl;
    else if (e.what() == std::string("MORT"))
      std::cout << "\e[0;31mI'm \e[0;30mDead\e[0;0m" << std::endl;
    else
      std::cerr << "Error caught in " << e.getComponent() << ": " << e.what()
		<< std::endl;
  }
  return (0);
}
