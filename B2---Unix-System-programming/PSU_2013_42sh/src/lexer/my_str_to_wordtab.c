/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/mar_b/minishell/parser
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 23 16:35:49 2014 mar_b mar_b
** Last update Thu Oct  2 18:26:48 2014 teyssa_r teyssa_r
*/

#include <stdlib.h>
#include "utils.h"

/*
** brief: this function will count words
** @str: we will find our words here
** @separ1: first separator like " \t" or "::"
** return: we will return the number of words
*/
static int	_my_count(const char *str, int end, int nbr)
{
  int		i;

  i = 0;
  while (str[i] && i < end)
    {
      while (str[i] && i < end  && (str[i] == ' ' ||
				    str[i] == '\t'))
	++i;
      if (str[i] && i < end)
	++nbr;
      while (str[i] && i < end &&
	     str[i] != ' ' && str[i] != '\t')
	++i;
      i = (str[i] == '\0' || i == end) ? i : i + 1;
    }
  return (nbr);
}

/*
** brief: like strlen but will count until sep1, sep2 or '\0'
** @str: strlen(str)
** @sep1, @sep2: our separators
** return: return the size
*/
static int	_my_strlen(const char *str, int end, int i)
{
  int		len;

  len = 0;
  while (i < end && str[i] && str[i] != ' ' && str[i] != '\t')
    {
      ++len;
      ++i;
    }
  return (len);
}

/*
** brief: like strdup but will fill our dest until sep1, sep2 or '\0'
** @dest: our char * destination
** @src: our src
** @end: the end of our travel
** @begin: to check if we can check i - 1
** return: return the nbr char pasted
*/
static void	_my_strdup(char *dest, char *src, int end, int *begin)
{
  int		i;
  int		j;

  i = *begin;
  j = 0;
  while (i < end && src[i] != '\0' && src[i] != ' ' && src[i] != '\t')
    {
      dest[j] = src[i];
      ++j;
      ++i;
    }
  dest[j] = '\0';
  *begin = i;
}

/*
** brief: it will create an char ** and separate each char * with sep1 and sep2
** @str: we will split this char *
** @end: used for the parser, set -1 for other functions
** @i, j: variable used for the fuckin' norme, i = 0, j = -1
** return: we will return our new array
*/
char	**my_str_to_wordtab(char *str, int end, int i, int j)
{
  char	**arr;
  int	len;

  if ((arr = malloc(sizeof(char *) * (_my_count(str, end, 0) + 1))) == NULL)
    return (my_puterror_null(ERR_MALLOC));
  while (str[i] && i < end)
    {
      len = -1;
      while (str[i] && i < end && (str[i] == ' ' || str[i] == '\t'))
	++i;
      if (str[i] != '\0' && i < end && (len = _my_strlen(str, end, i)) > 0)
	{
	  if ((arr[++j] = malloc((len + 1) * sizeof(char))) == NULL)
	    return (my_puterror_null(ERR_MALLOC));
	  _my_strdup(arr[j], str, end, &i);
	  i = (str[i] == '\0' || i == end) ? i : i + 1;
	}
      else if (len == 0)
	++i;
    }
  arr[++j] = NULL;
  return (arr);
}
