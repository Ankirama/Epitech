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

Toy::Toy(Toy const& copy) : m_type(copy.m_type), m_name(copy.m_name), m_pic(copy.m_pic) {}
Toy& Toy::operator=(Toy const& copy) {
    if (this != &copy) {
        this->m_type = copy.m_type;
        this->m_name = copy.m_name;
        this->m_pic = copy.m_pic;
    }
    
    return *this;
}

Toy::~Toy() {}

Toy::ToyType Toy::getType() {return this->m_type;}

std::string const& Toy::getName() const {return this->m_name;}
std::string const& Toy::getAscii() const {return this->m_pic.data;}

void    Toy::setName(std::string const& name) {
    this->m_name = name;
}

bool    Toy::setAscii(std::string const& file) {
    return this->m_pic.getPictureFromFile(file);
}

void    Toy::speak(std::string const& sentence) {
    std::cout << this->m_name << " \"" << sentence << "\"" << std::endl;
}