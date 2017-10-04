/*
** str_to_wordtab.c for utils in /home/mar_b/rendu/CPE_2014_corewar/asm
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Aug 21 13:20:33 2014 mar_b mar_b
** Last update Thu Aug 21 13:20:34 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"

/*
** brief: this function will count words separate by ' ' and '\t'
** @str: we will find our words here
** @sep: our separator
** @stop: the comment char (like #)
** return: we will return the number of words
*/
static int	_my_count(const char *str, char sep, char stop)
{
  int		i;
  int		nbr;

  nbr = 0;
  i = 0;
  while (str[i] && str[i] != stop)
    {
      while (str[i] && str[i] != stop &&
	     (str[i] == ' ' || str[i] == '\t' || str[i] == sep))
	++i;
      if (str[i] && str[i] != stop)
	++nbr;
      while (str[i] && str[i] != stop && str[i] != ' ' &&
	     str[i] != '\t' && str[i] != sep)
	++i;
      i = (str[i] == '\0' || str[i] == stop) ? i : i + 1;
    }
  return (nbr);
}

/*
** brief: like strlen but will count until ' ', '\t' or '\0'
** @str: strlen(str)
** @sep: our separator
** @stop: the comment char (like #)
** return: return the size
*/
static int	_my_strlen(const char *str, char sep, char stop)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != stop && str[i] != ' ' &&
	 str[i] != '\t' && str[i] != sep)
    ++i;
  return (i);
}

/*
** brief: like strdup but will fill our dest until sep1, sep2 or '\0'
** @dest: our char * destination
** @src: our src
** @sep: our separator
** @stop: the comment char (like #)
** return: return the nbr char pasted
*/
static int	_my_strdup(char *dest, char *src, char sep, char stop)
{
  int		i;

  i = -1;
  while (src[++i] && src[i] != stop && src[i] != ' ' &&
	 src[i] != '\t' && src[i] != sep)
    dest[i] = src[i];
  dest[i] = '\0';
  return (i);
}

/*
** brief: it will create an char ** and separate each char * with sep
** @str: we will split this char *
** @sep: our separator
** @stop: the comment char (like #)
** return: we will return our new array
*/
char	**my_str_to_wordtab(char *str, char sep, char stop)
{
  char	**arr;
  int	i;
  int	j;

  arr = my_malloc(sizeof(char *) * (_my_count(str, sep, stop) + 1));
  i = 0;
  j = -1;
  while (str[i] && str[i] != stop)
    {
      while (str[i] && str[i] != stop &&
	     (str[i] == ' ' || str[i] == '\t' || str[i] == sep))
	++i;
      if (str[i] != '\0' && str[i] != stop)
	{
	  arr[++j] = my_malloc((_my_strlen(&str[i], sep, stop) + 1)
			       * sizeof(char *));
	  i += _my_strdup(arr[j], &str[i], sep, stop);
	  i = (str[i] == '\0' || str[i] == stop) ? i : i + 1;
	}
    }
  arr[++j] = NULL;
  return (arr);
}
