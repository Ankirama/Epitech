//
// Created by ankirama on 12/10/2015.
//

#ifndef INC_307CEREALES_TEMPLATESTRING_H
#define INC_307CEREALES_TEMPLATESTRING_H

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
      return -1;
    return result;
  }
  return -1;
}

#endif //INC_307CEREALES_TEMPLATESTRING_H
