//
// koaladoctorlist.cpp for meow in /home/mar_b/rendu/piscine_cpp_d06/ex05
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Mon Jan 12 17:45:04 2015 Fabien Martinez
// Last update Tue Jan 13 01:20:10 2015 Fabien Martinez
//


#include <string>
#include "koaladoctorlist.h"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor) {
  this->_doctor = doctor;
  this->_next = NULL;
}

KoalaDoctorList::~KoalaDoctorList() {
}

bool KoalaDoctorList::isEnd() {
  return (true);
}

void KoalaDoctorList::append(KoalaDoctorList *list) {
  KoalaDoctorList *tmp;

  tmp = this;
  if (tmp == NULL)
    {
      this->_doctor = list->_doctor;
      this->_next = list->_next;
    }
  while (tmp != NULL && tmp->_next != NULL)
    tmp = tmp->_next;
  tmp->_next = list;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name) {
  KoalaDoctorList *tmp;

  tmp = this;
  while (tmp != NULL && ((tmp->_doctor != NULL && tmp->_doctor->getName() != name) || tmp->_doctor == NULL))
    tmp = tmp->_next;
  return (tmp != NULL ? tmp->_doctor : NULL);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *list) {
  KoalaDoctorList *tmp;
  KoalaDoctorList *rmv;

  tmp = this;
  if (tmp != NULL)
    {
      if (tmp == list)
	tmp = NULL;
      while (tmp != NULL && tmp->_next != NULL && tmp->_next != list)
	tmp = tmp->_next;
      if (tmp->_next != NULL && tmp->_next == list)
	{
	  rmv = tmp->_next;
	  tmp->_next = rmv->_next;
	  rmv->_doctor = NULL;
	  rmv = NULL;
	}
    }
  return (this);
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name) {
  KoalaDoctorList *tmp;
  KoalaDoctorList *rmv;

  tmp = this;
  if (tmp != NULL)
    {
      if (tmp->_doctor != NULL && tmp->_doctor->getName() == name)
	tmp = NULL;
      while (tmp != NULL && tmp->_next != NULL && ((tmp->_next->_doctor != NULL && tmp->_next->_doctor->getName() != name) || tmp->_next->_doctor == NULL))
	tmp = tmp->_next;
      if (tmp->_next != NULL && tmp->_next->_doctor->getName() == name)
	{
	  rmv = tmp->_next;
	  tmp->_next = rmv->_next;
	  rmv->_doctor = NULL;
	  rmv = NULL;
	}
    }
  return (this);
}

void KoalaDoctorList::dump() {
  std::cout << "Liste des medecins : ";
  for (KoalaDoctorList *tmp = this ; tmp != NULL ; tmp = tmp->_next)
    {
      if (tmp->_doctor == NULL)
	std::cout << "[NULL]";
      else
	std::cout << tmp->_doctor->getName();
      if (tmp->_next != NULL)
	std::cout << ", ";
      else
	std::cout << "." << std::endl;
    }
}

KoalaDoctor *KoalaDoctorList::getContent() {
  return (this->_doctor);
}

KoalaDoctorList *KoalaDoctorList::getNext() {
  return (this->_next);
}
