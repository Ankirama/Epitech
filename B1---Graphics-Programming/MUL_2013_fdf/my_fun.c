/*
** my_fun.c for my_fun in /home/mar_b/rendu/MUL_2013_fdf
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed May  7 19:10:26 2014 mar_b mar_b
** Last update Fri May  9 11:21:39 2014 mar_b mar_b
*/

#include <stdlib.h>

int	my_intlen(int nbr)
{
  if (nbr < 10)
    return (1);
  else
    return (1 + my_intlen(nbr / 10));
}

int	my_strlen(char *str)
{
  if (str == NULL || !str[0])
    return (0);
  else
    return (1 + my_strlen(&str[1]));
}

int	my_get_nbr(char *str)
{
  if (str[0])
    return ((str[0] - 0) * 10 + my_get_nbr(&str[1]));
  return (0);
}
