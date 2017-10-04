//
//  template_string.h
//  cpp_abstractvm
//
//  Created by Fabien Martinez on 19/02/15.
//  Copyright (c) 2015 Fabien Martinez. All rights reserved.
//

#ifndef cpp_abstractvm_template_string_h
#define cpp_abstractvm_template_string_h

#include <string>
#include <sstream>

#define MAX_CHAR  127
#define MIN_CHAR  -128

template <typename T>
std::string NumberToString (T nbr)
{
  std::ostringstream os;
  os << nbr;
  return os.str();
}

template <>
inline std::string NumberToString(char nbr) {
  return (NumberToString<int>(nbr));
}

template <typename T>
T StringToNumber (const std::string &str)
{
  std::istringstream is(str);
  T result;
  if (!(is >> result))
	throw UnknownError("Unable to convert string to numeric type", "template_string");
  return result;
}

template<>
inline char StringToNumber (const std::string &str) {
  short res;
  
  res = StringToNumber<short>(str);
  try {
	if (res > MAX_CHAR || res < MIN_CHAR)
	  throw UnknownError("Unable to convert string to numeric type", "template_string");
	}
  catch (UnknownError const &e) {
	throw UnknownError(e.what(), e.getComponent());
  }
  return (res);
}

#endif
