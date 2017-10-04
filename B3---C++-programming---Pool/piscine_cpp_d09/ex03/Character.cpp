//
//  Character.cpp
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Character.hh"

Character::Character(std::string const &name, int level) : _name(name), _level(level), _power(100), _pv(100), _strength(5), _stamina(5), _intelligence(5), _spirit(5), _agility(5), Range(CLOSE) {
    std::cout << name << " Created" << std::endl;
}

Character::~Character() {}

const std::string   &Character::getName() const {
    return this->_name;
}

int                 Character::getLvl() const {
    return this->_level;
}
int                 Character::getPv() const {
    return this->_pv;
}
int                 Character::getPower() const {
    return this->_power;
}

int                 Character::CloseAttack() {
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " strikes with a wood stick" << std::endl;
        return 10 + this->_strength;
    }
    else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
}

int                 Character::RangeAttack() {
    if (this->_power >= 10) {
        this->_power -= 10;
        std::cout << this->_name << " launches a stone" << std::endl;
        return 5 + this->_strength;
    }
    else {
        std::cout << this->_name << " out of power" << std::endl;
        return 0;
    }
}

void                Character::Heal() {
    this->_pv = this->_pv + 50 >= 100 ? 100 : this->_pv + 50;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void                Character::RestorePower() {
    this->_power = 100;
    std::cout << this->_name << " eats" << std::endl;
}

void                Character::TakeDamage(int _damage) {
    this->_pv -= _damage;
    if (this->_pv <= 0)
        std::cout << this->_name << " out of combat" << std::endl;
    else
        std::cout << this->_name << " takes "<< _damage << " damage" << std::endl;
}
