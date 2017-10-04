/*
** conv_color.c for conv_color in /home/chenev_d/rendu/MUL_2013_rtracer/RTcharles
**
** Made by chenev_d chenev_d
** Login   <chenev_d@epitech.net>
**
** Started on  Sat Oct  4 13:33:51 2014 chenev_d chenev_d
** Last update Fri Oct 10 20:04:10 2014 teyssa_r teyssa_r
*/

#include <math.h>

/*
** brief: convert the color char in int
** @r: it's R of RGB (red)
** @g: it's G of RGB (green)
** @b: it's B of RGB (blue)
** return: the color convert (unsigned int)
*/
unsigned int	conv_color(unsigned char r, unsigned char g, unsigned char b)
{
  unsigned int	result;

  result = ((b % 16) + ((b / 16) * 16)) +
    (((g % 16) * pow(16, 2)) + (g / 16) * pow(16, 3)) +
    (((r % 16) * pow(16, 4)) + ((r / 16) * pow(16, 5)));
  return (result);
}
