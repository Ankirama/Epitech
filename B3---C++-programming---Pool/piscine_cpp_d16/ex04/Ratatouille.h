//
//  Ratatouille.h
//  piscine_cpp_d16
//
//  Created by Fabien Martinez on 22/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef __piscine_cpp_d16__Ratatouille__
#define __piscine_cpp_d16__Ratatouille__

#include <string>
#include <sstream>

class Ratatouille {
public:
    // Canonical class
    Ratatouille();
    Ratatouille(Ratatouille const &);
    ~Ratatouille();
    Ratatouille &operator=(const Ratatouille &);
    // Member functions allowing to add ingredients in the cooking pot
    Ratatouille &addVegetable(unsigned char);
    Ratatouille &addCondiment(unsigned int);
    Ratatouille &addSpice(double);
    Ratatouille &addSauce(const std::string &);
    // The member function to extract the dish.
    // The result will be the concatenation of all the added ingredients.
    std::string kooc(void);
private:
    std::string m_concat;
};

#endif /* defined(__piscine_cpp_d16__Ratatouille__) */
