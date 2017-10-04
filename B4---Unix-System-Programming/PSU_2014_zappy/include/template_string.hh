//
// Created by ankirama on 5/11/15.
//

#ifndef CPP_BOMBERMAN_TEMPLATE_STRING_HH
#define CPP_BOMBERMAN_TEMPLATE_STRING_HH

#include <string>
#include <iostream>
#include <sstream>
#include "Error.hpp"

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
      throw ErrorClient(str + " isn't a number", "template_string");
    return result;
  }
  return 0;
}

#endif //CPP_BOMBERMAN_TEMPLATE_STRING_HH
