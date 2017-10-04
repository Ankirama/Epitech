//
//  Sorcerer.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Sorcerer.hh"

Sorcerer::Sorcerer(std::string const name, std::string const title) : _name(name), _title(title) {
    std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer() {
    std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string Sorcerer::getName() const{
    return this->_name;
}

std::string Sorcerer::getTitle() const{
    return this->_title;
}

void Sorcerer::polymorph(Victim const& victim) const {
    victim.getPolymorphed();
}

std::ostream& operator <<(std::ostream& os, Sorcerer const &sorcerer) {
    os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
    
    return os;
}