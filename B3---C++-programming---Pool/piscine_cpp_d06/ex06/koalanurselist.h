/*
** koalanurselist.h for list in /home/user/rendu/piscine_cpp_d06/ex05
**
** Made by 
** Login   
**
** Started on  Mon Jan 12 16:27:27 2015 
** Last update Mon Jan 12 23:40:48 2015 
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
  KoalaNurse *getContent();
  KoalaNurseList *getNext();
  void dump();
};

#endif /* !KOALANURSELIST_H_ */
