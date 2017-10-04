/*
** nbr.c for let it go in /home/mar_b/rendu/colle4_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 16 20:11:03 2014 mar_b mar_b
** Last update Tue Sep 16 20:16:35 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <time.h>
#include "utils.h"

int		my_rand_nbr(int nbr_cases)
{
  int		random;
  time_t	my_time;

  my_time = time(NULL);
  srand(my_time + rand());
  random = rand() % nbr_cases;
  return (random);
}

int	my_power(int nbr, int power)
{
  if (power == 0)
    return (1);
  else
    return (nbr * my_power(nbr, power - 1));
}

int	my_nbr_size(int nbr)
{
  int	size;

  size = 1;
  while (nbr != 0)
    {
      nbr /= 10;
      ++size;
    }
  return (size);
}

int    	my_getnbr(const char *str)
{
  int	nbr;
  int  	i;

  i = 0;
  nbr = 0;
  while (str[i] >= '0' && str[i] <= '9' && nbr >= 0)
    {
      nbr = ((nbr * 10) + (str[i] - '0'));
      i = i + 1;
    }
  if (nbr < 0)
    my_puterror(ERR_NBR_SIZE);
  else if (str[i] != '\0')
    my_puterror(ERR_NBR);
  return (nbr);
}
