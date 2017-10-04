//
// Cook.cpp for Cook in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sun Apr 26 21:25:16 2015 Alexandre Chenevier
// Last update Sun Apr 26 21:25:18 2015 Alexandre Chenevier
//

#include "Cook.hh"

Cook::Cook(float cookingTime, ICondVar *cond,
	   IMutex *mutex, Stock &stock,
	   std::vector<IPizza *> &pizzas):
  m_cookingTime(cookingTime), m_state(WAITING),
  m_cond(cond), m_mutex(mutex), m_stock(stock), m_pizzas(pizzas) {
  Log::getInstance().writeLog("Mario is ready to cook!", "Kitchen");
  this->m_thread = new PThread(*this);
  this->m_scoped = 0;
  this->m_pizza = 0;
}

Cook::~Cook() {
  Log::getInstance().writeLog("Mario is leaving!", "Kitchen");
  this->m_state = LEAVING;
  this->m_cond->broadcast();
  if (this->m_scoped != 0) {
    delete this->m_scoped;
    this->m_scoped = 0;
  }
  delete this->m_thread;
}

cookState	Cook::getState() {
  return this->m_state;
}

void		*Cook::start_routine() {
  this->m_cond->wait();
  //  this->m_scoped = new PScopedLock(this->m_mutex);
  if (!this->m_pizzas.empty()) {
    this->m_state = COOKING;
    this->m_pizza = this->m_pizzas.front();
    this->m_pizzas.erase(this->m_pizzas.begin());
    Log::getInstance().writeLog("Mario is cooking a "
				+ this->m_pizza->getName(), "Kitchen");
    sleep(this->m_cookingTime * this->m_pizza->getTime());
    Log::getInstance().writeLog("Mario no is delivring a "
				+ this->m_pizza->getName(), "Kitchen");
    this->m_state = DELIVERING;
    delete this->m_pizza;
    this->m_pizza = 0;
  }
  //  delete this->m_scoped;
  this->m_scoped = 0;
  return 0;
}
