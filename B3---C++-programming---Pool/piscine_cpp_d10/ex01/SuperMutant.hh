//
//  SuperMutant.h
//  piscine_cpp_d10
//
//  Created by  on 16/01/15.
//  Copyright (c) 2015 . All rights reserved.
//

#ifndef __piscine_cpp_d10__SuperMutant__
#define __piscine_cpp_d10__SuperMutant__

#include "AEnemy.hh"

class SuperMutant : public AEnemy {
public:
    SuperMutant();
    virtual ~SuperMutant();
    
    virtual void takeDamage(int);
};

#endif /* defined(__piscine_cpp_d10__SuperMutant__) */
