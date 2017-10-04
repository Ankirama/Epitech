//
//  Lemon.cpp
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "Lemon.h"

Lemon::Lemon() : Fruit(3, "lemon") {}

Lemon::~Lemon() {}

std::string Lemon::getName() const {return this->m_name; }
int Lemon::getVitamins() const {return this->_vitamins; }