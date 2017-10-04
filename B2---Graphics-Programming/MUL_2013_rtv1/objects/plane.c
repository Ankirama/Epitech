/*
** plane.c for plane in /home/mar_b/rendu/MUL_2013_rtv1/parser_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul 15 10:18:39 2014 mar_b mar_b
** Last update Mon Jul 28 11:31:28 2014 mar_b mar_b
*/

#include <math.h>
#include <stdlib.h>
#include "objects.h"
#include "utils.h"
#include "calc.h"

/*
** brief: it will add a new plane in our scene struct
** @scene: our scene with all objects
** @str: our str with informations (plane Z COLOR)
*/
void		add_plane(t_scene **scene, const char *str)
{
  int		i;
  int		start;
  t_planes	*elt;

  if ((elt = malloc(sizeof(*elt))) == NULL)
    my_puterror("error: problem to malloc in plane.c\n");
  i = -1;
  elt->k = 0.0;
  start = travel_string(str, &i);
  elt->z = char_to_float(&str[start], i);
  start = travel_string(str, &i);
  elt->ang_x = char_to_float(&str[start], i - start);
  start = travel_string(str, &i);
  elt->ang_y = char_to_float(&str[start], i - start);
  start = travel_string(str, &i);
  elt->ang_z = char_to_float(&str[start], i - start);
  elt->color = conv_color(&str[i + 1], "0123456789ABCDEF");
  elt->next = ((*scene)->planes == NULL) ? NULL : (*scene)->planes;
  (*scene)->planes = elt;
}

/*
** brief: it will try to find our intersection with plan
** @dis: our V vector
** @eye: our eye Vector
** return: return -1 if no intersection or k negative else return k >= 0
*/
static char	_inter_plane(t_planes *obj, t_vector *dis, t_vector *eye)
{
  if (fabs(dis->z) <= 0.00001)
    {
      obj->k = 0;
      return (-1);
    }
  else
    {
      obj->k = -1.0 * ((eye->z + obj->z) / dis->z);
      if (obj->k < 0)
	{
	  obj->k = 0;
	  return (-1);
	}
    }
  return (0);
}

/*
** brief: it will try to calculate the new color with the spot
** @scene: our scene struct
** @k: our k (intersection with obj)
** @dis: our director vector
** @color: our color
** return: return our new color
*/
static unsigned int	_brightness_planes(t_scene *scene, t_planes *obj,
					   unsigned int color)
{
  t_vector		point;
  t_vector		l;
  float			norme_N;
  float			norme_L;
  float			cos_a;

  point.x = 0.0;
  point.y = 0.0;
  point.z = 100.0 + obj->z;
  rotation_x(&point, obj->ang_x);
  rotation_y(&point, obj->ang_y);
  rotation_z(&point, obj->ang_z);
  l.x = scene->spots->x - point.x;
  l.y = scene->spots->y - point.y;
  l.z = scene->spots->z - point.z;
  norme_N = sqrt(pow(point.x, 2) + pow(point.y, 2) + pow(point.z, 2));
  norme_L = sqrt(pow(l.x, 2) + pow(l.y, 2) + pow(l.z, 2));
  cos_a = (point.x * l.x + point.y * l.y + point.z * l.z) / (norme_N * norme_L);
  if (cos_a >= 0 && cos_a <= 1)
    return (my_brightness(cos_a, color));
  if (cos_a < 0.0)
    return (0x000000);
  return (color);
}

/*
** brief: it will calculater k for each planes
** @planes: our planes' list
** @dis: our V vector
** @eye: our eye vector
*/
float		calc_inter_planes(t_scene *scene, t_vector *dis,
				  t_vector *eye, unsigned int *color)
{
  t_planes	*obj;
  t_vector	tmp;
  float		k;

  k = -1;
  obj = scene->planes;
  while (obj != NULL)
    {
      tmp.x = dis->x;
      tmp.y = dis->y;
      tmp.z = dis->z;
      rotation_x(&tmp, obj->ang_x);
      rotation_y(&tmp, obj->ang_y);
      rotation_z(&tmp, obj->ang_z);
      if (_inter_plane(obj, &tmp, eye) != -1 && (obj-> k < k || k < 0))
	{
	  k = obj->k;
	  *color = _brightness_planes(scene, obj, obj->color);
	}
      obj = obj->next;
    }
  return (k);
}
