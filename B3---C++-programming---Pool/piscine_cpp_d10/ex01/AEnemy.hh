//
//  AEnemy.h
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d10__AEnemy__
#define __piscine_cpp_d10__AEnemy__

#include <string>

class AEnemy
{
private:
    int               _hp;
    std::string const _type;
    
public:
    AEnemy(int hp, std::string const & type);
    virtual ~AEnemy();
    
    std::string getType() const;
    int getHP() const;
    
    virtual void takeDamage(int);
};

#endif /* defined(__piscine_cpp_d10__AEnemy__) */
