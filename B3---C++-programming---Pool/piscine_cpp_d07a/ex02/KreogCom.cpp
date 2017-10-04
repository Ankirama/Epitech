//
// KreogCom.cpp for click in /home/mar_b/rendu/piscine_cpp_d07a/ex02
//
// Made by Fabien Martinez
// Login   <mar_b@epitech.net>
//
// Started on  Wed Jan 14 00:23:03 2015 Fabien Martinez
// Last update Wed Jan 14 09:20:40 2015 Fabien Martinez
//

#include <iostream>
#include "KreogCom.h"

KreogCom::KreogCom(int x, int y, int serial) : m_serial(serial) {
  this->X = x;
  this->Y = y;
  this->_next = NULL;
  std::cout << "KreogCom " << serial << " initialised" << std::endl;
}

KreogCom::~KreogCom() {
  std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial) {
  KreogCom *next = new KreogCom(x, y, serial);
  KreogCom *tmp;
  if (this->_next == NULL)
    this->_next = next;
  else
    {
      tmp = this->_next;
      this->_next = next;
      next->_next = tmp;
    }
}

KreogCom *KreogCom::getCom() {
  return (this->_next);
}

void KreogCom::removeCom() {
  KreogCom *tmp;

  if (this->_next != NULL)
    {
      tmp = this->_next;
      this->_next = tmp->_next;
      delete(tmp);
    }
}

void KreogCom::locateSquad() const {
  KreogCom *tmp;

  tmp = this->_next;
  while (tmp != NULL)
    {
      tmp->ping();
      tmp = tmp->_next;
    }
  this->ping();
}

void KreogCom::ping() const{
  std::cout << "KreogCom " << this->m_serial << " currently at " << this->X << " " << this->X << std::endl;
}
