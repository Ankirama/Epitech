/*
** koaladoctor.h for meow in /home/user/rendu/piscine_cpp_d06/ex00
**
** Made by 
** Login   
**
** Started on  Mon Jan 12 10:30:31 2015 
** Last update Mon Jan 12 11:56:16 2015 
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
};

#endif /* !KOALADOCTOR_H_ */
