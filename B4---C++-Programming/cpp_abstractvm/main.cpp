//
//  main.cpp
//  cpp_abstractvm
//
//  Created by Fabien Martinez on 21/02/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "CalculStack.hh"

int		main(int ac, char **av)
{
  CalculStack	*calc = new CalculStack();

  try {
    if (ac == 1)
      calc->on_standard();
    else
      calc->on_file(av[1]);
  }
  catch (EndError const& e) {
    std::cerr << "Error in " << e.getComponent() << " : " << e.what() << std::endl;
    return (1);
  }
  catch (ErrorAbstract const& e) {
    return (1);
  }
  return (0);
}
