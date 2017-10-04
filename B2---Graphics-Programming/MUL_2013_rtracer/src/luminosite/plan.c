/*
** plan.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/luminosite
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Tue Oct  7 20:47:53 2014 charles viterbo
** Last update Sun Oct 12 22:48:54 2014 chenev_d chenev_d
*/

#include <stdlib.h>
#include <math.h>
#include "objects.h"
#include "rotation.h"
#include "utils.h"
#include "luminosite.h"


/*
** brief: calculate color for the plan
** @angle: angle for luminosity
** @plan: our struct plan
** @light: our struct light
*/
static t_color	*_calc(double angle, t_plan *plan, t_light *l)
{
  return (create_color((plan->color->r * angle * (1.0 - plan->brill) +
			l->color->r * plan->brill * angle) * l->puiss / 100,
		       (plan->color->g * angle * (1.0 - plan->brill) +
			l->color->g * plan->brill * angle) * l->puiss / 100,
		       (plan->color->b * angle * (1.0 - plan->brill) +
			l->color->b * plan->brill * angle) * l->puiss / 100));
}

/*
** brief: color withoyt ambiance luminosity
** @l: struct light
** @p: our vector p
** @color: plan's color
*/
static void	_normal_plan(t_light *l, t_vector *p,
			     t_plan *plan, t_color **color)
{
  t_vector	*vn;
  double	angle;
  t_color	*tmp;

  (void)p;
  vn = create_vector(0.0, 0.0, 100.0 + plan->trans);
  angle = calc_angle(vn, l->coord, p, plan->pn);
  free(vn);
  if (!(angle < 0.00001))
    {
      tmp = _calc(angle, plan, l);
      add_colors(color, tmp);
      free(tmp);
    }
}

/*
** brief: color with ambiance luminosity
** @l: our strcut light
** @p: our vector P
** @plan: our plan
** @color: the color of the plan
*/
static void	_normal_plan_amb(t_light *l, t_vector *p,
				 t_plan *plan, t_color **color)
{
  t_vector	*vn;
  double	angle;
  t_color	*tmp;

  (void)p;
  vn = create_vector(0.0, 0.0, 100.0 + plan->trans);
  angle = calc_angle_amb(vn, l->coord, p, plan->pn);
  free(vn);
  if (!(angle < 0.00001))
    {
      tmp = _calc(angle, plan, l);
      add_colors(color, tmp);
      free(tmp);
    }
}

/*
** brief: for a plan determine its luminosity
** @scene: our scene
** @plan: our plan
** @point: our vector point P
** return: the color
*/
t_color		*lumi_plan(t_scene *scene, t_plan *plan, t_vector *point)
{
  t_color	*color;
  int		nb_l;
  t_light	*light;

  nb_l = 0;
  light = scene->list_light;
  color = create_color(0, 0, 0);
  if (light == NULL)
    {
      free(color);
      return (plan->color);
    }
  while (light != NULL)
    {
      nb_l++;
      to_simple(&(light)->coord, plan->coord, plan->rot);
      if (scene->ambiance)
	_normal_plan_amb(light, point, plan, &color);
      else
	_normal_plan(light, point, plan, &color);
      to_real_life(&(light)->coord, plan->coord, plan->rot);
      light = light->next;
    }
  div_color(&color, nb_l);
  return (color);
}
