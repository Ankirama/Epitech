/*
** my_va_base_long.c for my_va_base_long in /home/mar_b/rendu/PSU_2013_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Apr 19 19:05:34 2014 Fabien Martinez
** Last update Sun Apr 20 22:45:19 2014 Fabien Martinez
*/

#include <unistd.h>
#include <stdarg.h>
#include "my_printf.h"

/*
** Display decimal in octal base
*/
int			my_putnbr_base_oct_short(va_list *ap,
						 t_flag_opt *flag_opt)
{
  char			*base;
  unsigned short int	nbr;
  int			len;
  int			space_zero;

  nbr = (unsigned short int)va_arg(*ap, unsigned int);
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
int			my_putnbr_base_bin_short(va_list *ap,
						t_flag_opt *flag_opt)
{
  char			*base;
  unsigned short int	nbr;
  int			len;
  int			space_zero;

  nbr = (unsigned short int)va_arg(*ap, unsigned int);
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
int			my_putnbr_base_hex_M_short(va_list *ap,
						  t_flag_opt *flag_opt)
{
  char			*base;
  unsigned short int	nbr;
  int			len;
  int			space_zero;

  nbr = (unsigned short int)va_arg(*ap, unsigned int);
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
int			my_putnbr_base_hex_m_short(va_list *ap,
						  t_flag_opt *flag_opt)
{
  char			*base;
  unsigned short int	nbr;
  int			len;
  int			space_zero;

  nbr = (unsigned short int)va_arg(*ap, unsigned int);
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
