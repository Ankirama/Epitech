//
//  Wrap.cpp
//  cpp_santa
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include "Wrap.hh"

/* constructors */
Wrap::Wrap() : Object(wrapWeight, UNKNOWN), m_isOpen(false), m_isEmpty(false), m_isWraped(false), m_object(NULL) {}
Wrap::Wrap(t_type type) : Object(wrapWeight, type), m_isOpen(false), m_isEmpty(false), m_isWraped(false), m_object(NULL) {}
Wrap::Wrap(Wrap const& copy) : Object(copy), m_isOpen(copy.isOpen()), m_isEmpty(copy.isEmpty()), m_isWraped(copy.isWraped()), m_object(copy.getObject()){}
Wrap& Wrap::operator=(Wrap const& copy) {
    if (this != &copy)
    {
        this->m_isOpen = copy.isOpen();
        this->m_isEmpty = copy.isEmpty();
        this->m_type = copy.getType();
        this->m_weight = copy.getWeight();
        this->m_isWraped = copy.isWraped();
        this->m_object = copy.getObject();
    }
    return *this;
}

/* destructor */
Wrap::~Wrap() {}

/* getter setter */
bool        Wrap::isEmpty() const { return this->m_isEmpty; }
bool        Wrap::isWraped() const {return this->m_isWraped; }
bool        Wrap::isOpen() const { return this->m_isOpen; }
std::string const Wrap::getTitle() const {return "Unknown";}

void Wrap::isTaken() {
    if (!this->m_isTaken) {
        std::cout << "whistles while working" << std::endl;
        this->m_isWraped = true;
    }
    else
        std::cerr << "Mais voyons gaston, tu m'as deja dans les mains !" << std::endl;
}

Object      *Wrap::getObject() const {return this->m_object ;}

bool Wrap::operator!=(Wrap const& test) const {
    return (this->m_isOpen != test.isOpen() || this->m_isEmpty != test.isEmpty() || this->getTitle() != test.getTitle() || this->m_type != test.getType() || this->m_weight != test.getWeight() || this->m_isWraped != test.isWraped() || this->m_object != test.getObject());
}