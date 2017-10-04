/*
** rotation.c for  in /home/viterb_c/rendu/MUL_2013_rtracer/src/rotation
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Sat Oct  4 13:43:36 2014 charles viterbo
** Last update Sun Oct 12 21:24:08 2014 teyssa_r teyssa_r
*/

#include <math.h>
#include "objects.h"
#include "rotation.h"
#include "utils.h"

t_vector	*rotate_vector(t_vector *vec, t_vector *angle, double coeff)
{
  t_vector	*tmp;

  tmp = create_vector(vec->x, vec->y, vec->z);
  rot_x(&tmp->x, &tmp->y, &tmp->z, coeff * angle->x);
  rot_y(&tmp->x, &tmp->y, &tmp->z, coeff * angle->y);
  rot_z(&tmp->x, &tmp->y, &tmp->z, coeff * angle->z);
  return (tmp);
}

/*
** brief : rotate % 0x
** @x : coordinate x of the vector
** @y : coordinate y of the vector
** @z : coordinate z of the vector
** @angle : the ange of rotation
** return : if angle too small, near 0, return -1 and don't rotate
*/
char		rot_x(const double *x, double *y, double *z, double angle)
{
  double	tmp_y;
  double	tmp_z;

  (void)x;
  if (fabs(angle) < 0.00001)
    return (-1);
  angle = angle * M_PI / 180.0;
  tmp_y = *y * cos(angle) + *z * (-1.0) * sin(angle);
  tmp_z = *y * sin(angle) + *z * cos(angle);
  *y = tmp_y;
  *z = tmp_z;
  return (0);
}

/*
** brief : rotate % 0y
** @x : coordinate x of the vector
** @y : coordinate y of the vector
** @z : coordinate z of the vector
** @angle : the ange of rotation
** return : if angle too small, near 0, return -1 and don't rotate
*/
char		rot_y(double *x, const double *y, double *z, double angle)
{
  double	tmp_x;
  double	tmp_z;

  (void)y;
  if (fabs(angle) < 0.00001)
    return (-1);
  angle = angle * M_PI / 180.0;
  tmp_x = *x * cos(angle) + *z * sin(angle);
  tmp_z = (-1.0) * *x * sin(angle) + *z * cos(angle);
  *x = tmp_x;
  *z = tmp_z;
  return (0);
}

/*
** brief : rotate % 0z
** @x : coordinate x of the vector
** @y : coordinate y of the vector
** @z : coordinate z of the vector
** @angle : the ange of rotation
** return : if angle too small, near 0, return -1 and don't rotate
*/
char		rot_z(double *x, double *y, const double *z, double angle)
{
  double	tmp_x;
  double	tmp_y;

  (void)z;
  if (fabs(angle) < 0.00001)
    return (-1);
  angle = angle * M_PI / 180.0;
  tmp_x = *x * cos(angle) + (-1.0) * *y * sin(angle);
  tmp_y = *x * sin(angle) + *y * cos(angle);
  *x = tmp_x;
  *y = tmp_y;
  return (0);
}
