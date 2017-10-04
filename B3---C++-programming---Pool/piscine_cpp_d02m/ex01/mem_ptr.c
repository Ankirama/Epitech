/*
** mem_ptr.c for file_mem in /home/user/rendu/piscine_cpp_d02m/ex01
**
** Made by 
** Login   
**
** Started on  Thu Jan  8 10:00:14 2015 
** Last update Thu Jan  8 10:15:13 2015 
*/

#include <string.h>
#include <stdlib.h>
#include "mem_ptr.h"

void	my_null(char *str, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    str[i] = '\0';
}

void	add_str(char *str1, char *str2, char **res)
{
  int	size;

  size = strlen(str1) + strlen(str2) + 1;
  res[0] = malloc(sizeof(char) * size);
  my_null(res[0], size);
  strcat(res[0], str1);
  strcat(res[0], str2);
}

void add_str_struct(t_str_op *str_op)
{
  add_str(str_op->str1, str_op->str2, &(str_op->res));
}
