/*
** my_check.c for my_check in /home/mar_b/perso
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sat Apr 19 14:04:41 2014 Fabien Martinez
** Last update Sun Apr 20 22:48:51 2014 Fabien Martinez
*/

#include "my_printf.h"

static void	my_chec_space(t_ptr_fun *struc, t_flag_opt *flag_opt,
			      const char *format, int *i);

/*
** This function will "remove" space and set flag_opt->space at 1
*/
static void	my_check_space(t_ptr_fun *struc, t_flag_opt *flag_opt,
		       const char *format, int *i)
{
  while (format[*i] == struc->opt[SPACE])
    {
      flag_opt->space = 1;
      *i += 1;
    }
}

/*
** This function will check our options
*/
char	my_check_opt(t_ptr_fun *struc, t_flag_opt *flag_opt,
		     const char *format, int *i)
{
  my_check_space(struc, flag_opt, format, i);
  if (format[*i] == struc->opt[SHARP])
    flag_opt->sharp = 1;
  else if (format[*i] > '0' && format[*i] <= '9')
    flag_opt->number = my_create_nbr(format, i);
  else if (format[*i] == struc->opt[2] && !flag_opt->zero && !flag_opt->number)
    flag_opt->zero = my_create_nbr(format, i);
  else if (format[*i] == struc->opt[PLUS])
    flag_opt->plus = 1;
  else if (format[*i] == struc->opt[MINUS] &&
	   !flag_opt->zero && !flag_opt->number)
    {
      flag_opt->minus = 1;
      *i += 1;
      flag_opt->number = my_create_nbr(format, i);
    }
  else if (format[*i] == struc->opt[POINT])
    {
      *i += 1;
      flag_opt->prec = my_create_nbr(format, i);
    }
  else
    return (0);
  *i += 1;
  return (1);
}

/*
** Will check if an option like l or h is here
*/
int	my_check_lh(const char *str, t_ptr_fun *s, int i, char c)
{
  int	flag;

  flag = 0;
  if (str[i] == c && str[i + 1] != 0 &&
      (flag = my_pos(s->tab, str[i + 1])) <= 6)
    return (flag);
  return (-1);
}
