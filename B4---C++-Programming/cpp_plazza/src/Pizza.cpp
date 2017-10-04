//
// Pizza.cpp for  in /home/teyssa_r/rendu/cpp_plazza
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Sun Apr 19 04:23:19 2015 Raphael Teyssandier
// Last update Wed Apr 22 16:12:57 2015 Alexandre Chenevier
//

#include "Pizza.hh"
#include "Ingredient.hh"

Pizza::Pizza(const std::string &name, const int time,
	     const std::vector<IIngredient *> list) : m_name(name),
						    m_time(time),
						    m_ingredients(list) {
  this->m_name = name;
  this->m_time = time;
  this->m_ingredients = list;
}

Pizza::~Pizza(){
}

void				Pizza::setName(const std::string &name) {
  this->m_name = name;
}

std::string			Pizza::getName() const {
  return (this->m_name);
}

void				Pizza::setTime(const int time){
  this->m_time = time;
}

int				Pizza::getTime() const {
  return (this->m_time);
}

void				Pizza::setIngredient(const std::vector<IIngredient *> list) {
  this->m_ingredients = list;
}

std::vector<IIngredient *>	Pizza::getIngredient() const {
  return (this->m_ingredients);
}
