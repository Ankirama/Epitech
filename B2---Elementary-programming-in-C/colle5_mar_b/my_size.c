/*
** my_size.c for my_size in /home/lefebv_1/rendu/colle5_mar_b
** 
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
** 
** Started on  Tue Sep 23 20:45:42 2014 lefebv_1 lefebv_1
** Last update Tue Sep 23 21:58:21 2014 lefebv_1 lefebv_1
*/

#include "utils.h"

void	my_size(char *str, t_option *option)
{
  int	size;

  if ((size = my_getnbr(str)) != -1)
    option->size = size;
  else
    {
      my_putstr(ERR_SIZE, 2);
      my_puterror(ERR_ARG);
    }
}
