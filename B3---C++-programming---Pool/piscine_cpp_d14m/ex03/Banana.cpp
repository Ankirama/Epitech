//
//  Banana.cpp
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "Banana.h"

Banana::Banana() : Fruit(5, "banana") {}

Banana::~Banana() {}

std::string Banana::getName() const {return this->m_name; }
int Banana::getVitamins() const {return this->_vitamins; }