/*
** my_power_it.c for my_power_it in /home/mar_b/rendu/Piscine-C-Jour_05
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Fri Mar  7 09:13:38 2014 Fabien Martinez
** Last update Fri Mar  7 09:33:42 2014 Fabien Martinez
*/

int	my_power_it(int nb, int power)
{
  int	i;
  int	nbr;

  if (power == 0)
    return (1);
  i = 0;
  nbr = 1;
  while (i < power)
    {
      nbr *= nb;
      i += 1;
    }
  return (nbr);
}
