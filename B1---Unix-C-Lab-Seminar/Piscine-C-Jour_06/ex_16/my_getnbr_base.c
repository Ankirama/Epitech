/*
** my_getnbr_base.c for my_getnbr_base in /home/mar_b/rendu/Piscine-C-Jour_06/ex_16
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 10 16:18:03 2014 Fabien Martinez
** Last update Mon Mar 10 19:21:34 2014 Fabien Martinez
*/

char	my_nbr_error(char *nbr, char *base, int base_len)
{
  int	i;

  i = 0;
  while (nbr[i] == '-' || nbr[i] == '+')
    i += 1;
  while (nbr[i] != '\0')
    {
      if (base_len >= 10)
	{
	  if (nbr[i] < '0' || nbr[i] > '9' && nbr[i] > base[base_len - 1])
	    return (1);
	}
      else
	{
	  if (nbr[i] < '0' || nbr[i] > base[base_len - 1])
	    return (1);
	}
      i += 1;
    }
  return (0);
}

char	my_errors(char *nbr, char *base)
{
  int	i;
  int   j;

  i = 0;
  if (nbr[0] == '\0' || base[0] == '\0')
    return (1);
  while (base[i] != '\0')
    {
      j = 0;
      while (base[j] != '\0')
	{
	  if (i != j)
	    {
	      if (base[i] == base[j])
		return (1);
	    }
	  j += 1;
	}
      i += 1;
    }
  return (my_nbr_error(nbr, base, i));
}

int	mp(int a, int e)
{
  if (e == 0)
    return (1);
  else
    return (a * mp(a, e - 1));
}

int	fun(char *nbr, int p, int len)
{
  char	*a;

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
	 return ((nbr[0] - 'A' + 10) * mp(len, p) + fun(a, p - 1, len));
      return ((nbr[0] - '0') * mp(len, p) + fun(&(nbr[1]), p - 1, len));
    }
}

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	count;
  int	power;
  int	base_len;

  base_len = 0;
  i = 0;
  count = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if(str[i] == '-')
	count += 1;
      i += 1;
    }
  if (count % 2 != 0)
    my_putchar('-');
  power = 0;
  while (str[power] != '\0')
    power += 1;
  while (base[base_len] != '\0')
    base_len += 1;
  power -= i;
  if (my_errors(str, base) == 1)
    return (0);
  return (fun(&(str[i]), power - 1, base_len));
}
