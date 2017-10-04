/*
** my_len.c for my_len in /home/mar_b/rendu/Piscine-C-Jour_06/ex_15
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 14:05:01 2014 Fabien Martinez
** Last update Sat Apr 19 12:27:44 2014 Fabien Martinez
*/

#include <stdlib.h>
#include <string.h>

/*
** Calculate length to long/int
*/
int	my_nbrlen(long nbr)
{
  if (nbr < 10 && nbr >= 0)
    return (1);
  else if (nbr < 0 && nbr * -1 < 10)
    return (2);
  else
    return (1 + my_nbrlen(nbr / 10));
}

/*
** Calculate length to char*
*/
int	my_strlen(char *str)
{
  if (str == NULL || str[0] == '\0')
    return (0);
  else
    return (strlen(str));
}

/*
** Calculate length to anybase
*/
int	my_baselen(unsigned long int nbr, int len)
{
  if (nbr / len == 0)
    return (1);
  else
    return (1 + my_baselen(nbr / len, len));
}
