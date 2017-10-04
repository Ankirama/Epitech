/*
** sickkoala.h for meow in /home/user/rendu/piscine_cpp_d06/ex00
**
** Made by 
** Login   
**
** Started on  Mon Jan 12 10:29:49 2015 
** Last update Mon Jan 12 12:25:55 2015 
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
