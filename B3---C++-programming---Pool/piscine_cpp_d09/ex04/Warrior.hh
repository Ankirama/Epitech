//
//  Warrior.h
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d09__Warrior__
#define __piscine_cpp_d09__Warrior__

#include <string>
#include "Character.hh"

class   Warrior : virtual public Character {
protected:
    std::string weaponName;
public:
    Warrior(std::string name, int level);
    ~Warrior();
    
    int CloseAttack();
    int RangeAttack();
};

#endif /* defined(__piscine_cpp_d09__Warrior__) */
