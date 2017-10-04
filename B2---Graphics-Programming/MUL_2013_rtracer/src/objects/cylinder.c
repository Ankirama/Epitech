/*
** cylinder.c for cylinder in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Oct  3 18:26:42 2014 mar_b mar_b
** Last update Sun Oct 12 22:20:53 2014 charles viterbo
*/

#include <stdlib.h>
#include "utils.h"
#include "objects.h"

/*
** brief : create our struct cylinder
** @scene : our scene
** @arr : our tab
*/
void		create_cylinder(t_scene **scene, char **arr)
{
  t_cylinder	*elt;

  if (my_arrlen(arr) < 20)
    my_warning_obj("cylinder");
  else
    {
      elt = my_malloc(sizeof(*elt));
      elt->coord = create_vector(atof(arr[0]), atof(arr[1]), atof(arr[2]));
      elt->radius = atof(arr[3]);
      elt->rot = create_vector(atof(arr[4]), atof(arr[5]), atof(arr[6]));
      elt->color = create_color(atoi(arr[7]), atoi(arr[8]), atoi(arr[9]));
      elt->brill = atof(arr[10]);
      elt->pn = create_vector(atof(arr[11]), atof(arr[12]), atof(arr[13]));
      elt->limit_up = create_vector(atof(arr[14]), atof(arr[15]),
				    atof(arr[16]));
      elt->limit_low = create_vector(atof(arr[17]), atof(arr[18]),
				     atof(arr[19]));
      elt->next = (*scene)->list_cyl;
      (*scene)->list_cyl = elt;
    }
}

/*
** brief : free struct cylinder
** @scene : our scene
*/
void		free_cylinder(t_scene *scene)
{
  t_cylinder	*tmp;

  while (scene->list_cyl != NULL)
    {
      tmp = scene->list_cyl;
      scene->list_cyl = tmp->next;
      free(tmp->coord);
      free(tmp->rot);
      free(tmp->color);
      free(tmp);
    }
}
