//
//  AssaultTerminator.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "AssaultTerminator.hh"

AssaultTerminator::AssaultTerminator() {
    std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator() {
    std::cout << "I'll be back ..." << std::endl;
}

ISpaceMarine* AssaultTerminator::clone() const {
    return (ISpaceMarine *)(new AssaultTerminator());
}

void AssaultTerminator::battleCry() const {
    std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void AssaultTerminator::rangedAttack() const {
    std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const  {
    std::cout << "* attacks with chainfists *" << std::endl;
}