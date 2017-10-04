/*
** mv_position.c for coucou in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  9 17:01:25 2014 mar_b mar_b
** Last update Sat Oct 11 17:53:33 2014 teyssa_r teyssa_r
*/

#include <stdlib.h>
#include "rotation.h"
#include "objects.h"

/*
** brief: to put position in position simple
** @light: the light
** @coord: the coordonee of vector
** @rot: vector rotation
*/
void	to_simple(t_vector **light, t_vector *coord, t_vector *rot)
{
  if (coord != NULL)
    {
      (*light)->x -= coord->x;
      (*light)->y -= coord->y;
      (*light)->z -= coord->z;
    }
  if (rot != NULL)
    {
      rot_z(&(*light)->x, &(*light)->y,
	    &(*light)->z,  -rot->z);
      rot_y(&(*light)->x, &(*light)->y,
	    &(*light)->z,  -rot->y);
      rot_x(&(*light)->x, &(*light)->y,
	    &(*light)->z,  -rot->x);
    }
}

/*
** brief: to put position in position real
** @light: the light
** @coord: the coordonee of vector
** @rot: vector rotation
*/
void	to_real_life(t_vector **light, t_vector *coord, t_vector *rot)
{
  if (rot != NULL)
    {
      rot_x(&(*light)->x, &(*light)->y,
	    &(*light)->z, rot->x);
      rot_y(&(*light)->x, &(*light)->y,
	    &(*light)->z, rot->y);
      rot_z(&(*light)->x, &(*light)->y,
	    &(*light)->z, rot->z);
    }
  if (coord != NULL)
    {
      (*light)->x += coord->x;
      (*light)->y += coord->y;
      (*light)->z += coord->z;
    }
}
