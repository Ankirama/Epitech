/*
** my_calc.c for my_calc in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jun 11 15:14:33 2014 mar_b mar_b
** Last update Fri Jun 13 18:59:47 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_error.h"
#include "wolf3d.h"

/*
** brief: this function will calculate our new position
** @par: the struct used to define the move, each ptr like the img etc...
** @up: if up == 1 -> the key pressed is up, up == 0 -> the key pressed is down
** @pos: will receive the new values for x and y
*/
void	my_move_xy(t_ptr *par, char up, t_vector **pos)
{
  if (up)
    {
      (*pos)->x = par->move->pos->x +
	(0.1 * par->move->cos_ang[par->move->id_ang]);
      (*pos)->y = par->move->pos->y +
	(0.1 * par->move->sin_ang[par->move->id_ang]);
    }
  else
    {
      (*pos)->x = par->move->pos->x -
	(0.1 * par->move->cos_ang[par->move->id_ang]);
      (*pos)->y = par->move->pos->y -
	(0.1 * par->move->sin_ang[par->move->id_ang]);
    }
}

/*
** brief: will check if the lab(x, y) is not the wall (wall = 1), if it's ok,
** we will change the player's position
** @par: the struct used to define the move, each ptr like the img etc...
** @pos: is the new position for the player, we will check this position
*/
void	my_check_collision(t_ptr *par, t_vector *pos)
{
  if (pos->x >= 0 && pos->x <= par->lab->x
      && pos->y >= 0 && pos->y <= par->lab->y &&
      par->lab->patrn[(int)pos->x][(int)pos->y] == '0')
    {
      par->move->pos->x = pos->x;
      par->move->pos->y = pos->y;
    }
}

/*
** brief: this function will calculate the range with the next wall
** @pr: the struct used to define the move, each ptr like the img etc...
** @x: real x in the map (X'') after transformation, (eg my_display_wall)
** @y: real y in the map (Y'') after transformation, (eg my_display_wall)
** BRIEF: i is equal to x0 + k * vectorX with vectorX = x'' - x0
**        j is equal to y0 + k * vectorY with vectorY = y'' - y0
** we will increase the range_k while there is no collision/wall
** return: return the new range for k
*/
float	my_range(t_ptr *pr, float x, float y)
{
  int	i;
  int	j;
  float	range_k;

  range_k = 1;
  i = x;
  j = y;
  while (pr->lab->patrn[i][j] == '0')
    {
      range_k += 0.01;
      i = pr->move->pos->x + (range_k * (x - pr->move->pos->x));
      j = pr->move->pos->y + (range_k * (y - pr->move->pos->y));
    }
  return (range_k);
}
