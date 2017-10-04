//
//  Buzz.cpp
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Buzz.h"

Buzz::Buzz(std::string const& name) : Toy(BUZZ, name, "./buzz.txt") {}
Buzz::Buzz(std::string const& name, std::string const& file) : Toy(BUZZ, name, file) {}
Buzz::Buzz(Buzz const& copy) : Toy(copy.m_type, copy.m_name, "") {this->m_pic = copy.m_pic;}
Buzz& Buzz::operator=(Buzz const& copy) {
    if (this != &copy) {
        this->m_pic = copy.m_pic;
        this->m_type = copy.m_type;
        this->m_name = copy.m_name;
    }
    return *this;
}
Buzz::~Buzz() {}

void    Buzz::speak(std::string const& sentence) {
    std::cout << "BUZZ: " << this->m_name << " \"" << sentence << "\"" << std::endl;
}