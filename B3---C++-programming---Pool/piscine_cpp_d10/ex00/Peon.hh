
//
//  Peon.h
//  piscine_cpp_d10
//
//  Created by  on 16/01/15.
//  Copyright (c) 2015 . All rights reserved.
//

#ifndef __piscine_cpp_d10__Peon__
#define __piscine_cpp_d10__Peon__

#include <string>
#include "Victim.hh"

class   Peon : public Victim {
public:
    explicit Peon(std::string const);
    virtual ~Peon();
    
    virtual void getPolymorphed() const;
};


#endif /* defined(__piscine_cpp_d10__Peon__) */
