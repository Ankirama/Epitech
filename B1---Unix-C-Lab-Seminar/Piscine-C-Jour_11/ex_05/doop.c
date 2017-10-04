/*
** do-op.c for do-op in /home/mar_b/rendu/Piscine-C-Jour_11/do-op
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 24 09:21:43 2014 Fabien Martinez
** Last update Mon Mar 24 16:27:04 2014 Fabien Martinez
*/

#include "my_fun.h"
#include "my_nbr.h"
int	my_usage(int, int);
#include "operations.h"
#include "my_opp.h"

int	my_own_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != 0 && str2[i] != 0 && str1[i] == str2[i])
    i += 1;
  return (!(str2[i] == 0 || str1[i] == 0));
}

int	find_my_op(char *op)
{
  int	i;

  i = 0;
  while (i < 5 && my_own_strcmp(gl_opptab[i].str, op) != 0)
    i += 1;
  return (i);
}

int	my_usage(int a, int b)
{
  int	i;

  (void)a;
  (void)b;
  i = 0;
  my_putstr("error: only [ ");
  while (i < 5)
    {
      my_putstr(gl_opptab[i].str);
      my_putchar(' ');
      i += 1;
    }
  my_putstr("] are supported");
  return (0);
}

int	main(int argc, char **argv)
{
  int	i;

  if (argc == 4)
    {
      i = find_my_op(argv[2]);
      gl_opptab[i].fun(my_getnbr(argv[1]), my_getnbr(argv[3]));
      my_putchar('\n');
    }
  return (0);
}
