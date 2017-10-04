/*
** koaladoctorlist.h for meow in /home/user/rendu/piscine_cpp_d06/ex05
**
** Made by 
** Login   
**
** Started on  Mon Jan 12 17:38:33 2015 
** Last update Mon Jan 12 20:30:11 2015 
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
  void dump();
};

#endif /* !KOALADOCTORLIST_H_ */
