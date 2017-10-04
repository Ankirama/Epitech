/*
** Skat.h for dkqow in /home/mar_b/rendu/piscine_cpp_d07a/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jan 13 20:03:31 2015 Fabien Martinez
** Last update Tue Jan 13 22:16:26 2015 Fabien Martinez
*/

#include <string>

#ifndef SKAT_H_
# define SKAT_H_

class	Skat
{
 public:
  Skat(std::string const& name, int stimPaks);
  Skat();
  ~Skat();

 public:
 int& stimPaks();
 const std::string& name();

 public:
 void	shareStimPaks(int number, int& stock);
 void	addStimPaks(unsigned int number);
 void	useStimPaks();

 public:
 void	status();

 private:
 std::string	_name;
 int		_nbrStimPacks;
};

#endif /* !SKAT_H_ */
