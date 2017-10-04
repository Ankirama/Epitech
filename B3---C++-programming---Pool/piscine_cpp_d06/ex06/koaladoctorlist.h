/*
** koaladoctorlist.h for meow in /home/mar_b/rendu/piscine_cpp_d06/ex05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jan 12 17:38:33 2015 Fabien Martinez
** Last update Mon Jan 12 23:41:47 2015 Fabien Martinez
*/

#ifndef KOALADOCTORLIST_H_
# define KOALADOCTORLIST_H_

# include <string>
# include "koaladoctor.h"

class KoalaDoctorList
{
 private:
  KoalaDoctor *_doctor;
  KoalaDoctorList *_next;

 public:
  KoalaDoctorList(KoalaDoctor *koala);
  ~KoalaDoctorList();

  bool isEnd();
  void append(KoalaDoctorList *);
  KoalaDoctor *getFromName(std::string);
  KoalaDoctorList *remove(KoalaDoctorList*);
  KoalaDoctorList *removeFromName(std::string);
  KoalaDoctor *getContent();
  KoalaDoctorList *getNext();
  void dump();
};

#endif /* !KOALADOCTORLIST_H_ */
