//
//  Hunter.h
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d09__Hunter__
#define __piscine_cpp_d09__Hunter__

#include <string>
#include "Warrior.hh"

class   Hunter : public Warrior {
public:
    Hunter(std::string const&, int);
    ~Hunter();
    
    int                 RangeAttack();
    void                RestorePower();
    using Warrior::CloseAttack;
    using Warrior::Heal;
};

#endif /* defined(__piscine_cpp_d09__Hunter__) */
