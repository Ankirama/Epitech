//
//  TacticalMarine.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "TacticalMarine.hh"

TacticalMarine::TacticalMarine() {
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine() {
    std::cout << "Aaargh ..." << std::endl;
}

ISpaceMarine* TacticalMarine::clone() const {
    return (ISpaceMarine *)(new TacticalMarine());
}

void TacticalMarine::battleCry() const {
    std::cout << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack() const {
    std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const  {
    std::cout << "* attacks with chainsword *" << std::endl;
}