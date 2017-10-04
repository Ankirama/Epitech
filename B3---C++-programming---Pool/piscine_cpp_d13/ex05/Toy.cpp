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

Toy::Toy() : m_type(BASIC_TOY), m_name("toy"), m_pic(Picture()), m_error(Error()){}
Toy::Toy(ToyType type, std::string const& name, std::string const& file) : m_type(type), m_name(name), m_error(Error()) {
    this->m_pic = Picture(file);
}

Toy::Toy(Toy const& copy) : m_type(copy.m_type), m_name(copy.m_name), m_pic(copy.m_pic), m_error(copy.m_error) {}
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
Toy::Error&   Toy::getLastError() { return m_error; }

void    Toy::setName(std::string const& name) {
    this->m_name = name;
}

bool    Toy::setAscii(std::string const& file) {
    bool res;
    
    res = this->m_pic.getPictureFromFile(file);
    if (res == false)
        this->m_error.type = Error::PICTURE;
    return res;
}

void    Toy::speak(std::string const& sentence) {
    std::cout << this->m_name << " \"" << sentence << "\"" << std::endl;
}

bool    Toy::speak_es(std::string const& sentence) {
    (void)sentence;
    this->m_error.type = Error::SPEAK;
    return false;
}

Toy& Toy::operator<<(std::string const& picture) {
    this->m_pic.data = picture;
    return *this;
}

std::ostream& operator<<(std::ostream& os, Toy const& toy) {
    os << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return os;
}

std::string Toy::Error::what() const{
    if (this->type == UNKNOWN)
        return "";
    else if (this->type == PICTURE)
        return "bad new illustration";
    else
        return "wrong mode";
}

std::string Toy::Error::where() const{
    if (this->type == UNKNOWN)
        return "";
    else if (this->type == PICTURE)
        return "setAscii";
    else
        return "speak_es";
}

Toy::Error::Error() : type(UNKNOWN){}