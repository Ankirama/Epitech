/*
** String.c for class in /home/mar_b/rendu/piscine_cpp_d03/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jan  9 09:44:20 2015 Fabien Martinez
** Last update Sat Jan 10 00:53:28 2015 Fabien Martinez
*/

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "String.h"

static void		assign_s(String *this, String const * str);
static void		assign_c(String *this, char const * s );
static char		at(String* this, size_t pos);
static void		append_s(String* this, String const* ap);
static void		append_c(String* this, char const* ap);
static void		clear(String* this);
static int		size(String* this);
static int		compare_s(String *this, const String* str);
static int		compare_c(String *this, char const* str);
static size_t		copy(String* this, char* s, size_t n, size_t pos);
static char const*	c_str (String * this);
static int		empty (String* this);
static int		find_s (String* this, const String *str, size_t pos);
static int		find_c (String* this, char const* str, size_t pos);
static void		insert_c(String * this, size_t pos, char const* str);
static void		insert_s(String * this, size_t pos, String const* str);
static int		to_int(String * this);
static String*		split_s(String* this, char separator);
static char**		split_c(String* this, char separator);
static void		aff(String * this);
static void		join_c(String* this, char delim, char const** tab);
static void		join_s(String* this, char delim, String* tab);

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
  this->copy = &copy;
  this->c_str = &c_str;
  this->empty = &empty;
  this->find_s = &find_s;
  this->find_c = &find_c;
  this->insert_c = &insert_c;
  this->insert_s = &insert_s;
  this->to_int = &to_int;
  this->split_s = &split_s;
  this->split_c = &split_c;
  this->aff = &aff;
  this->join_c = &join_c;
  this->join_s = &join_s;
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

size_t	copy(String* this, char* s, size_t n, size_t pos)
{
  s = strncpy(s, &this->str[pos], n);
  return (strlen(s) < n ? strlen(s) : n);
}

char const*	c_str (String * this)
{
  return (this->str);
}

int	empty (String* this)
{
  return ((this == NULL || this->str == NULL || this->str[0] == '\0') ? 1 : -1);
}

int	find_s (String* this, const String *str, size_t pos)
{
  int	i;
  int	j;

  if (pos >= strlen(this->str))
    return (-1);
  i = pos - 1;
  while (this->str[++i] != '\0')
    {
      if (this->str[i] == str->str[0])
	{
	  j = 0;
	  while (this->str[i + j] != '\0' && str->str[j] != '\0' && this->str[i + j] == str->str[j])
	    ++j;
	  if (str->str[j] == '\0')
	    return (i);
	  if (this->str[i + j] == '\0')
	    return (-1);
	}
    }
  return (-1);
}

int	find_c (String* this, char const* str, size_t pos)
{
  int	i;
  int	j;

  if (pos >= strlen(this->str))
    return (-1);
  i = pos - 1;
  while (this->str[++i] != '\0')
    {
      if (this->str[i] == str[0])
	{
	  j = 0;
	  while (this->str[i + j] != '\0' && str[j] != '\0' && this->str[i + j] == str[j])
	    ++j;
	  if (str[j] == '\0')
	    return (i);
	  if (this->str[i + j] == '\0')
	    return (-1);
	}
    }
  return (-1);
}

void		insert_c(String * this, size_t pos, char const* str)
{
  char		*res;
  size_t	i;
  size_t	j;

  if (pos > strlen(this->str))
    pos = strlen(this->str);
  res = malloc(sizeof(char) * (strlen(this->str) + strlen(str) + 1));
  i = -1;
  while (++i < pos)
    res[i] = this->str[i];
  j = -1;
  while (str[++j] != '\0')
    {
      res[i] = str[j];
      ++i;
    }
  j = pos - 1;
  while (this->str[++j] != '\0')
    {
      res[i] = this->str[j];
      ++i;
    }
  res[i] = '\0';
  free(this->str);
  this->str = strdup(res);
  free(res);
}

void		insert_s(String * this, size_t pos, String const* str)
{
  char		*res;
  size_t	i;
  size_t	j;

  if (pos > strlen(this->str))
    pos = strlen(this->str);
  res = malloc(sizeof(char) * (strlen(this->str) + strlen(str->str) + 1));
  i = -1;
  while (++i < pos)
    res[i] = this->str[i];
  j = -1;
  while (str->str[++j] != '\0')
    {
      res[i] = str->str[j];
      ++i;
    }
  j = pos - 1;
  while (this->str[++j] != '\0')
    {
      res[i] = this->str[j];
      ++i;
    }
  res[i] = '\0';
  free(this->str);
  this->str = strdup(res);
  free(res);
}

int	to_int(String * this)
{
  return (atoi(this->str));
}

String*		split_s(String* this, char separator)
{
  String	*array;
  int		i;
  char		*s;
  int		occu;

  i = -1;
  occu = 0;
  while (this->str[++i] != '\0')
    occu = this->str[i] == separator ? occu + 1 : occu;
  array = malloc(sizeof(*array) * (occu + 2));
  i = -1;
  s = strtok(this->str, &separator);
  while (s != NULL)
    {
      StringInit(&(array[++i]), s);
      s = strtok(NULL, &separator);
    }
  StringInit(&(array[i++]), "\0");
  return (array);
}

char**		split_c(String* this, char separator)
{
  char	**rslt;
  int	i;
  char	*s;
  int	occu;

  i = -1;
  occu = 0;
  while (this->str[++i] != '\0')
    occu = this->str[i] == separator ? occu + 1 : occu;
  rslt = malloc(sizeof(char *) * (occu + 2));
  i = -1;
  s = strtok(this->str, &separator);
  while (s != NULL)
    {
      rslt[++i] = strdup(s);
      s = strtok(NULL, &separator);
    }
  rslt[++i] = NULL;
  return (rslt);
}

void	aff(String * this)
{
  write(1, this->str, strlen(this->str));
}

void	join_c(String* this, char delim, char const** tab)
{
  int	glob_size;
  int	i;

  i = -1;
  glob_size = 0;
  while (tab[++i] != NULL)
    glob_size += strlen(tab[i]);
  this->str = malloc(sizeof(char) * (glob_size + 1 + (i * delim)));
  i = -1;
  while (tab[++i] != NULL)
    {
      this->str = strcat(this->str, tab[i]);
      if (tab[i + 1] != NULL)
	{
	  this->str[strlen(this->str)] = delim;
	  this->str[strlen(this->str) + 1] = '\0';
	}
      else
	this->str[strlen(this->str)] = '\0';
    }
}

void	join_s(String* this, char delim, String* tab)
{
  int	glob_size;
  int	i;

  i = -1;
  glob_size = 0;
  while (tab[++i].str != NULL && tab[++i].str[0] != '\0')
    glob_size += strlen(tab[i].str);
  this->str = malloc(sizeof(char) * (glob_size + 1 + (i * delim)));
  i = -1;
  while (tab[++i].str != NULL && tab[++i].str[0] != '\0')
    {
      this->str = strcat(this->str, tab[i].str);
      if (tab[i + 1].str != NULL && tab[i + 1].str[0] != '\0')
	{
	  this->str[strlen(this->str)] = delim;
	  this->str[strlen(this->str) + 1] = '\0';
	}
      else
	this->str[strlen(this->str)] = '\0';
    }
}
