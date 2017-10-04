//
//  AssaultTerminator.h
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d10__AssaultTerminator__
#define __piscine_cpp_d10__AssaultTerminator__

#include "ISpaceMarine.hh"

class AssaultTerminator : public ISpaceMarine {
public:
    AssaultTerminator();
    virtual ~AssaultTerminator();
    
    virtual ISpaceMarine* clone() const;
    virtual void battleCry() const;
    virtual void rangedAttack() const;
    virtual void meleeAttack() const;
};


#endif /* defined(__piscine_cpp_d10__AssaultTerminator__) */
