/*
** String.c for class in /home/mar_b/rendu/piscine_cpp_d03/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jan  9 09:44:20 2015 Fabien Martinez
** Last update Fri Jan  9 11:19:55 2015 Fabien Martinez
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "String.h"

static void	assign_s(String *this, String const * str);
static void	assign_c(String *this, char const * s );
static char	at(String* this, size_t pos);
static void	append_s(String* this, String const* ap);
static void	append_c(String* this, char const* ap);

void StringInit(String* this, char const * s)
{
  this->str = strdup(s);
  this->assign_c = &assign_c;
  this->assign_s = &assign_s;
  this->at = &at;
  this->append_s = &append_s;
  this->append_c = &append_c;
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

void	append_s(String* this, String const* ap)
{
  char	*res;

  res = malloc(sizeof(char) * (strlen(this->str) + strlen(ap->str) + 1));
  res[0] = '\0';
  res = strcat(res, this->str);
  res = strcat(res, ap->str);
  free(this->str);
  this->str = strdup(res);
  free(res);
}

void	append_c(String* this, char const* ap)
{
  char	*res;

  res = malloc(sizeof(char) * (strlen(this->str) + strlen(ap) + 1));
  res[0] = '\0';
  res = strcat(res, this->str);
  res = strcat(res, ap);
  free(this->str);
  this->str = strdup(res);
  free(res);
}

char	at(String* this, size_t pos)
{
  if (strlen(this->str) < pos)
    return (-1);
  return (this->str[pos]);
}
