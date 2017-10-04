//
// koalanurselist.cpp for meow in /home/mar_b/rendu/piscine_cpp_d06/ex05
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Mon Jan 12 16:30:54 2015 Fabien Martinez
// Last update Tue Jan 13 00:51:23 2015 Fabien Martinez
//

#include <string>
#include "koalanurselist.h"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse) {
  this->_nurse = nurse;
  this->_next = NULL;
}

KoalaNurseList::~KoalaNurseList() {
}

bool KoalaNurseList::isEnd() {
  return (this->_next == NULL);
}

void KoalaNurseList::append(KoalaNurseList *list) {
  KoalaNurseList *tmp;

  tmp = this;
  if (tmp == NULL)
    {
      this->_nurse = list->_nurse;
      this->_next = list->_next;
    }
  while (tmp != NULL && tmp->_next != NULL)
    tmp = tmp->_next;
  tmp->_next = list;
}

KoalaNurse *KoalaNurseList::getFromID(int id) {
  KoalaNurseList *tmp;

  tmp = this;
  while (tmp != NULL && ((tmp->_nurse != NULL && tmp->_nurse->getID() != id) || tmp->_nurse == NULL))
    tmp = tmp->_next;
  return (tmp != NULL && tmp->_nurse != NULL ? tmp->_nurse : NULL);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *list) {
  KoalaNurseList *tmp;
  KoalaNurseList *rmv;

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
	  rmv->_nurse = NULL;
	  rmv = NULL;
	}
    }
  return (this);
}

KoalaNurseList *KoalaNurseList::removeFromID(int id) {
  KoalaNurseList *tmp;
  KoalaNurseList *rmv;

  tmp = this;
  if (tmp != NULL)
    {
      if (tmp->_nurse != NULL && tmp->_nurse->getID() == id)
	tmp = NULL;
      while (tmp != NULL && tmp->_next != NULL && ((tmp->_next->_nurse != NULL && tmp->_next->_nurse->getID() != id) || tmp->_next->_nurse == NULL))
	tmp = tmp->_next;
      if (tmp->_next != NULL && tmp->_next->_nurse->getID() == id)
	{
	  rmv = tmp->_next;
	  tmp->_next = rmv->_next;
	  rmv->_nurse = NULL;
	  rmv = NULL;
	}
    }
  return (this);
}

void KoalaNurseList::dump() {
  std::cout << "Liste des infirmieres : ";
  for (KoalaNurseList *tmp = this ; tmp != NULL ; tmp = tmp->_next)
    {
      if (tmp->_nurse == NULL)
	std::cout << "[NULL]";
      else
	std::cout << tmp->_nurse->getID();
      if (tmp->_next != NULL)
	std::cout << ", ";
      else
	std::cout << "." << std::endl;
    }
}
