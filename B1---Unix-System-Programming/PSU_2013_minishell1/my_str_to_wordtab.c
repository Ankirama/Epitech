/*
** my_str_to_wordtab.c for str_to_wordtab in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 16 03:40:04 2014 mar_b mar_b
** Last update Sun Jun 22 17:04:55 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_error.h"
#include "my_fun.h"

/*
** brief: special my_strlen because we will calculate the size until end char
** @str: we will calculate this char * size
** @end: the limit
** @end: the limit
** return: we will return the size
*/
static int	_my_strlen(const char *str, char end, char end1)
{
  int		i;

  i = -1;
  while (str[++i] && str[i] != end && str[i] != end1);
  return (i);
}

/*
** brief: it will count the end value
** @path: we will check this char *
** @end: allow us to delimitate each value
** @end: allow us to delimitate each value
** return: we will return the number
*/
static	int	_my_nbr_words(const char *str, char end, char end1)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      while (str[i] && (str[i] == end || str[i] == end1))
	++i;
      count = (str[i] && str[i] != end && str[i] != end1) ? count + 1 : count;
      while (str[i] && str[i] != end && str[i] != end1)
	++i;
      i = str[i] == '\0' ? i : i + 1;
    }
  return (count);
}

/*
** brief: we will copy the src into our copy
** @cpy: this char * will receive the copy
** @src: this is the source char *
** @end: we will copy until end char
** @end1: we will copy until end char
** return: we will return the position where we found our end char
*/
static	int	_my_strdup(char *cpy, const char *src, char end, char end1)
{
  int		i;
  int		j;

  i = -1;
  j = 0;
  while (src[j] && (src[j] == end || src[j] == end1))
    ++j;
  while (src[j] && src[j] != end && src[j] != end1)
    {
      cpy[++i] = src[j];
      j++;
    }
  cpy[++i] = '\0';
  return (j);
}

/*
** brief: we will convert our char * into a char **
** @path: our char * we will convert
** return: we will return our new value with each value
*/
char	**my_str_to_wordtab(char *path, char end, char end1)
{
  char	**array;
  int	size;
  int	i;
  int	j;

  size = _my_nbr_words(path, end, end1);
  if (size == 0)
    return (NULL);
  if ((array = malloc(sizeof(char *) * (size + 1))) == NULL)
    my_puterror("error: problem to malloc array in my_str_to_wordtab.c: l91\n");
  i = 0;
  j = -1;
  while (path[i])
    {
      if ((array[++j] = malloc(sizeof(char) * _my_strlen(&path[i], end, end1)))
	  == NULL)
	my_puterror("error: problem to malloc in my_str_to_wordtab.c: l98!\n");
      i += _my_strdup(array[j], &path[i], end, end1);
      i = (path[i] == '\0') ? i : i + 1;
    }
  array[++j] = NULL;
  return (array);
}
