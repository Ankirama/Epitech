/*
** cylinder.c for cylinder in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Oct  7 23:21:35 2014 mar_b mar_b
** Last update Sun Oct 12 22:38:53 2014 charles viterbo
*/

#include <stdlib.h>
#include "objects.h"
#include "luminosite.h"
#include "utils.h"
#include "rotation.h"

/*
** brief : calculate color for the cylinder
** @angle : angle from luminosity
** @cylinder : our struct cylinder
** @light : our struct light
*/
static t_color	*_calc(double angle, t_cylinder *cyl, t_light *l)
{
  return (create_color((cyl->color->r * angle * (1.0 - cyl->brill) +
			l->color->r * cyl->brill * angle) * l->puiss / 100,
		       (cyl->color->g * angle * (1.0 - cyl->brill) +
			l->color->g * cyl->brill * angle) * l->puiss / 100,
		       (cyl->color->b * angle * (1.0 - cyl->brill) +
			l->color->b * cyl->brill * angle) * l->puiss / 100));
}

/*
** brief : color without ambiance luminosity
** @our struct light
** @p : our vector P
** @cyl : cylinder's color
*/
static void	_normal_cyl(t_light *l, t_vector *p,
			    t_cylinder *cyl, t_color **color)
{
  double	angle;
  t_vector	*vn;
  t_color	*tmp;

  vn = create_vector(p->x, p->y, 0.0);
  angle = calc_angle(vn, l->coord, p, cyl->pn);
  free(vn);
  if (!(angle < 0.00001))
    {
      tmp = _calc(angle, cyl, l);
      add_colors(color, tmp);
      free(tmp);
    }
}

/*
** brief : color with ambiance luminosity
** @light : our struct light
** @p : our vector P
** @cyl : our cylinder
** @color : the color of the cylinder
*/
static void	_normal_cyl_amb(t_light *l, t_vector *p,
				t_cylinder *cyl, t_color **color)
{
  double	angle;
  t_vector	*vn;
  t_color	*tmp;

  vn = create_vector(p->x, p->y, 0.0);
  angle = calc_angle_amb(vn, l->coord, p, cyl->pn);
  free(vn);
  if (!(angle < 0.00001))
    {
      tmp = _calc(angle, cyl, l);
      add_colors(color, tmp);
      free(tmp);
    }
}

/*
** brief : for a cylinder determine its luminosity
** @scene : our scene
** @cylinder : our cylinder
** @point : our vector point P
** return : the color
*/
t_color		*lumi_cyl(t_scene *scene, t_cylinder *cyl, t_vector *point)
{
  t_color	*color;
  t_light	*light;
  int		nb_l;

  nb_l = 0;
  light = scene->list_light;
  if (light == NULL)
    return (cyl->color);
  color = create_color(0, 0, 0);
  while (light != NULL)
    {
      ++nb_l;
      to_simple(&(light)->coord, cyl->coord, cyl->rot);
      if (scene->ambiance)
	_normal_cyl_amb(light, point, cyl, &color);
      else
	_normal_cyl(light, point, cyl, &color);
      to_real_life(&(light)->coord, cyl->coord, cyl->rot);
      light = light->next;
    }
  div_color(&color, nb_l);
  return (color);
}
