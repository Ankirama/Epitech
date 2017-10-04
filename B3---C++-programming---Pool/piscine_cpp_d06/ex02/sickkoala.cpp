//
// sickkoala.cpp<2> for meow in /home/mar_b/rendu/piscine_cpp_d06/ex00
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Mon Jan 12 10:30:15 2015 Fabien Martinez
// Last update Mon Jan 12 16:40:33 2015 Fabien Martinez
//

#include <iostream>
#include <string>
#include "sickkoala.h"

static bool	_str_cmp_insensitive(std::string s1, std::string s2) {
  int		i;
  bool		diff;
  char		c1;
  char		c2;

  i = 0;
  diff = true;
  do {
    c1 = s1[i] >= 'A' && s1[i] <= 'Z' ? s1[i]  + 32: s1[i];
    c2 = s2[i];
    diff = c1 == c2;
    ++i;
  } while (diff && c1 != '\0' && c2 != '\0');
  return (diff);
}

SickKoala::SickKoala(std::string name) {
  this->_name = name;
}

SickKoala::~SickKoala() {
  std::cout << "Mr." << this->_name << ": Kreooogg !! Je suis gueriiii !" << std::endl;
}

void	SickKoala::poke() {
  std::cout << "Mr." << this->_name << ": Gooeeeeerrk !! :'(" << std::endl;
}

bool		SickKoala::takeDrug(std::string drug) {
  if (_str_cmp_insensitive(drug, "mars"))
    {
      std::cout << "Mr." << this->_name << ": Mars, et ca kreog !" << std::endl;
      return (true);
    }
  else if (drug.compare("Buronzand") == 0)
    {
      std::cout << "Mr." << this->_name << ": Et la fatigue a fait son temps !" << std::endl;
      return (true);
    }
  else
    {
      std::cout << "Mr." << this->_name << ": Goerkreog !" << std::endl;
      return (false);
    }
}

void		SickKoala::overDrive(std::string str) {
  std::size_t	found;

  found = 0;
  while ((found = str.find("Kreog !", found)) != std::string::npos)
      str.replace(found, 7, "1337 !");
  std::cout << "Mr." << this->_name << ": " << str << std::endl;
}
