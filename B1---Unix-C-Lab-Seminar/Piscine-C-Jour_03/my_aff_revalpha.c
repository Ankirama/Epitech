/*
** my_aff_revalpha.c for aff_revalpha in /home/user/rendu/Piscine-C-Jour_03
** 
** Made by 
** Login   
** 
** Started on  Wed Mar  5 10:11:12 2014 
** Last update Thu Mar  6 08:52:04 2014 
*/

int	my_aff_revalpha()
{
  char	i;

  i = 'z';
  while (i >= 'a')
    {
      my_putchar(i);
      i -= 1;
    }
  return (0);
}
