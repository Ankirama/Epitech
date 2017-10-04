/*
** koalanurse.h for meow in /home/mar_b/rendu/piscine_cpp_d06/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jan 12 10:30:02 2015 Fabien Martinez
** Last update Mon Jan 12 13:47:39 2015 Fabien Martinez
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
};

#endif /* !KOALANURSE_H_ */
