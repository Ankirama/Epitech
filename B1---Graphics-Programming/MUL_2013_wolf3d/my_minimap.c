/*
** my_minimap.c for my_minimap.c in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Jun 14 19:13:24 2014 mar_b mar_b
** Last update Sun Jun 15 17:37:59 2014 mar_b mar_b
*/

#include "mlx.h"
#include "wolf3d.h"
#include "my_pixel.h"

/*
** brief it will color the "range" for our wall
** @size: the wall's length
** @x: the wall's x_position
** @y: the wall's y_position
** @pr: the struct used to define the move, each ptr like the img etc...
*/
static void	_my_fill_wall(int size, int x, int y, t_ptr *pr)
{
  int		i;
  int		j;
  unsigned int	tmp;
  unsigned char	*color;

  tmp = mlx_get_color_value(pr->mlx, 0xFFFFFF);
  color = (unsigned char *)&tmp;
  j = (y * size);
  while (j < (y * size) + size)
    {
      i = (x * size);
      while (i < (x * size) + size)
	{
	  my_put_pixel_to_mini(pr->mini_p, i, j, color);
	  ++i;
	}
      ++j;
    }
}

/*
** brief it will color the "range" for our player
** @size: the player's length
** @x: the player's x_position
** @y: the player's y_position
** @pr: the struct used to define the move, each ptr like the img etc...
*/
static void	_my_fill_player(int size, int x, int y, t_ptr *pr)
{
  int		i;
  int		j;
  unsigned int	tmp;
  unsigned char	*color;

  tmp = mlx_get_color_value(pr->mlx, 0xFF0000);
  color = (unsigned char *)&tmp;
  j = (y * size);
  while (j < (y * size) + size)
    {
      i = (x * size);
      while (i < (x * size) + size)
	{
	  my_put_pixel_to_mini(pr->mini_p, i, j, color);
	  ++i;
	}
      ++j;
    }
}

/*
** brief: we will travel our maze and check each position
** @pr: the struct used to define the move, each ptr like the img etc...
*/
static void	_my_find_maze(t_ptr *pr)
{
  int		size;
  int		i;
  int		j;

  size = WIDTH_MINI / pr->lab->x;
  i = -1;
  while (++i < pr->lab->x)
    {
      j = -1;
      while (++j < pr->lab->y)
	{
	  if (pr->lab->patrn[i][j] == '0')
	    _my_fill_wall(size, i, j, pr);
	}
    }
}

/*
** brief: we will color the player's position
** @pr: the struct used to define the move, each ptr like the img etc...
*/
static void	_my_find_player(t_ptr *pr)
{
  int		size;

  size = WIDTH_MINI / pr->lab->x;
  _my_fill_player(size, (int)pr->move->pos->x, (int)pr->move->pos->y, pr);
}

/*
** brief: this function will create our minimap
** @pr: the struct used to define the move, each ptr like the img etc...
*/
void		my_fill_minimap(t_ptr *pr)
{
  int		i;
  int		j;
  unsigned int	color;
  unsigned char	*minimap;

  color = mlx_get_color_value(pr->mlx, 0x000000);
  minimap = (unsigned char *)&color;
  j = -1;
  while (++j < HEIGHT_MINI)
    {
      i = -1;
      while (++i < WIDTH_MINI)
	my_put_pixel_to_mini(pr->mini_p, i, j, minimap);
    }
  _my_find_maze(pr);
  _my_find_player(pr);
}
