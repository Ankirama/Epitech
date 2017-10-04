/*
** my_putnbr.c for my_putstr in /home/mar_b/rendu/PSU_2014_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Apr 11 15:37:23 2014 Fabien Martinez
** Last update Sun Apr 20 22:24:29 2014 Fabien Martinez
*/

#include <unistd.h>
#include <stdarg.h>
#include "my_printf.h"

/*
** Recursive function called by my_putnbr_un
*/
int	my_putnbr_un_rec(unsigned long int nbr)
{
  if (nbr < 10)
    return (my_putchar_c(nbr + '0'));
  else
    return (my_putnbr_un_rec(nbr / 10) + my_putchar_c(nbr % 10 + '0'));
}

/*
** Recursive function used in signed my_putnbr_*
*/
int	my_putnbr_sign(long int nbr)
{
  if ((nbr < 10 && nbr >= 0) || (nbr < 0 && nbr * -1 < 10))
    return (my_putchar_c(nbr < 0 ? (nbr * -1) + '0' : nbr + '0'));
  else
    {
      return (my_putnbr_sign(nbr / 10) +
	      my_putchar_c(nbr < 0 ? (nbr * -1) % 10 + '0' : nbr % 10 + '0'));
    }
}

/*
** called by my_putnbr_base_* except my_putnbr_base_p
** Recursive function which will search the good char in the base
*/
int	my_putnbr_base(unsigned long int nbr, char *base, int len)
{
  if (nbr / len == 0)
    return (my_putchar_c(base[nbr]));
  else
    return (my_putnbr_base(nbr / len, base, len) +
	    my_putchar_c(base[nbr % len]));
}

/*
** This function will display our number with .
*/
int	my_putnbr_rec_double(double nbr, int prec)
{
  if (prec == 0)
    return (my_putnbr_rec_double(nbr / 10, prec - 1) +
	    my_putchar_c((nbr - ((long)nbr / 10 * 10)) + '0') +
	    my_putchar_c('.'));
  else if (nbr < 10)
    {
      if (nbr < 1)
	return (0);
      return (my_putchar_c((long)nbr + '0'));
    }
  else
    return (my_putnbr_rec_double(nbr / 10, prec - 1) +
	    my_putchar_c((nbr - ((long)nbr / 10 * 10)) + '0'));
}
