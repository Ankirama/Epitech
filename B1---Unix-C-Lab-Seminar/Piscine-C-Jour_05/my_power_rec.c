/*
** my_power_rec.c for my_power_rec in /home/mar_b/rendu/Piscine-C-Jour_05
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Fri Mar  7 09:28:29 2014 Fabien Martinez
** Last update Sun Mar  9 07:57:12 2014 Fabien Martinez
*/

int	my_power_rec(int nb, int power)
{
  if (nb == 0)
    return (0);
  if (nb == 1)
    return (1);
  return (my_power_rec_main(nb, power));
}

int	my_power_rec_main(int nb, int power)
{
  if (power == 0)
    return (1);
  else
    return (nb * my_power_rec(nb, (power - 1)));
}
