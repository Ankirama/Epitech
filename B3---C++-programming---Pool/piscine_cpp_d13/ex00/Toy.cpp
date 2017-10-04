//
//  Toy.cpp
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Toy.h"

Toy::Toy() : m_type(BASIC_TOY), m_name("toy"), m_pic(Picture()){}
Toy::Toy(ToyType type, std::string const& name, std::string const& file) : m_type(type), m_name(name) {
    this->m_pic = Picture(file);
}

Toy::~Toy() {}

Toy::ToyType Toy::getType() const {return this->m_type;}

std::string const& Toy::getName() const {return this->m_name;}
std::string const& Toy::getAscii() const {return this->m_pic.data;}

void    Toy::setName(std::string const& name) {
    this->m_name = name;
}

bool    Toy::setAscii(std::string const& file) {
    return this->m_pic.getPictureFromFile(file);
}