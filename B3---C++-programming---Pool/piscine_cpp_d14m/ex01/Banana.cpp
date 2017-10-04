//
//  Banana.cpp
//  piscine_cpp_d14m
//
//  Created by  on 20/01/15.
//  Copyright (c) 2015 . All rights reserved.
//

#include "Banana.h"

Banana::Banana() : Fruit(5, "banana") {}

Banana::~Banana() {}

std::string Banana::getName() const {return this->m_name; }
int Banana::getVitamins() const {return this->_vitamins; }