/*
** pixel.c for pixel in /home/mar_b/rendu/MUL_2013_rtv1/calc
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:42:19 2014 mar_b mar_b
** Last update Fri Jul 11 20:32:23 2014 mar_b mar_b
*/

#include "rtv1.h"

/*
** brief: this function will color a pixel
** @img: we will use img->data to copy into our real data
** @color: this color will be used for each pixel
** @i: the position
*/
void	my_put_pixel_to_img(t_img *img, unsigned char *color, int i)
{
  int	j;

  if (!img->endian)
    {
      j = -1;
      while (++j < img->bpp / 8)
	{
	  img->data[i] = color[j];
	  ++i;
	}
    }
  else
    {
      j = img->bpp / 8;
      while (--j >= 0)
	{
	  img->data[i] = color[j];
	  ++i;
	}
    }
}
