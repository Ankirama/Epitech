/*
** koalanurse.h for meow in /home/user/rendu/piscine_cpp_d06/ex00
**
** Made by 
** Login   
**
** Started on  Mon Jan 12 10:30:02 2015 
** Last update Mon Jan 12 13:50:39 2015 
*/

#ifndef KOALANURSE_H_
# define KOALANURSE_H_

#include <string.h>
#include "sickkoala.h"

class	KoalaNurse
{
 private:
  int	_id;
  bool	_status;

 public:
  KoalaNurse(int);
  ~KoalaNurse();

  void giveDrug(std::string medicament, SickKoala *Koala);
  std::string readReport(std::string report);
  void timeCheck();
  int	getID();
};

#endif /* !KOALANURSE_H_ */
