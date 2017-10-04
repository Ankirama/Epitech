//
//  Mixer.cpp
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "Mixer.h"

static int _testMeThat(FruitBox& box) {
    Fruit const *fruit;
    int vitamins;
    
    vitamins = 0;
    while ((fruit = box.pickFruit()) != 0)
        vitamins += fruit->getVitamins();
    return vitamins;
}

Mixer::Mixer() {
    this->_plugged = true;
    this->_mixfunc = &_testMeThat;
}