//
//  carrier.h
//  piscine_cpp_d08
//
//  Created by Fabien Martinez on 14/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d08__carrier__
#define __piscine_cpp_d08__carrier__

#include <iostream>
#include <string>
#include "droid.hh"

class Carrier {
private:
    std::string     Id;
    size_t          Energy;
    size_t const    Attack;
    size_t const    Toughness;
    size_t          Speed;
    
public:
    Droid*          Droids[5];
    /* Cannonical basic form */
    Carrier();
    Carrier(std::string);
    Carrier& operator=(Carrier const &);
    ~Carrier();
    
    /* get set */
    std::string     getId() const;
    void            setId(std::string);
    size_t          getEnergy() const;
    void            setEnergy(size_t);
    size_t          getAttack() const;
    size_t          getToughness() const;
    size_t          getSpeed() const;
    
    /* operators */
    void operator=(size_t);
    Carrier &operator~(void);
    bool    operator()(int, int);
    Droid   &operator[](int) const;
    Carrier &operator<<(Droid *&);
    Carrier &operator>>(Droid *);
    Carrier &operator<<(size_t &);
    
};

std::ostream &operator<<(std::ostream &, Carrier const&);

#endif /* defined(__piscine_cpp_d08__carrier__) */
