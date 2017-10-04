//
//  Character.h
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d10__Character__
#define __piscine_cpp_d10__Character__

#include <iostream>
#include <string>
#include "SuperMutant.hh"
#include "RadScorpion.hh"
#include "PowerFist.hh"
#include "PlasmaRifle.hh"

class Character
{
private:
    std::string   _name;
    int                 _ap;
    AWeapon             *_weapon;
public:
    Character(std::string const & name);
    Character(Character const&);
    Character& operator=(Character const&);
    ~Character();
    void recoverAP();
    void equip(AWeapon*);
    void attack(AEnemy*);
    
    std::string getName() const;
    int         getAp() const;
    AWeapon     *getWeapon() const;
};

std::ostream& operator<<(std::ostream &, Character const& );
    
#endif /* defined(__piscine_cpp_d10__Character__) */
