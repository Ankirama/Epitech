/*
** operations.c for operations in /home/mar_b/rendu/Piscine-C-Jour_11/do-op
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 24 09:38:12 2014 Fabien Martinez
** Last update Mon Mar 24 16:27:42 2014 Fabien Martinez
*/

#include "my_fun.h"
#include "my_nbr.h"

int	my_add(int a, int b)
{
  my_put_nbr(a + b);
  return (0);
}

int	my_sub(int a, int b)
{
  my_put_nbr(a - b);
  return (0);
}

int	my_div(int a, int b)
{
  if (b == 0)
    my_putstr("Stop: division by zero");
  else
    my_put_nbr(a / b);
  return (0);
}

int	my_mul(int a, int b)
{
  my_put_nbr(a * b);
  return (0);
}

int	my_mod(int a, int b)
{
  if (b == 0)
    my_putstr("Stop: modulo by zero");
  else
    my_put_nbr(a % b);
  return (0);
}
