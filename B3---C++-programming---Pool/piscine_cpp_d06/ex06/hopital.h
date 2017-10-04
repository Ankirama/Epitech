/*
** hopital.h for hospital in /home/mar_b/rendu/piscine_cpp_d06/ex06
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jan 12 18:16:14 2015 Fabien Martinez
** Last update Mon Jan 12 22:34:55 2015 Fabien Martinez
*/

#ifndef HOPITAL_H_
# define HOPITAL_H_

# include <stdlib.h>

# include "koaladoctorlist.h"
# include "koalanurselist.h"
# include "sickkoalalist.h"

class Hospital
{
 public:
  KoalaDoctorList *_doctors = NULL;
  KoalaNurseList *_nurses = NULL;
  SickKoalaList *_sicks = NULL;
  void	addDoctor(KoalaDoctorList *);
  void	addNurse(KoalaNurseList *);
  void	addSick(SickKoalaList *);
  void	run();
};

#endif /* !HOPITAL_H_ */
