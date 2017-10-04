/*
** div.c for division in /home/user/rendu/piscine_cpp_d02m/ex04
**
** Made by 
** Login   
**
** Started on  Thu Jan  8 11:18:30 2015 
** Last update Thu Jan  8 13:25:21 2015 
*/

#include "castmania.h"

int integer_div(int a, int b)
{
  return (b == 0 ? b : a / b);
}

float decimale_div(int a, int b)
{
  return (b == 0 ? 0 : (float)a / (float)b);
}

void exec_div(t_div *operation)
{
  if (operation->div_type == INTEGER)
    {
      t_integer_op	*p;
      p = operation->div_op;
      p->res = integer_div(p->a ,p->b);
      operation->div_op = p;
    }
  else
    {
      t_decimale_op	*p;
      p = operation->div_op;
      p->res = decimale_div(p->a ,p->b);
      operation->div_op = p;
    }

}
