/*
** orb.c<2> for orb in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Oct  3 16:31:38 2014 mar_b mar_b
** Last update Sun Oct 12 22:24:23 2014 charles viterbo
*/

#include <stdlib.h>
#include "objects.h"
#include "utils.h"

/*
** brief : create our struct orb
** @scene : our scene
** @arr : our array (informations needed)
*/
void	create_orb(t_scene **scene, char **arr)
{
  t_orb	*my_orb;

  if (my_arrlen(arr) < 18)
    my_warning_obj("orb");
  else
    {
      my_orb = my_malloc(sizeof(*my_orb));
      my_orb->coord = create_vector(atof(arr[0]), atof(arr[1]), atof(arr[2]));
      my_orb->radius = atof(arr[3]);
      my_orb->color = create_color(atoi(arr[4]), atoi(arr[5]), atoi(arr[6]));
      my_orb->brill = atof(arr[7]);
      my_orb->pn = create_vector(atof(arr[8]), atof(arr[9]), atof(arr[10]));
      my_orb->limit_up = create_vector(atof(arr[11]),
				       atof(arr[12]), atof(arr[13]));
      my_orb->limit_low = create_vector(atof(arr[14]),
					atof(arr[15]), atof(arr[16]));
      my_orb->perlin = atoi(arr[17]);
      my_orb->next = (*scene)->list_orb;
      (*scene)->list_orb = my_orb;
    }
}

/*
** brief : free scene
** @scene : our scene
*/
void	free_orb(t_scene *scene)
{
  t_orb	*tmp;

  while (scene->list_orb != NULL)
    {
      tmp = scene->list_orb;
      scene->list_orb = tmp->next;
      free(tmp->coord);
      free(tmp->color);
      free(tmp);
    }
}
