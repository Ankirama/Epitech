/*
** my_str.c for my_str in /home/mar_b/rendu/Piscine-C-eval_expr
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Mar 27 20:57:24 2014 Fabien Martinez
** Last update Sun Mar 30 11:23:56 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "my.h"

char	*my_sub_string(char *str, int begin, int end)
{
  char	*my_sub;
  int	i;

  i = 0;
  my_sub = malloc((end - begin) * sizeof(char));
  begin += 1;
  while (begin < end)
    {
      my_sub[i] = str[begin];
      begin += 1;
      i += 1;
    }
  my_sub[i] = '\0';
  return (my_sub);
}

char	*my_start_string(char *str, char *start, char *nbr, int begin)
{
  int	i;
  int	j;

  i = 0;
  while (str[i] != 0 && i < begin)
    {
      start[i] = str[i];
      i += 1;
    }
  start[i] = ' ';
  j = 0;
  i += 1;
  while (nbr[j] != 0)
    {
      start[i] = nbr[j];
      i += 1;
      j += 1;
    }
  start[i + 1] = '\0';
  return (start);
}

char	*my_newstring(char *str, char *nbr, int begin, int end)
{
  char	*my_start;
  char	*my_end;
  int	i;

  my_start = malloc((my_strlen(str) + my_strlen(nbr)) * sizeof(char) + 3);
  my_start = my_start_string(str, my_start, nbr, begin);
  my_end = malloc(my_strlen(str));
  i = 0;
  while (str[end + i + 1] != 0)
    {
      my_end[i] = str[end + i + 1];
      i += 1;
    }
  my_end[i] = '\0';
  return (my_strcat(my_start, my_end));
}
