/*
** convert_base.c for convert_base in /home/mar_b/rendu/Piscine-C-Jour_08/ex_02
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Mar 12 09:28:27 2014 Fabien Martinez
** Last update Wed Mar 12 22:56:03 2014 Fabien Martinez
*/

#include <stdlib.h>

long	fun(char *nbr, int p, int l)
{
  char  *a;

  if (p == 0)
    {
      if (nbr[0] >= 'A' && nbr[0] <= 'F')
        return (nbr[0] - 'A' + 10);
      return (nbr[0] - '0');
    }
  else
    {
      a = &(nbr[1]);
      if (nbr[0] >= 'A' && nbr[0] <= 'F')
	return ((nbr[0] - 'A' + 10) * my_power_rec(l, p) + fun(a, p - 1, l));
      return ((nbr[0] - '0') * my_power_rec(l, p) + fun(&(nbr[1]), p - 1, l));
    }
}

long     my_getnbr_base(char *str, char *base)
{
  int   i;
  int   count;
  int   power;
  int   base_len;

  i = 0;
  count = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
        count += 1;
      i += 1;
    }
  power = 0;
  base_len = 0;
  while (str[power] != '\0')
    power += 1;
  while (base[base_len] != '\0')
    base_len += 1;
  base_len = fun(&(str[i]), power - 1 - i, base_len);
  return (base_len = count % 2 != 0 ? base_len * -1 : base_len);
}

void	my_neg_int(char *str, long *nbr, char *base)
{
  int	i;
  int	j;

  if (str[0] == '-')
    {
      i = 0;
      while (base[i] != '\0')
	i += 1;
      j = 1;
      while (str[j] != '\0' && str[j] == base[i - 1])
	j += 1;
      if (str[j] == '\0')
	{
	  *nbr -= 1;
	}
    }
}

void	my_int_to_base(long nbr, char *base_to, char *str, int i)
{
  int	len;

  len = 0;
  while (base_to[len] != '\0')
    len += 1;
  if (nbr / len == 0)
    {
      str[i] = base_to[nbr % len];
    }
  else
    {
      my_int_to_base(nbr / len, base_to, str, i + 1);
      str[i] = base_to[nbr % len];
    }
}

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  long	i;
  char	*ptr;
  int	base_len;

  i = my_getnbr_base(nbr, base_from);
  my_neg_int(nbr, &i, base_from);
  ptr = malloc (33);
  if (i < 0)
    {
      my_int_to_base(i * -1, base_to, ptr, 0);
      my_revstr(ptr);
      base_len = 0;
      while (ptr[base_len] != '\0')
      	base_len += 1;
      while (base_len > 0)
	{
	  ptr[base_len] = ptr[base_len - 1];
	  base_len -= 1;
	}
      ptr[0] = '-';
      return (ptr);
    }
  my_int_to_base(i, base_to, ptr, 0);
  my_revstr(ptr);
  return (ptr);
}
