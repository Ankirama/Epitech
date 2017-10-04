//
// Ingredient.cpp for Ingredient in /home/chenev_d/rendu/cpp_plazza/src
// 
// Made by Alexandre Chenevier
// Login   <chenev_d@epitech.net>
// 
// Started on  Sun Apr 26 21:24:56 2015 Alexandre Chenevier
// Last update Sun Apr 26 21:24:57 2015 Alexandre Chenevier
//

#include "Ingredient.hh"

Ingredient::Ingredient(std::string const &name, int quantity) : m_defaultQuantity(quantity) {
  this->m_name = name;
  this->m_quantity = quantity;
}

Ingredient::~Ingredient() {}

int		Ingredient::getQuantity() const {return this->m_quantity;}

std::string	const &Ingredient::getName() const {return this->m_name;}

bool		Ingredient::setQuantity(int quantity) {
  std::stringstream	ss;
  if (quantity < 0) {
    ss << quantity;
    Log::getInstance().writeError("is not a valid quantity for " + this->m_name, ss.str());
    ss.clear();
    return false;
  }
  else {
    this->m_quantity = quantity;
    return true;
  }
}

bool		Ingredient::removeQuantity(int quantity) {
  std::stringstream	tmp;
  if (quantity < 0 || this->m_quantity - quantity < 0) {
    tmp << quantity;
    Log::getInstance().writeError("is not a valid quantity for " + this->m_name, tmp.str());
    tmp.clear();
    return false;
  }
  else {
    this->m_quantity -= quantity;
    return true;
  }
}

void		Ingredient::resetIngredient() {
  this->m_quantity = this->m_defaultQuantity;
}
