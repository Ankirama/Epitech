//
//  Lime.cpp
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "Lime.h"

Lime::Lime() {this->m_name = "lime"; this->_vitamins = 2;}
Lime::~Lime() {}

std::string Lime::getName() const {return this->m_name;}

int Lime::getVitamins() const {return this->_vitamins;}