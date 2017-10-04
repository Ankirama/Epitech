/*
** my_pret.c for pre teatment in /home/user/rendu/MUL_2013_wolf3d
**
** Made by 
** Login   
**
** Started on  Thu Jun 12 02:17:47 2014 
** Last update Sun Jun 15 17:58:34 2014 
*/

#include <math.h>

/*
** brief: each angle is convert to radian (pi * ang / 180)
** @sin_ang: the array we will fill with sinus values
** @cos_ang: the array we will fill with cosinus values
*/
void	my_calc_angles(float *sin_ang, float *cos_ang)
{
  int	i;
  float	rad;

  i = -1;
  while (++i < 25)
    {
      rad = M_PI * (i * 15) / 180;
      sin_ang[i] = sin(rad);
      cos_ang[i] = cos(rad);
    }
}
