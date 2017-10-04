//
// Created by ankirama on 5/11/15.
//

#ifndef CPP_BOMBERMAN_TEMPLATE_STRING_HH
#define CPP_BOMBERMAN_TEMPLATE_STRING_HH

#include <string>
#include <iostream>
#include <sstream>

template <typename T>
std::string NumberToString (T nbr)
{
    std::ostringstream os;
    os << nbr;
    return os.str();
}

template <typename T>
T StringToNumber (const std::string &str)
{
    std::istringstream is(str);
    T result;
    if (!(is >> result)) {
        std::cerr << "error" << std::endl;
        return 0;
    }
    return result;
}

#endif //CPP_BOMBERMAN_TEMPLATE_STRING_HH
