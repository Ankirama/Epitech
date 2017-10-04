//
//  PowerFist.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "PowerFist.hh"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {}

PowerFist::~PowerFist() {}

void PowerFist::attack() const {
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
