/*
** duparray.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src/utils
**
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
**
** Started on  Thu Oct  2 22:06:49 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 22:18:52 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

char	**dup_array(char **arr)
{
  int	i;
  char	**tmp;

  if (arr != NULL)
    {
      i = 0;
      if ((tmp = malloc(sizeof(char *) * (my_arrlen(arr) + 1))) == NULL)
	return (my_puterror_null(ERR_MALLOC));
      while (arr[i] != NULL)
	{
	  tmp[i] = my_strdup(arr[i]);
	  i++;
	}
      tmp[i] = NULL;
      return (tmp);
    }
  else
    return (NULL);
}
