//
//  Paladin.cpp
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Paladin.hh"

Paladin::Paladin(std::string const &name, int level) : Character(name, level), Warrior(name, level), Priest(name, level) {
    this->_agility = 2;
    this->_stamina = 10;
    this->_strength = 9;
    this->_spirit = 10;
    this->_intelligence = 10;
    std::cout << "the light falls on " << name << std::endl;
}

Paladin::~Paladin() {}

int Paladin::Intercept() {
    return Warrior::RangeAttack();
}