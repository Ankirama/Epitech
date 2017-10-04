//
//  Ratatouille.cpp
//  piscine_cpp_d16
//
//  Created by Fabien Martinez on 22/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "Ratatouille.h"

// Canonical class
Ratatouille::Ratatouille() : m_concat("") {}
Ratatouille::Ratatouille(Ratatouille const &copy) : m_concat(copy.m_concat) {}
Ratatouille::~Ratatouille() {}
Ratatouille& Ratatouille::operator=(const Ratatouille & copy) {
    if (this != &copy)
        m_concat = copy.m_concat;
    return *this;
}

// Member functions allowing to add ingredients in the cooking pot
Ratatouille &Ratatouille::addVegetable(unsigned char var) {
    std::ostringstream coucou;
    
    coucou << var;
    m_concat += coucou.str();
    
    return *this;
}

Ratatouille &Ratatouille::addCondiment(unsigned int var) {
    std::ostringstream coucou;
    
    coucou << var;
    m_concat += coucou.str();
    
    return *this;
}
Ratatouille &Ratatouille::addSpice(double var) {
    std::ostringstream coucou;
    
    coucou << var;
    m_concat += coucou.str();
    
    return *this;
}
Ratatouille &Ratatouille::addSauce(const std::string &var) {
    m_concat += var;
    
    return *this;
}
// The member function to extract the dish.
// The result will be the concatenation of all the added ingredients.
std::string Ratatouille::kooc(void) {
    return m_concat;
}