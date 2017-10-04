/*
** my_wall.c for my_wall in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jun 12 15:44:47 2014 mar_b mar_b
** Last update Sun Jun 15 03:53:44 2014 mar_b mar_b
*/

#include "mlx.h"
#include "wolf3d.h"
#include "my_calc.h"
#include "my_pixel.h"

/*
** brief: This function will write/display for each x
** @pr: the struct used to define the move, each ptr like the img etc...
** @x: is the horizontal position
** BRIEF: ID_WALL + cst is the value with the range
*/
static void	_my_write_wall(t_ptr *pr, int x)
{
  int		i;
  int	        wall_l;
  int		y;
  unsigned int	color;
  unsigned char	*wall;

  color = mlx_get_color_value(pr->mlx, ID_WALL + (pr->move->range_k * 8));
  wall_l = (HEIGHT / (2 * pr->move->range_k));
  y = ((HEIGHT / 2) * pr->pic->sizeline) + (x * pr->pic->bpp / 8);
  wall = (unsigned char *)&color;
  i = -1;
  while (++i < wall_l)
    {
      (void)my_put_pixel_to_img(pr->pic, wall, y - (i * pr->pic->sizeline));
      (void)my_put_pixel_to_img(pr->pic, wall, y + (i * pr->pic->sizeline));
    }
}

/*
** brief: This function will, for each pixel calculate the range with the wall
** @pr: the struct used to define the move, each ptr like the img etc...
** BRIEF: This function will, for each pixel calculate the range with the wall
** and "write" it with the my_write_wall function
** we initialize our x to 0.5 (half of case) and y = (win_x / 2 - i) / win_x
** apply a rotation : x' = x * cos(a) - y * sin(a), y' = x * sin(a) + y * cos(a)
** and the translation : x'' = x' + x0, y'' = y' + y0
*/
void	my_display_wall(t_ptr *pr)
{
  float x;
  float y;
  float i;

  i = -1;
  while (++i <= WIDTH)
    {
      y = (((WIDTH / 2) - i) / WIDTH);
      x = (0.5 * pr->move->cos_ang[pr->move->id_ang]) -
	(y * pr->move->sin_ang[pr->move->id_ang]);
      y = (0.5 * pr->move->sin_ang[pr->move->id_ang]) +
	(y * pr->move->cos_ang[pr->move->id_ang]);
      x += pr->move->pos->x;
      y += pr->move->pos->y;
      pr->move->range_k = my_range(pr, x, y);
      _my_write_wall(pr, i);
    }
}
