//
// LittlePony.cpp for  in /home/viterb_c/rendu/cpp_santa
// 
// Made by CHARLES VITERBO
// Login   <viterb_c@epitech.net>
// 
// Started on  Sat Jan 17 11:05:28 2015 CHARLES VITERBO
// Last update Sat Jan 17 15:58:48 2015 Alexandre Chenevier
//

#include "LittlePony.hh"
#include "Toy.hh"
#include "Object.hh"

#include <iostream>

// Constructor
LittlePony::LittlePony() : Toy(), m_shitrainbow(false)	{
}

LittlePony::LittlePony(int weight, t_type type, std::string const color, std::string brand, std::string title, bool rainbow) : Toy(weight, type, color, brand, title), m_shitrainbow(rainbow) {
  if (m_shitrainbow == true)
    std::cout << "Rainbow Dash ! Youpi !" << std::endl;
  else
    std::cout << "New LittlePony made !" << std::endl;
}

LittlePony::LittlePony(LittlePony const & copy) : Toy(copy), m_shitrainbow(copy.m_shitrainbow)	{
  if (m_shitrainbow == true)
    std::cout << "Rainbow Dash ! Youpi !" << std::endl;
  else
    std::cout << "New LittlePony made !" << std::endl;
}

LittlePony&	LittlePony::operator=(LittlePony const &copy)	{
  if (this != &copy)	{
    this->m_weight = copy.m_weight;
    this->m_isTaken = copy.m_isTaken;
    this->m_type = copy.m_type;
    this->m_color = copy.m_color;
    this->m_brand = copy.m_brand;
    this->m_title = copy.m_title;
    this->m_shitrainbow = copy.m_shitrainbow;
    if (m_shitrainbow == true)
      std::cout << "Rainbow Dash ! Youpi !" << std::endl;
    else
      std::cout << "New LittlePony made !" << std::endl;
  }
  return (*this);
}


// Destructor
LittlePony::~LittlePony()	{
  if (this->m_shitrainbow == true)
    std::cout << "En direction de l'arc en ciel !" << std::endl;
  else
    std::cout << "It's not a pony, it's an unicorn !" << std::endl;
}


// Getter
bool	LittlePony::getShitRainbow() const	{
  return (this->m_shitrainbow);
}

void	LittlePony::isTaken()	{
  if (this->m_isTaken == true)
    std::cerr << "Erreur 404 : regarde tes mains !" << std::endl;
  else	{
    this->m_isTaken = true;
    std::cout << "yo man" << std::endl;
  }
}

std::string const	LittlePony::getTitle() const	{
  return (this->m_title);
}

bool LittlePony::operator!=(LittlePony const& test) const {
  return (this->m_color != test.getColor() || this->m_type != test.getType() || this->m_weight != test.getWeight() || this->m_title != test.getTitle() || this->m_shitrainbow != test.getShitRainbow());
}

std::ostream&	operator<<(std::ostream& os, LittlePony const &pony)	{
  if (pony.getShitRainbow() == true)
    os << "Mon petit poney chie des arcs en ciel !";
  else
    os << "LittlePony with characteristic : weight " << pony.getWeight() << "g, color " << pony.getColor() << ", brand " << pony.getBrand() << ", title " << pony.getTitle() << ".";
  return (os);
}
