/*
** func_ptr.c for fun_c in /home/mar_b/rendu/piscine_cpp_d02m/ex03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 10:37:52 2015 Fabien Martinez
** Last update Thu Jan  8 16:30:22 2015 Fabien Martinez
*/

#include <stdio.h>
#include <string.h>
#include "func_ptr.h"

void	print_normal(char *str)
{
  printf("%s\n", str);
}

void	print_reverse(char *str)
{
  int	i;

  i = strlen(str);
  while (--i >= 0)
    printf("%c", str[i]);
  printf("\n");
}

void	print_upper(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    printf("%c", str[i] >= 'a' && str[i] <= 'z' ? str[i] - 32 : str[i]);
  printf("\n");
}

void	print_42(char *str)
{
  (void)str;
  printf("42\n");
}

void		do_action(t_action action, char *str)
{
  t_do_action	array[4] = {{PRINT_NORMAL, print_normal}, {PRINT_REVERSE, print_reverse}, {PRINT_UPPER, print_upper}, {PRINT_42, print_42}};
  int		i;

  i = -1;
  while (++i < 4 && array[i].current != action);
  (array[i]).my_func(str);
}
