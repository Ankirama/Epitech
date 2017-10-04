/*
** my_square_root.c for my_square_root in /home/mar_b/rendu/Piscine-C-Jour_05
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Fri Mar  7 09:51:21 2014 Fabien Martinez
** Last update Sun Mar  9 07:55:51 2014 Fabien Martinez
*/

double	my_square_root_rec(int nb, int e)
{
  if (e == 1)
    return (1);
  else
    return (0.5 * (my_square_root_rec(nb, e - 1) + ((double)nb / my_square_root_rec(nb, e - 1))));
}

int		my_square_root(int nb)
{
  double	result;
  double	deci;

  result = my_square_root_rec(nb, 20);
  deci = result - (int)result;
  if (deci > 0.1)
    return (0);
  return (result);
}

