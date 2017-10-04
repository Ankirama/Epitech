/*
** my_8r1.c for my_8r1 in /home/mar_b/rendu/Piscine-C-Jour_05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Mar  7 09:36:53 2014 Fabien Martinez
** Last update Sun Mar  9 20:37:36 2014 Fabien Martinez
*/

int	my_abs(int n)
{
  if (n < 0)
    return (n * -1);
  return (n);
}

char	my_array_is_ok(int x, int y, int dames_x[8])
{
  int	j;

  j = 0;
  while (j < y)
    {
      if (my_abs(dames_x[j] - x) == my_abs(j - y) || dames_x[j] == x)
	return (0);
      j += 1;
    }
  return (1);
}

void	my_rec(int y, int *nbr, int *dames_x)
{
  int	x;

  if (y == 8)
    {
      *nbr += 1;
    }
  else
    {
      x = 0;
      while (x < 8)
	{
	  if (my_array_is_ok(x, y, dames_x))
	    {
	      *(dames_x + y) = x;
	      my_rec((y + 1), nbr, dames_x);
	    }
	  x += 1;
	}
    }
}

int	my_8r1()
{
  int	dames_x[8];
  int	nbr;

  nbr = 0;
  my_rec(0, &nbr, &(dames_x[0]));
  return (nbr);
}
