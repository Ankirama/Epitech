/*
** my_free.c for my_free in /home/mar_b/rendu/MUL_2013_wolf3d
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jun 11 15:48:03 2014 mar_b mar_b
** Last update Sun Jun 15 17:52:29 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "wolf3d.h"

/*
** brief: Frozen 2013 (will free our struct)
** @param: the struct used to define the move, each ptr like the img etc...
*/
void	let_it_go(t_ptr *param)
{
  free(param->mlx);
  free(param->sky);
  free(param->win);
  free(param->img);
  free(param->mini);
  free(param->sky_p);
  free(param->mini_p);
  free(param->pic);
  free(param->move->pos);
  free(param->move);
  free(param->lab);
  free(param);
  exit(EXIT_SUCCESS);
}

/*
** brief: pretty useless but dont want to create a file with 1 function
** @pos: this is the vector we'll free
*/
void	my_free_vec(t_vector *pos)
{
  free(pos);
}
