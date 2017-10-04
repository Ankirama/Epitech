//
// koaladoctor.cpp for meow in /home/mar_b/rendu/piscine_cpp_d06/ex00
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Mon Jan 12 10:30:27 2015 Fabien Martinez
// Last update Tue Jan 13 01:33:45 2015 Fabien Martinez
//

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "koaladoctor.h"

KoalaDoctor::KoalaDoctor(std::string name) {
  this->_name = name;
  this->_status = false;

  std::cout << "Dr." << this->_name << ": Je suis le Dr." << this->_name << " ! Comment Kreoggez-vous ?" << std::endl;
}

KoalaDoctor::~KoalaDoctor() {
}

void	KoalaDoctor::diagnose(SickKoala *patient) {
  std::string	drug[] = {"mars", "Buronzand", "Viagra", "Extasy", "Feuille d'eucalyptus"};
  std::string	filename = patient->getName() + ".report";
  std::ofstream	file(filename.c_str(), std::ios::out);

  std::cout << "Dr." << this->_name << ": Alors qu'est-ce qui vous goerk Mr." << patient->getName() << " ?" << std::endl;
  patient->poke();
  if (file)
    {
      file << drug[random() % 5] << "" << std::endl;
      file.close();
    }
}

void	KoalaDoctor::timeCheck() {
  if (this->_status)
    std::cout << "Dr." << this->_name << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
  else
    std::cout << "Dr." << this->_name << ": Je commence le travail !" << std::endl;
  this->_status = !this->_status;
}

std::string	KoalaDoctor::getName() {
  return (this->_name);
}
