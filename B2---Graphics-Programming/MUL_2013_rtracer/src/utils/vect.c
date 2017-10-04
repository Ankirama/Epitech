/*
** vect.c for vect in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Oct  8 18:22:54 2014 mar_b mar_b
** Last update Fri Oct 10 19:09:48 2014 teyssa_r teyssa_r
*/

#include "objects.h"

/*
** brief: addition vector 2 to vector 1
** @v1: vector 1
** @v2: vector 2
*/
void	add_vectors(t_vector **v1, t_vector *v2)
{
  (*v1)->x += v2->x;
  (*v1)->y += v2->y;
  (*v1)->z += v2->z;
}

/*
** brief: substraction vector 2 to vector 1
** @v1: vector 1
** @v2: vector 2
*/
void	sub_vectors(t_vector **v1, t_vector *v2)
{
  (*v1)->x -= v2->x;
  (*v1)->y -= v2->y;
  (*v1)->z -= v2->z;
}

/*
** brief: multiplicate vector 2 to vector 1
** @v1: vector 1
** @v2: vector 2
*/
void	mul_vector(t_vector **v1, int k)
{
  (*v1)->x *= k;
  (*v1)->y *= k;
  (*v1)->z *= k;
}

/*
** brief: division vector 2 to vector 1
** @v1: vector 1
** @v2: vector 2
*/
void	div_vector(t_vector **v1, int k)
{
  (*v1)->x /= k;
  (*v1)->y /= k;
  (*v1)->z /= k;
}
