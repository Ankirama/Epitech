//
// Stock.cpp for Stock in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sun Apr 26 21:24:31 2015 Alexandre Chenevier
// Last update Sun Apr 26 21:24:31 2015 Alexandre Chenevier
//

#include <iostream>
#include "Stock.hh"

Stock::Stock(long replaceTime, std::vector<IIngredient *> ingredients, IMutex *mutex) {
  this->m_thread = new PThread(*this);
  for (std::vector<IIngredient *>::iterator it = ingredients.begin(); it != ingredients.end(); ++it) {
    this->m_ingredients.push_back(new Ingredient((*it)->getName(), (*it)->getQuantity()));
  }
  this->m_running = true;
  this->m_mutex = mutex;
  this->m_replaceTime = replaceTime * 1000;
  this->m_scoped = 0;
}

Stock::~Stock() {
  if (this->m_scoped != 0)
    delete this->m_scoped;
  delete this->m_thread;
}

std::vector<IIngredient *>	&Stock::getIngredients() {
  return this->m_ingredients;
}

bool	Stock::removeQuantity(std::string const& ingredient, int quantity) {
  bool	res;
  this->m_mutex->lock();
  std::vector<IIngredient *>::iterator it = this->m_ingredients.begin();
  while (it != this->m_ingredients.end() && (*it)->getName().compare(ingredient) != 0)
    ++it;
  if (it == this->m_ingredients.end()) {
    this->m_mutex->unlock();
    return false;
  }
  else {
    res = (*it)->setQuantity(quantity);
    this->m_mutex->unlock();
    return res;
  }
}

void	Stock::setStatus(bool running) {
  this->m_running = running;
}

void	*Stock::start_routine() {
  while (this->m_running) {
    usleep(this->m_replaceTime);
    this->m_scoped = new PScopedLock(this->m_mutex);
    for (std::vector<IIngredient *>::iterator it = this->m_ingredients.begin();
	 it != this->m_ingredients.end(); ++it)
      (*it)->setQuantity((*it)->getQuantity() + 1);
    delete this->m_scoped;
    this->m_scoped = 0;
  }
  return 0;
}
