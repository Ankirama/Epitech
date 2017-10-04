/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/mar_b/minishell/parser
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 23 16:35:49 2014 mar_b mar_b
** Last update Wed Jul 23 10:21:46 2014 mar_b
*/

#include <stdlib.h>
#include "utils.h"

/*
** brief: this function will count words
** @str: we will find our words here
** @separ1: first separator like " \t" or "::"
** return: we will return the number of words
*/
static int	_my_count(const char *str, const char *separ, int end)
{
  int		i;
  int		nbr;

  nbr = 0;
  i = 0;
  while (str[i] && i < end)
    {
      while (str[i] && i < end && (str[i] == separ[0] || str[i] == separ[1]))
	++i;
      if (str[i] && i < end)
	++nbr;
      while (str[i] && i < end && str[i] != separ[0] && str[i] != separ[1])
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
static int	_my_strlen(const char *str, const char *sep, int end)
{
  int		i;

  i = -1;
  while (++i < end && str[i] && str[i] != sep[0] && str[i] != sep[1]);
  return (i);
}

/*
** brief: like strdup but will fill our dest until sep1, sep2 or '\0'
** @dest: our char * destination
** @src: our src
** @sep1: our separator
** return: return the nbr char pasted
*/
static int	_my_strdup(char *dest, char *src, const char *sep, int end)
{
  int		i;

  i = -1;
  while (++i < end && src[i] && src[i] != sep[0] && src[i] != sep[1])
    dest[i] = src[i];
  dest[i] = '\0';
  return (i);
}

/*
** brief: it will create an char ** and separate each char * with sep1 and sep2
** @str: we will split this char *
** @sep: our separator
** @end: used for the parser, set -1 for other functions
** return: we will return our new array
*/
char	**my_str_to_wordtab(char *str, const char *sep, int end)
{
  char	**arr;
  int	i;
  int	j;

  end = (end != -1) ? end : my_strlen(str);
  if ((arr = malloc(sizeof(char *) *
		    (_my_count(str, sep, end) + 1))) == NULL)
    my_puterror("error: problem to malloc char ** in my_str_to_wordtab.c\n");
  i = 0;
  j = -1;
  while (str[i] && i < end)
    {
      while (str[i] && i < end && (str[i] == sep[0] || str[i] == sep[1]))
	++i;
      if (str[i] != '\0' && i < end)
	{
	  if ((arr[++j] = malloc((_my_strlen(&str[i], sep, end) + 1) *
				 sizeof(char *))) == NULL)
	    my_puterror("error: problem to malloc char * in wordtab\n");
	  i += _my_strdup(arr[j], &str[i], sep, end - i);
	  i = (str[i] == '\0' || i == end) ? i : i + 1;
	}
    }
  arr[++j] = NULL;
  return (arr);
}
