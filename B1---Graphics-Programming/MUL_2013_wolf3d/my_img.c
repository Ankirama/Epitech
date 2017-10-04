/*
** my_img.c for my_img in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Jun  7 02:45:21 2014 mar_b mar_b
** Last update Sun Jun 15 17:56:03 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "my_init.h"
#include "my_pixel.h"
#include "my_wall.h"
#include "my_error.h"
#include "my_img.h"
#include "my_calc.h"
#include "my_free.h"
#include "my_minimap.h"

/*
** brief: will display our image if the expose is used
** @param: the struct used to define the move, each ptr like the img etc...
** return: will return 0, a classical value for mlx_epose_hook
*/
int	my_expose(t_ptr *param)
{
  mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
  mlx_put_image_to_window(param->mlx, param->win, param->mini,
			  WIDTH - WIDTH_MINI, HEIGHT - HEIGHT_MINI);
  return (0);
}

/*
** brief: will initialize our char *data
** @ptr: the struct used to define the move, each ptr like the img etc...
** return: it will return our new struct
*/
t_img	*my_initimg(void *ptr)
{
  t_img	*img;

  if ((img = malloc(sizeof(*img))) == NULL)
    my_puterror("error: problem to malloc!\n");
  img->data = mlx_get_data_addr(ptr, &(img->bpp), &(img->sizeline),
				&(img->endian));
  return (img);
}

/*
** brief: this function will draw the ground and the sky
** @param: the struct used to define the move, each ptr like the img etc...
*/
void		my_sky_ground(t_ptr *param)
{
  int		i;
  int		k;
  unsigned int	color;
  unsigned char	*ground;

  color = mlx_get_color_value(param->mlx, ID_GROUND);
  ground = (unsigned char *)&color;
  i = 0;
  k = 0;
  while (i < (param->pic->sizeline * (HEIGHT / 2)))
    i = my_img_to_pixel(param, param->sky_p, i, &k);
  while (i < HEIGHT * param->pic->sizeline)
    i = my_put_pixel_to_img(param->pic, ground, i);
  my_fill_minimap(param);
}

/*
** brief: this function will check the collisions, will draw the sky and ground,
** display each wall and put it to the window
** @param: the struct used to define the move, each ptr like the img etc...
** @pos: is the new position, we will set the player's position
** if there is no collision
*/
void	my_wall(t_ptr *param, t_vector *pos)
{
  my_check_collision(param, pos);
  my_sky_ground(param);
  my_display_wall(param);
  mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
  mlx_put_image_to_window(param->mlx, param->win, param->mini,
			  WIDTH - WIDTH_MINI, HEIGHT - HEIGHT_MINI);
}
