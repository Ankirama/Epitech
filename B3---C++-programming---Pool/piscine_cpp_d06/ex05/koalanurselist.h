/*
** koalanurselist.h for list in /home/mar_b/rendu/piscine_cpp_d06/ex05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jan 12 16:27:27 2015 Fabien Martinez
** Last update Mon Jan 12 20:31:33 2015 Fabien Martinez
*/

#ifndef KOALANURSELIST_H_
# define KOALANURSELIST_H_

#include <string>
#include "koalanurse.h"

class KoalaNurseList
{
 private:
  KoalaNurse	*_nurse;
  KoalaNurseList *_next;

 public:
  KoalaNurseList(KoalaNurse*);
  ~KoalaNurseList();

  bool isEnd();
  void append(KoalaNurseList *);
  KoalaNurse *getFromID(int);
  KoalaNurseList *remove(KoalaNurseList*);
  KoalaNurseList *removeFromID(int);
  void dump();
};

#endif /* !KOALANURSELIST_H_ */
