//
//  Victim.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Victim.hh"

Victim::Victim(std::string const name) : _name(name) {
    std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::~Victim() {
    std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

std::string Victim::getName() const {
    return this->_name;
}

void Victim::getPolymorphed() const {
    std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Victim const& victim) {
    os << "I'm " << victim.getName() << " and i like otters !" << std::endl;
    
    return os;
}