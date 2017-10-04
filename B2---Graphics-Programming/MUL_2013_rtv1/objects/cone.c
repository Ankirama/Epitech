/*
** cone.c for cone in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jul 17 19:04:57 2014 mar_b mar_b
** Last update Thu Jul 24 18:15:38 2014 mar_b
*/

#include <math.h>
#include <stdlib.h>
#include "utils.h"
#include "objects.h"
#include "calc.h"

/*
** brief: it will add a new cone about scene file
** @scene: our scene with all objects
** @str: our str with information (cone CST X Y Z COLOR)
*/
void		add_cone(t_scene **scene, const char *str)
{
  int		i;
  int		start;
  t_cones	*elt;

  if ((elt = malloc(sizeof(*elt))) == NULL)
    my_puterror("error: problem to malloc in cone.c\n");
  elt->k = 0.0;
  i = -1;
  start = travel_string(str, &i);
  elt->cst = char_to_float(&str[start], i);
  start = travel_string(str, &i);
  elt->x = char_to_float(&str[start], i - start);
  start = travel_string(str, &i);
  elt->y = char_to_float(&str[start], i - start);
  start = travel_string(str, &i);
  elt->z = char_to_float(&str[start], i - start);
  start = travel_string(str, &i);
  elt->ang_x = char_to_float(&str[start], i - start);
  start = travel_string(str, &i);
  elt->ang_y = char_to_float(&str[start], i - start);
  start = travel_string(str, &i);
  elt->ang_z = char_to_float(&str[start], i - start);
  elt->color = conv_color(&str[i + 1], "0123456789ABCDEF");
  elt->next = ((*scene)->cones == NULL) ? NULL : (*scene)->cones;
  (*scene)->cones = elt;
}

/*
** brief: it will try to find an intersection with the sphere
** @dis: our V vector
** @eye: our eye position
** @cones: our cone position
** return: return -1 if no intersection or the smaller k found
*/
static char	_inter_cone(t_vector *dis, t_vector *eye, t_cones *cones)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		k;
  float		k1;

  a = pow(dis->x, 2) + pow(dis->y, 2) - pow(dis->z, 2) * cones->cst;
  b = 2.0 * ((eye->x - cones->x) * dis->x + (eye->y - cones->y) * dis->y +
	     (eye->z - cones->z) * (-1.0 * cones->cst * dis->z));
  c = pow(eye->x - cones->x, 2) + pow(eye->y - cones->y, 2) -
    (cones->cst * pow(eye->z - cones->z, 2));
  delta = pow(b, 2) - (4.0 * a * c);
  k = delta >= 0 ? (-1.0 * b + sqrt(delta)) / (2 * a) : -1.0;
  k1 = delta >= 0 ? (-1.0 * b - sqrt(delta)) / (2 * a) : -1.0;
  if (k >= 0 && (k1 < 0 || k <= k1))
    cones->k = k;
  else if (k1 >= 0 && (k < 0 || k1 < k))
    cones->k = k1;
  else
    {
      cones->k = 0.0;
      return (-1);
    }
  return (0);
}

/*
** brief: it will try to calculate the new color with the spot
** @scene: our scene struct
** @k: our k (intersection with obj)
** @dis: our director vector
** return: return our new color
*/
static unsigned int	_brightness_cones(t_scene *scene, t_cones *obj,
					    t_vector *dis)
{
  t_vector		point;
  t_vector		l;
  float			norme_N;
  float			norme_L;
  float			cos_a;

  point.x = scene->eye->x + obj->k * dis->x;
  point.y = scene->eye->y + obj->k * dis->y;
  point.z = (scene->eye->z + obj->k * dis->z) * obj->cst;
  l.x = scene->spots->x - point.x;
  l.y = scene->spots->y - point.y;
  l.z = scene->spots->z - point.z;
  norme_N = sqrt(pow(point.x, 2) + pow(point.y, 2) + pow(point.z, 2));
  norme_L = sqrt(pow(l.x, 2) + pow(l.y, 2) + pow(l.z, 2));
  cos_a = (point.x * l.x + point.y * l.y + point.z * l.z) / (norme_N * norme_L);
  if (cos_a >= 0 && cos_a <= 1)
    return (my_brightness(cos_a, obj->color));
  if (cos_a < 0.0)
    return (0x000000);
  return (obj->color);
}

/*
** brief: it will calculate k for each cones
** @cones: our cones' list
** @dis: our V vector
** @eye: our eye vector
** @color: our color
** return: return the smaller k;
*/
float		calc_inter_cones(t_scene *scene, t_vector *dis,
				 t_vector *eye, unsigned int *color)
{
  t_cones	*obj;
  t_vector	tmp;
  float		k;

  obj = scene->cones;
  k = -1.0;
  while (obj != NULL)
    {
      tmp.x = dis->x;
      tmp.y = dis->y;
      tmp.z = dis->z;
      rotation_x(&tmp, obj->ang_x);
      rotation_y(&tmp, obj->ang_y);
      rotation_z(&tmp, obj->ang_z);
      if (_inter_cone(&tmp, eye, obj) != -1 && (obj->k < k || k < 0))
	{
	  k = obj->k;
	  *color = _brightness_cones(scene, obj, &tmp);
	}
      obj = obj->next;
    }
  return (k);
}
