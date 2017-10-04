#include <iostream>
#include <string>
#include <stdlib.h>
#include "Federation.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp) {
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  this->_core = NULL;
  std::cout << "The ship USS " << name << " has been finished. It is " << length << " m in length and " << width << " m in width." << std::endl << "It can go to Warp " << maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship() {
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
  std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore() {
  std::cout << "USS " << this->_name << ": The core is " << (this->_core->checkReactor()->isStable() == true ? "stable" : "unstable") << " at the time." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name) {
  this->_length = length;
  this->_width = width;
  this->_name = name;

  std::cout << "The independant ship " << name << " just finished its construction. It is " << length << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship() {
}

void Federation::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
  std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore() {
  std::cout << this->_name << ": The core is " << (this->_core->checkReactor()->isStable() == true ? "stable" : "unstable") << " at the time." << std::endl;
}
