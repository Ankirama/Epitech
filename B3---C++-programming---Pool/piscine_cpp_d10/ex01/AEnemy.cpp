//
//  AEnemy.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const & type) : _hp(hp), _type(type) {}

AEnemy::~AEnemy() {}

void AEnemy::takeDamage(int damage) {
    if (damage > 0) {
        this->_hp -= damage;
    }
}

std::string AEnemy::getType() const {
    return this->_type;
}

int AEnemy::getHP() const {
    return this->_hp;
}