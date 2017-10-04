/*
** nbr.c for let it go in /home/user/rendu/colle1_
**
** Made by 
** Login   
**
** Started on  Tue Aug 26 20:59:51 2014 
** Last update Tue Aug 26 21:08:26 2014 
*/

#include "utils.h"

int	my_getnbr(const char *str)
{
  int	nbr;
  int	i;

  i = 0;
  nbr = 0;
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9' && nbr >= 0)
    {
      nbr = nbr * 10 + str[i] - '0';
      ++i;
    }
  if (str[i] != '\0')
    my_puterror(ERR_NBR);
  return (nbr);
}
