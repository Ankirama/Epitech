/*
** read.c for read in /home/user/rendu/PSU_2014_myirc
**
** Made by 
** Login   
**
** Started on  Wed Apr  1 10:18:18 2015 
** Last update Wed Apr  1 10:37:57 2015 
*/

#include "utils.h"

int	str_nbr(int nb)
{
  if (nb < 10)
    return (1);
  else
    return (1 + str_nbr(nb / 10));
}

char	*int_to_str(int nb)
{
  char	*s;
  int	i;
  int	size;

  size = str_nbr(nb);
  s = my_malloc(size + 1);
  i = -1;
  s[size] = '\0';
  while (nb >= 10)
    {
      s[size - ++i - 1] = (nb % 10) + '0';
      nb /= 10;
    }
  s[size - ++i - 1] = nb + '0';
  return (s);
}
