//
//  AMateria.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "AMateria.hh"

AMateria::AMateria(std::string const& type) : m_type(type), xp_(0){}

AMateria::AMateria(AMateria const& amateria) : m_type(amateria.getType()), xp_(amateria.getXP()){}

AMateria& AMateria::operator=(AMateria const& amateria) {
    if (this != &amateria) {
        this->m_type = amateria.getType();
        this->xp_ = amateria.getXP();
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
    return this->m_type;
}

unsigned int AMateria::getXP() const {
    return this->m_xp;
}

void AMateria::use(ICharacter& target) {
    
}