//
//  TacticalMarine.h
//  piscine_cpp_d10
//
//  Created by  on 16/01/15.
//  Copyright (c) 2015 . All rights reserved.
//

#ifndef __piscine_cpp_d10__TacticalMarine__
#define __piscine_cpp_d10__TacticalMarine__

#include "ISpaceMarine.hh"

class TacticalMarine : public ISpaceMarine {
public:
    TacticalMarine();
    virtual ~TacticalMarine();
    
    virtual ISpaceMarine* clone() const;
    virtual void battleCry() const;
    virtual void rangedAttack() const;
    virtual void meleeAttack() const;
};

#endif /* defined(__piscine_cpp_d10__TacticalMarine__) */
