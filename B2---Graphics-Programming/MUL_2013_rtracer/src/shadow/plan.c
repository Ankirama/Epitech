/*
** plan.c for  in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  9 11:07:52 2014 mar_b mar_b
** Last update Sun Oct 12 22:14:26 2014 charles viterbo
*/

#include <stdlib.h>
#include "shadow.h"
#include "utils.h"
#include "intersection.h"
#include "objects.h"
#include "rotation.h"

/*
** brief : intersection with a plan for the shadow
** @scene : our scene
** @l : our vector light
** @p : our vector P
*/
double		shadow_plan(t_scene *scene, t_vector *l, t_vector *p)
{
  t_plan	*plans;
  t_vector	*tmp;
  double	k;

  plans = scene->list_plan;
  while (plans != NULL)
    {
      pass_to_simple(&p, &l, NULL, plans->rot);
      tmp = create_vector(l->x - p->x, l->y - p->y, l->z - p->z);
      if ((k = inter_plan(tmp, p, plans->trans)) > 0 && k < 1 &&
	  limit(vec_p(p, k, tmp), plans->limit_up, plans->limit_low))
	{
	  pass_to_real(&p, &l, NULL, plans->rot);
	  free(tmp);
	  return (k);
	}
      pass_to_real(&p, &l, NULL, plans->rot);
      free(tmp);
      plans = plans->next;
    }
  return (-1);
}
