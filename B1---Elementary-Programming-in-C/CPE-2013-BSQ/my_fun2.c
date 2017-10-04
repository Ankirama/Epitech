/*
** my_fun2.c for my_fun in /home/mar_b/rendu/CPE-2013-BSQ
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue May  6 23:23:59 2014 mar_b mar_b
** Last update Sun May 11 19:59:07 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "bsq.h"

void	my_change_pos(t_vector **pos, int x, int y, char up)
{
  if (up)
    {
      (*pos)->x = x;
      (*pos)->y = y;
    }
}

char	**my_add_array(char **arr, int size, t_vector **save, t_vector **pos)
{
  int	x;
  int	y;

  y = (*save)->y;
  while (y < (*save)->y + size)
    {
      x = (*save)->x;
      while (x < (*save)->x + size)
	arr[y][x++] = 'x';
      y += 1;
    }
  free(*pos);
  free(*save);
  return (arr);
}
