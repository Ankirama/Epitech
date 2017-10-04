//
// Teddy.cpp for  in /home/viterb_c/rendu/cpp_santa
// 
// Made by CHARLES VITERBO
// Login   <viterb_c@epitech.net>
// 
// Started on  Sat Jan 17 01:19:33 2015 CHARLES VITERBO
// Last update Sat Jan 17 11:00:12 2015 CHARLES VITERBO
//

#include "Teddy.hh"
#include "Toy.hh"
#include "Object.hh"

#include <iostream>

// Constructor
Teddy::Teddy() : Toy(), m_ted(false)	{
}

Teddy::Teddy(int weight, t_type type, std::string const color, std::string brand, std::string title, bool ted) : Toy(weight, type, color, brand, title), m_ted(ted) {
  if (m_ted == true)
    std::cout << "Hello I'm Ted, your new best friend !" << std::endl;
  else
    std::cout << "New teddy made !" << std::endl;
}

Teddy::Teddy(Teddy const & copy) : Toy(copy), m_ted(copy.m_ted)	{
  if (m_ted == true)
    std::cout << "Hello I'm Ted, your new best friend !" << std::endl;
  else
    std::cout << "New teddy made !" << std::endl;
}

Teddy&	Teddy::operator=(Teddy const &copy)	{
  if (this != &copy)	{
    this->m_weight = copy.m_weight;
    this->m_isTaken = copy.m_isTaken;
    this->m_type = copy.m_type;
    this->m_color = copy.m_color;
    this->m_brand = copy.m_brand;
    this->m_title = copy.m_title;
    this->m_ted = copy.m_ted;
    if (m_ted == true)
      std::cout << "Hello I'm Ted, your new best friend !" << std::endl;
    else
      std::cout << "New teddy made !" << std::endl;
  }
  return (*this);
}


// Destructor
Teddy::~Teddy()	{
  if (this->m_ted == true)
    std::cout << "Goodbye :'(" << std::endl;
  else
    std::cout << "Destroy the teddy " << this->m_title << " it's look like a chinese toy !" << std::endl;
}


// Getter
bool	Teddy::getTed() const	{
  return (this->m_ted);
}

std::string const Teddy::getTitle() const {return this->m_title;}

void	Teddy::isTaken()	{
  if (this->m_isTaken == true)
    std::cerr << "Erreur 404 : regarde tes mains !" << std::endl;
  else	{
    this->m_isTaken = true;
    std::cout << "gra hu" << std::endl;
  }
}

bool Teddy::operator!=(Teddy const& test) const {
    return (this->m_color != test.getColor() || this->m_type != test.getType() || this->m_weight != test.getWeight() || this->m_title != test.getTitle() || this->m_ted != test.getTed());
}

std::ostream&	operator<<(std::ostream& os, Teddy const &teddy)	{
  if (teddy.getTed() == true)
    os << "* Fuck you, thunder ! You can suck my dick ! You can't get me thunder'cause you're just god's farts *";
  else
    os << "Teddy with characteristic : weight " << teddy.getWeight() << "g, color " << teddy.getColor() << ", brand " << teddy.getBrand() << ", title " << teddy.getTitle() << ".";
  return (os);
}
