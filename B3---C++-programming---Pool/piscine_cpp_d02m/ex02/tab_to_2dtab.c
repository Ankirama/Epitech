/*
** tab_to_2dtab.c for tab in /home/mar_b/rendu/piscine_cpp_d02m/ex02
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 10:16:14 2015 Fabien Martinez
** Last update Thu Jan  8 10:36:39 2015 Fabien Martinez
*/

#include <stdlib.h>
#include <unistd.h>

void	tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int	i;
  int	j;
  int	k;
  int	**tmp;

  tmp = malloc(sizeof(int *) * length);
  j = -1;
  k = -1;
  while (++j < length)
    {
      i = -1;
      tmp[j] = malloc(sizeof(int) * width);
      while (++i < width)
	tmp[j][i] = tab[++k];
    }
  res[0] = tmp;
}
