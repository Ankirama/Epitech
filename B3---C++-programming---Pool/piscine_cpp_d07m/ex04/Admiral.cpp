//
// Admiral.cpp for adksodq in /home/user/rendu/piscine_cpp_d07m/ex04
//
// Made by 
// Login   
//
// Started on  Tue Jan 13 16:24:28 2015 
// Last update Wed Jan 14 08:48:29 2015 
//

#include <iostream>
#include "Admiral.hh"

Federation::Starfleet::Admiral::Admiral(std::string name) {
  this->_name = name;
  this->firePtr = &Federation::Starfleet::Ship::fire;
  this->movePtr = &Federation::Starfleet::Ship::move;
  std::cout << "Admiral " << name << " ready for action." << std::endl;
}

Federation::Starfleet::Admiral::~Admiral() {}

void	Federation::Starfleet::Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *borg) {
  std::cout << "On order from Admiral " << this->_name << ":" << std::endl;
  (ship->*(this->firePtr))(borg);
}

bool	Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *foe, Destination d) {
  return ((foe->*(this->movePtr))(d));
}
