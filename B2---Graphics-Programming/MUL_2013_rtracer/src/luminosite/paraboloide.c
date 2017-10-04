/*
** cone.c for cone in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Oct  7 21:01:19 2014 mar_b mar_b
** Last update Sun Oct 12 22:52:11 2014 chenev_d chenev_d
*/

#include <stdlib.h>
#include "objects.h"
#include "luminosite.h"
#include "utils.h"
#include "rotation.h"

/*
** brief: color without ambiance luminosity
** @l: our struct light
** @p: our vector P
** @para: our struct paraboloide
** @color: paraboloide's color
*/
static void	_normal_paraboloide(t_light *l, t_vector *p,
				    t_para *para, t_color **color)
{
  double	angle;
  t_vector	*vn;

  vn = create_vector(p->x, p->y, (-1.0) * para->cst);
  angle = calc_angle(p, l->coord, vn, para->pn);
  free(vn);
  if (!(angle < 0.00001))
    {
      (*color)->r += (para->color->r * angle * (1.0 - para->brill) +
		      l->color->r * para->brill * angle) * l->puiss / 100;
      (*color)->g += (para->color->g * angle * (1.0 - para->brill) + l->color->g
		      * para->brill * angle) * l->puiss / 100;
      (*color)->b += (para->color->b * angle * (1.0 - para->brill) + l->color->b
		      * para->brill * angle) * l->puiss / 100;
    }
}

/*
** brief: for a paraboloide determine its luminosity
** @scene: our scene
** @para: our paraboloide
** @point: our vector point P
** return: the color
*/
t_color		*lumi_paraboloide(t_scene *scene, t_para *para, t_vector *point)
{
  t_color	*color;
  int		nb_l;
  t_light	*light;

  nb_l = 0;
  light = scene->list_light;
  color = create_color(0, 0, 0);
  if (light == NULL)
    return (para->color);
  while (light != NULL)
    {
      ++nb_l;
      to_simple(&(light)->coord, para->coord, para->rot);
      _normal_paraboloide(light, point, para, &color);
      to_real_life(&(light)->coord, para->coord, para->rot);
      light = light->next;
    }
  color->r = color->r / nb_l;
  color->g = color->g / nb_l;
  color->b = color->b / nb_l;
  return (color);
}
