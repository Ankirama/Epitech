/*
** light.c for light in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Oct  3 18:40:41 2014 mar_b mar_b
** Last update Sun Oct 12 22:23:29 2014 charles viterbo
*/

#include <stdlib.h>
#include "utils.h"
#include "objects.h"

/*
** brief : create our struct light
** @scene : our scene
** @arr : our tab (informations)
*/
void		create_light(t_scene **scene, char **arr)
{
  t_light	*elt;

  if (my_arrlen(arr) < 7)
    my_warning_obj("light");
  else
    {
      elt = my_malloc(sizeof(*elt));
      elt->coord = create_vector(atof(arr[0]), atof(arr[1]), atof(arr[2]));
      elt->color = create_color(atoi(arr[3]), atoi(arr[4]), atoi(arr[5]));
      elt->puiss = atof(arr[6]);
      elt->next = (*scene)->list_light;
      (*scene)->list_light = elt;
    }
}

/*
** brief : free our struct light
** @scene : our scene
*/
void		free_light(t_scene *scene)
{
  t_light	*tmp;

  while (scene->list_light != NULL)
    {
      tmp = scene->list_light;
      scene->list_light = tmp->next;
      free(tmp->coord);
      free(tmp->color);
      free(tmp);
    }
}
