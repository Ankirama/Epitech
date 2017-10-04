//
//  PlasmaRifle.h
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d10__PlasmaRifle__
#define __piscine_cpp_d10__PlasmaRifle__

#include "AWeapon.hh"

class PlasmaRifle : public AWeapon {
public:
    PlasmaRifle();
    virtual ~PlasmaRifle();
    
    virtual void attack() const;
};

#endif /* defined(__piscine_cpp_d10__PlasmaRifle__) */
