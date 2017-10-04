/*
** drawing.h for drawing in /home/mar_b/rendu/piscine_cpp_d01/ex03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jan  7 15:25:38 2015 Fabien Martinez
** Last update Thu Jan  8 02:48:13 2015 Fabien Martinez
*/

#ifndef DRAWING_H_
# define DRAWING_H_

#include <stdint.h>
#include <sys/types.h>

typedef struct	s_point
{
  unsigned int	x;
  unsigned int	y;
}		t_point;

void draw_square(uint32_t ** img, t_point * orig, size_t size, uint32_t color);

#endif /* !DRAWING_H_ */
