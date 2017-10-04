//
//  Character.h
//  piscine_cpp_d09
//
//  Created by Fabien Martinez on 15/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d09__Character__
#define __piscine_cpp_d09__Character__

#include <string>

class   Character {
protected:
    std::string const   _name;
    int                 _level;
    int                 _power;
    int                 _pv;
    int                 _strength;
    int                 _stamina;
    int                 _intelligence;
    int                 _spirit;
    int                 _agility;
    
public:
    /* Cannonical */
    explicit            Character(std::string const &, int);
    ~Character();
    
    int                 getLvl() const;
    int                 getPv() const;
    int                 getPower() const;
    const std::string   &getName() const;
    
    int                 CloseAttack();
    int                 RangeAttack();
    void                Heal();
    void                RestorePower();
    void                TakeDamage(int);

    /* Variables */
    typedef enum AttackRange {
        CLOSE,
        RANGE
    } AttackRange;
    
    AttackRange         Range;
    

};

#endif /* defined(__piscine_cpp_d09__Character__) */
