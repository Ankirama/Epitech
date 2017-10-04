/*
** picture.c for  in /home/viterb_c/rendu/MUL_2013_rtracer
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Sat Oct  4 12:08:08 2014 charles viterbo
** Last update Sun Oct 12 21:13:09 2014 teyssa_r teyssa_r
*/

#include <stdlib.h>
#include "rotation.h"
#include "rtracer.h"
#include "utils.h"
#include "mlx.h"
#include "intersection.h"

/*
** brief : it will put a pixel into our image
** @x, @y : the position
** @img : our img struct
** @color : our color (like 0x00ff00)
*/
static void	_my_pixel_put_to_image(const int x, const int y,
				       t_img *img,
				       unsigned int color)
{
  unsigned char	*color_pixel;
  int		i;

  color_pixel = (unsigned char *)&color;
  if (img->endian == 0)
    {
      i = -1;
      while (++i < img->bpp / 8)
	*(img->data + y * img->sizeline +
	  (x * img->bpp / 8) + i) = color_pixel[i];
    }
  else
    {
      i = img->bpp / 8;
      while (--i >= 0)
	*(img->data + y * img->sizeline +
	  (x * img->bpp / 8) + i) = color_pixel[i];
    }
}

/*
** brief: it will put the pixel from our bg into our img
** @x, @y: the position
** @img : our img which will receive our new pixel
** @bg: our background
*/
static void	_my_img_to_image(const int x, const int y, t_img *img,
				 t_img *bg)
{
  int		i;

  if (img->endian == 0)
    {
      i = -1;
      while (++i < img->bpp / 8)
	*(img->data + y * img->sizeline +
	  (x * img->bpp / 8) + i) = *(bg->data + y * bg->sizeline +
				      (x * bg->bpp / 8) + i);
    }
  else
    {
      i = img->bpp / 8;
      while (--i >= 0)
	*(img->data + y * img->sizeline +
	  (x * img->bpp / 8) + i) = *(bg->data + y * bg->sizeline +
				      (x * bg->bpp / 8) + i);
    }
}

/*
** brief : it will calc each pixel and set a color
** @i, @j : our position
** @ptr : our main struct
** @scene : our scene with every objects
*/
static void	_calc(const int i, const int j,
		      t_window *ptr, t_scene *scene)
{
  t_vector	vision;
  t_dis		obj;
  t_color	*color;
  t_eye		*eye;

  eye = scene->list_eye;
  vision.x = 1000.0 - eye->coord->x;
  vision.y = (WIDTH / 2.0) - i - eye->coord->y;
  vision.z = (HEIGHT / 2.0) - j - eye->coord->z;
  obj.type = NO_OBJ;
  obj.k = -1.0;
  obj.element = NULL;
  rot_x(&vision.x, &vision.y, &vision.z, eye->rot->x);
  rot_y(&vision.x, &vision.y, &vision.z, eye->rot->y);
  rot_z(&vision.x, &vision.y, &vision.z, eye->rot->z);
  color = objects(scene, eye, &vision, &obj);
  if (color == NULL && ptr->background != NULL)
    _my_img_to_image(i, j, ptr->pic, ptr->bg);
  else if (color == NULL)
    _my_pixel_put_to_image(i, j, ptr->pic, 0x000000);
  else
    _my_pixel_put_to_image(i, j, ptr->pic,
			   conv_color(color->r, color->g, color->b));
}

/*
** brief: create a loading bar
** @i: value to start the loading bar in the middle
** @*ptr: struct to use mlx_pixel_put
** @len: It's just WIDTH/2 to ajust our loading bar
*/
static void	_loading_on_screen(int i, t_window *ptr)
{
  int		grow;
  int		j;
  int		fa;
  t_color	*cl;

  grow = HEIGHT / 9;
  j = grow * 4;
  if (i < WIDTH)
    while (j != grow * 5)
      {
	fa = ((i * grow - j * 42) / 2) & 255;
	cl = create_color(fa, (i / 5) & 255, (i / 4) & 255);
	_my_pixel_put_to_image(i, j++, ptr->load,
			       conv_color(cl->r, cl->g, cl->b));
	free(cl);
      }
}

/*
** brief : it will create our scene
** @ptr : our main struct
** @scene : our scene objects
*/
void	create_scene(t_window *ptr, t_scene *scene)
{
  int	x;
  int	y;
  int	wait;

  wait = 0;
  x = -1;
  if (scene->list_eye == NULL)
    my_puterror(ERR_EYE);
  my_write(1, "Please wait ...\n", my_strlen("Please wait ...\n"));
  while (++x < WIDTH)
    {
      if (x % (WIDTH / 10) == 0)
	{
	  display_progession(wait);
	  wait = wait + 10;
	}
      _loading_on_screen(x, ptr);
      mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->loading, 0, 0);
      y = -1;
      while (++y < HEIGHT)
	_calc(x, y, ptr, scene);
    }
  my_write(1, END, my_strlen(END));
}
