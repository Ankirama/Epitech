//
// hopital.cpp for hospital in /home/mar_b/rendu/piscine_cpp_d06/ex06
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Mon Jan 12 18:16:30 2015 Fabien Martinez
// Last update Tue Jan 13 01:21:13 2015 Fabien Martinez
//

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include"hopital.h"

void Hospital::addDoctor(KoalaDoctorList *doctors) {
  if (this->_doctors == NULL)
    {
      std::cout << "[HOSPITAL] Doctor " << doctors->getContent()->getName() << " just arrived !" << std::endl;
      doctors->getContent()->timeCheck();
      this->_doctors = doctors;
    }
  else
    {
      if (_doctors->getFromName(doctors->getContent()->getName()) == NULL)
	{
	  std::cout << "[HOSPITAL] Doctor " << doctors->getContent()->getName() << " just arrived !" << std::endl;
	  doctors->getContent()->timeCheck();
	  this->_doctors->append(doctors);
	}
    }

}

void Hospital::addNurse(KoalaNurseList *nurses) {
  if (this->_nurses == NULL)
    {
      std::cout << "[HOSPITAL] Nurse " << nurses->getContent()->getID() << " just arrived !" << std::endl;
      nurses->getContent()->timeCheck();
      this->_nurses = nurses;
    }
  else
    {
      if (_nurses->getFromID(nurses->getContent()->getID()) == NULL)
	{
	  std::cout << "[HOSPITAL] Nurse " << nurses->getContent()->getID() << " just arrived !" << std::endl;
	  nurses->getContent()->timeCheck();
	  this->_nurses->append(nurses);
	}
    }
}

void Hospital::addSick(SickKoalaList *sicks) {
  if (this->_sicks == NULL)
    this->_sicks = sicks;
  else
    {
      if (_sicks->getFromName(sicks->getContent()->getName()) == NULL)
	  this->_sicks->append(sicks);
    }
  std::cout << "[HOSPITAL] Patient " << sicks->getContent()->getName() << " just arrived !" << std::endl;
}

void	free_me(KoalaDoctorList *doctors)
{
  if (doctors != NULL)
    {
      if (doctors->isEnd())
	doctors = NULL;
      else
	free_me(doctors->getNext());
    }
}

void Hospital::run() {
  std::string	nurse;
  KoalaDoctorList *doctors = this->_doctors;
  KoalaNurseList *nurses = this->_nurses;
  SickKoalaList *sicks = this->_sicks;
  std::cout << "[HOSPITAL] Debut du travail avec :" << std::endl;
  this->_doctors->dump();
  this->_nurses->dump();
  this->_sicks->dump();
  std::cout << std::endl;
  while (sicks != NULL)
    {
      if (doctors == NULL)
	doctors = this->_doctors;
      if (nurses == NULL)
	nurses = this->_nurses;
      doctors->getContent()->diagnose(sicks->getContent());
      nurse = nurses->getContent()->readReport(sicks->getContent()->getName() + ".report");
      (void)sicks->getContent()->takeDrug(nurse);
      doctors = doctors->getNext();
      nurses = nurses->getNext();
      sicks = sicks->getNext();
    }
  while (this->_nurses != NULL)
    {
      this->_nurses->getContent()->timeCheck();
      this->_nurses = this->_nurses->getNext();
    }
  while (this->_doctors != NULL)
    {
      this->_doctors->getContent()->timeCheck();
      this->_doctors = this->_doctors->getNext();
    }
}
