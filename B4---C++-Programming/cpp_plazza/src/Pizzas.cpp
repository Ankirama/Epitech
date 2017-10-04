//
// Pizzas.cpp for Pizzas in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sun Apr 26 21:24:37 2015 Alexandre Chenevier
// Last update Sun Apr 26 21:24:38 2015 Alexandre Chenevier
//

#include "Pizzas.hh"

Pizzas	Pizzas::m_instance = Pizzas();

Pizzas::Pizzas() {}

Pizzas::~Pizzas() {
  IPizza	*tmp;
  while (!this->m_pizzas.empty()) {
    tmp = this->m_pizzas.back();
    this->m_pizzas.pop_back();
    delete tmp;
  }
}

Pizzas&	Pizzas::getInstance() {
  return m_instance;
}

std::vector<IPizza *>	Pizzas::getAllPizza() const{
  return (this->m_pizzas);
}

IPizza	*Pizzas::getPizza(std::string const &name) {
  std::vector<IPizza *>::iterator	it = this->m_pizzas.begin();
  std::string				tmp;

  tmp = name;
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
  while (it != this->m_pizzas.end() && tmp.compare((*it)->getName()) != 0)
    ++it;
  if (it != this->m_pizzas.end())
    return (*it);
  else {
    Log::getInstance().writeError("Unable to find the pizza", tmp);
    return 0;
  }
}

void	Pizzas::addPizza(std::string const &name, const int time,
			 const std::vector<IIngredient *> ingredients) {
  std::vector<IPizza *>::iterator	it = this->m_pizzas.begin();
  std::string				tmp;

  tmp = name;
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
  while (it != this->m_pizzas.end() && tmp.compare((*it)->getName()) != 0)
    ++it;
  if (it != this->m_pizzas.end())
    Log::getInstance().writeError("This pizza is already added", name);
  else {
    this->m_pizzas.push_back(new Pizza(tmp, time, ingredients));
  }
}
