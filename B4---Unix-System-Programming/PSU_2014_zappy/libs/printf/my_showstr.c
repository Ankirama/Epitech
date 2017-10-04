/*
** my_showstr.c for my_showstr in /home/mar_b/rendu/Piscine-C-Jour_06/ex_17
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 19:25:33 2014 Fabien Martinez
** Last update Sun Apr 20 16:54:21 2014 Fabien Martinez
*/

#include <stdarg.h>
#include "my_printf.h"

int	my_showstr(va_list *ap, t_flag_opt *flag_opt)
{
  int	i;
  int	count;
  char	*str;

  (void)flag_opt;
  str = va_arg(*ap, char *);
  count = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= ' ' && str[i] <= '~')
	count += my_putchar_c(str[i]);
      else
	{
	  count += my_putchar_c('\\');
	  if (str[i] < 8)
	    count += my_putchar_c('0');
	  if (str[i] < 64)
	    count += my_putchar_c('0');
	  count += my_putnbr_base(str[i], "01234567", 8);
	}
      i += 1;
    }
  return (count);
}
