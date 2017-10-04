//
//  Coconut.cpp
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "Coconut.h"

Coconut::Coconut() : Fruit(15, "coconut") {}

Coconut::~Coconut() {}

std::string Coconut::getName() const {return this->m_name; }
int Coconut::getVitamins() const {return this->_vitamins; }