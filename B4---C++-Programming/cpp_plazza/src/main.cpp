//
// main.cpp for main in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sun Apr 26 21:25:41 2015 Alexandre Chenevier
// Last update Sun Apr 26 22:22:13 2015 Raphael Teyssandier
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <QThread>
#include "Pizza.hh"
#include "IPizza.hh"
#include "PMutex.hh"
#include "Kitchen.hh"
#include "Ingredient.hh"
#include "Graphic.hh"
#include "Parser.hh"
#include "Log.hh"
#include "POutNamedPipe.hh"
#include "PInNamedPipe.hh"
#include "Pizzas.hh"

pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

static bool	_usage() {
  std::cout << "Usage: ./plazza cooking_time_multiplier number_cooks time_replace" << std::endl;
  return (false);
}

/*
** brief: check params
** @argv: each params
** return: return false if any problem, else true
*/
static bool		_check_params(char **argv, float &multi, int &cooks, int &time)
{
  std::istringstream	tmp;

  tmp.str(argv[1]);
  if (!(tmp >> multi) || multi < 0.0f) {
    Log::getInstance().writeError("must be a float >= 0", argv[1]);
    return _usage();
  }
  tmp.clear();
  tmp.str(argv[2]);
  if (!(tmp >> cooks) || cooks <= 0) {
    Log::getInstance().writeError("must be a number greater than 0", argv[2]);
    return _usage();
  }
  tmp.clear();
  tmp.str(argv[3]);
  if (!(tmp >> time) || time < 0) {
    Log::getInstance().writeError("must be a number greater than 0", argv[3]);
    return _usage();
  }
  return true;
}

static void	_init_ingredients(std::vector<IIngredient *> &ingredients) {
  ingredients.push_back(new Ingredient(std::string("doe")));
  ingredients.push_back(new Ingredient("tomato"));
  ingredients.push_back(new Ingredient("gruyere"));
  ingredients.push_back(new Ingredient("ham"));
  ingredients.push_back(new Ingredient("mushrooms"));
  ingredients.push_back(new Ingredient("steak"));
  ingredients.push_back(new Ingredient("eggplant"));
  ingredients.push_back(new Ingredient("goat cheese"));
  ingredients.push_back(new Ingredient("chief love"));
}

static void	_clean_ingredients(std::vector<IIngredient *> &ingredients) {
  IIngredient *tmp;
  while (!ingredients.empty()) {
    tmp = ingredients.back();
    ingredients.pop_back();
    delete tmp;
  }
}

void    named_pipe()
{
  POutNamedPipe                 *pipeOut;
  PInNamedPipe                  *pipeIn;

  int pid = fork();
  if (pid == 0) {
    std::cout << "child" << std::endl;
    pipeOut = new POutNamedPipe("/tmp/myfifo42");
    pipeOut->send("This is a Named Pipe test");
    delete pipeOut;
  }
  else {
    std::cout << "not child" << std::endl;
    pipeIn = new PInNamedPipe("/tmp/myfifo42");
    std::cout << "I received: " << pipeIn->receive();
    delete pipeIn;
  }
}

int				main(int argc, char **argv)
{
  float				multi;
  int				cooks, time;
  std::vector<IIngredient *>	ingredients;
  Kitchen			*kitchen1;
  QApplication			app(argc, argv);
  myWindow			*window;
  std::vector<IPizza *>		pizza;

  multi = 0.0f;
  cooks = 0;
  time = 0;
  if (argc != 4) {
    Log::getInstance().writeError("Not enough parameters", "argv");
    _usage();
    return (1);
  }
  if (!_check_params(argv, multi, cooks, time))
    return (1);
  _init_ingredients(ingredients);
  window = new myWindow(ingredients);
  kitchen1 = new Kitchen(multi, time, cooks, ingredients);
  window->addKitchen(multi, time, cooks, WAIT_KIT);
  Pizzas::getInstance().addPizza("Regina", 10, ingredients);
  Pizzas::getInstance().addPizza("plop", 10, ingredients);
  Pizzas::getInstance().addPizza("test", 10, ingredients);
  delete kitchen1;
  _clean_ingredients(ingredients);
  return (app.exec());
}
