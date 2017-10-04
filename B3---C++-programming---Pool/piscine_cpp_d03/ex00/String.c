/*
** String.c for class in /home/mar_b/rendu/piscine_cpp_d03/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jan  9 09:44:20 2015 Fabien Martinez
** Last update Fri Jan  9 11:01:54 2015 Fabien Martinez
*/

#include <stdlib.h>
#include <string.h>
#include "String.h"

void StringInit(String* this, char const * s)
{
  this->str = strdup(s);
}

void StringDestroy(String* this)
{
  free(this->str);
  this->str = NULL;
}
