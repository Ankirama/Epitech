/*
** cone.c for cone in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Oct  3 17:50:31 2014 mar_b mar_b
** Last update Sun Oct 12 22:20:09 2014 charles viterbo
*/

#include <stdlib.h>
#include "utils.h"
#include "objects.h"

/*
** brief : create our struct cone
** @scene : our scene
** @arr : our tab
*/
void		create_cone(t_scene **scene, char **arr)
{
  t_cone	*elt;

  elt = my_malloc(sizeof(*elt));
  if (my_arrlen(arr) < 21)
    my_warning_obj("cone");
  else
    {
      elt->coord = create_vector(atof(arr[0]), atof(arr[1]), atof(arr[2]));
      elt->angle = atof(arr[3]);
      elt->rot = create_vector(atof(arr[4]), atof(arr[5]), atof(arr[6]));
      elt->color = create_color(atoi(arr[7]), atoi(arr[8]), atoi(arr[9]));
      elt->brill = atof(arr[10]);
      elt->hyper = atof(arr[11]);
      elt->pn = create_vector(atof(arr[12]), atof(arr[13]), atof(arr[14]));
      elt->limit_up = create_vector(atof(arr[15]), atof(arr[16]),
				    atof(arr[17]));
      elt->limit_low = create_vector(atof(arr[18]), atof(arr[19]),
				     atof(arr[20]));
      elt->next = (*scene)->list_cone;
      (*scene)->list_cone = elt;
    }
}

/*
** brief : free the struct cone
** @scene : our scene
*/
void		free_cone(t_scene *scene)
{
  t_cone	*tmp;

  while (scene->list_cone != NULL)
    {
      tmp = scene->list_cone;
      scene->list_cone = tmp->next;
      free(tmp->coord);
      free(tmp->rot);
      free(tmp->color);
      free(tmp);
    }
}
