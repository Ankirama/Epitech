//
//  Mage.cpp
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Mage.hh"

Mage::Mage(std::string name, int level) : Character(name, level) {
    this->_stamina = 6;
    this->_strength = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
    std::cout << name << " teleported" << std::endl;
}

Mage::~Mage() {}

int                 Mage::CloseAttack() {
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " blinks" << std::endl;
        this->Range = Mage::RANGE;
        return 0;
    }
    else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
}

int                 Mage::RangeAttack() {
    if (this->_power >= 25) {
        this->_power -= 25;
        std::cout << this->_name << " launches a fire ball" << std::endl;
        return 20 + this->_spirit;
    }
    else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
}

void                Mage::RestorePower() {
    this->_power += 50 + this->_intelligence;
    this->_power = this->_power >= 100 ? 100 : this->_power;
    std::cout << this->_name << " takes a mana potion" << std::endl;
}
