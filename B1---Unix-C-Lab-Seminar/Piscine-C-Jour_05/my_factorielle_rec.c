/*
** my_factorielle_rec.c for facto_rec in /home/user/rendu/Piscine-C-Jour_05
** 
** Made by 
** Login   
** 
** Started on  Fri Mar  7 09:03:30 2014 
** Last update Sun Mar  9 07:51:07 2014 
*/

int	my_factorielle_rec(int nb)
{
  if (nb < 0 || nb > 12)
    return (0);
  else
    my_hat_function(nb);
}

int	my_hat_function(int nb)
{
  if (nb == 1 || nb == 0)
    return (1);
  else
    return (nb * my_hat_function(nb - 1));
}
