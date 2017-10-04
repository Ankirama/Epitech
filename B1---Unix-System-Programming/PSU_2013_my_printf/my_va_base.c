/*
** my_putnbr_base.c for my_putnbr_base in /home/mar_b/rendu/Piscine-C-Jour_06/ex_15
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 14:05:01 2014 Fabien Martinez
** Last update Sun Apr 20 16:54:35 2014 Fabien Martinez
*/

#include <unistd.h>
#include <stdarg.h>
#include "my_printf.h"

/*
** Display decimal in octal base
*/
int		my_putnbr_base_oct(va_list *ap, t_flag_opt *flag_opt)
{
  char		*base;
  unsigned int	nbr;
  int		len;
  int		space_zero;

  nbr = va_arg(*ap, unsigned int);
  base = "01234567";
  len = my_baselen(nbr, my_strlen(base));
  space_zero = my_opt_base(flag_opt, "0", len);
  if (flag_opt->minus && (flag_opt->number || flag_opt->zero))
    {
      my_putnbr_base(nbr, base, my_strlen(base));
      space_zero += my_add_space_zero(len  + space_zero,
				      flag_opt->number + flag_opt->zero, ' ');
      my_init_opt(flag_opt);
      return (space_zero + len);
    }
  my_init_opt(flag_opt);
  return (space_zero + my_putnbr_base(nbr, base, my_strlen(base)));
}

/*
** Display decimal in binary base
*/
int		my_putnbr_base_bin(va_list *ap, t_flag_opt *flag_opt)
{
  char		*base;
  unsigned int	nbr;
  int		len;
  int		space_zero;

  nbr = va_arg(*ap, unsigned int);
  base = "01";
  len = my_baselen(nbr, my_strlen(base));
  space_zero = my_opt_base(flag_opt, NULL, len);
  if (flag_opt->minus && (flag_opt->number || flag_opt->zero))
    {
      my_putnbr_base(nbr, base, my_strlen(base));
      space_zero += my_add_space_zero(len  + space_zero,
				      flag_opt->number + flag_opt->zero, ' ');
      my_init_opt(flag_opt);
      return (space_zero + len);
    }
  my_init_opt(flag_opt);
  return (space_zero + my_putnbr_base(nbr, base, my_strlen(base)));
}

/*
** display decimal in hexa (uppercase) base
*/
int		my_putnbr_base_hex_M(va_list *ap, t_flag_opt *flag_opt)
{
  char		*base;
  unsigned int	nbr;
  int		len;
  int		space_zero;

  nbr = va_arg(*ap, unsigned int);
  base = "0123456789ABCDEF";
  len = my_baselen(nbr, my_strlen(base));
  space_zero = my_opt_base(flag_opt, "0X", len);
  if (flag_opt->minus && (flag_opt->number || flag_opt->zero))
    {
      my_putnbr_base(nbr, base, my_strlen(base));
      space_zero += my_add_space_zero(len  + space_zero,
				      flag_opt->number + flag_opt->zero, ' ');
      my_init_opt(flag_opt);
      return (space_zero + len);
    }
  my_init_opt(flag_opt);
  return (space_zero + my_putnbr_base(nbr, base, my_strlen(base)));
}

/*
** display decimal in hexa (lowercase) base
*/
int		my_putnbr_base_hex_m(va_list *ap, t_flag_opt *flag_opt)
{
  char		*base;
  unsigned int	nbr;
  int		len;
  int		space_zero;

  nbr = va_arg(*ap, unsigned int);
  base = "0123456789abcdef";
  len = my_baselen(nbr, my_strlen(base));
  space_zero = my_opt_base(flag_opt, "0x", len);
  if (flag_opt->minus && (flag_opt->number || flag_opt->zero))
    {
      my_putnbr_base(nbr, base, my_strlen(base));
      space_zero += my_add_space_zero(len  + space_zero,
				      flag_opt->number + flag_opt->zero, ' ');
      my_init_opt(flag_opt);
      return (space_zero + len);
    }
  my_init_opt(flag_opt);
  return (space_zero + my_putnbr_base(nbr, base, my_strlen(base)));
}

/*
** Display pointer (decimal) in hexa (uppercase) base
*/
int			my_putnbr_base_p(va_list *ap, t_flag_opt *flag_opt)
{
  char			*base;
  unsigned long int	nbr;
  int			len;
  int			space_zero;

  nbr = (unsigned long int)va_arg(*ap, void *);
  base = "0123456789abcdef";
  len = my_baselen(nbr, my_strlen(base));
  if (nbr == 0)
    return (write(1, "(nil)", 5));
  space_zero = my_opt_pointer(flag_opt, len);
  if (flag_opt->minus && (flag_opt->number || flag_opt->zero))
    {
      my_putnbr_base(nbr, base, my_strlen(base));
      space_zero += my_add_space_zero(len  + space_zero,
				      flag_opt->number + flag_opt->zero, ' ');
      my_init_opt(flag_opt);
      return (space_zero + len);
    }
  my_init_opt(flag_opt);
  return (space_zero + my_putnbr_base(nbr, base, my_strlen(base)));
}
