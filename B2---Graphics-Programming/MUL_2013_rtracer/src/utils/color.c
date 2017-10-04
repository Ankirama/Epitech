/*
** color.c for color in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Oct  8 18:52:03 2014 mar_b mar_b
** Last update Fri Oct 10 19:11:13 2014 teyssa_r teyssa_r
*/

#include "objects.h"

/*
** brief: addition color 2 to color 1
** v1: color 1
** v2: color 2
*/
void	add_colors(t_color **v1, t_color *v2)
{
  (*v1)->r += v2->r;
  (*v1)->g += v2->g;
  (*v1)->b += v2->b;
}

/*
** brief: substraction color 2 to color 1
** v1: color 1
** v2: color 2
*/
void	sub_colors(t_color **v1, t_color *v2)
{
  (*v1)->r -= v2->r;
  (*v1)->g -= v2->g;
  (*v1)->b -= v2->b;
}

/*
** brief: multiplicate color 2 to color 1
** v1: color 1
** v2: color 2
*/
void	mul_color(t_color **v1, int k)
{
  (*v1)->r *= k;
  (*v1)->g *= k;
  (*v1)->b *= k;
}

/*
** brief: division color 2 to color 1
** v1: color 1
** v2: color 2
*/
void	div_color(t_color **v1, int k)
{
  (*v1)->r /= k;
  (*v1)->g /= k;
  (*v1)->b /= k;
}
