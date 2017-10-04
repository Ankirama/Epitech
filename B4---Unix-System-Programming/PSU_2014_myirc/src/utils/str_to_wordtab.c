/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** *
* Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Fri Mar  6 22:56:39 2015 Fabien Martinez
*/

#include "utils.h"

static int	_nbr_words(char *str, char sep1, char sep2)
{
  int		i;
  int		nbr;

  i = -1;
  nbr = 0;
  while (str[++i] != '\0')
    {
      while (str[i] && (str[i] == sep1))
	++i;
      nbr = str[i] != '\0' ? nbr + 1 : nbr;
      while (str[i] && (str[i] != sep1 && str[i] != sep2))
	++i;
      i = str[i] == '\0' ? i - 1 : i;
    }
  return (nbr);
}

static char	*_strdup(char *str, char sep1, char sep2)
{
  int	i;
  int	len;
  char	*dest;

  i = 0;
  while (str[i] != '\0' && str[i] != sep1 && str[i] != sep2)
    ++i;
  len = i;
  if (!(dest = my_malloc(sizeof(char) * (len + 1))))
    return (NULL);
  i = 0;
  while (str[i] != '\0' && str[i] != sep1 && str[i] != sep2)
    {
      dest[i] = str[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

int	array_len(char **array)
{
  int	i;
  int	size;

  i = 0;
  size = 0;
  if (!array)
    return (size);
  while (array[i] != NULL)
    {
      size += strlen(array[i]);
      ++i;
    }
  return (size);
}

void	free_wordtab(char **arr)
{
  int	i;

  i = 0;
  if (arr)
    {
      while (arr[i] != NULL)
	{
	  free(arr[i]);
	  ++i;
	}
      free(arr);
    }
}

/*
** brief: it will create array's token from a str
** @str: str like "couocu c'est moi ton pere hahaha"
** @sep1: separator like ' ' or '\t' etc...
** @sep2: separator like ' ' or '\t' etc...
** return: array with each token
*/
char	**str_to_wordtab(char *str, char sep1, char sep2)
{
  char	**arr;
  int	i;
  int	j;

  if (!(arr = my_malloc(sizeof(char *) * (_nbr_words(str, sep1, sep2) + 1))))
    return (NULL);
  i = -1;
  j = -1;
  while (str[++i] != '\0')
    {
      while (str[i] && (str[i] == sep1 || str[i] == sep2))
	++i;
      if (str[i] != '\0')
	{
	  if (!(arr[++j] = _strdup(&str[i], sep1, sep2)))
	    return (NULL);
	  while (str[i] && (str[i] != sep1 && str[i] != sep2))
	    ++i;
	}
      i = str[i] == '\0' ? i - 1 : i;
    }
  arr[++j] = NULL;
  return (arr);
}
