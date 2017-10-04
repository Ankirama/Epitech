/*
** my_va_fun.c for my_va_fun in /home/mar_b/rendu/PSU_2014_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Apr 11 13:52:12 2014 Fabien Martinez
** Last update Sun Apr 20 16:54:47 2014 Fabien Martinez
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"

/*
** Used for %n flag (store into an integer the nbr of char printed)
*/
int	my_count_print(va_list *ap, t_flag_opt *flag_opt)
{
  *(va_arg(*ap, int *)) = flag_opt->count;
  return (0);
}

/*
** it'll display integer (signed) decimal
*/
int	my_putnbr_int(va_list *ap, t_flag_opt *flag_opt)
{
  int	nbr;
  int	len;
  int	space_zero;

  nbr = va_arg(*ap, int);
  len = my_nbrlen(nbr);
  space_zero = my_opt_nbr(flag_opt, nbr < 0, &len);
  if (flag_opt->minus && (flag_opt->number || flag_opt->zero))
    {
      my_putnbr_sign((long)nbr);
      space_zero += my_add_space_zero(len,
				      flag_opt->number + flag_opt->zero, ' ');
      my_init_opt(flag_opt);
      return (len + space_zero - (nbr < 0));
    }
  my_init_opt(flag_opt);
  return (space_zero + my_putnbr_sign(((long)nbr)));
}

/*
** it'll display integer (unsigned) decimal
*/
int		my_putnbr_un(va_list *ap, t_flag_opt *flag_opt)
{
  unsigned int	nbr;
  int		len;
  int		space_zero;

  nbr = va_arg(*ap, unsigned int);
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
** This function will display our float LIKE A BOSS !!!
*/
int		my_putnbr_double(va_list *ap, t_flag_opt *flag_opt)
{
  double	nbr;
  int		len;
  int		space_zero;

  nbr = va_arg(*ap, double);
  nbr *= my_power(10, flag_opt->prec);
  len = my_count_integer(nbr) - 1;
  if (nbr < 0)
    {
      my_putchar_c('-');
      nbr = nbr * -1;
    }
  space_zero = my_opt_nbr(flag_opt, 0, &len);
  flag_opt->prec = flag_opt->prec == 0 ? -1 : flag_opt->prec;
  if ((nbr - (long)nbr) * 10 >= 5)
    nbr += 1;
  space_zero += my_putnbr_rec_double(nbr, flag_opt->prec);
  if (flag_opt->minus && (flag_opt->number || flag_opt->zero))
    space_zero += my_add_space_zero(space_zero + my_count_integer(nbr),
				    flag_opt->number + flag_opt->zero, ' ');
  my_init_opt(flag_opt);
  return (space_zero);
}

/*
** This function will display our float in scientist mod LIKE A BOSS !!!
*/
int		my_putnbr_sci(va_list *ap, t_flag_opt *flag_opt)
{
  double	nbr;
  int		len;
  int		space_zero;
  int		sci;

  nbr = va_arg(*ap, double);
  sci = my_count_integer(nbr) - 1;
  nbr *= my_power(10, flag_opt->prec);
  space_zero = 0;
  if (nbr < 0)
    {
      my_putchar_c('-');
      nbr = nbr * -1;
    }
  flag_opt->prec = flag_opt->prec == 0 ? -1 : flag_opt->prec;
  if ((nbr - (long)nbr) * 10 >= 5)
    nbr += 1;
  space_zero += my_putnbr_rec_double(nbr, flag_opt->prec + sci);
  my_init_opt(flag_opt);
  space_zero += write(1, "e+", 2);
  space_zero += my_putchar_c(sci / 10 + '0');
  space_zero += my_putchar_c(sci % 10  + '0');
  return (space_zero);
}
