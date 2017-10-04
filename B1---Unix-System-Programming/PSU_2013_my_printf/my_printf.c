/*
** my_printf.c for my_printf in /home/mar_b/rendu/PSU_2014_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Apr  8 13:48:42 2014 Fabien Martinez
** Last update Sun Apr 20 22:52:47 2014 Fabien Martinez
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "my_printf.h"

/*
** We'll iterate to find our char in tab
*/
int	my_pos(char *str, char c)
{
  if (str[0] == 0 || str[0] == c)
    return (0);
  else
    return (1 + my_pos(&str[1], c));
}

/*
** Initialize our structs and variables
*/
t_ptr_fun	*my_init_malloc(t_flag_opt **flag_opt, int *i)
{
  t_ptr_fun	*struc;

  if ((struc = malloc(sizeof(*struc))) == NULL)
    return (NULL);
  if ((struc->ptr_fun = create_ptr_fun()) == NULL ||
      (struc->tab = my_create_tab_flags()) == NULL ||
      (struc->opt = my_create_tab_options()) == NULL ||
      (struc->ptr_fun_long = create_ptr_fun_long()) == NULL ||
      (struc->ptr_fun_short = create_ptr_fun_short()) == NULL)
    return (NULL);
  (*flag_opt)->count = 0;
  (*flag_opt)->sharp = 0;
  (*flag_opt)->space = 0;
  (*flag_opt)->zero = 0;
  (*flag_opt)->number = 0;
  (*flag_opt)->plus = 0;
  (*flag_opt)->minus = 0;
  (*flag_opt)->prec = 6;
  *i = 0;
  return (struc);
}

/*
** This function will find our flag and display the result
** (return number of chars printed)
*/
void	my_display_flag(t_ptr_fun *s, t_flag_opt *flag_opt,
			const char *str, int *i)
{
  int	flag;

  *i += 1;
  while (my_check_opt(s, flag_opt, str, i));
  if ((flag = my_check_lh(str, s, *i, 'l')) >= 0)
    {
      flag_opt->count += (s->ptr_fun_long[flag](s->ap, flag_opt));
      *i += 1;
    }
  else if ((flag = my_check_lh(str, s, *i, 'h')) >= 0)
    {
      flag_opt->count += (s->ptr_fun_short[flag](s->ap, flag_opt));
      *i += 1;
    }
  else if ((flag = my_pos(s->tab, str[*i])) <= 14)
    flag_opt->count += (s->ptr_fun[flag](s->ap, flag_opt));
  else if (flag == 15)
    flag_opt->count += (my_print_error(errno));
  else
    {
      flag_opt->count += write(1, &(str[*i - 1]), 1);
      flag_opt->count += write(1, &(str[*i]), 1);
      *i += 1;
    }
}

/*
** main function which will itialize our values, and will iterate to format
** AND I'VE USED FREE !!! <3
*/
int		my_printf(const char *format, ...)
{
  int		i;
  t_ptr_fun	*ptr_fun;
  t_flag_opt	*flag_opt;
  int		count;
  va_list	ap;

  if ((flag_opt = malloc(sizeof(*flag_opt))) == NULL)
    return (-1);
  if ((ptr_fun = my_init_malloc(&flag_opt, &i)) == NULL)
    return (-1);
  va_start(ap, format);
  ptr_fun->ap = &ap;
  while (format != NULL && format[i] != 0)
    {
      if (format[i] == '%')
        my_display_flag(ptr_fun, flag_opt, format, &i);
      else
	flag_opt->count += write(1, &(format[i]), 1);
      i += 1;
    }
  count = flag_opt->count;
  va_end(ap);
  my_let_it_go(flag_opt, ptr_fun);
  return (count);
}
