/*
** my_put_nbr.c for test in /home/bourde_g/rendu/Library/Library
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 24 12:04:08 2014 Gauthier Bourdenx
** Last update Mon Mar 24 12:04:09 2014 Gauthier Bourdenx
*/

int	my_power_it(int nb, int power)
{
  int n;

  n = 1;
  if (power == 0)
      return (1);
  if (power < 0)
      return (0);
  else
    {
      while (power != 0)
	{
	  power = power - 1;
	  n = n * nb;
	}
      return (n);
    }
}

void	my_putchar(char c)
{
  write(1 ,&c, 1);
}

int	my_while(int nb)
{
  int	n;
  int	nbc;

  nbc = -1;
  n = nb;
  while (n != 0)
    {
      n = n / 10;
      nbc = nbc + 1;
    }
  nbc = my_power_it(10, nbc);
  while (nbc != 0)
    {
      n = nb / nbc;
      n = n % 10;
      my_putchar(n + 48);
      nbc = nbc / 10;
    }
  return (0);
}

int	my_put_nbr(int nb)
{
  if ((nb >= 0) && (nb < 10))
      my_putchar(48 + nb);
  else
    {
      if (nb < 0)
	{
	  nb = nb * -1;
	  my_putchar('-');
	  my_while(nb);
	}
      else
	my_while(nb);
    }
}
