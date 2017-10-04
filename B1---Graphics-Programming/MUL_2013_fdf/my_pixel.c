/*
** my_pixel.c for my_pixel in /home/mar_b/rendu/MUL_2013_fdf
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 30 13:32:25 2014 Fabien Martinez
** Last update Thu May  8 23:10:10 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_pixel.h"

static void	my_conv_pos(t_pixel *pix, int z, int *x, int *y)
{
  *x = (int)(0.84 * pix->x - 0.56 * pix->y);
  *y = (int)(z + 0.42 * pix->x + 0.28 * pix->y);
}

void	my_put_pixel_to_img(t_pixel *pix, char **data, int sizeline, int z)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  my_conv_pos(pix, z, &x, &y);
  while (i < pix->nbr_oct)
    {
      (*data)[y * sizeline + x + i] = pix->color[i];
      i += 1;
    }
}

t_pixel		*fill_my_pixel(int x, int y, char nbr_oct, unsigned char *color)
{
  t_pixel	*pix;

  if ((pix = malloc(sizeof(*pix))) == NULL)
    return (NULL);
  pix->x = x;
  pix->y = y;
  pix->nbr_oct = nbr_oct;
  pix->color = color;
  return (pix);
}
