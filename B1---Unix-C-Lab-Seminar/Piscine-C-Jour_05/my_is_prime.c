/*
** my_is_prime.c for my_is_prime in /home/mar_b/rendu/Piscine-C-Jour_05
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Fri Mar  7 10:17:17 2014 Fabien Martinez
** Last update Fri Mar  7 10:25:36 2014 Fabien Martinez
*/

int	my_is_prime(int nb)
{
  int	i;

  if (nb < 2)
    return (0);
  if (nb == 2)
    return (1);
  if (nb % 2 == 0)
    return (0);
  i = 3;
  while (i * i <= nb)
    {
      if (nb % i == 0)
	return (0);
      i += 2;
    }
  return (1);
}
