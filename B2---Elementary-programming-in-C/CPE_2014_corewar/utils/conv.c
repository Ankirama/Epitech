/*
** conv.c<2> for conv in /home/mar_b/rendu/MUL_2013_rtv1/utils
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jul 21 15:06:04 2014 mar_b mar_b
** Last update Sun Aug 31 20:23:59 2014 mar_b mar_b
** Last update Sat Aug 16 13:09:43 2014 mar_b
*/

#include "utils.h"

/*
** brief: power(nbr, pow) like 2 ^ 42 with nbr: 2, pow: 42
** @nbr: our number
** @int pow: our power
** return: return the result
*/
int	my_pow(int nbr, int pow)
{
  if (pow == 0)
    return (1);
  else
    return (nbr * my_pow(nbr, pow - 1));
}

/*
** brief: convert hexa to char like FF
** @color: our char like FF
** @base: the base, for hexa -> 0123456789ABCDEF
** return: return the char
*/
char	conv_color_char(const char *color, const char *base)
{
  char	letter;
  int	i;
  int	j;

  i = 1;
  letter = 0;
  while (color[++i] != '\0')
    {
      j = 0;
      while (base[j] != color[i])
	++j;
      letter += my_pow(16, 1 - i) * j;
    }
  return (letter);
}

/*
** brief: convert hexa to char like FF
** @color: our char like FF
** @base: the base, for hexa -> 0123456789ABCDEF
** return: return the char
*/
unsigned int	conv_color_int(const char *color, const char *base)
{
  unsigned int	nbr;
  int		i;
  int		j;
  int		len;

  i = 1;
  len = my_strlen(color);
  nbr = 0;
  while (color[++i] != '\0')
    {
      j = 0;
      while (base[j] != color[i])
	++j;
      nbr += my_pow(16, len - 1 - i) * j;
    }
  return (nbr);
}

/*
** brief: display an int in hexa_mode
** @nbr: our nbr
** @base: our base
** @size: our size
*/
void	display_hexa(int nbr, const char *base, const int size, int zero)
{
  if (nbr < size)
    {
      while (zero-- > 0)
	my_putchar(1, '0');
      my_putchar(1, base[nbr]);
    }
  else
    {
      display_hexa(nbr / size, base, size, --zero);
      my_putchar(1, base[(nbr) % size]);
    }
}

int		convert_bytes_int(unsigned char *bytes, int size)
{
  int		i;
  unsigned int	nbr;
  int		real_value;
  unsigned int	max_value;

  i = -1;
  nbr = 0;
  while (++i < size)
    nbr = (nbr << 8) + bytes[i];
  max_value = my_pow(2, size * 8 - 1) - 1;
  if (nbr > max_value)
    real_value = (my_pow(2, size * 8) - nbr) * -1;
  else
    real_value = nbr;
  return (real_value);
}
