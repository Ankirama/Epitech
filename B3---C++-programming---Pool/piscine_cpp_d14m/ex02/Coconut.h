//
//  Coconut.h
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d14m__Coconut__
#define __piscine_cpp_d14m__Coconut__

#include "Fruit.h"

class   Coconut : public Fruit {
public:
    Coconut();
    ~Coconut();
    
    virtual std::string getName() const;
    virtual int getVitamins() const;

};

#endif /* defined(__piscine_cpp_d14m__Coconut__) */
