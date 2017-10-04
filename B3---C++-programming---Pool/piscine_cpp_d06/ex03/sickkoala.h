/*
** sickkoala.h<2> for meow in /home/mar_b/rendu/piscine_cpp_d06/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jan 12 10:30:20 2015 Fabien Martinez
** Last update Mon Jan 12 12:27:48 2015 Fabien Martinez
*/

#ifndef SICKKOALA_H_
# define SICKKOALA_H_

# include <iostream>
# include <string>

class	SickKoala
{
 private:
  std::string _name;

 public:
  SickKoala(std::string);
  ~SickKoala();

  void poke();
  bool takeDrug(std::string drug);
  void overDrive(std::string str);
};

#endif /* !SICKKOALA_H_ */
