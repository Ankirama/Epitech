//
//  Priest.h
//  piscine_cpp_d09
//
//  Created by  on 15/01/15.
//  Copyright (c) 2015 . All rights reserved.
//

#ifndef __piscine_cpp_d09__Priest__
#define __piscine_cpp_d09__Priest__

#include "Mage.hh"

class   Priest : public Mage {
public:
    Priest(std::string name, int level);
    ~Priest();
    int                 CloseAttack();
    void                Heal();
};

#endif /* defined(__piscine_cpp_d09__Priest__) */
