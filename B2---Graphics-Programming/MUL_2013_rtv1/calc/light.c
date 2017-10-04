/*
** light.c for light in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul 22 09:12:17 2014 mar_b mar_b
** Last update Sun Aug  3 10:33:14 2014 mar_b mar_b
*/

#include <math.h>
#include "objects.h"

/*
** brief: it will calculate our brightness
** @cos_a: our cosinus
** @color: our basic color
** return: return our new color
*/
unsigned int	my_brightness(float cos_a, unsigned int color)
{
  unsigned int	res;
  int		cal_col[3];
  unsigned char	*clr;

  clr = (unsigned char *)&color;
  cal_col[0] = clr[0] * cos_a;
  cal_col[0] = cal_col[0] > 255 ? 255 : cal_col[0];
  cal_col[1] = clr[1] * cos_a;
  cal_col[1] = cal_col[1] > 255 ? 255 : cal_col[1];
  cal_col[2] = clr[2] * cos_a;
  cal_col[2] = cal_col[2] > 255 ? 255 : cal_col[2];
  res = cal_col[0] % 16 + (cal_col[0] / 16) * 16 +
    (cal_col[1] % 16) * pow(16, 2) + (cal_col[1] / 16) * pow(16, 3) +
    (cal_col[2] % 16) * pow(16, 4) + (cal_col[2] / 16) * pow(16, 5);
  return (res);
}
