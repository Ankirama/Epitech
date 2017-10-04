/*
** orb.c for orb in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  9 11:09:17 2014 mar_b mar_b
** Last update Sun Oct 12 22:13:19 2014 charles viterbo
*/

#include <stdlib.h>
#include "shadow.h"
#include "utils.h"
#include "intersection.h"
#include "objects.h"
#include "rotation.h"

/*
** brief : intersection with a orb for the shadow
** @scene : our scene
** @l : our vector light
** @p : our vector P
*/
double		shadow_orb(t_scene *scene, t_vector *l, t_vector *p)
{
  t_orb		*orb;
  t_vector	*tmp;
  double	k;

  orb = scene->list_orb;
  while (orb != NULL)
    {
      pass_to_simple(&p, &l, orb->coord, NULL);
      tmp = create_vector(l->x - p->x, l->y - p->y,
			  l->z - p->z);
      if ((k = inter_orb(tmp,  p, orb->radius)) > 0 && k < 1 &&
	  limit(vec_p(p, k, tmp), orb->limit_up, orb->limit_low))
	{
	  pass_to_real(&p, &l, orb->coord, NULL);
	  free(tmp);
	  return (k);
	}
      pass_to_real(&p, &l, orb->coord, NULL);
      free(tmp);
      orb = orb->next;
    }
  return (-1);
}
