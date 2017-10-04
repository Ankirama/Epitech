/*
** koaladoctor.h for meow in /home/mar_b/rendu/piscine_cpp_d06/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jan 12 10:30:31 2015 Fabien Martinez
** Last update Mon Jan 12 12:55:06 2015 Fabien Martinez
*/

#ifndef KOALADOCTOR_H_
# define KOALADOCTOR_H_

# include <string>
# include "sickkoala.h"
# include "koalanurse.h"

class KoalaDoctor
{
 private:
  std::string	_name;
  bool		_status;

 public:
  KoalaDoctor(std::string name);
  ~KoalaDoctor();
  void diagnose(SickKoala *patient);
  void timeCheck();
  std::string getName();
};

#endif /* !KOALADOCTOR_H_ */
