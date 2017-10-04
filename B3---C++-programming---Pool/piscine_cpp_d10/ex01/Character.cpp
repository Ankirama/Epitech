//
//  Character.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Character.hh"

Character::Character(std::string const &name) : _name(name), _ap(40), _weapon(NULL) {}

Character::Character(Character const& character) : _name(character.getName()), _ap(character.getAp()), _weapon(character.getWeapon()) {}

Character& Character::operator=(Character const& character) {
    if (this != &character) {
        this->_name = character.getName();
        this->_ap = character.getAp();
        this->_weapon = character.getWeapon();
    }
    return *this;
}

Character::~Character() {}

void Character::recoverAP() {
    this->_ap = this->_ap + 10 >= 40 ? 40 : this->_ap + 10;
}

void Character::equip(AWeapon* weapon) {
    this->_weapon = weapon;
}

void Character::attack(AEnemy* enemy) {
    if (this->_weapon && this->_ap >= this->_weapon->getAPCost()) {
        std::cout << this->_name << " attacks "<< enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
        this->_weapon->attack();
        enemy->takeDamage(this->_weapon->getDamage());
        this->_ap -= this->_weapon->getAPCost();
        if (enemy->getHP() <= 0) {
            delete enemy;
            enemy = NULL;
        }
    }
}

std::string Character::getName() const {
    return this->_name;
}

int         Character::getAp() const {
    return this->_ap;
}

AWeapon *Character::getWeapon() const {
    return (this->_weapon ? this->_weapon : NULL);
}

std::ostream& operator<<(std::ostream &os, Character const& hero) {
    if (hero.getWeapon())
        os << hero.getName() << " has " << hero.getAp() << " AP and wields a " << hero.getWeapon()->getName() << std::endl;
    else
        os << hero.getName() << " has " << hero.getAp() << " AP and is unarmed" << std::endl;
    return os;
}