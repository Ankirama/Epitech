/*
** cone.c for cone in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  9 10:26:09 2014 mar_b mar_b
** Last update Sun Oct 12 18:25:57 2014 charles viterbo
*/

#include <stdlib.h>
#include "shadow.h"
#include "utils.h"
#include "intersection.h"
#include "objects.h"
#include "rotation.h"

/*
** brief : this functions is to set cons
** @cons : a tab of int
** @angle : cone's angle
** @hyper : if hyper > 0 2 nappes & < 0 1 nappe
*/
static void	_set_const(double *cons, double angle, double hyper)
{
  cons[0] = angle;
  cons[1] = hyper;
}

/*
** brief : this function is to find the cone's shadow
** @scene : our scene
** @l : the vector light
** @p : the vector P
** return : the distance between P and the cone or -1 if cone
** is not find
*/
double		shadow_cones(t_scene *scene, t_vector *l, t_vector *p)
{
  t_cone	*cones;
  t_vector	*tmp;
  double	k;
  double	cons[2];

  cones = scene->list_cone;
  while (cones != NULL)
    {
      pass_to_simple(&p, &l, cones->coord, cones->rot);
      tmp = create_vector(l->x - p->x, l->y - p->y, l->z - p->z);
      _set_const(&cons[0], cones->angle, cones->hyper);
      if ((k = inter_cone(tmp, p, cons)) > 0 && k < 1 &&
	  limit(vec_p(p, k, tmp), cones->limit_up, cones->limit_low))
	{
	  pass_to_real(&p, &l, cones->coord, cones->rot);
	  free(tmp);
	  return (k);
	}
      pass_to_real(&p, &l, cones->coord, cones->rot);
      free(tmp);
      cones = cones->next;
    }
  return (-1);
}
