/*
** my_fun.c for my_fun in /home/mar_b/rendu/PSU_2014_my_printf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Apr 11 13:52:12 2014 Fabien Martinez
** Last update Sun Apr 20 22:37:03 2014 Fabien Martinez
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

/*
** Return len integer
*/
int	my_count_integer(double nbr)
{
  if (nbr < 10 && nbr >= 0)
    return (1);
  else if (nbr < 0 && nbr * -1 < 10)
    return (1);
  else
    return (1 + my_count_integer(nbr / 10));
}

/*
** This function will print '0' or ' ' for %0nbr and %nbr
*/
int	my_add_space_zero(int length, int space_zero, char c)
{
  int	return_value;

  return_value = space_zero - length;
  while (space_zero - length > 0)
    {
      my_putchar_c(c);
      space_zero -= 1;
    }
  return (return_value < 0 ? 0 : return_value);
}

/*
** power like 10 ^ 3
*/
int	my_power(int nbr, int p)
{
  if (p == 0)
    return (1);
  else
    return (nbr * my_power(nbr, p - 1));
}

/*
** Let it go, let it go (Frozen, 2013)
** Free structs
*/
void	my_let_it_go(t_flag_opt *flag_opt, t_ptr_fun *my_fun)
{
  free(my_fun->tab);
  my_fun->tab = NULL;
  free(my_fun->opt);
  my_fun->opt = NULL;
  free(my_fun->ptr_fun);
  my_fun->ptr_fun = NULL;
  free(my_fun->ptr_fun_long);
  my_fun->ptr_fun_long = NULL;
  free(my_fun->ptr_fun_short);
  my_fun->ptr_fun_short = NULL;
  free(my_fun);
  my_fun = NULL;
  free(flag_opt);
  flag_opt = NULL;
}
