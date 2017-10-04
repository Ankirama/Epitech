/*
** my_factorielle_it.c for facto it in /home/user/rendu/Piscine-C-Jour_05
** 
** Made by 
** Login   
** 
** Started on  Fri Mar  7 08:51:53 2014 
** Last update Fri Mar  7 09:02:27 2014 
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
