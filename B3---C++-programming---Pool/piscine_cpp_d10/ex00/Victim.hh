//
//  Victim.h
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d10__Victim__
#define __piscine_cpp_d10__Victim__

#include <string>
#include <iostream>

class   Victim {
protected:
    std::string const   _name;
    
public:
    explicit Victim(std::string const);
    virtual ~Victim();
    
    std::string getName() const;
    virtual void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream&, Victim const&);

#endif /* defined(__piscine_cpp_d10__Victim__) */
