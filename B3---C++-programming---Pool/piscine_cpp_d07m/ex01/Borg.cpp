#include <iostream>
#include "Borg.hh"

Borg::Ship::Ship() : _side(300), _maxWarp(9) {
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship() {}

void Borg::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
}

void Borg::Ship::checkCore() {
  std::cout << (this->_core->checkReactor()->isStable() == true ? "Everything is in order." : "Critical failure imminent.") << std::endl;
}
