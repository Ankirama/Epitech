//
//  MateriaSource.cpp
//  piscine_cpp_d10
//
//  Created by Fabien Martinez on 16/01/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#include "MateriaSource.hh"

static char _my_compare(std::string s1, std::string s2) {
    int     i;
    char    c1;
    char    c2;
    
    i = 0;
    do {
        c1 = s1[i] >= 'A' && s1[i] <= 'Z' ? s1[i] + 32 : s1[i];
        c2 = s2[i] >= 'A' && s2[i] <= 'Z' ? s2[i] + 32 : s2[i];
    } while (c1 == c2 && c1 != '\0' && c2 != '\0');
    return (c1 - c2);
}