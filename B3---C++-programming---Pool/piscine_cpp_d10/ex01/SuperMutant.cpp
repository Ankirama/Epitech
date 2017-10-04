//
//  SuperMutant.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "SuperMutant.hh"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant") {
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant() {
    std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int damage) {
    AEnemy::takeDamage(damage - 3);
}