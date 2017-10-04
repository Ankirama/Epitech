//
//  Peon.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Peon.hh"

Peon::Peon(std::string const name) : Victim(name){
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
    std::cout << "Bleuark..." << std::endl;
}

void    Peon::getPolymorphed() const {
    std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}