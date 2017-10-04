/*
** String.c for class in /home/mar_b/rendu/piscine_cpp_d03/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jan  9 09:44:20 2015 Fabien Martinez
** Last update Fri Jan  9 12:06:28 2015 Fabien Martinez
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
static void	clear(String* this);
static int	size(String* this);
static int	compare_s(String *this, const String* str);
static int	compare_c(String *this, char const* str);

void StringInit(String* this, char const * s)
{
  this->str = strdup(s);
  this->assign_c = &assign_c;
  this->assign_s = &assign_s;
  this->at = &at;
  this->append_s = &append_s;
  this->append_c = &append_c;
  this->clear = &clear;
  this->size = &size;
  this->compare_s = &compare_s;
  this->compare_c = &compare_c;
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

void	clear(String* this)
{
  int	i;
  int	length;

  i = -1;
  length = strlen(this->str);
  while (++i < length)
    this->str[i] = '\0';
}

int	size(String* this)
{
  if ((this == NULL || this->str == NULL))
    return (-1);
  else
    return (strlen(this->str));
}

int	compare_s(String *this, const String* str)
{
  return (strcmp(this->str, str->str));
}

int	compare_c(String *this, char const* str)
{
  return (strcmp(this->str, str));
}
