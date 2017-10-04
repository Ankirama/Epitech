//
// myUnitTest.cpp for  in /home/teyssa_r/rendu/cpp_santa
// 
// Made by Raphael Teyssandier
// Login   <teyssa_r@epitech.net>
// 
// Started on  Sat Jan 17 10:45:59 2015 Raphael Teyssandier
// Last update Sat Jan 17 15:01:16 2015 Raphael Teyssandier
//

#include "Object.hh"
#include "Wrap.hh"
#include "Box.hh"
#include "GiftPaper.hh"
#include "Teddy.hh"
#include "myUnitTest.hh"

#include <stdlib.h>
#include <iostream>

GiftPaper      	my_UnitTest(Object **tmp){
  if (!tmp[0] && !tmp[1] && !tmp[2]){
    std::cout << "Un ou plusieur element est vide." << std::endl;
    return (NULL);
  }
  init_tmp(tmp);
  if (((Wrap*)tmp[1])->isOpen())
    {
      if (tmp[1] != NULL)
	((Wrap*)tmp[1])->wrapMeThat(tmp[0]);
    }
  else
    {
      ((Wrap*)tmp[1])->openMe();
      if (tmp[1] != NULL)
	((Wrap*)tmp[1])->wrapMeThat(tmp[0]);
    }
  ((Wrap*)tmp[1])->closeMe();
  if (tmp[0] != NULL && ((Wrap*)tmp[1])->isWraped() && !((Wrap*)tmp[2])->isOpen())
    if (((Wrap*)tmp[0])->isOpen())
      ((Wrap*)tmp[0])->closeMe();
    else{
      ((Wrap*)tmp[0])->wrapMeThat(tmp[1]);
      ((Wrap*)tmp[0])->closeMe();
    }
  std::cout << "Le motif de papier cadeaux " << ((GiftPaper*)tmp[2])->getPattern() << "->" << std::endl;
  return (0);
  return (GiftPaper);
}

void	init_tmp(Object **tmp){
  if (tmp[0]->getType() != TEDDY){
    std::cout << "Erreur 404 :Teddy not found !" << std::endl;
    exit (2);
  }
  if (tmp[1]->getType() != BOX){
    std::cout << "Ce n'est pas une boite !" << std::endl;
    exit (2);
  }
  if (tmp[2]->getType() != GIFT_PAPER){
    std::cout << "GiftPaper: dechire ou trop moche !" << std::endl;
    exit(2);
  }
  if (tmp[3] != NULL){
    std::cout << "Vous n'avez pas le bon nombre d'element !" << std::endl;
    exit (2);
  }
}
