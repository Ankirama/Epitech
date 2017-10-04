//
// Parts.cpp for parts in /home/mar_b/rendu/piscine_cpp_d07a/ex01
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Tue Jan 13 23:03:14 2015 Fabien Martinez
// Last update Wed Jan 14 09:20:01 2015 Fabien Martinez
//

#include <string>
#include <iomanip>
#include <iostream>
#include "Parts.h"

Arms::Arms(std::string serial, bool functionnal) {
  _serial = serial;
  _functionnal = functionnal;
}

Arms::Arms() : _serial("A-01"), _functionnal(true) {}

bool Arms::isFunctionnal() const {
  return (_functionnal);
}

std::string Arms::serial() const {
  return (_serial);
}

void Arms::informations() const {
std::cout << "[Parts] Arms " << _serial << " status : " << (_functionnal == true ? "OK" : "KO") << std::endl;
}

Legs::Legs(std::string serial, bool functionnal) {
  _serial = serial;
  _functionnal = functionnal;
}

Legs::Legs() : _serial("L-01"), _functionnal(true) {}

bool Legs::isFunctionnal() const {
  return (_functionnal);
}

std::string Legs::serial() const {
  return (_serial);
}

void Legs::informations() const {
std::cout << "[Parts] Legs " << _serial << " status : " << (_functionnal == true ? "OK" : "KO") << std::endl;
}

Head::Head(std::string serial, bool functionnal) {
  _serial = serial;
  _functionnal = functionnal;
}

Head::Head() : _serial("H-01"), _functionnal(true) {}

bool Head::isFunctionnal() const {
  return (_functionnal);
}

std::string Head::serial() const {
  return (_serial);
}


void Head::informations() const {
  std::cout << "[Parts] Head " << _serial << " status : " << (_functionnal == true ? "OK" : "KO") << std::endl;
}
