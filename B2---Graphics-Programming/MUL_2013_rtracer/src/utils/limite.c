/*
** limite.c for  in /home/viterb_c/rendu/MUL_2013_rtracer
**
** Made by charles viterbo
** Login   <viterb_c@epitech.net>
**
** Started on  Sun Oct 12 12:21:59 2014 charles viterbo
** Last update Sun Oct 12 17:19:11 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "objects.h"
#include "utils.h"

/*
** brief : this function will create our point P
** @eye : coordinates of the eye
** @k : the value of the distance between our eye
** and object
** @vis : the coordinates of our vector vision
*/
t_vector	*vec_p(const t_vector *eye, const double k,
		       const t_vector *vis)
{
  return (create_vector(eye->x + k * vis->x,
			eye->y + k * vis->y,
			eye->z + k * vis->z));
}

/*
** brief : this function
** @point : the coordinates of the point P
** @limit_low : the low limite
** @limit_up : the up limit
** return : 1 if intersection 0 if not
*/
char		limit(t_vector *point, t_vector *limit_up,
		      t_vector *limit_low)
{
  if ((limit_low->x != -1 && point->x < limit_low->x) ||
      (limit_low->y != -1 && point->y < limit_low->y) ||
      (limit_low->z != -1 && point->z < limit_low->z))
    {
      free(point);
      return (0);
    }
  if ((limit_up->x != -1 && point->x > limit_up->x) ||
      (limit_up->y != -1 && point->y > limit_up->y) ||
      (limit_up->z != -1 && point->z > limit_up->z))
    {
      free(point);
      return (0);
    }
  free(point);
  return (1);
}
