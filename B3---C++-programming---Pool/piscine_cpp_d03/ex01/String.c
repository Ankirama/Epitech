/*
** String.c for class in /home/user/rendu/piscine_cpp_d03/ex00
**
** Made by 
** Login   
**
** Started on  Fri Jan  9 09:44:20 2015 
** Last update Fri Jan  9 11:03:02 2015 
*/

#include <stdlib.h>
#include <string.h>
#include "String.h"

static void	assign_s(String *this, String const * str);
static void	assign_c(String *this, char const * s );

void StringInit(String* this, char const * s)
{
  this->str = strdup(s);
  this->assign_c = &assign_c;
  this->assign_s = &assign_s;
}

void StringDestroy(String* this)
{
  free(this->str);
  this->str = NULL;
}

void	assign_s(String *this, String const * str)
{
  this->str = strdup(str->str);
}

void	assign_c(String *this, char const * s )
{
  this->str = strdup(s);
}
