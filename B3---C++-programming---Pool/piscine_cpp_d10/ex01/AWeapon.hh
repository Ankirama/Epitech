//
//  AWeapon.h
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d10__AWeapon__
#define __piscine_cpp_d10__AWeapon__

#include <string>

class AWeapon
{
private:
    std::string const   _name;
    int                 _apcost;
    int                 _damage;
    
public:
    AWeapon(std::string const & name, int apcost, int damage);
    virtual ~AWeapon();
    
    std::string const getName() const;
    int getAPCost() const;
    int getDamage() const;
    
    virtual void attack() const = 0;
};
    
#endif /* defined(__piscine_cpp_d10__AWeapon__) */
