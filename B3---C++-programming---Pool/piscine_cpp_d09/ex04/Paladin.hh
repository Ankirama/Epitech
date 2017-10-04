//
//  Paladin.h
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d09__Paladin__
#define __piscine_cpp_d09__Paladin__

#include "Priest.hh"
#include "Warrior.hh"

class   Paladin : public Warrior, public Priest {
public:
    Paladin(std::string const &, int);
    ~Paladin();
    
    /* using */
    using               Warrior::CloseAttack;
    using               Warrior::RestorePower;
    using               Priest::Heal;
    using               Priest::RangeAttack;
    
    int                 Intercept();
};

#endif /* defined(__piscine_cpp_d09__Paladin__) */
