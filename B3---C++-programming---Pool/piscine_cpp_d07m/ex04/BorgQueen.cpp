//
// BorgQueen.cpp for borg in /home/user/rendu/piscine_cpp_d07m/ex04
//
// Made by 
// Login   
//
// Started on  Tue Jan 13 17:00:13 2015 
// Last update Wed Jan 14 08:48:46 2015 
//

#include "BorgQueen.hh"

Borg::BorgQueen::BorgQueen() {
  this->movePtr = &Borg::Ship::move;
  this->firePtr = &Borg::Ship::fire;
  this->destroyPtr = &Borg::Ship::fire;
}

bool Borg::BorgQueen::move(Borg::Ship* ship, Destination d) {
  return ((ship->*(this->movePtr))(d));
}

Borg::BorgQueen::~BorgQueen() {}

void Borg::BorgQueen::fire(Borg::Ship* ship, Federation::Starfleet::Ship* foe) {
  (ship->*(this->firePtr))(foe);
}

void Borg::BorgQueen::destroy(Borg::Ship* ship, Federation::Ship* foe) {
  (ship->*(this->destroyPtr))(foe);
}
