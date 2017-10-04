/*
** nbr.c for nbr in /home/user/colle_06_HBX_
**
** Made by 
** Login   
**
** Started on  Tue Sep 30 19:15:38 2014 
** Last update Tue Sep 30 20:23:15 2014 
*/

#include "utils.h"

void	my_putnbr(unsigned int nbr)
{
  if (nbr < 10)
    my_putchar(nbr + '0');
  else
    {
      my_putnbr(nbr / 10);
      my_putchar(nbr % 10 + '0');
    }
}
