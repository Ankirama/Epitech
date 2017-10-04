/*
** vec_calc.c for vector calc in /home/mar_b/rendu/MUL_2013_rtv1/calc
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Jul 12 18:02:51 2014 mar_b mar_b
** Last update Tue Jul 22 10:23:08 2014 mar_b mar_b
*/

#include <math.h>
#include <stdlib.h>
#include "rtv1.h"
#include "utils.h"
#include "calc.h"

/*
** brief: rotation about x with ang degree
*/
void		rotation_x(t_vector *pos, float ang)
{
  t_vector	tmp;

  if (fabs(ang) > 0.00001)
    {
      ang = C_ANG(ang);
      tmp.x = pos->x;
      tmp.y = pos->y * cos(ang) + pos->z * (-1 * sin(ang));
      tmp.z = pos->y * sin(ang) + pos->z * cos(ang);
      pos->x = tmp.x;
      pos->y = tmp.y;
      pos->z = tmp.z;
    }
}

/*
** brief: rotation about y with ang degree
*/
void		rotation_y(t_vector *pos, float ang)
{
  t_vector	tmp;

  if (fabs(ang) > 0.00001)
    {
      ang = C_ANG(ang);
      tmp.x = pos->x * cos(ang) + pos->z * sin(ang);
      tmp.y = pos->y;
      tmp.z = pos->x * (-1 * sin(ang)) + pos->z * cos(ang);
      pos->x = tmp.x;
      pos->y = tmp.y;
      pos->z = tmp.z;
    }
}

/*
** brief: rotation about z with ang degree
*/
void		rotation_z(t_vector *pos, float ang)
{
  t_vector	tmp;

  if (fabs(ang) > 0.00001)
    {
      ang = C_ANG(ang);
      tmp.x = pos->x * cos(ang) + pos->y * (-1 * sin(ang));
      tmp.y = pos->x * sin(ang) + pos->y * cos(ang);
      tmp.z = pos->z;
      pos->x = tmp.x;
      pos->y = tmp.y;
      pos->z = tmp.z;
    }
}
