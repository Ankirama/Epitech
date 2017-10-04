/*
** fun.c for fun in /home/mar_b/rendu/MUL_2013_rtracer
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Oct 10 13:16:53 2014 mar_b mar_b
** Last update Mon Oct  6 04:50:38 2014
*/

/*
** brief: lerp, used for perlin noise
*/
double	lr(double t, double a, double b)
{
  return (a + t * (b - a));
}

/*
** brief: it will be used for perlin noise
*/
double	fade(double t)
{
  return (t * t * t * (t * (t * 6.0 - 15.0) + 10.0));
}

/*
** brief: gradient, used for perlin noise
*/
double		gr(int hash, double x, double y, double z)
{
  int		h;
  double	u;
  double	v;

  h = hash & 15;
  u = h  < 8 ? x : y;
  if (h < 4)
      v = y;
  else
    v = (h == 12 || h == 14) ? x : z;
  return ((((h & 1) == 0) ? u : -1.0 * u) + (((h & 2) == 0) ? v : -1.0 * v));
}
