/*
** my_8r2.c for my_8r2 in /home/mar_b/rendu/Piscine-C-Jour_05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Fri Mar  7 16:36:53 2014 Fabien Martinez
** Last update Sun Mar  9 20:38:28 2014 Fabien Martinez
*/

int	my_abs2(int n) {
  if (n < 0)
    return (n * -1);
  return (n);
}

char	my_array_is_ok2(int x, int y, int dames_x[8])
{
  int	j;

  j = 0;
  while (j < y)
    {
      if (my_abs2(dames_x[j] - x) == my_abs2(j - y) || dames_x[j] == x)
	return (0);
      j += 1;
    }
  return (1);
}

void	my_rec2(int y, int *nbr, int *dames_x)
{
  int	x;
  int	j;

  if (y == 8)
    {
      j = 0;
      while (j < 8)
	{
	  my_putchar('0' + *(dames_x + j));
	  j += 1;
	}
      my_putchar('\n');
    }
  else
    {
      x = 0;
      while (x < 8)
	{
	  if (my_array_is_ok2(x, y, dames_x))
	    {
	      *(dames_x + y) = x;
	      my_rec2((y + 1), nbr, dames_x);
	    }
	  x += 1;
	}
    }
}

int	my_8r2()
{
  int	dames_x[8];
  int	nbr;

  nbr = 0;
  my_rec2(0, &nbr, &(dames_x[0]));
}
