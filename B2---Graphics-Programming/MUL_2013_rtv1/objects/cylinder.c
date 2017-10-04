/*
** cylinders.c for cylinders in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jul 17 13:28:50 2014 mar_b mar_b
** Last update Sun Aug  3 10:32:30 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"
#include "objects.h"
#include "calc.h"

/*
** brief: it will add a new cylidner about scene file
** @scene: our scene with all objects
** @str: our str with information (cylinder X Y Z ANG_X ANG_Y ANG_Z R COLOR)
*/
void		add_cylinder(t_scene **scene, const char *str)
{
  int		i;
  int		start;
  t_cylinders	*elt;

  if ((elt = malloc(sizeof(*elt))) == NULL)
    my_puterror("error: problem to malloc in cylinders.c\n");
  i = -1;
  elt->k = 0.0;
  start = travel_string(str, &i);
  elt->x = char_to_float(&str[start], i);
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
  start = travel_string(str, &i);
  elt->radius = char_to_float(&str[start], i - start);
  elt->color = conv_color(&str[i + 1], "0123456789ABCDEF");
  elt->next = ((*scene)->cylinders == NULL) ? NULL : (*scene)->cylinders;
  (*scene)->cylinders = elt;
}

/*
** brief: it will try to find an intersection with the sphere
** @dis: our V vector
** @eye: our eye position
** @obj: our cylinder position
** return: return -1 if no intersection or the smaller k found
*/
static char	_inter_cylinder(t_vector *dis, t_vector *eye, t_cylinders *obj)
{
  float		a;
  float		b;
  float		c;
  float		delta;
  float		k;
  float		k1;


  a = pow(dis->x, 2) + pow(dis->y, 2);
  b = 2.0 * ((eye->x - obj->x) * dis->x + (eye->y - obj->y) * dis->y);
  c = pow(eye->x - obj->x, 2) + pow(eye->y - obj->y, 2) - pow(obj->radius, 2);
  delta = pow(b, 2) - (4.0 * a * c);
  k = (delta >= 0) ? (-1.0 * b + sqrt(delta)) / (2.0 * a) : -1.0;
  k1 = (delta >= 0) ? (-1.0 * b - sqrt(delta)) / (2.0 * a) : -1.0;
  if (k >= 0.0 && (k1 < 0.0 || k <= k1))
    obj->k = k;
  else if (k1 >= 0.0 && (k < 0.0 || k1 < k))
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
static unsigned int	_brightness_cylinders(t_scene *scene, float k,
					      t_vector *dis, unsigned int color)
{
  t_vector		point;
  t_vector		l;
  float			norme_N;
  float			norme_L;
  float			cos_a;

  point.x = scene->eye->x + k * dis->x;
  point.y = scene->eye->y + k * dis->y;
  point.z = 0;
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
** brief: it will calculate k for each cylinder
** @cylinders: our cylinders' list
** @dis: our V vector
** @eye: our eye vector
** @color: our color
** return: return the smaller k;
*/
float		calc_inter_cylinders(t_scene *scene, t_vector *dis,
				     t_vector *eye, unsigned int *color)
{
  t_cylinders	*obj;
  float		k;
  t_vector	tmp;

  obj = scene->cylinders;
  k = -1.0;
  while (obj != NULL)
    {
      tmp.x = dis->x;
      tmp.y = dis->y;
      tmp.z = dis->z;
      rotation_x(&tmp, obj->ang_x);
      rotation_y(&tmp, obj->ang_y);
      rotation_z(&tmp, obj->ang_z);
      if (_inter_cylinder(&tmp, eye, obj) != -1 && (obj->k < k || k < 0))
	{
	  k = obj->k;
	  *color = _brightness_cylinders(scene, obj->k, &tmp, obj->color);
	}
      obj = obj->next;
    }
  return (k);
}
