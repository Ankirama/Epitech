/*
** my_nbr.c for my_nbr in /home/mar_b/rendu/Piscine-C-Jour_11/do-op
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 24 15:04:01 2014 Fabien Martinez
** Last update Mon Mar 24 16:36:33 2014 Fabien Martinez
*/

#include "my_fun.h"

int		my_bool_int(unsigned int nbr, char bool)
{
  unsigned int	max;
  unsigned int	min;

  max = 2147483647;
  min = 2147483648;
  if ((nbr > max && bool != 1) || (nbr > min && bool == 1))
    {
      return (1);
    }
  return (0);
}

int		my_getnbr(char *str)
{
  int		i;
  unsigned int	nbr;
  int		less;

  less = 0;
  nbr = 0;
  i = 0;
  if (my_strlen(str) > 11)
    return (0);
  while (str[i] != 0 && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
	less += 1;
      i += 1;
    }
  while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10 + (*(str + i) - '0');
      if (my_bool_int(nbr, less % 2) == 1)
	return (0);
      i += 1;
    }
  if (less % 2 == 1 && nbr <= 2147483648)
    return (-nbr);
  return (nbr);
}

void	rec_my_put_nbr(unsigned int nbr)
{
   if (nbr <= 9)
    {
      my_putchar('0' + nbr);
    }
  else
    {
      rec_my_put_nbr(nbr / 10);
      my_putchar ('0' + (nbr % 10));
    }
}

void	my_put_nbr(int nbr)
{
  if (nbr < 0)
    {
      my_putchar('-');
      rec_my_put_nbr(-nbr);
    }
  else
    rec_my_put_nbr(nbr);
}
