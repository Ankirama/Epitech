/*
** cone.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/intersection
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Sat Oct  4 15:33:51 2014 charles viterbo
** Last update Sun Oct 12 21:43:10 2014 charles viterbo
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
** @v2 : - for intersection it will be the cone
**       - for the shadow it will be the cone
** @v3 : - for the intersection it will be the eye
**       - for the shadow it will be the distance
** @cons : the orb's radius
** return : both solution of the equation
*/
double		inter_paraboloide(t_vector *v1, t_vector *v2,
				  t_vector *v3, double cons[2])
{
  double	k1;
  double	k2;
  double	a;
  double	b;
  double	c;
  double	delta;

  a = pow(v1->x, 2) + pow(v1->y, 2) * cons[0];
  b = (((2.0 * ((v3->x - v2->x) * v1->x)) +
	((2.0 * ((v3->y - v2->y) * v1->y)) * cons[0]))
       - (v3->z - v2->z) * v1->z * cons[1]);
  c = pow((v3->x - v2->x), 2) + (pow((v3->y - v2->y), 2) * cons[0])
    - (v3->z - v2->z) * cons[1];
  delta = pow(b, 2) - 4.0 * a * c;
  if (delta >= 0.0)
    {
      k1 = (-1.0 * b + sqrt(delta)) / (2.0 * a);
      k2 = (-1.0 * b - sqrt(delta)) / (2.0 * a);
      return ((k1 < k2 && k1 >= 0.0) ? k1 : k2);
    }
  return (-1);
}

static void	_set_cons(double *cons, double type, double cst)
{
  cons[0] = type;
  cons[1] = cst;
}

/*
** brief : intersection for all paraboloide
** @scene : our scene
** @eye : our vector eye
** @vision : our vector vision
** @obj : our nearest objects
*/
void		all_paraboloide(t_scene *scene, t_eye *eye,
				t_vector *vision, t_dis *obj)
{
  t_para	*para;
  double	k;
  double	cons[2];
  t_vector	*tmp_o;
  t_vector	*tmp_v;

  para = scene->list_para;
  while (para != NULL)
    {
      tmp_o = rotate_vector(eye->coord, para->rot, 1.0);
      tmp_v = rotate_vector(vision, para->rot, 1.0);
      _set_cons(cons, para->type, para->cst);
      if ((k = inter_paraboloide(tmp_v, para->coord, tmp_o, cons)) >= 0.0
	  && (k < obj->k || obj->k < 0.0)
	  && limit(vec_p(eye->coord, k, vision),
                   para->limit_up, para->limit_low))
	{
	  obj->type = PARA;
	  obj->k = k;
	  obj->element = para;
	}
      free(tmp_o);
      free(tmp_v);
      para = para->next;
    }
}

/*
** brief : create our point P for a paraboloide
** @obj: our objects
** @eye : our vector eye
** @vision : our vector vision
*/
t_vector	*create_p_paraboloide(t_dis *obj, t_eye *eye, t_vector *vision)
{
  t_para	*para;
  t_vector	*point;

  para = obj->element;
  to_simple(&(eye->coord), para->coord, para->rot);
  to_simple(&(vision), para->coord, para->rot);
  point = create_vector(eye->coord->x + obj->k * vision->x,
			eye->coord->y + obj->k * vision->y,
			eye->coord->z + obj->k * vision->z);
  to_real_life(&(eye->coord), para->coord, para->rot);
  to_real_life(&(vision), para->coord, para->rot);
  return (point);
}

/*
** brief : calculate the color for a paraboloide
** @scene : our scene
** @obj : our object
** @point : our vector point
*/
t_color		*color_paraboloide(t_scene *scene, t_dis *obj, t_vector *point)
{
  t_para	*tmp;

  tmp = obj->element;
  return (lumi_paraboloide(scene, tmp, point));
}
