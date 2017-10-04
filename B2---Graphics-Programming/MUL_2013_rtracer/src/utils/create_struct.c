/*
** create_struct.c for create in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Oct  3 17:24:01 2014 mar_b mar_b
** Last update Tue Oct  7 21:30:54 2014 charles viterbo
*/

#include "utils.h"
#include "objects.h"

/*
** brief: to create the struct vector
** @x: position of vector x
** @y: position of vector y
** @z: position of vector z
** return: the struct malloc or null
*/
t_vector	*create_vector(double x, double y, int z)
{
  t_vector	*vect;

  vect = my_malloc(sizeof(*vect));
  vect->x = x;
  vect->y = y;
  vect->z = z;
  return (vect);
}

/*
** brief: to create the struct color
** @r: value of r
** @g: value of vector g
** @b: value of vector b
** return: the struct malloc or null
*/
t_color		*create_color(int r, int g, int b)
{
  t_color	*color;

  color = my_malloc(sizeof(*color));
  color->r = r;
  color->g = g;
  color->b = b;
  return (color);
}
