/*
** sickkoalalist.h for list in /home/mar_b/rendu/piscine_cpp_d06/ex05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jan 12 13:58:35 2015 Fabien Martinez
** Last update Mon Jan 12 20:31:40 2015 Fabien Martinez
*/

#ifndef SICKKOALALIST_H_
# define SICKKOALALIST_H_

# include <string>
# include "sickkoala.h"

class SickKoalaList
{
 private:
  SickKoala *_koala;
  SickKoalaList *_next;

 public:
  SickKoalaList(SickKoala *koala);
  ~SickKoalaList();

  bool isEnd();
  void append(SickKoalaList *);
  SickKoala *getFromName(std::string);
  SickKoalaList *remove(SickKoalaList*);
  SickKoalaList *removeFromName(std::string);
  void dump();
  SickKoala *getContent();
  SickKoalaList *getNext();
};

#endif /* !SICKKOALALIST_H_ */
