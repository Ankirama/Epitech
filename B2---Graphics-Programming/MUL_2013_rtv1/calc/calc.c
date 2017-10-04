/*
** calc.c for calc in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 19:07:56 2014 mar_b mar_b
** Last update Wed Jul 23 15:35:11 2014 mar_b mar_b
*/

#include <stdio.h>
#include <stdlib.h>
#include "rtv1.h"
#include "objects.h"
#include "calc.h"

/*
** brief: little function to set a vector
** @eye: the vector
** @x: x position
** @y: y position
** @z: z position
*/
static void	_recalculate_vec(t_vector *eye, float x, float y, float z)
{
  eye->x = x;
  eye->y = y;
  eye->z = z;
}

static float	_find_my_little_k(t_scene *scene, t_vector *dis,
				  unsigned int *clr)
{
  unsigned int	clr_tmp;
  float		tmp;
  float		k;

  k = -1;
  tmp = calc_inter_planes(scene, dis, scene->eye, &clr_tmp);
  *clr = ((tmp >= 0.0 && tmp < k) || (k < 0.0 && tmp >= 0.0)) ? clr_tmp : *clr;
  k = ((tmp >= 0.0 && tmp < k) || (k < 0.0 && tmp >= 0.0)) ? tmp : k;
  tmp = calc_inter_spheres(scene, dis, scene->eye, &clr_tmp);
  *clr = ((tmp >= 0.0 && tmp < k) || (k < 0.0 && tmp >= 0.0)) ? clr_tmp : *clr;
  k = ((tmp >= 0.0 && tmp < k) || (k < 0.0 && tmp >= 0.0)) ? tmp : k;
  tmp = calc_inter_cylinders(scene, dis, scene->eye, &clr_tmp);
  *clr = ((tmp >= 0.0 && tmp < k) || (k < 0.0 && tmp >= 0.0)) ? clr_tmp : *clr;
  k = ((tmp >= 0.0 && tmp < k) || (k < 0.0 && tmp >= 0.0)) ? tmp : k;
  tmp = calc_inter_cones(scene, dis, scene->eye, &clr_tmp);
  *clr = ((tmp >= 0.0 && tmp < k) || (k < 0.0 && tmp >= 0.0)) ? clr_tmp : *clr;
  k = ((tmp >= 0.0 && tmp < k) || (k < 0.0 && tmp >= 0.0)) ? tmp : k;
  return (k);
}

/*
** brief: it will try to calc the intersection
** @x: x position
** @y: y position
** return: return the good color (about the range)
*/
unsigned int	my_calc(int x, int y, t_scene *scene)
{
  t_vector	dis;
  t_vector	pos;
  unsigned int	color;
  float		k;

  color = 0x000000;
  _recalculate_vec(&dis, (float)ID_RANGE - scene->eye->x,
		   (float)WIDTH / 2.0 - (float)x - (float)scene->eye->y,
		   (float)HEIGHT / 2.0 - (float)y - (float)scene->eye->z);
  k = _find_my_little_k(scene, &dis, &color);
  (void)k;
  (void)pos;
  return (color);
}
