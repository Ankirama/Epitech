/*
** plan.c for plan in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Oct  6 01:23:05 2014 mar_b mar_b
** Last update Sun Oct 12 21:38:02 2014 charles viterbo
*/

#include <math.h>
#include <stdlib.h>
#include "objects.h"
#include "rotation.h"
#include "utils.h"
#include "intersection.h"
#include "luminosite.h"

/*
** brief : intersection with a plan
** @v1 : our eye
** @v3 : our vector vision
** @cons : translation
*/
double		inter_plan(t_vector *v1, t_vector *v3, double cons)
{
  double	k;

  if (fabs(v1->z) >= 0.00001)
    {
      k = -1.0 * (v3->z + cons) / v1->z;
      return (k >= 0.0 ? k : -1);
    }
  return (-1);
}

/*
** brief : intersection for all plans
** @scene : our scene
** @eye : our eye
** @vision : vector vision
** @obj : the object the nearest
*/
void		all_plan(t_scene *scene, t_eye *eye,
			 t_vector *vision, t_dis *obj)
{
  t_plan	*plan;
  double	k;

  plan = scene->list_plan;
  while (plan != NULL)
    {
      to_simple(&(eye->coord), NULL, plan->rot);
      to_simple(&vision, NULL, plan->rot);
      if ((k = inter_plan(vision, eye->coord, plan->trans)) >= 0.0
	  && (k < obj->k || obj->k < 0.0)
	  && limit(vec_p(eye->coord, k, vision),
                   plan->limit_up, plan->limit_low))
	{
	  obj->type = PLAN;
	  obj->k = k;
	  obj->element = plan;
	}
      to_real_life(&(eye->coord), NULL, plan->rot);
      to_real_life(&vision, NULL, plan->rot);
      plan = plan->next;
    }
}

/*
** brief : create the point P for a plan
** @obj : our objects (a plan)
** @eye : our vector eye
** @vision : our vector vision
*/
t_vector	*create_p_plan(t_dis *obj, t_eye *eye, t_vector *vision)
{
  t_plan	*plan;
  t_vector	*point;

  plan	= obj->element;
  to_simple(&(eye->coord), plan->coord, plan->rot);
  to_simple(&(vision), plan->coord, plan->rot);
  point = create_vector(eye->coord->x + obj->k * vision->x,
			eye->coord->y + obj->k * vision->y,
			eye->coord->z + obj->k * vision->z);
  to_real_life(&(eye->coord), plan->coord, plan->rot);
  to_real_life(&(vision), plan->coord, plan->rot);
  return (point);
}

/*
** brief : this function will calculate the color for a plan
** @scene : our scene
** @obj : our object (a plan)
** @point : our point P
*/
t_color		*color_plan(t_scene *scene, t_dis *obj, t_vector *point)
{
  t_plan	*tmp;

  tmp = obj->element;
  return (lumi_plan(scene, tmp, point));
}
