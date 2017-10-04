/*
** my_aff_combn.c for my_aff_combn in /home/mar_b/rendu/Piscine-C-Jour_03
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Wed Mar  5 12:06:06 2014 Fabien Martinez
** Last update Thu Mar  6 08:56:50 2014 Fabien Martinez
*/

int	my_power(int a, int e)
{
  if (e == 0)
    return (1);
  else
    return (a * my_power(a, (e - 1)));
}

void	my_displaycomb(int nbr, char len, char first)
{
  char	a;
  if (first)
    {
      my_putchar(',');
      my_putchar(' ');
    }
  while (len >= 0)
    {
      my_putchar('0' + ((nbr / my_power(10, len)) % 10));
      len -= 1;
    }
}

int	my_ok_number(int nbr, char length)
{
  char	count;
  char	a;
  char	b;

  count = length;
  while (count > 0)
    {
      a = (nbr / my_power(10, count)) % 10;
      if (count >= 1)
	{
	  b = (nbr / my_power(10, (count - 1))) % 10;
	  if (a >= b)
	    {
	      count = 0;
	      return (0);
	    }
	}
      count -= 1;
    }
  return (1);
}

int	my_new_aff_combn(char n)
{
  int	nbr;
  char	count;
  char	a;
  char	b;
  char	bool;
  char	first;
  
  nbr = 0;
  b = 10;
  first = 0;
  while (nbr < (my_power(10, n)))
    {
      count = (n - 1);
      bool = my_ok_number(nbr, count);
      if (bool)
	{
	  my_displaycomb(nbr, (n - 1), first);
	  first = 1;
	}
      nbr += 1;
    }
}

int	my_aff_combn(int n)
{
  char	a;

  a = '0';
  if (n > 10 || n <= 0)
    {
      my_putchar('\n');
    }
  else if (n == 10)
    {
      while (a <= '9')
	{
	  my_putchar(a);
	  a += 1;
	}
    }
  else
    {
      my_new_aff_combn(n);
    }
  return (0);
}
