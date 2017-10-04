/*
** utils.c for conv in /home/mar_b/rendu/MUL_2013_rtv1/parser_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jul 15 09:35:21 2014 mar_b mar_b
** Last update Sun Aug  3 10:32:25 2014 mar_b mar_b
*/

#include "utils.h"

static int	_my_pow(int nbr, int pow)
{
  if (pow == 0)
    return (1);
  else
    return (nbr * _my_pow(nbr, pow - 1));
}

float	char_to_float(const char *str, int end)
{
  int	i;
  int	j;
  float	nbr;

  nbr = 0;
  i = str[0] == '-' ? 0 : -1;
  while (str[++i] != '\0' && str[i] != '.' && i < end)
    nbr = nbr * 10 + str[i] - '0';
  if (str[i] == '\0' || i == end)
    return (str[0] == '-' ? nbr * -1.0 : nbr);
  j = 1;
  while (str[++i] != '\0' && i < end)
    {
      nbr = nbr + ((float)(str[i] - '0') / (float)_my_pow(10, j));
      ++j;
    }
  return (str[0] == '-' ? nbr * -1.0 : nbr);
}

int	char_to_int(const char *str, int end)
{
  int	i;
  int	nbr;

  i = str[0] == '-' ? 0 : -1;
  nbr = 0;
  while (str[++i] != '\0' && i < end)
    nbr = nbr * 10 + str[i] - '0';
  return (str[0] == '-' ? nbr * -1 : nbr);
}

unsigned int	conv_color(const char *color, const char *base)
{
  unsigned int	nbr;
  int		i;
  int		j;

  i = 1;
  nbr = 0;
  while (color[++i] != '\0' && i < 8)
    {
      j = - 1;
      while (base[++j] != color[i]);
      nbr += _my_pow(16, 7 - i) * j;
    }
  return (nbr);
}

void		put_nbr(char nbr)
{
  char		str[3];

  str[0] = nbr / 10 + '0';
  str[1] = nbr % 10 + '0';
  str[2] = '\0';
  my_write(str);
}
