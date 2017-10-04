/*
** my_op.c for my_op in /home/mar_b/rendu/colle3_bob42
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep  9 20:29:50 2014 mar_b mar_b
** Last update Tue Sep  9 21:12:52 2014 mar_b mar_b
*/

#include "utils.h"
#include "calc.h"

int	my_add(const int nb1, const int nb2)
{
  return (nb1 + nb2);
}

int	my_sub(const int nb1, const int nb2)
{
  return (nb1 - nb2);
}

int	my_mul(const int nb1, const int nb2)
{
  return (nb1 * nb2);
}

int	my_div(const int nb1, const int nb2)
{
  if (nb2 == 0)
    my_puterror(ERR_DIVISION);
  return (nb1 / nb2);
}

int	my_mod(const int nb1, const int nb2)
{
  if (nb2 == 0)
    my_puterror(ERR_MODULO);
  return (nb1 % nb2);
}
