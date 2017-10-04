//
// sickkoalalist.cpp for list in /home/mar_b/rendu/piscine_cpp_d06/ex05
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Mon Jan 12 13:58:43 2015 Fabien Martinez
// Last update Tue Jan 13 00:51:32 2015 Fabien Martinez
//

#include <string>
#include "sickkoalalist.h"

SickKoalaList::SickKoalaList(SickKoala *koala) {
  this->_koala = koala;
  this->_next = NULL;
}

SickKoalaList::~SickKoalaList() {
}

bool SickKoalaList::isEnd() {
  return (this->_next == NULL);
}

void SickKoalaList::append(SickKoalaList *list) {
  SickKoalaList *tmp;

  tmp = this;
  if (tmp == NULL)
    {
      this->_koala = list->_koala;
      this->_next = list->_next;
    }
  while (tmp != NULL && tmp->_next != NULL)
    tmp = tmp->_next;
  tmp->_next = list;
}

SickKoala *SickKoalaList::getFromName(std::string name) {
  SickKoalaList *tmp;

  tmp = this;
  while (tmp != NULL && ((tmp->_koala != NULL && tmp->_koala->getName() != name) || tmp->_koala == NULL))
    tmp = tmp->_next;
  return (tmp != NULL && tmp->_koala != NULL ? tmp->_koala : NULL);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *list) {
  SickKoalaList *tmp;
  SickKoalaList *rmv;

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
	  rmv->_koala = NULL;
	  rmv = NULL;
	}
    }
  return (this);
}

SickKoalaList *SickKoalaList::removeFromName(std::string name) {
  SickKoalaList *tmp;
  SickKoalaList *rmv;

  tmp = this;
  if (tmp != NULL)
    {
      if (tmp->_koala != NULL && tmp->_koala->getName() == name)
	tmp = NULL;
      while (tmp != NULL && tmp->_next != NULL && ((tmp->_next->_koala != NULL && tmp->_next->_koala->getName() != name) || tmp->_next->_koala == NULL))
	tmp = tmp->_next;
      if (tmp->_next != NULL && tmp->_next->_koala->getName() == name)
	{
	  rmv = tmp->_next;
	  tmp->_next = rmv->_next;
	  rmv->_koala = NULL;
	  rmv = NULL;
	}
    }
  return (this);
}

void SickKoalaList::dump() {
  std::cout << "Liste des patients : ";
  for (SickKoalaList *tmp = this ; tmp != NULL ; tmp = tmp->_next)
    {
      if (tmp->_koala == NULL)
	std::cout << "[NULL]";
      else
	std::cout << tmp->_koala->getName();
      if (tmp->_next != NULL)
	std::cout << ", ";
      else
	std::cout << "." << std::endl;
    }
}

SickKoala *SickKoalaList::getContent() {
  return (this->_koala);
}

SickKoalaList *SickKoalaList::getNext() {
  return (this->_next);
}
