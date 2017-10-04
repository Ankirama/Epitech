//
// Skat.cpp for dkqowdkqwod in /home/mar_b/rendu/piscine_cpp_d07a/ex00
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Tue Jan 13 20:08:59 2015 Fabien Martinez
// Last update Wed Jan 14 09:00:22 2015 Fabien Martinez
//

#include <iostream>
#include <string>
#include "Skat.h"

Skat::Skat() : _name("bob"), _nbrStimPacks(15) {}

Skat::Skat(std::string const& name, int stimPaks) {
  _name = name;
  _nbrStimPacks = stimPaks;
}

Skat::~Skat() {}

int& Skat::stimPaks() {
  return (_nbrStimPacks);
}

const std::string &Skat::name() {
  return (_name);
}

void Skat::shareStimPaks(int number, int& stock) {
  if (_nbrStimPacks < number)
    std::cout << "Don't be greedy" << std::endl;
  else
    {
      stock += number;
      _nbrStimPacks -= number;
      std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number) {
  if (number == 0)
    std::cout << "Hey boya, did you forget something ?" << std::endl;
  else
    _nbrStimPacks += number;
}

void Skat::useStimPaks() {
  if (_nbrStimPacks > 0)
    {
      std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
      --_nbrStimPacks;
    }
  else
    std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status() {
  std::cout << "Soldier " << _name << " reporting " << _nbrStimPacks << " stimpaks remaining sir !" << std::endl;
}
