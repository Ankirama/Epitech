/*
** my_factorielle_it.c for facto it in /home/mar_b/rendu/Piscine-C-Jour_05
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Fri Mar  7 08:51:53 2014 Fabien Martinez
** Last update Fri Mar  7 09:02:27 2014 Fabien Martinez
*/

int	my_factorielle_it(int nb)
{
  int	i;
  int	nbr;

  if (nb < 0 || nb > 12)
    return (0);
  i = nb;
  nbr = 1;
  while (i > 0)
    {
      nbr *= i;
      i -= 1;
    }
  return (nbr);
}
