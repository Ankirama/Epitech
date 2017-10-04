/*
** menger.c for menger in /home/mar_b/rendu/piscine_cpp_d01/ex01
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jan  7 11:18:39 2015 Fabien Martinez
** Last update Wed Jan  7 22:05:03 2015 Fabien Martinez
*/

#include <stdio.h>

void	menger(int x, int y, int size, int n)
{
  if (n > 0)
    {
      size /= 3;
      printf("%.3d %.3d %.3d\n", size, x / 3, y / 3);
      menger(x - 2 * size, y - size  * 2, size, n - 1);
      menger(x - 2 * size, y + size, size, n - 1);
      menger(x - 2 * size, y + size * 3 + size, size, n - 1);
      menger(x + size, y - size * 2, size, n - 1);
      menger(x + size, y + size * 3 + size, size, n - 1);
      menger(x + size * 3 + size, y - 2 * size, size, n - 1);
      menger(x + size * 3 + size , y + size, size, n - 1);
      menger(x + 3 * size + size, y + 3 * size + size, size, n - 1);
    }
}
