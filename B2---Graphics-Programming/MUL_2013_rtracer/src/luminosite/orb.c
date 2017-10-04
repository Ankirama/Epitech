/*
** orb.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/luminosite
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Mon Oct  6 14:17:30 2014 charles viterbo
** Last update Sun Oct 12 22:49:24 2014 charles viterbo
*/

#include <stdlib.h>
#include <math.h>
#include "luminosite.h"
#include "objects.h"
#include "utils.h"
#include "noise.h"

/*
** brief : calculate color for the orb
** @angle : angle from luminosity
** @orb : our struct orb
** @light : our struct light
*/
static t_color	*_calc(double angle, t_orb *orb, t_light *l)
{
  return (create_color((orb->color->r * angle * (1.0 - orb->brill) +
			l->color->r * orb->brill * angle) * l->puiss / 100,
		       (orb->color->g * angle * (1.0 - orb->brill) +
			l->color->g * orb->brill * angle) * l->puiss / 100,
		       (orb->color->b * angle * (1.0 - orb->brill) +
			l->color->b * orb->brill * angle) * l->puiss / 100));
}

/*
** brief : color without ambiance luminosity
** @our struct light
** @p : our vector P
** @color : orb's color
*/
static void	_normal_orb(t_light *l, t_vector *p,
			    t_orb *orb, t_color **color)
{
  double	angle;
  t_color	*tmp;

  angle = calc_angle(p, l->coord, p, orb->pn);
  if (!(angle < 0.00001))
    {
      tmp = _calc(angle, orb, l);
      add_colors(color, tmp);
      free(tmp);
    }
}

/*
** brief : color with ambiance luminosity
** @our struct light
** @p : our vector P
** @color : orb's color
*/
static void	_normal_orb_amb(t_light *l, t_vector *p,
				t_orb *orb, t_color **color)
{
  double	angle;
  t_color	*tmp;

  angle = calc_angle_amb(p, l->coord, p, orb->pn);
  if (!(angle < 0.00001))
    {
      tmp = _calc(angle, orb, l);
      add_colors(color, tmp);
      free(tmp);
    }
}

/*
** brief : color with perlin
** @orb struct orb
** @color : our color
** @point : our vector point
*/
static void	_perlin(t_orb *orb, t_color **color, t_vector *point)
{
  t_color	*tmp;

  if (orb->perlin)
    {
      tmp = choose_color(perlin_noise(point));
      (*color)->r = ((*color)->r + tmp->r) & 255;
      (*color)->g = ((*color)->g + tmp->g) & 255;
      (*color)->b = ((*color)->b + tmp->b) & 255;
    }
}

/*
** brief : for a orb determine its luminosity
** @scene : our scene
** @orn : our orb
** @point : our vector point P
** return : the color
*/
t_color		*lumi_orb(t_scene *scene, t_orb *orb, t_vector *point)
{
  t_color	*color;
  int		nb_l;
  t_light	*light;

  nb_l = 0;
  light = scene->list_light;
  if (light == NULL)
    return (orb->color);
  color = create_color(0, 0, 0);
  while (light != NULL)
    {
      nb_l++;
      to_simple(&(light)->coord, orb->coord, NULL);
      if (scene->ambiance)
	_normal_orb_amb(light, point, orb, &color);
      else
	_normal_orb(light, point, orb, &color);
      to_real_life(&(light)->coord, orb->coord, NULL);
      light = light->next;
    }
  div_color(&color, nb_l);
  _perlin(orb, &color, point);
  return (color);
}
