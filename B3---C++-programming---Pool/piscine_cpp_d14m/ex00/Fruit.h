//
//  Fruit.h
//  piscine_cpp_d14m
//
//  Created by Fabien Martinez on 20/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d14m__Fruit__
#define __piscine_cpp_d14m__Fruit__

#include <string>

class Fruit {
public:
    Fruit(int, std::string const&);
    ~Fruit();
    
    virtual int getVitamins() const = 0;
    virtual std::string getName() const = 0;
protected:
    int _vitamins;
    std::string m_name;
};

#endif /* defined(__piscine_cpp_d14m__Fruit__) */
