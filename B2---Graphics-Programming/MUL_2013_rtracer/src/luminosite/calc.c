/*
** calc.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/luminosite
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Tue Oct  7 21:08:45 2014 charles viterbo
** Last update Sun Oct 12 22:05:35 2014 charles viterbo
*/

#include <math.h>
#include "objects.h"

/*
** brief : calculate the angle for the luminosity
** @n : our normal
** @light : the coordinates of light
** @p : our point P (intersection)
** @var : for perturbation of normal
*/
double		calc_angle(t_vector *n, t_vector *light,
			   t_vector *p, t_vector *var)
{
  double	angle;
  double	norme_vn;
  double	norme_vl;

  norme_vn = sqrt(pow(n->x, 2) + pow(n->y, 2) + pow(n->z, 2));
  norme_vl = sqrt(pow(light->x - p->x, 2) +
		  pow(light->y - p->y, 2) +
                  pow(light->z - p->z, 2));
  n->x = (var->x > 0) ? n->x + (cos(p->x) / var->x) * (norme_vn / var->x) :
    n->x;
  n->y = (var->y > 0) ? n->y + (cos(p->y) / var->y) * (norme_vn / var->y) :
    n->y;
  n->z = (var->z > 0) ? n->z + (cos(p->z) / var->z) * (norme_vn / var->z) :
    n->z;
  angle = (n->x * (light->x - p->x) +
           n->y * (light->y - p->y) +
           n->z * (light->z - p->z)) / (norme_vn * norme_vl);
  return (angle);
}

/*
** brief : calculate the angle for the luminosity
** @n : our vector normal
** @light : our light
** @p : our point P (intersection)
** @var : for perturbation of normal
*/
double		calc_angle_amb(t_vector *n, t_vector *light,
			       t_vector *p, t_vector *var)
{
  double	angle;
  double	norme_vn;
  double	norme_vl;

  norme_vn = sqrt(pow(n->x, 2) + pow(n->y, 2) + pow(n->z, 2));
  norme_vl = sqrt(pow(light->x - p->x, 2) +
		  pow(light->y - p->y, 2) +
                  pow(light->z - p->z, 2));
  n->x = (var->x > 0) ? n->x + (cos(p->x) / var->x) * (norme_vn / var->x) :
    n->x;
  n->y = (var->y > 0) ? n->y + (cos(p->y) / var->y) * (norme_vn / var->y) :
    n->y;
  n->z = (var->z > 0) ? n->z + (cos(p->z) / var->z) * (norme_vn / var->z) :
    n->z;
  angle = (n->x * (light->x - p->x) +
           n->y * (light->y - p->y) +
           n->z * (light->z - p->z)) / (norme_vn * norme_vl);
  return (angle < 0.21 ? 0.21 : angle);
}
