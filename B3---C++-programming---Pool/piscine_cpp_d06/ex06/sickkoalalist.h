/*
** sickkoalalist.h for list in /home/user/rendu/piscine_cpp_d06/ex05
**
** Made by 
** Login   
**
** Started on  Mon Jan 12 13:58:35 2015 
** Last update Mon Jan 12 20:31:02 2015 
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
