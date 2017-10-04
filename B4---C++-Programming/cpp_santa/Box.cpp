//
//  Box.cpp
//  cpp_santa
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include "Box.hh"

Box::Box() : Wrap(BOX){
    std::cout << "* POUF * A wild box appears!" << std::endl;
}
Box::Box(Box const& copy) : Wrap(copy.getType()) {
    std::cout << "* POUF * A wild box appears!" << std::endl;
}
Box& Box::operator=(Box const& copy) {
    if (this != &copy)
    {
        this->m_isOpen = copy.isOpen();
        this->m_isEmpty = copy.isEmpty();
        this->m_type = copy.getType();
        this->m_weight = copy.getWeight();
        this->m_isWraped = copy.isWraped();
        this->m_object = copy.getObject();
        std::cout << "your freebox clone is ready" << std::endl;
    }
    return *this;
}

/*destructor */
Box::~Box() {}

std::string const Box::getTitle() const {return "Box";}

void    Box::wrapMeThat(Object *toy) {
    if (this->m_isOpen && this->m_object == NULL && toy != NULL && (toy->getType() == LITTLE_PONY || toy->getType() == TEDDY)) {
        std::cout << "tuuuut tuuut tuut" << std::endl;
        toy->isTaken();
        this->m_object = toy;
        this->m_isWraped = true;
    }
    else if (!this->m_isOpen || this->m_object)
        std::cerr << "Il est impossible de mettre un jouet dans la boite!" << std::endl;
    else
        std::cerr << "Mais voyons Gaston, ce n'est pas un jouet !" << std::endl;
}

void    Box::openMe() {
    if (this->m_isOpen) {
        std::cerr << "La boite est deja ouverte, ce n'est pas tres malin !" << std::endl;
    }
    else
        this->m_isOpen = true;
}

void    Box::closeMe() {
    if (!this->m_isOpen)
        std::cerr << "La boite est deja fermee, ce n'est pas tres malin !" << std::endl;
    else
        this->m_isOpen = false;
}