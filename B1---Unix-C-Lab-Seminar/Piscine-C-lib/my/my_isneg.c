/*
** my_isneg.c for test in /home/bourde_g/rendu/Library/Library
** 
** Made by Gauthier Bourdenx
** Login   <bourde_g@epitech.net>
** 
** Started on  Mon Mar 24 12:02:33 2014 Gauthier Bourdenx
** Last update Mon Mar 24 12:02:35 2014 Gauthier Bourdenx
*/

int	my_isneg(int nb)
{
  int	n;

  if (nb < 0)
    n = 'N';
  else
    n = 'P';
  my_putchar(n);
  return (0);
}
