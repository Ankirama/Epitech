/*
** cone.c for cone in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Oct  7 21:01:19 2014 mar_b mar_b
** Last update Sun Oct 12 22:48:04 2014 charles viterbo
*/

#include <stdlib.h>
#include "objects.h"
#include "luminosite.h"
#include "utils.h"
#include "rotation.h"

/*
** brief : calculate color for the cone
** @angle : angle from luminosity
** @cone : our struct cone
** @light : our struct light
*/
static t_color	*_calc(double angle, t_cone *cone, t_light *l)
{
  return (create_color((cone->color->r * angle * (1.0 - cone->brill) +
			l->color->r * cone->brill * angle) * l->puiss / 100,
		       (cone->color->g * angle * (1.0 - cone->brill) +
			l->color->g * cone->brill * angle) * l->puiss / 100,
		       (cone->color->b * angle * (1.0 - cone->brill) +
			l->color->b * cone->brill * angle) * l->puiss / 100));
}

/*
** brief : color without ambiance luminosity
** @our struct light
** @p : our vector P
** @color : cone's color
*/
static void	_normal_cone(t_light *l, t_vector *p,
			     t_cone *cone, t_color **color)
{
  double	angle;
  t_vector	*vn;
  t_color	*tmp;

  vn = create_vector(p->x, p->y, (-1.0) * cone->angle * p->z);
  angle = calc_angle(p, l->coord, vn, cone->pn);
  free(vn);
  if (!(angle < 0))
    {
      tmp = _calc(angle, cone, l);
      add_colors(color, tmp);
      free(tmp);
    }
}

/*
** brief : color with ambiance luminosity
** @light : our struct light
** @p : our vector P
** @cone : our cone
** @color : the color of the cone
*/
static void	_normal_cone_amb(t_light *l, t_vector *p,
				 t_cone *cone, t_color **color)
{
  double	angle;
  t_vector	*vn;
  t_color	*tmp;

  vn = create_vector(p->x, p->y, (-1.0) * cone->angle * p->z);
  angle = calc_angle_amb(p, l->coord, vn, cone->pn);
  free(vn);
  if (!(angle < 0.00001))
    {
      tmp = _calc(angle, cone, l);
      add_colors(color, tmp);
      free(tmp);
    }
}

/*
** brief : for a cone determine its luminosity
** @scene : our scene
** @cone : our cone
** @point : our vector point P
** return : the color
*/
t_color		*lumi_cone(t_scene *scene, t_cone *cone, t_vector *point)
{
  t_color	*color;
  int		nb_l;
  t_light	*light;

  nb_l = 0;
  light = scene->list_light;
  if (light == NULL)
    return (cone->color);
  color = create_color(0, 0, 0);
  while (light != NULL)
    {
      ++nb_l;
      to_simple(&(light)->coord, cone->coord, cone->rot);
      if (scene->ambiance)
	_normal_cone_amb(light, point, cone, &color);
      else
	_normal_cone(light, point, cone, &color);
      to_real_life(&(light)->coord, cone->coord, cone->rot);
      light = light->next;
    }
  div_color(&color, nb_l);
  return (color);
}
