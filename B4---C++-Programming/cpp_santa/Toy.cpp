//
// Toy.cpp for  in /home/viterb_c/rendu/cpp_santa
// 
// Made by CHARLES VITERBO
// Login   <viterb_c@epitech.net>
// 
// Started on  Sat Jan 17 00:22:45 2015 CHARLES VITERBO
// Last update Sat Jan 17 16:11:41 2015 Alexandre Chenevier
//


#include "Toy.hh"
#include <iostream>

// Constructors
Toy::Toy() : Object(0, UNKNOWN), m_color(""), m_brand(""), m_title("Unknown")	{
}

Toy::Toy(int weight, t_type type, std::string const color,
	 std::string const brand, std::string title) : Object(weight, type), m_color(color), m_brand(brand), m_title(title)	{
}

Toy::Toy(Toy const &copy) : Object(copy), m_color(copy.m_color), m_brand(copy.m_brand), m_title(copy.m_title)	{
}

Toy&	Toy::operator=(Toy const &copy)	{
  if (this != &copy) {
    this->m_weight = copy.m_weight;
    this->m_isTaken = copy.m_isTaken;
    this->m_type = copy.m_type;
    this->m_color = copy.m_color;
    this->m_brand = copy.m_brand;
    this->m_title = copy.m_title;
  }
  return (*this);
}


// Destructor
Toy::~Toy()	{
}


// Getter
std::string	Toy::getColor() const	{
  return (this->m_color);
}

std::string	Toy::getBrand() const	{
  return (this->m_brand);
}

std::string	const Toy::getTitle() const	{
  return (this->m_title);
}
