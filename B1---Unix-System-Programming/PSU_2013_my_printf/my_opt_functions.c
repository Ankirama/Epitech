/*
** my_opt_functions.c for my_opt_func in /home/mar_b/rendu/PSU_2013_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Apr 18 14:33:06 2014 Fabien Martinez
** Last update Sun Apr 20 11:41:17 2014 Fabien Martinez
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_printf.h"

/*
** This function will add space, 0 or 0x/0 for any base
*/
int	my_opt_base(t_flag_opt *flag_opt, char *str, int len)
{
  int	space_zero;

  space_zero = 0;
  if (flag_opt->minus == 0 && flag_opt->number != 0)
    space_zero += my_add_space_zero(len + flag_opt->sharp * my_strlen(str),
				    flag_opt->number, ' ');
  if (str != NULL && flag_opt->sharp == 1)
    space_zero += write(1, str, my_strlen(str));
  if (!flag_opt->minus && flag_opt->zero != 0)
    space_zero += my_add_space_zero(len + space_zero, flag_opt->zero, '0');
  return (space_zero);
}

int	my_opt_pointer(t_flag_opt *flag_opt, int len)
{
  int	space_zero;

  space_zero = 2 + flag_opt->space + flag_opt->plus;
  if (flag_opt->minus == 0 && flag_opt->number)
    space_zero += my_add_space_zero(len + space_zero,
				    flag_opt->number, ' ');
  else if (flag_opt->space)
    write(1, " ", 1);
  if (flag_opt->plus)
    write(1, "+", 1);
  write(1, "0x", 2);
  if (!flag_opt->minus && flag_opt->zero)
    space_zero += my_add_space_zero(len + space_zero, flag_opt->zero, '0');
  return (space_zero);
}

/*
** This function will add space, 0 or 0x/0 for any number
*/
int	my_opt_nbr(t_flag_opt *flag_opt, char minus, int *len)
{
  int	space_zero;

  space_zero = ((flag_opt->plus || flag_opt->space) && minus == 0) ? 1 : 0;
  *len += space_zero;
  if (flag_opt->minus == 0 && flag_opt->number != 0)
    space_zero += my_add_space_zero(*len, flag_opt->number, ' ');
  if (minus)
    my_putchar_c('-');
  if (!minus && flag_opt->plus)
    my_putchar_c('+');
  else if (!minus && flag_opt->space)
    my_putchar_c(' ');
  if (!flag_opt->minus && flag_opt->zero)
    space_zero += my_add_space_zero(*len, flag_opt->zero, '0');
  return (space_zero + minus);
}

void	my_init_opt(t_flag_opt *flag_opt)
{
  flag_opt->sharp = 0;
  flag_opt->space = 0;
  flag_opt->zero = 0;
  flag_opt->number = 0;
  flag_opt->plus = 0;
  flag_opt->minus = 0;
  flag_opt->prec = 6;
}
