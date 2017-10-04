//
// Created by ankirama on 12/10/2015.
//

#ifndef INC_307CEREALES_REGEXISFUNNY_HH
#define INC_307CEREALES_REGEXISFUNNY_HH


#include <string>
#include "templateString.h"

class RegexIsFunny {
public:
    RegexIsFunny();
    ~RegexIsFunny() { }

    float checkRayon(std::string number);
    int checkNumber(std::string number);

};


#endif //INC_307CEREALES_REGEXISFUNNY_HH
