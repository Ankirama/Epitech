//
//  RadScorpion.cpp
//  piscine_cpp_d10
//
//  Created by  on 16/01/15.
//  Copyright (c) 2015 . All rights reserved.
//

#include <iostream>
#include "RadScorpion.hh"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion") {
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion() {
    std::cout << "* SPROTCH *" << std::endl;
}
