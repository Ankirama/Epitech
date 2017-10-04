/*
** str_to_wordtab.c for  in /home/teyssa_r/rendu/MUL_2013_rtracer/src/parser
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Sun Oct 12 16:00:30 2014 teyssa_r teyssa_r
** Last update Sun Oct 12 22:17:55 2014 charles viterbo
*/

#include <stdlib.h>
#include "utils.h"

/*
** brief : count the number of words
** @str : our string
*/
static int	_nbr_words(const char *str)
{
  int		nbr;
  int		i;

  i = 0;
  nbr = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
	++i;
      if (str[i] != '\0')
	++nbr;
      while (str[i] && str[i] != ' ' && str[i] != '\t')
	++i;
      i = (str[i] == '\0') ? i : i + 1;
    }
  return (nbr);
}

/*
** brief : same as the real function
*/
static int	_strlen(const char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    ++i;
  return (i);
}

/*
** brief : same as the real fonction
*/
static int	_strdup(char *src, char *dest)
{
  int		i;

  i = 0;
  while (src[i] != '\0' && src[i] != ' ' && src[i] != '\t')
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (i);
}

/*
** brief : put a char * in a char **
*/
char	**str_to_wordtab(char *str)
{
  char	**arr;
  int	i;
  int	j;
  int	size;

  size = _nbr_words(str) + 1;
  arr = my_malloc(sizeof(char *) * size);
  i = 0;
  j = -1;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
	++i;
      if (str[i] != '\0')
	{
	  arr[++j] = my_malloc(sizeof(char) * (_strlen(&str[i]) + 1));
	  i += _strdup(&str[i], arr[j]);
	}
      i = (str[i] == '\0') ? i : i + 1;
    }
  arr[++j] = NULL;
  return (arr);
}
