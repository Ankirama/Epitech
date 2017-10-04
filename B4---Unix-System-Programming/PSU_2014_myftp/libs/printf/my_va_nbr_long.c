/*
** my_va_nbr_long.c for my_va_nbr_long in /home/mar_b/rendu/PSU_2013_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Apr 19 19:08:10 2014 Fabien Martinez
** Last update Sun Apr 20 22:47:17 2014 Fabien Martinez
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"

/*
** it'll display integer (unsigned) decimal
*/
int			my_putnbr_un_long(va_list *ap, t_flag_opt *flag_opt)
{
  unsigned long int	nbr;
  int			len;
  int			space_zero;

  nbr = va_arg(*ap, unsigned long int);
  len = my_nbrlen(nbr);
  space_zero = 0;
  if (flag_opt->minus == 0 && flag_opt->number)
    space_zero = my_add_space_zero(len, flag_opt->number, ' ');
  else if (flag_opt->minus == 0 && flag_opt->zero)
    space_zero = my_add_space_zero(len, flag_opt->zero, '0');
  else if (flag_opt->minus && (flag_opt->number || flag_opt->zero))
    {
      my_putnbr_un_rec(nbr);
      space_zero = my_add_space_zero(len,
				     flag_opt->number + flag_opt->zero, ' ');
      my_init_opt(flag_opt);
      return (space_zero + len);
    }
  my_init_opt(flag_opt);
  return (space_zero + my_putnbr_un_rec(nbr));
}

/*
** It'll call my_putnbr_sign to display long decimal nbr
*/
int		my_putnbr_long(va_list *ap, t_flag_opt *flag_opt)
{
  long int	nbr;
  int		len;
  int		space_zero;

  nbr = va_arg(*ap, long int);
  len = my_nbrlen(nbr);
  space_zero = my_opt_nbr(flag_opt, nbr < 0, &len);
  if (flag_opt->minus && (flag_opt->number || flag_opt->zero))
    {
      my_putnbr_un_rec(nbr);
      space_zero = my_add_space_zero(len,
				     flag_opt->number + flag_opt->zero, ' ');
      my_init_opt(flag_opt);
      return (space_zero + len);
    }
  my_init_opt(flag_opt);
  return (space_zero + my_putnbr_sign(nbr));
}
