/*
** my_aff_chiffre.c for my_aff_chiffre in /home/user/rendu/Piscine-C-Jour_03
** 
** Made by 
** Login   
** 
** Started on  Wed Mar  5 10:17:10 2014 
** Last update Thu Mar  6 08:49:28 2014 
*/

int	my_aff_chiffre()
{
  char	n;

  n = '0';
  while (n <= '9')
    {
      my_putchar(n);
      n += 1;
    }
  return (0);
}
