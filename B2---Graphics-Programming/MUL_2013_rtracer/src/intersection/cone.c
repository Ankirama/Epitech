/*
** cone.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/intersection
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Sat Oct  4 15:33:51 2014 charles viterbo
** Last update Sun Oct 12 21:31:21 2014 charles viterbo
*/

#include <stdlib.h>
#include <math.h>
#include "objects.h"
#include "utils.h"
#include "luminosite.h"
#include "rotation.h"

/*
** brief : This function will solve the equation x²+y² = az² (cone)
** @v1 : - for intersection it will be the vision vector
**       - for the shadow it will be light - P
** @v3 : - for the intersection it will be the eye
**       - for the shadow it will be the distance
** @cons : the orb's radius
** return : both solution of the equation
*/
double		inter_cone(t_vector *v1, t_vector *v3, double cons[2])
{
  double	k1;
  double	k2;
  double	a;
  double	b;
  double	c;
  double	delta;

  a = pow(v1->x, 2) + pow(v1->y, 2) - pow(v1->z, 2) * pow(cons[0], 2);
  b = 2.0 * ((v3->x) * v1->x + (v3->y) * v1->y
             - (v3->z) * v1->z * pow(cons[0], 2));
  c = pow((v3->x), 2) + pow((v3->y), 2)
    - pow((v3->z), 2) * pow(cons[0], 2) + cons[1];
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
** brief : to calcul all cone
** @scene : scene
** @eye : eye
** @vision : vector vision
** @obj : the object
*/
void		all_cone(t_scene *scene, t_eye *eye,
			 t_vector *vision, t_dis *obj)
{
  t_cone	*cone;
  double	k;
  double	cons[2];

  cone = scene->list_cone;
  while (cone != NULL)
    {
      to_simple(&(eye->coord), cone->coord, cone->rot);
      to_simple(&vision, NULL, cone->rot);
      cons[0] = cone->angle;
      cons[1] = cone->hyper;
      if ((k = inter_cone(vision, eye->coord, cons)) >= 0.0
	  && (k < obj->k || obj->k < 0.0)
	  && limit(vec_p(eye->coord, k, vision),
		   cone->limit_up, cone->limit_low))
	{
	  obj->type = CONE;
	  obj->k = k;
	  obj->element = cone;
	}
      to_real_life(&(eye->coord), cone->coord, cone->rot);
      to_real_life(&vision, NULL, cone->rot);
      cone = cone->next;
    }
}

/*
** brief : to create a point p
** @obj : objects
** @eye : eye
** @vision : vector vision
*/
t_vector	*create_p_cone(t_dis *obj, t_eye *eye, t_vector *vision)
{
  t_cone	*cone;
  t_vector	*point;

  cone	= obj->element;
  to_simple(&(eye->coord), cone->coord, cone->rot);
  to_simple(&(vision), cone->coord, cone->rot);
  point = create_vector(eye->coord->x + obj->k * vision->x,
			eye->coord->y + obj->k * vision->y,
			eye->coord->z + obj->k * vision->z);
  to_real_life(&(eye->coord), cone->coord, cone->rot);
  to_real_life(&(vision), cone->coord, cone->rot);
  return (point);
}

/*
** brief : color of cone
** @scene : scene
** @obj : the object
** @point : vector pont
*/
t_color		*color_cone(t_scene *scene, t_dis *obj, t_vector *point)
{
  t_cone	*tmp;

  tmp = obj->element;
  return (lumi_cone(scene, tmp, point));
}
