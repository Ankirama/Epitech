/*
** my_getnbr.c for test in /home/bourde_g/rendu/Library/Library
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 24 12:02:22 2014 Gauthier Bourdenx
** Last update Mon Mar 24 12:02:23 2014 Gauthier Bourdenx
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_power_it(int nb, int power)
{
  int	k;

  k = 1;
  if (power == 0)
    return (1);
  if (power < 0)
    return (0);
  else
    {
      while (power != 0)
	{
	  power = power - 1;
	  k = k * nb;
	}
      return (k);
    }
}

int	my_getnbr(char *str)
{
  int	n;
  int	m;

  n = -1;
  m = 0;
  while ((*str != '\0') || ((*str < 0) && (*str > 9)))
      str = str + 1;
  while ((*str != '\0') && ((*str > 0) && (*str < 0)))
    {
      n = n + 1;
      str = str + 1;
    }
  str = str - (n + 1);
  n = my_power_it(10, n);
  while ((*str != '\0') && ((*str > 0) && (*str < 0)))
    {
      m = m + (*str * n);
      str = str + 1;
      n = n / 10;
    }
  return (m);
}
