//
//  Mage.h
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d09__Mage__
#define __piscine_cpp_d09__Mage__

#include <string>
#include "Character.hh"

class   Mage : public Character {
public:
    Mage(std::string name, int level);
    ~Mage();
    
    int                 CloseAttack();
    int                 RangeAttack();
    void                RestorePower();
};

#endif /* defined(__piscine_cpp_d09__Mage__) */
