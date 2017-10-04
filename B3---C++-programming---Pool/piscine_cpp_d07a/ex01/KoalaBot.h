/*
** KoalaBot.h for mdr in /home/user/rendu/piscine_cpp_d07a/ex01
**
** Made by 
** Login   
**
** Started on  Tue Jan 13 22:25:21 2015 
** Last update Wed Jan 14 00:35:15 2015 
*/

#ifndef KOALABOT_H_
# define KOALABOT_H_

#include <string>
#include "Parts.h"
#include <iostream>

class KoalaBot
{
 private:
  Arms _arms;
  Legs _legs;
  Head _head;
  std::string _serial;

 public:
  KoalaBot(Arms);
  KoalaBot(Legs);
  KoalaBot(Head);
  KoalaBot();

  void setParts(const Arms &);
  void setParts(const Legs &);
  void setParts(const Head &);

  void swapParts(Arms &);
  void swapParts(Legs &);
  void swapParts(Head &);

  void informations();

  bool status();
};

#endif /* !KOALABOT_H_ */
