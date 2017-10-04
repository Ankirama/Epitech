//
// koalanurse.cpp for meow in /home/mar_b/rendu/piscine_cpp_d06/ex00
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Mon Jan 12 10:29:57 2015 Fabien Martinez
// Last update Mon Jan 12 16:44:13 2015 Fabien Martinez
//

#include <iostream>
#include <fstream>
#include <string>
#include "sickkoala.h"
#include "koalanurse.h"

KoalaNurse::KoalaNurse(int id) {
  this->_id = id;
  this->_status = false;
}

KoalaNurse::~KoalaNurse() {
  std::cout << "Nurse " << this->_id << ": Enfin un peu de repos !" << std::endl;
}

void KoalaNurse::giveDrug(std::string medicament, SickKoala *patient) {
  if (patient != NULL)
    patient->takeDrug(medicament);
}

std::string KoalaNurse::readReport(std::string report) {
  std::ifstream file(report.c_str(), std::ios::in);
  std::string	medicament;
  std::string	koala;
  std::size_t	pos;

  koala = report;
  report.clear();
  if (file)
    {
      if (!getline(file, medicament))
	return (report);
      if ((pos = koala.find(".report", 0)) != std::string::npos && pos + 7 == koala.length())
	koala.replace(koala.length() - 7, 7, "\0");
      else
	return (report);
      std::cout << "Nurse " << this->_id << ": Kreog ! Il faut donner un " << medicament << " a Mr." << koala << " !" << std::endl;
      return (medicament);
    }
  else
    return (report);
}

void KoalaNurse::timeCheck() {
  if (this->_status)
    std::cout << "Nurse " << this->_id << ": Je rentre dans ma foret d'eucalyptus !" << std::endl;
  else
    std::cout << "Nurse " << this->_id << ": Je commence le travail !" << std::endl;
  this->_status = !this->_status;
}
