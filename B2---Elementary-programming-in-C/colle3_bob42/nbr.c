/*
** nbr.c for nbr in /home/mar_b/rendu/colle3_bob42
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep  9 21:02:43 2014 mar_b mar_b
** Last update Tue Sep  9 22:52:10 2014 mar_b mar_b
*/

#include "calc.h"
#include "utils.h"

static void	my_putchar(char c)
{
  my_write(1, &c, 1);
}

void	my_put_nbr(int nb)
{
  if (nb < 0 && nb > -10)
    {
      my_putchar('-');
      my_putchar((nb * -1) + '0');
    }
  else if (nb < 10 && nb >= 0)
    my_putchar(nb + '0');
  else
    {
      my_put_nbr(nb / 10);
      my_putchar((nb < 0) ? (nb * -1 % 10) + '0' : nb % 10 + '0');
    }
}

int	my_getnbr(const char *str, int limit)
{
  int	nbr;
  int	i;

  nbr = 0;
  i = str[0] == '_' ? 1 : 0;
  limit = (i == 1) ? limit + 1 : limit;
  if (str[limit - 1] < '0' || str[limit - 1] > '9')
    --limit;
  if (i == 1)
    {
      while (str[i] != '\0' && i < limit && str[i] >= '0' && str[i] <= '9')
	{
	  nbr = ((nbr * 10) - (str[i] - '0'));
	  i = i + 1;
	}
    }
  else
    {
      while (str[i] != '\0' && i < limit && str[i] >= '0' && str[i] <= '9')
	{
	  nbr = ((nbr * 10) + (str[i] - '0'));
	  i = i + 1;
	}
    }
  return (nbr);
}

int	size_nbr(int nbr)
{
  if ((nbr < 10 && nbr >= 0) || (nbr < 0 && nbr >= -9))
    return (1);
  else
    return (1 + size_nbr(nbr / 10));
}
