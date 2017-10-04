/*
** nbr.c for nbr in /home/mar_b/colle_06_HBX_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 30 19:15:38 2014 mar_b mar_b
** Last update Tue Sep 30 20:23:15 2014 mar_b mar_b
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
