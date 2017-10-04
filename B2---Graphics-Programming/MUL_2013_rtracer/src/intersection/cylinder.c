/*
** cylinder.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/intersection
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Sat Oct  4 15:31:40 2014 charles viterbo
** Last update Sun Oct 12 21:33:49 2014 charles viterbo
*/

#include <math.h>
#include <stdlib.h>
#include "objects.h"
#include "intersection.h"
#include "utils.h"
#include "luminosite.h"
#include "rotation.h"

/*
** brief : This function will solve the equation x²+y² = R² (cylinder)
** @v1 : - for intersection it will be the vision vector
**       - for the shadow it will be light - P
** @v3 : - for the intersection it will be the eye
**       - for the shadow it will be the distance
** @cons : the orb's radius
** return : both solution of the equation
*/
double		inter_cylinder(t_vector *v1, t_vector *v3, double cons)
{
  double	k1;
  double	k2;
  double	a;
  double	b;
  double	c;
  double	delta;

  a = pow(v1->x, 2) + pow(v1->y, 2);
  b = 2.0 * ((v3->x) * v1->x + (v3->y) * v1->y);
  c = pow((v3->x), 2) + pow((v3->y), 2) - pow(cons, 2);
  delta = pow(b, 2) - 4.0 * a * c;
  if (delta >= 0.0)
    {
      k1 = (-1.0 * b + sqrt(delta)) / (2.0 * a);
      k2 = (-1.0 * b - sqrt(delta)) / (2.0 * a);
      return ((k1 < k2 && k1 >= 0.0) ? k1 : k2);
    }
  return (-2);
}

/*
** brief : this function will create a point P for a cylinder
** @obj : our cylinder
** @eye : our eye
** @vision : our vector vision
*/
t_vector	*create_p_cyl(t_dis *obj, t_eye *eye, t_vector *vision)
{
  t_cylinder	*cyl;
  t_vector	*point;

  cyl = obj->element;
  to_simple(&(eye->coord), cyl->coord, cyl->rot);
  to_simple(&vision, cyl->coord, cyl->rot);
  point = create_vector(eye->coord->x + obj->k * vision->x,
			eye->coord->y + obj->k * vision->y,
			eye->coord->z + obj->k * vision->z);
  to_real_life(&(eye->coord), cyl->coord, cyl->rot);
  to_real_life(&vision, cyl->coord, cyl->rot);
  return (point);
}

/*
** brief : it will calculate the intersection for all cylinder
** @scene : our scene
** @eye : our eye
** @vision : our vector vision
** @obj : our struct that contain k and the nearest element
*/
void		all_cylinder(t_scene *scene, t_eye *eye,
			     t_vector *vision, t_dis *obj)
{
  t_cylinder	*cl;
  double	k;

  cl = scene->list_cyl;
  while (cl != NULL)
    {
      to_simple(&eye->coord, cl->coord, cl->rot);
      to_simple(&vision, NULL, cl->rot);
      if ((k = inter_cylinder(vision, eye->coord, cl->radius)) >= 0.0
	  && (k < obj->k || obj->k < 0.0)
	  && limit(vec_p(eye->coord, k, vision),
                   cl->limit_up, cl->limit_low))
	{
	  obj->type = CYLIND;
	  obj->k = k;
	  obj->element = cl;
	}
      to_real_life(&eye->coord, cl->coord, cl->rot);
      to_real_life(&vision, NULL, cl->rot);
      cl = cl->next;
    }
}

/*
** brief : color the cylinder
** @scene : scene
** @obj : objects
** @point : vector point
*/
t_color		*color_cylinder(t_scene *scene, t_dis *obj, t_vector *point)
{
  t_cylinder	*tmp;

  tmp = obj->element;
  return (lumi_cyl(scene, tmp, point));
}
