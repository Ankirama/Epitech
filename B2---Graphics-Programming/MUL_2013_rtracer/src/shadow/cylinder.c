/*
** cylinder.c for cylinder in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  9 11:04:36 2014 mar_b mar_b
** Last update Sun Oct 12 22:12:47 2014 charles viterbo
*/

#include <stdlib.h>
#include "shadow.h"
#include "utils.h"
#include "intersection.h"
#include "objects.h"
#include "rotation.h"

/*
** brief : intersection with a cylinder for the shadow
** @scene : our scene
** @l : our vector light
** @p : our vector P
*/
double		shadow_cylinder(t_scene *scene, t_vector *l, t_vector *p)
{
  t_cylinder	*cyls;
  t_vector	*tmp;
  double	k;

  cyls = scene->list_cyl;
  while (cyls != NULL)
    {
      pass_to_simple(&p, &l, cyls->coord, cyls->rot);
       tmp = create_vector(l->x - p->x, l->y - p->y, l->z - p->z);
      if ((k = inter_cylinder(tmp, p, cyls->radius)) > 0 && k < 1 &&
	  limit(vec_p(p, k, tmp), cyls->limit_up, cyls->limit_low))
	{
	  pass_to_real(&p, &l, cyls->coord, cyls->rot);
          free(tmp);
	  return (k);
	}
      pass_to_real(&p, &l, cyls->coord, cyls->rot);
      free(tmp);
      cyls = cyls->next;
    }
  return (-1);
}
