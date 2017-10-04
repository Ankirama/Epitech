//
//  GiftPaper.cpp
//  cpp_santa
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "GiftPaper.hh"

/* constructors */
GiftPaper::GiftPaper() : Wrap(GIFT_PAPER), m_pattern("pony pattern") {
    std::cout << "Et voila, avec ce joli papier cadeau avec le motif " << m_pattern << std::endl;
}
GiftPaper::GiftPaper(GiftPaper const& copy) : Wrap(copy), m_pattern("pony pattern") {
    std::cout << "Et voila, avec ce joli papier cadeau avec le motif " << m_pattern << std::endl;
    this->m_object = copy.getObject();
}

GiftPaper& GiftPaper::operator=(GiftPaper const& copy) {
    if (this != &copy)
    {
        this->m_pattern = copy.getPattern();
        this->m_isOpen = copy.isOpen();
        this->m_isEmpty = copy.isEmpty();
        this->m_type = copy.getType();
        this->m_weight = copy.getWeight();
        this->m_isWraped = copy.isWraped();
        this->m_object = copy.getObject();
        std::cout << "Bien joue, tu as clone un papier cadeau !" << std::endl;
    }
    
    return *this;
}

/* destructor */
GiftPaper::~GiftPaper() {}

std::string     const GiftPaper::getTitle() const {return "Gift Paper";}

void    GiftPaper::wrapMeThat(Object *object) {
    if (object != NULL && object->getType() == BOX && ((Box *)object)->isWraped())
    {
        std::cout << "C'est parti, qu'on emballe cette boite contenant un " << ((Toy *)(((Box *)object)->getObject()))->getTitle();
        this->m_isWraped = true;
        this->m_object = (Box *)object;
    }
    else
        std::cerr << "Hum, je pense qu'il manque une etape avant de pouvoir emballer cette boite tu ne crois pas ?" << std::endl;
}

void    GiftPaper::openMe() {
    if (this->m_isOpen) {
        std::cerr << "La boite n'est pas encore pose sur la boite !" << std::endl;
    }
    else
        this->m_isOpen = true;
}

void    GiftPaper::closeMe() {
    if (!this->m_isOpen)
        std::cerr << "Le papier cadeau est deja autour de la boite, non mais !" << std::endl;
    else
        this->m_isOpen = false;
}

