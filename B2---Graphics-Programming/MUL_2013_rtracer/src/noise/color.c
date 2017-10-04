/*
** color.c for color in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Oct 10 15:19:47 2014 mar_b mar_b
** Last update Mon Oct  6 04:49:14 2014
*/

#include <stdlib.h>
#include "objects.h"
#include "utils.h"

static t_color	g_cr[4] =
  {
    {255, 0, 0},
    {0, 255, 0},
    {0, 0, 255},
  };

/*
** brief: used to choose a color from perlin noise (3 colors)
** @n: -1 <= n <= 1
** return: return the new color
*/
t_color		*choose_color(double n)
{
  double	v1;
  double	v2;
  double	v3;

  v1 = -0.6543;
  v2 = 0.2542151;
  v3 = 0.724151;
  if (n < v1)
    return (create_color(g_cr[0].r, g_cr[0].g, g_cr[0].b));
  else if (v1 < n && n < v2)
    return (create_color(g_cr[0].r * (n - v1) / (v2 - v1) + g_cr[1].r *
  			 (v2 - n) / (v2 - v1), g_cr[0].g * (n - v1) /
  			 (v2 - v1) + g_cr[1].g * (v2 - n) / (v2 - v1),
  			 g_cr[0].b * (n - v1) / (v2 - v1) + g_cr[1].b *
  			 (v2 - n) / (v2 - v1)));
  else if (v2 < n && n < v3)
    return (create_color(g_cr[1].r * (n - v2) / (v3 - v2) + g_cr[2].r *
  			 (v3 - n) / (v3 - v2), g_cr[1].g * (n - v2) / (v3 - v2)
  			 + g_cr[2].g * (v3 - n) / (v3 - v2), g_cr[1].b *
  			 (n - v2) / (v3 - v2) + g_cr[2].b * (v3 - n)
  			 / (v3 - v2)));
  else
    return (create_color(g_cr[2].r, g_cr[2].g, g_cr[2].b));
}
