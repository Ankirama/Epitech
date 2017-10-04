/*
** my_convert.c for my_conv in /home/mar_b/rendu/MUL_2013_fdf
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed May  7 12:52:54 2014 mar_b mar_b
** Last update Fri May  9 11:23:15 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_fun.h"
#include "my_display.h"

static int	mp(int a, int e)
{
  if (e == 0)
    return (1);
  else
    return (a * mp(a, e - 1));
}

static int	fun(char *nbr, int p)
{
  char		*a;

  if (p == 0)
    {
      if (nbr[0] >= 'A' && nbr[0] <= 'F')
	return (nbr[0] - 'A' + 10);
      return (nbr[0] - '0');
    }
  else
    {
      a = &(nbr[1]);
      if (nbr[0] >= 'A' && nbr[0] <= 'F')
	 return ((nbr[0] - 'A' + 10) * mp(16, p) + fun(a, p - 1));
      return ((nbr[0] - '0') * mp(16, p) + fun(&(nbr[1]), p - 1));
    }
}

static int	my_getnbr_base(char *str)
{
  int		power;

  power = 0;
  while (str[power] != '\0')
    power += 1;
  return (fun(str, power - 1));
}

char	*my_conv_hexa(char *str)
{
  int	nbr;
  int	i;
  int	len;

  nbr = my_getnbr_base(&str[2]);
  free(str);
  len = my_intlen(nbr);
  i = len - 1;
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    my_puterror(0, 0);
  while (i >= 0)
    {
      str[i] = nbr % 10 + '0';
      i -= 1;
      nbr /= 10;
    }
  str[len] = '\0';
  return (str);
}
