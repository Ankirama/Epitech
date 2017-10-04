//
//  Priest.cpp
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Priest.hh"

Priest::Priest(std::string name, int level) : Mage(name, level) {
    this->_stamina = 4;
    this->_strength = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
    std::cout << name << " enters in the order" << std::endl;
}

Priest::~Priest() {}

int                 Priest::CloseAttack() {
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " uses a spirit explosion" << std::endl;
        return 10 + this->_spirit;
    }
    else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
}

void                Priest::Heal() {
    if (this->_power >= 10) {
        this->_power -= 10;
        this->_pv = this->_pv + 70 >= 100 ? 100 : this->_pv + 70;
        std::cout << this->_name << " casts a little heal spell" << std::endl;
    }
    else
        std::cout << this->_name << " out of power" << std::endl;
}