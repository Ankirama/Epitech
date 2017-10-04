#include <iostream>
#include <string>
#include <stdlib.h>
#include "Federation.hh"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo) : _captain(NULL), _home(EARTH), _shield(100) {
  this->_length = length;
  this->_width = width;
  this->_name = name;
  this->_maxWarp = maxWarp;
  this->_core = NULL;
  this->_photonTorpedo = torpedo;
  std::cout << "The ship USS " << name << " has been finished. It is " << length << " m in length and " << width << " m in width. It can go to Warp " << maxWarp << "! Weapons are set: " << torpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship() {
  this->_length = 289;
  this->_width = 132;
  this->_name = "Entreprise";
  this->_maxWarp = 6;
  this->_core = NULL;
  this->_captain = NULL;
  this->_home = EARTH;
  this->_shield = 100;
  this->_photonTorpedo = 20;
  std::cout << "The ship USS Entreprise has been finished. It is 289 m in length and 132 m in width. It can go to Warp 6! Weapons are set: 20 torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::~Ship() {}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
  std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore() {
  std::cout << "USS " << this->_name << ": The core is " << (this->_core->checkReactor()->isStable() == true ? "stable" : "unstable") << " at the time." << std::endl;
}

int Federation::Starfleet::Ship::getShield() {
  return (this->_shield);
}

void Federation::Starfleet::Ship::setShield(int shield) {
  this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo() {
  return (this->_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo) {
  this->_photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *foe) {
  if (this->_photonTorpedo == 0)
    std::cout << this->_name << "No more torpedo to fire, " << this->_captain->_name << "!" << std::endl;
  else
    {
      foe->setShield(foe->getShield() - 50);
      --this->_photonTorpedo;
      std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
    }
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *foe) {
  if (this->_photonTorpedo == 0)
    std::cout << this->_name << "No more torpedo to fire, " << this->_captain->_name << "!" << std::endl;
  else if (this->_photonTorpedo >= torpedoes)
    {
      foe->setShield(foe->getShield() - (50 * torpedoes));
      this->_photonTorpedo -= torpedoes;
      std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
    }
  else
    std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->_name << "!" << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain) {
  this->_captain = captain;
  std::cout << captain->_name << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

bool Federation::Starfleet::Ship::Ship::move(int warp, Destination d) {
  if (warp <= (int)this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
    this->_location = d;
    return (true);
  }
  return (false);
}

bool Federation::Starfleet::Ship::Ship::move(int warp) {
  if (warp <= (int)this->_maxWarp && this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}

bool Federation::Starfleet::Ship::Ship::move(Destination d) {
  if (this->_location != d && this->_core->checkReactor()->isStable())
    {
      this->_location = d;
      return (true);
    }
  else
    return (false);
}

bool Federation::Starfleet::Ship::Ship::move() {
  if (this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}

Federation::Starfleet::Captain::Captain(std::string name) : _age(42) {
  this->_name = name;
}

Federation::Starfleet::Captain::~Captain() {}

void Federation::Starfleet::Captain::setAge(int age) {
  this->_age = age;
}

int Federation::Starfleet::Captain::getAge() {
  return (this->_age);
}

Federation::Starfleet::Ensign::Ensign(std::string name) {
  this->_name = name;
  std::cout << "Ensign " << name << ", awaiting orders." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name) : _home(VULCAN){
  this->_length = length;
  this->_width = width;
  this->_name = name;

  std::cout << "The independant ship " << name << " just finished its construction. It is " << length << " m in length and " << width << " m in width." << std::endl;
}

Federation::Ship::~Ship() {}

void Federation::Ship::setupCore(WarpSystem::Core *core) {
  this->_core = core;
  std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore() {
  std::cout << this->_name << ": The core is " << (this->_core->checkReactor()->isStable() == true ? "stable" : "unstable") << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d) {
  if (warp <= (int)this->_maxWarp && d != this->_location && this->_core->checkReactor()->isStable()) {
    this->_location = d;
    return (true);
  }
  return (false);
}

bool Federation::Ship::move(int warp) {
  if (warp <= (int)this->_maxWarp && this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}

WarpSystem::Core *Federation::Ship::getCore() {
  return (this->_core);
}

bool Federation::Ship::move(Destination d) {
  if (this->_location != d && this->_core->checkReactor()->isStable())
    {
      this->_location = d;
      return (true);
    }
  else
    return (false);
}

bool Federation::Ship::move() {
  if (this->_core->checkReactor()->isStable())
    {
      this->_location = this->_home;
      return (true);
    }
  return (false);
}
