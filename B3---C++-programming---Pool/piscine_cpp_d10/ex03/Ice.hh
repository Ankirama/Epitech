//
//  Ice.h
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d10__Ice__
#define __piscine_cpp_d10__Ice__

#include "AMateria.hh"

class Ice : AMateria {
public:
    Ice();
    virtual ~Ice();
    
    virtual Ice* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif /* defined(__piscine_cpp_d10__Ice__) */
