/*
** my_grid.c for my_grid in /home/lefebv_1/rendu/colle5_mar_b
** 
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
** 
** Started on  Tue Sep 23 20:47:24 2014 lefebv_1 lefebv_1
** Last update Tue Sep 23 22:13:24 2014 lefebv_1 lefebv_1
*/

#include "utils.h"

static int	_my_check_grid(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 'a' || str[i] > 'z')
	{
	  my_putstr("syntax error for [-g GRID]\n", 2);
	  return (-1);
	}
      i = i + 1;
    }
  return (0);
}

void	my_grid(char *str, t_option *option)
{
  if (_my_check_grid(str) == 0)
    option->grid = str;
  else
    my_puterror(ERR_ARG);
}
