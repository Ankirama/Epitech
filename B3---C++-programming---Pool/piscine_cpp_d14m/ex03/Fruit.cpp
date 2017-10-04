//
//  Fruit.cpp
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "Fruit.h"

Fruit::Fruit(int vitamins, std::string const& name) : _vitamins(vitamins), m_name(name) {}

Fruit::~Fruit() {}