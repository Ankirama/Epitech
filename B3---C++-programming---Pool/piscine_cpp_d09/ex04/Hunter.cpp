//
//  Hunter.cpp
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Hunter.hh"

Hunter::Hunter(std::string const& name, int level) : Character(name, level), Warrior(name, level){
    this->_stamina = 9;
    this->_strength = 9;
    this->_intelligence = 5;
    this->_spirit = 6;
    this->_agility = 24;
    this->weaponName = "sword";
    std::cout << name << " is born from a tree" << std::endl;
}

Hunter::~Hunter() {}

int                 Hunter::RangeAttack() {
    if (this->_power >= 25) {
        this->_power -= 25;
        std::cout << this->_name << " uses his bow" << std::endl;
        return 20 + this->_agility;
    }
    else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
}

void                Hunter::RestorePower() {
    this->_power = 100;
    
    std::cout << this->_name << " meditates" << std::endl;
}