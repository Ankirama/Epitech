/*
** my_str_ap.c for my_str_ap in /home/mar_b/rendu/PSU_2014_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Apr 14 20:10:12 2014 Fabien Martinez
** Last update Sun Apr 20 16:52:22 2014 Fabien Martinez
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"

/*
** convert to unsigned char va_arg(ap) and print the char
*/
int	my_putchar(va_list *ap, t_flag_opt *flag_opt)
{
  char	c;
  int	space_zero;
  int	len;

  space_zero = 0;
  c = (unsigned char)va_arg(*ap, int);
  if (!flag_opt->minus && (flag_opt->zero != 0 || flag_opt->number != 0))
    {
      space_zero = my_add_space_zero(1,
				     flag_opt->zero + flag_opt->number, ' ');
    }
  else if (flag_opt->minus && (flag_opt->zero != 0 || flag_opt->number != 0))
    {
      space_zero = write(1, &c, 1) +
	my_add_space_zero(1, flag_opt->zero + flag_opt->number, ' ');
      my_init_opt(flag_opt);
      return (space_zero);
    }
  my_init_opt(flag_opt);
  return (space_zero + write(1, &c, 1));
}

int	my_putmod(va_list *ap, t_flag_opt *flag_opt)
{
  (void)*ap;
  (void)flag_opt;
  return (my_putchar_c('%'));
}

/*
** print the char * from va_arg(ap), print (null) if char * == NULL
*/
int	my_putstr(va_list *ap, t_flag_opt *flag_opt)
{
  char	*str;
  int	space_zero;

  space_zero = 0;
  str = va_arg(*ap, char *);
  if (str == NULL)
    return (write(1, "(null)", 6));
  if (!flag_opt->minus && (flag_opt->zero != 0 || flag_opt->number != 0))
    {
      space_zero = my_add_space_zero(my_strlen(str),
				     flag_opt->zero + flag_opt->number, ' ');
    }
  else if (flag_opt->minus && (flag_opt->zero != 0 || flag_opt->number != 0))
    {
      space_zero += write(1, str, my_strlen(str));
      space_zero += my_add_space_zero(my_strlen(str),
				     flag_opt->number + flag_opt->zero, ' ');
      my_init_opt(flag_opt);
      return (space_zero);
    }
  my_init_opt(flag_opt);
  return (space_zero + write(1, str, my_strlen(str)));
}
