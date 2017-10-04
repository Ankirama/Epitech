#include <iostream>
#include "Borg.hh"

Borg::Ship::Ship(int weaponFrequency) : _side(300), _maxWarp(9), _home(UNICOMPLEX), _shield(100), _repair(3) {
  this->_weaponFrequency = weaponFrequency;
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::Ship(int weaponFrequency, short repair) : _side(300), _maxWarp(9), _home(UNICOMPLEX), _shield(100) {
  this->_weaponFrequency = weaponFrequency;
  this->_repair = repair;
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

bool Borg::Ship::move(int warp, Destination d) {
  if (warp <= (int)this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
    this->_location = d;
    return (true);
  }
  return (false);
}

bool Borg::Ship::move(int warp) {
  if (warp <= (int)this->_maxWarp && this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}

bool Borg::Ship::move(Destination d) {
  if (this->_location != d && this->_core->checkReactor()->isStable())
    {
      this->_location = d;
      return (true);
    }
  else
    return (false);
}

bool Borg::Ship::move() {
  if (this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}

int Borg::Ship::getShield() {
  return (this->_shield);
}

void Borg::Ship::setShield(int shield) {
  this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency() {
  return (this->_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int weaponFrequency) {
  this->_weaponFrequency = weaponFrequency;
}

short Borg::Ship::getRepair() {
  return (this->_repair);
}

void Borg::Ship::setRepair(short repair) {
  this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *foe) {
  foe->setShield(foe->getShield() - this->_weaponFrequency);
  std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *foe) {
  foe->getCore()->checkReactor()->setStability(false);
  std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair() {
  if (this->_repair == 0)
    std::cout << "Energy cells depleted, shield weakening." << std::endl;
  else
    {
      --this->_repair;
      this->_shield = 100;
      std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions."<< std::endl;
    }
}
