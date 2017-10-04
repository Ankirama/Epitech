/*
** cone.c for cone in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  9 10:26:09 2014 mar_b mar_b
** Last update Sun Oct 12 22:13:51 2014 charles viterbo
*/

#include <stdlib.h>
#include "shadow.h"
#include "utils.h"
#include "intersection.h"
#include "objects.h"
#include "rotation.h"

static void	_set_const(double *cons, double type, double cst)
{
  cons[0] = type;
  cons[1] = cst;
}

/*
** brief : intersection with a paraboloide for the shadow
** @scene : our scene
** @l : our vector light
** @p : our vector P
*/
double		shadow_paraboloide(t_scene *scene, t_vector *l, t_vector *p)
{
  t_para	*para;
  t_vector	*tmp;
  double	k;
  double	cons[2];

  para = scene->list_para;
  while (para != NULL)
    {
      pass_to_simple(&p, &l, para->coord, para->rot);
      tmp = create_vector(l->x - p->x, l->y - p->y, l->z - p->z);
      _set_const(&cons[0], para->type, para->cst);
      if ((k = inter_paraboloide(tmp, para->coord, p, cons)) > 0.1 && k < 1.0
	  && limit(vec_p(p, k, tmp), para->limit_up, para->limit_low))
	{
	  pass_to_real(&p, &l, para->coord, para->rot);
	  free(tmp);
	  return (k);
	}
      pass_to_real(&p, &l, para->coord, para->rot);
      free(tmp);
      para = para->next;
    }
  return (-1);
}
