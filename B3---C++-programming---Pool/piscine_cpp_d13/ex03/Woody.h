//
//  Woody.h
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d13__Woody__
#define __piscine_cpp_d13__Woody__

#include <string>
#include "Toy.h"

class Woody : public Toy {
public:
    explicit Woody(std::string const&);
    explicit Woody(std::string const&, std::string const&);
    explicit Woody(Woody const&);
    Woody& operator=(Woody const&);
    ~Woody();
    
    virtual void    speak(std::string const&);
};

#endif /* defined(__piscine_cpp_d13__Woody__) */
