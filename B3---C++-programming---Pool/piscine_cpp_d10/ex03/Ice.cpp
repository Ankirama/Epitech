//
//  Ice.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "Ice.hh"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {
    
}

Ice* Ice::clone() const {
    return (new Ice());
}