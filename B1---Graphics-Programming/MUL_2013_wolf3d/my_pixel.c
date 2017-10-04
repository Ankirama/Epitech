/*
** my_pixel.c<2> for my_pixel in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Jun  7 02:48:49 2014 mar_b mar_b
** Last update Sun Jun 15 17:46:41 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_pixel.h"
#include "wolf3d.h"

/*
** brief: this function will color a pixel
** @img: we will use img->data to copy into our real data
** @color: this color will be used for each pixel
** @i: the position
** return: i + bpp / 8
*/
int	my_put_pixel_to_img(t_img *img, unsigned char *color, int i)
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
  return (i);
}

/*
** brief: this function will write the color img into our data
** @param: the struct used to define the move, each ptr like the img etc...
** @img: we will use img->data to copy into our real data
** @i: it's the pixel's position we will color
** @k: used to travel through our img->data
** return: it will return i + bpp / 8
*/
int	my_img_to_pixel(t_ptr *param, t_img *img, int i, int *k)
{
  int	j;

  if (!param->pic->endian)
    {
      j = -1;
      while (++j <= param->pic->bpp / 8)
	{
	  param->pic->data[i] = img->data[*k];
	  ++(*k);
	  ++i;
	}
    }
  else
    {
      j = param->pic->bpp / 8;
      while (--j >= 0)
	{
	  param->pic->data[i] = img->data[*k + j];
	  ++i;
	}
      (*k) = (*k) + 4;
    }
  return (i);
}

/*
** brief: it will color our pixel in (x,y) position
** @img: the struct with data, bpp, sizeline, endian
** @x: the x_position
** @y: the y_position
** @color: the color we will fill into our pixel
*/
void    my_put_pixel_to_mini(t_img *img, int x, int y, unsigned char *color)
{
  int   i;
  int	j;

  if (!img->endian)
    {
      i = -1;
      while (++i < img->bpp / 8)
	img->data[y * img->sizeline + (x * img->bpp / 8) + i] = color[i];
    }
  else
    {
      j = img->bpp / 8;
      i = -1;
      while (--j >= 0)
	img->data[y * img->sizeline + (x * img->bpp / 8) + ++i] = color[j];
    }
}
