//
//  ToyStory.h
//  piscine_cpp_d13
//
//  Created by Fabien Martinez on 19/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d13__ToyStory__
#define __piscine_cpp_d13__ToyStory__

#include <string>
#include "Toy.h"

class ToyStory {
public:
    static void tellMeAStory(std::string const&, Toy&, bool (Toy::*func1)(std::string), Toy&, bool (Toy::*func2)(std::string));
};

#endif /* defined(__piscine_cpp_d13__ToyStory__) */
