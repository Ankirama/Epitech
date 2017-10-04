/*
** nbr.c for nbr in /root/rendu/PSU_2013_minitalk/server
**
** Made by
** Login   <-n@epitech.net>
**
** Started on  Tue Aug  5 00:10:24 2014
** Last update Tue Aug  5 00:19:31 2014
*/

#include "utils.h"

static void	_my_putchar(char c)
{
  my_write(1, &c, 1);
}

void my_putnbr(const int nbr)
{
  if (nbr >= 0 && nbr < 10)
    _my_putchar(nbr + '0');
  else if (nbr < 0 && nbr > -10)
    {
      _my_putchar('-');
      _my_putchar((nbr * -1) + '0');
    }
  else
    {
      my_putnbr(nbr / 10);
      _my_putchar(nbr < 0 ? ((nbr * -1) % 10) + '0' : (nbr % 10) + '0');
    }
}

/*
** brief: Like ATOI
** @str: we will convert this string to an integer
** return: it will return the new integer
*/
int	my_getnbr(const char *str)
{
  int	i;
  int	nbr;

  i = -1;
  while (str[++i])
    {
      if (str[i] < '0' || str[i] > '9')
	{
	  my_write(2, "error: '", 8);
	  my_write(2, &str[i], 1);
	  my_puterror("' is not valid, this world is so bad !\n");
	}
    }
  i = -1;
  nbr = 0;
  while (str[++i] && nbr >= 0)
    nbr = nbr * 10 + (str[i] - '0');
  return (nbr);
}
