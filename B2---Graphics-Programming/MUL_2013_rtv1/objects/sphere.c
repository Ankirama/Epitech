/*
** sphere.c for sphere in /home/mar_b/rendu/MUL_2013_rtv1/parser_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul 15 09:35:05 2014 mar_b mar_b
** Last update Thu Jul 24 17:18:57 2014 mar_b
*/

#include <math.h>
#include <stdlib.h>
#include "utils.h"
#include "objects.h"
#include "calc.h"

/*
** brief: it will add a new sphere about scene file
** @scene: our scene with all objects
** @str: our str with information (sphere X Y Z R COLOR)
*/
void		add_sphere(t_scene **scene, const char *str)
{
  int		i;
  int		start;
  t_spheres	*elt;

  if ((elt = malloc(sizeof(*elt))) == NULL)
    my_puterror("error: problem to malloc in sphere.c\n");
  i = -1;
  elt->k = 0.0;
  start = travel_string(str, &i);
  elt->x = char_to_float(&str[start], i);
  start = travel_string(str, &i);
  elt->y = char_to_float(&str[start], i - start);
  start = travel_string(str, &i);
  elt->z = char_to_float(&str[start], i - start);
  start = travel_string(str, &i);
  elt->radius = char_to_float(&str[start], i - start);
  elt->color = conv_color(&str[i + 1], "0123456789ABCDEF");
  elt->next = ((*scene)->spheres == NULL) ? NULL : (*scene)->spheres;
  (*scene)->spheres = elt;
}

/*
** brief: it will try to find an intersection with the sphere
** @dis: our V vector
** @eye: our eye position
** @sphere: our sphere position
** return: return -1 if no intersection or the smaller k found
*/
static char	_inter_sphere(t_vector *dis, t_vector *eye, t_spheres *obj)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		k;
  float		k1;

  a = pow(dis->x, 2) + pow(dis->y, 2) + pow(dis->z, 2);
  b = 2.0 * ((eye->x - obj->x) * dis->x +
	     (eye->y - obj->y) * dis->y + (eye->z - obj->z) * dis->z);
  c = pow(eye->x - obj->x, 2) + pow(eye->y - obj->y, 2) +
    pow(eye->z - obj->z, 2) - pow(obj->radius, 2);
  delta = pow(b, 2) - (4.0 * a * c);
  k = delta >= 0 ? (-1.0 * b + sqrt(delta)) / (2 * a) : -1.0;
  k1 = delta >= 0 ? (-1.0 * b - sqrt(delta)) / (2 * a) : -1.0;
  if (k >= 0 && (k1 < 0 || k <= k1))
    obj->k = k;
  else if (k1 >= 0 && (k < 0 || k1 < k))
    obj->k = k1;
  else
    {
      obj->k = 0.0;
      return (-1);
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
static unsigned int	_brightness_spheres(t_scene *scene, float k,
					    t_vector *dis, unsigned int color)
{
  t_vector		point;
  t_vector		l;
  float			norme_N;
  float			norme_L;
  float			cos_a;

  point.x = scene->eye->x + k * dis->x;
  point.y = scene->eye->y + k * dis->y;
  point.z = scene->eye->z + k * dis->z;
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
** brief: it will calculate k for each spheres
** @spheres: our spheres' list
** @dis: our V vector
** @eye: our eye vector
** @color: our color
** return: return the smaller k;
*/
float		calc_inter_spheres(t_scene *scene, t_vector *dis,
				   t_vector *eye, unsigned int *color)
{
  t_spheres	*obj;
  float		k;

  obj = scene->spheres;
  k = -1.0;
  while (obj != NULL)
    {
      if (_inter_sphere(dis, eye, obj) != -1 && (obj->k < k || k < 0))
	{
	  k = obj->k;
	  *color = _brightness_spheres(scene, k, dis, obj->color);
	}
      obj = obj->next;
    }
  return (k);
}
