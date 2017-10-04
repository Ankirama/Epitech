//
//  Buzz.h
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d13__Buzz__
#define __piscine_cpp_d13__Buzz__

#include <string>
#include "Toy.h"

class Buzz : public Toy {
public:
    explicit Buzz(std::string const&);
    explicit Buzz(std::string const&, std::string const&);
    explicit Buzz(Buzz const&);
    Buzz& operator=(Buzz const&);
    ~Buzz();
    
    virtual void    speak(std::string const&);
};

#endif /* defined(__piscine_cpp_d13__Buzz__) */
