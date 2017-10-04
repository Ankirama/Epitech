/*
** free.c for free in /home/user/rendu/MUL_2013_rtv1
**
** Made by 
** Login   
**
** Started on  Fri Jul 11 18:10:11 2014 
** Last update Thu Jul 24 23:52:13 2014 
*/

#include <stdlib.h>
#include "rtv1.h"
#include "objects.h"

/*
** brief: Frozen 2013 (will free our struct)
** @param: the struct used to define the move, each ptr like the img etc...
*/
void		let_it_go(t_window *param)
{
  free(param->mlx);
  free(param->win);
  free(param->img);
  free(param->pic);
  free_spheres(param->scene->spheres);
  free_spots(param->scene->spots);
  free_planes(param->scene->planes);
  free_cones(param->scene->cones);
  free_cylinders(param->scene->cylinders);
  free(param->scene->eye);
  free(param->scene);
  free(param);
  exit(EXIT_SUCCESS);
}
