/*
** drawing.c for drawing in /home/mar_b/rendu/piscine_cpp_d01/ex03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jan  7 15:29:18 2015 Fabien Martinez
** Last update Thu Jan  8 08:18:15 2015 Fabien Martinez
*/

#include <stdint.h>
#include <sys/types.h>
#include "drawing.h"

/*
** @img : a two-dimensional array representing the image
** @orig : the position of the bottom-left corner of the square
** @size : the size of one of the square’s sides
** @color : the color of the square to be drawn
*/
void		draw_square(uint32_t ** img, t_point * orig, size_t size, uint32_t color)
{
  uint32_t	j;
  uint32_t	i;

  i = 0;
  while (i < size)
    {
      j = -1;
      while (++j < size)
	img[orig->x + i][orig->y + j] = color;
      ++i;
    }
}
