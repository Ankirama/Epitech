//
//  Warrior.cpp
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Warrior.hh"

Warrior::Warrior(std::string name, int level) : Character(name, level), weaponName("hammer") {
    this->_stamina = 12;
    this->_strength = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agility = 7;
    std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior() {}

int Warrior::CloseAttack() {
    if (this->_power >= 30) {
        this->_power -= 30;
        std::cout << this->_name << " strikes with his " << this->weaponName << std::endl;
        return 20 + this->_strength;
    }
    else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
}

int Warrior::RangeAttack() {
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " intercepts" << std::endl;
        this->Range = Character::CLOSE;
        return 0;
    }
    else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
}