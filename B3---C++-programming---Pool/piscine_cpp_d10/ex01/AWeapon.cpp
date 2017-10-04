//
//  AWeapon.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "AWeapon.hh"

AWeapon::AWeapon(std::string const& name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage) {}

AWeapon::~AWeapon() {}

std::string const AWeapon::getName() const {
    return this->_name;
}

int AWeapon::getAPCost() const {
    return this->_apcost;
}

int AWeapon::getDamage() const {
    return this->_damage;
}