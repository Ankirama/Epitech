/*
** my_square_root.c for test in /home/bourde_g/rendu/Library/Library
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 24 12:05:34 2014 Gauthier Bourdenx
** Last update Mon Mar 24 12:05:35 2014 Gauthier Bourdenx
*/

int	my_square_root(int nb)
{
  int	n;
  int	m;

  n = 0;
  m = 1;
  if (nb <= 0)
    return (0);
  else
    {
      while (nb <= 0)
	{
	  nb = nb - m;
	  n = n + 1;
	  m = m + 2;
	}
      if (nb == 0)
	return (n);
      else
	return (0);
    }
}
