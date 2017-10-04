/*
** my_power_rec.c for test in /home/bourde_g/rendu/Library/Library
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 24 12:02:46 2014 Gauthier Bourdenx
** Last update Mon Mar 24 12:02:47 2014 Gauthier Bourdenx
*/

int	my_power_rec (int nb, int power)
{
  if (power == 0)
    {
      return (1);
    }
  if (power < 0)
    {
      return (0);
    }
  if (power != 0)
    {
      power = power - 1;
      return (nb * my_power_rec(nb, power));
    }
}
