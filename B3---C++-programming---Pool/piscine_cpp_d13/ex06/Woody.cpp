//
//  Woody.cpp
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Woody.h"

Woody::Woody(std::string const& name) : Toy(WOODY, name, "./woody.txt") {}
Woody::Woody(std::string const& name, std::string const& file) : Toy(WOODY, name, file) {}
Woody::Woody(Woody const& copy) : Toy(copy.m_type, copy.m_name, "") {this->m_pic = copy.m_pic;}
Woody& Woody::operator=(Woody const& copy) {
    if (this != &copy) {
        this->m_pic = copy.m_pic;
        this->m_type = copy.m_type;
        this->m_name = copy.m_name;
    }
    return *this;
}
Woody::~Woody() {}

bool    Woody::speak(std::string sentence) {
    std::cout << "WOODY: " << this->m_name << " \"" << sentence << "\"" << std::endl;
    return true;
}

bool    Woody::speak_es(std::string sentence) {
    (void)sentence;
    this->m_error.type = Error::SPEAK;
    return false;
}