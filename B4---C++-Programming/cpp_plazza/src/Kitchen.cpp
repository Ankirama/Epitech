//
// Kitchen.cpp for Kitchen in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sun Apr 26 21:25:22 2015 Alexandre Chenevier
// Last update Sun Apr 26 21:25:23 2015 Alexandre Chenevier
//

#include "Kitchen.hh"

Kitchen::Kitchen(int cookingTime, long replaceTime, int nbCooks,
		 std::vector<IIngredient *> ingredients) {
  this->m_cookingTime = cookingTime;
  this->m_replaceTime = replaceTime;
  this->m_nbCooks = nbCooks;
  this->m_mutex = new PMutex();
  this->m_cond = new PCondVar();
  this->m_stock = new Stock(replaceTime, ingredients, this->m_mutex);
  this->m_scoped = 0;
  for (int i = 0; i < nbCooks; ++i) {
    this->m_cooks.push_back(new Cook(cookingTime, this->m_cond, this->m_mutex,
				     *this->m_stock, m_pizzas));
  }
}

Kitchen::~Kitchen() {
  Cook *tmp;
  while (!this->m_cooks.empty()) {
    tmp = this->m_cooks.back();
    this->m_cooks.pop_back();
    delete tmp;
  }
  Log::getInstance().writeLog("Cooks deleted", "Kitchen");
  this->m_stock->setStatus(false);
  delete this->m_stock;
  Log::getInstance().writeLog("Stock deleted", "Kitchen");
  if (this->m_scoped != 0)
    delete this->m_scoped;
  Log::getInstance().writeLog("scoped deleted", "Kitchen");
  delete this->m_mutex;
  Log::getInstance().writeLog("Mutex deleted", "Kitchen");
  this->m_cond->broadcast();
  delete this->m_cond;
  Log::getInstance().writeLog("Cond deleted", "Kitchen");
}

bool	Kitchen::addPizza(IPizza *pizza) {
  int	i;
  bool	work;
  int	time;

  //  this->m_scoped = new PScopedLock(this->m_mutex);
  if (this->m_pizzas.size() > (unsigned int)(this->m_nbCooks * 2)) {
    //    delete this->m_scoped;
    this->m_scoped = 0;
    return false;
  }
  this->m_pizzas.push_back(new Pizza(pizza->getName(), pizza->getTime(), pizza->getIngredient()));
  this->m_pizzas.push_back(new Pizza(pizza->getName(), pizza->getTime(), pizza->getIngredient()));
  this->m_pizzas.push_back(new Pizza(pizza->getName(), pizza->getTime(), pizza->getIngredient()));
  this->m_pizzas.push_back(new Pizza(pizza->getName(), pizza->getTime(), pizza->getIngredient()));
  this->m_pizzas.push_back(new Pizza(pizza->getName(), pizza->getTime(), pizza->getIngredient()));
  this->m_pizzas.push_back(new Pizza(pizza->getName(), pizza->getTime(), pizza->getIngredient()));
  //  delete this->m_scoped;
  this->m_scoped = 0;
  this->m_cond->signal();
  time = 0;
  while (time < 5) {
    work = false;
    i = 0;
    while (i < this->m_nbCooks) {
      if (this->m_cooks[i]->getState() == COOKING) {
	work = true;
	time = 0;
      }
    }
    if (!work) {
      ++time;
    }
    sleep(1);
  }
  return true;
}

void	Kitchen::displayIngredient() {
  int	i;

  i = 0;
  while (i < 5) {
    std::cout << this->m_stock->getIngredients()[0]->getName() << ": " << this->m_stock->getIngredients()[0]->getQuantity() << std::endl;
    sleep(1);
    ++i;
  }
}
