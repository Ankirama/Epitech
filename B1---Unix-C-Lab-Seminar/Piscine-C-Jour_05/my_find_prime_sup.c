/*
** my_find_prime_sup.c for my_find_prime_sup in /home/mar_b/rendu/Piscine-C-Jour_05
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Fri Mar  7 10:29:44 2014 Fabien Martinez
** Last update Sun Mar  9 07:51:21 2014 Fabien Martinez
*/

int	my_find_prime_sup(int nb)
{
  int	nbr;

  nbr = nb;
  if (nbr <= 2)
    return (2);
  if (nbr % 2 == 0)
    {
      nbr += 1;
    }
  while (my_prime(nbr) != 1)
    {
      nbr += 2; 
    }
  return (nbr);
}

int	my_prime(int nb)
{
  int   i;

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
