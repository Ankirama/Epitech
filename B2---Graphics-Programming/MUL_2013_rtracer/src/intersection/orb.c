/*
** orb.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/intersection
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Sat Oct  4 15:27:15 2014 charles viterbo
** Last update Sun Oct 12 16:17:13 2014 charles viterbo
*/

#include <stdlib.h>
#include <math.h>
#include "objects.h"
#include "utils.h"
#include "luminosite.h"

/*
** brief : This function will solve the equation x²+y²+z² = R² (orb)
** @v1 : - for intersection it will be the vision vector
**       - for the shadow it will be light - P
** @v2 : - for the intersection it will be the eye
**       - for the shadow it will be the distance
** @cons : the orb's radius
** return : both solution of the equation
*/
double		inter_orb(t_vector *v1, t_vector *v2, double cons)
{
  double	k1;
  double	k2;
  double	a;
  double	b;
  double	c;
  double	delta;

  a = pow(v1->x, 2) + pow(v1->y, 2) + pow(v1->z, 2);
  b = 2.0 * (v2->x * v1->x + v2->y * v1->y + v2->z * v1->z);
  c = pow(v2->x, 2) + pow(v2->y, 2) + pow(v2->z, 2) - pow(cons, 2);
  delta = pow(b, 2) - 4.0 * a * c;
  if (delta >= 0.0)
    {
      k1 = (-1.0 * b + sqrt(delta)) / (2.0 * a);
      k2 = (-1.0 * b - sqrt(delta)) / (2.0 * a);
      return ((k1 < k2 && k1 >= 0.0) ? k1 : k2);
    }
  return (-1);
}

/*
** brief : to create a point p of orb
** @obj : objects
** @eye : eye
** @vision : vector vision
*/
t_vector	*create_p_orb(t_dis *obj, t_eye *eye, t_vector *vision)
{
  t_orb		*orb;
  t_vector	*point;

  orb = obj->element;
  to_simple(&eye->coord, orb->coord, NULL);
  to_simple(&vision, NULL, NULL);
  point = create_vector(eye->coord->x + obj->k * vision->x,
                        eye->coord->y + obj->k * vision->y,
                        eye->coord->z + obj->k * vision->z);
  to_real_life(&eye->coord, orb->coord, NULL);
  to_real_life(&vision, NULL, NULL);
  return (point);
}

/*
** brief : to create all orb
** @scene : scene
** @eye : eye
** @vision : vector vision
** @obj: object
*/
void		all_orb(t_scene *scene, t_eye *eye,
			t_vector *vision, t_dis *obj)
{
  t_orb		*orb;
  double	k;

  orb = scene->list_orb;
  while (orb != NULL)
    {
      to_simple(&(eye->coord), orb->coord, NULL);
      to_simple(&vision, NULL, NULL);
      if ((k = inter_orb(vision, eye->coord, orb->radius)) >= 0.0
	  && (k < obj->k || obj->k < 0.0)
	  && limit(vec_p(eye->coord, k, vision),
		   orb->limit_up, orb->limit_low))
	{
	  obj->type = ORB;
	  obj->k = k;
	  obj->element = orb;
	}
      to_real_life(&(eye->coord), orb->coord, NULL);
      to_real_life(&vision, NULL, NULL);
      orb = orb->next;
    }
}

/*
** brief : color of orb
** @scene : scene
** @obj : obj
** @point: vector point
*/
t_color	*color_orb(t_scene *scene, t_dis *obj, t_vector *point)
{
  t_orb	*tmp;

  tmp = obj->element;
  return (lumi_orb(scene, tmp, point));
}
