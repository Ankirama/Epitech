/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Fri Mar  6 22:56:39 2015 Fabien Martinez
*/

#include "utils.h"

static int	_nbr_words(char *str)
{
  int		i;
  int		nbr;

  i = -1;
  nbr = 0;
  while (str[++i] != '\0')
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	++i;
      nbr = str[i] != '\0' ? nbr + 1 : nbr;
      while (str[i] && (str[i] != ' ' && str[i] != '\t'))
	++i;
      i = str[i] == '\0' ? i - 1 : i;
    }
  return (nbr);
}

static char	*_strdup(char *str)
{
  int	i;
  int	len;
  char	*dest;

  i = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    ++i;
  len = i;
  if (!(dest = my_malloc(sizeof(char) * (len + 1))))
    return (NULL);
  i = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    {
      dest[i] = str[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}

void	free_wordtab(char **arr)
{
  int	i;

  i = -1;
  if (arr)
    {
      while (arr[++i])
	free(arr[i]);
      free(arr);
    }
}

char	**str_to_wordtab(char *str)
{
  char	**arr;
  int	i;
  int	j;

  if (!(arr = my_malloc(sizeof(char *) * (_nbr_words(str) + 1))))
    return (NULL);
  i = -1;
  j = -1;
  while (str[++i] != '\0')
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	++i;
      if (str[i] != '\0')
	{
	  if (!(arr[++j] = _strdup(&str[i])))
	    return (NULL);
	  while (str[i] && (str[i] != ' ' && str[i] != '\t'))
	    ++i;
	}
      i = str[i] == '\0' ? i - 1 : i;
    }
  arr[++j] = NULL;
  return (arr);
}
