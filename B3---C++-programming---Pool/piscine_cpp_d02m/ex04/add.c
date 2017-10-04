/*
** add.c for add in /home/mar_b/rendu/piscine_cpp_d02m/ex04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 11:35:03 2015 Fabien Martinez
** Last update Thu Jan  8 13:01:02 2015 Fabien Martinez
*/

#include "castmania.h"

int normal_add(int a, int b)
{
  return (a + b);
}

int absolute_add(int a, int b)
{
  return ((a < 0 ? a * -1 : a) + (b < 0 ? b * -1 : b));
}

void exec_add(t_add *operation)
{
  if (operation->add_type == NORMAL)
    {
      operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
    }
  else
      operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
}
