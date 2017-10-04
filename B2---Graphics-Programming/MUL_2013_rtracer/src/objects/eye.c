/*
** eye.c for eye in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Oct  3 17:43:52 2014 mar_b mar_b
** Last update Sun Oct 12 22:21:43 2014 charles viterbo
*/

#include <stdlib.h>
#include "utils.h"
#include "objects.h"

/*
** brief : create our struct eye
** @scene : our scene
** @arr : our tab (informations)
*/
void	create_eye(t_scene **scene, char **arr)
{
  t_eye	*elt;

  if (my_arrlen(arr) < 6)
    my_warning_obj("eye");
  else
    {
      elt = my_malloc(sizeof(*elt));
      elt->coord = create_vector(atof(arr[0]), atof(arr[1]), atof(arr[2]));
      elt->rot = create_vector(atof(arr[3]), atof(arr[4]), atof(arr[5]));
      elt->next = (*scene)->list_eye;
      (*scene)->list_eye = elt;
    }
}

/*
** brief : free our struct eye
** @scene : our struct scene
*/
void	free_eye(t_scene *scene)
{
  t_eye	*tmp;

  while (scene->list_eye != NULL)
    {
      tmp = scene->list_eye;
      scene->list_eye = tmp->next;
      free(tmp->coord);
      free(tmp->rot);
      free(tmp);
    }
}
