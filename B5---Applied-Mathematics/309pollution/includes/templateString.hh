//
// Created by ankirama on 1/14/2016.
//

#ifndef INC_309POLLUTION_TEMPLATESTRING_HH
#define INC_309POLLUTION_TEMPLATESTRING_HH

#include <string>
#include <iostream>
#include <sstream>
#include <exception>

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
    if (!str.empty()){
        std::istringstream is(str);
        T result;
        if (!(is >> result))
            exit(84);
        return result;
    }
    return 0;
}

#endif //INC_309POLLUTION_TEMPLATESTRING_HH
