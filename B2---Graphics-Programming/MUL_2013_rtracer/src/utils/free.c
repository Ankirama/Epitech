/*
** free.c for let it go in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun Oct 12 15:01:51 2014 mar_b mar_b
** Last update Sun Oct 12 16:37:43 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "objects.h"
#include "rtracer.h"

/*
** brief: to free the string arr
*/
void	free_arr(char **arr)
{
  int	i;

  if (arr != NULL)
    {
      i = -1;
      while (arr[++i] != NULL)
	free(arr[i]);
      free(arr);
    }
}

/*
** brief: to free all element of the scene
*/
void	free_scene(t_scene *scene)
{
  free_cone(scene);
  free_eye(scene);
  free_orb(scene);
  free_plan(scene);
  free_cylinder(scene);
  free_light(scene);
  free(scene);
}

/*
** brief: it will free our main struct
*/
void	let_it_go(t_window *ptr)
{
  free(ptr->mlx);
  free(ptr->win);
  free(ptr->loading);
  free(ptr->img);
  free(ptr->background);
  free(ptr->pic);
  free(ptr->load);
  if (ptr->background != NULL)
    free(ptr->bg);
  free(ptr);
}
