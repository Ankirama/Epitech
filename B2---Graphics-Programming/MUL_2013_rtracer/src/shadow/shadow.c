/*
** shadow.c for shadow in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  9 10:26:00 2014 mar_b mar_b
** Last update Sun Oct 12 22:16:10 2014 charles viterbo
*/

#include <stdlib.h>
#include "objects.h"
#include "utils.h"
#include "intersection.h"
#include "shadow.h"

static t_inter_shadow	g_my_shadow[FUNC] =
  {
    {shadow_cones},
    {shadow_cylinder},
    {shadow_plan},
    {shadow_orb},
    {shadow_paraboloide}
  };

/*
** brief : this function pass p & l to simple coordinates
** @p : the vector P
** @l : the vector light
** @coord : the translation
** @rot : the rotation
*/
void	pass_to_simple(t_vector **p, t_vector **l,
		       t_vector *coord, t_vector *rot)
{
  to_simple(p, coord, rot);
  to_simple(l, coord, rot);
}

/*
** brief : this function pass p & l to real coordinates
** @p : the vector P
** @l : the vector light
** @coord : the translation
** @rot : the rotation
*/
void	pass_to_real(t_vector **p, t_vector **l,
		       t_vector *coord, t_vector *rot)
{
  to_real_life(p, coord, rot);
  to_real_life(l, coord, rot);
}

/*
** brief : intersection between all the lights and our point P
** @scene : our scene
** @light : our vector light
** @p : our vector P
*/
static char	_my_inter_light(t_scene *scene, t_vector *light, t_vector *p)
{
  int		i;
  double	k;

  i = 0;
  while (i < FUNC)
    {
      k = g_my_shadow[i].fun(scene, light, p);
      ++i;
      if (k > 0.0001 && k < 1)
	return (1);
    }
  return (0);
}

/*
** brief : when all the intersections are done walculte the color
** @scene : our scene
** @shadow : our vector P
** @color : our color
** return : the real color (with shadow)
*/
t_color		*my_shadow(t_scene *scene, t_vector *shadow, t_color *color)
{
  t_light	*l;
  int		nbr_shadow;
  int		nbr_ls;

  l = scene->list_light;
  nbr_shadow = 0;
  nbr_ls = 0;
  if (l == NULL)
    return (color);
  while (l != NULL)
    {
      if (_my_inter_light(scene, l->coord, shadow))
	++nbr_shadow;
      l = l->next;
      ++nbr_ls;
    }
  color->r *= 1.0 - (float)nbr_shadow / (float)nbr_ls;
  color->g *= 1.0 - (float)nbr_shadow / (float)nbr_ls;
  color->b *= 1.0 - (float)nbr_shadow / (float)nbr_ls;
  return (color);
}
