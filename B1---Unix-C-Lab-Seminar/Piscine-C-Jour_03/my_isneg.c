/*
** my_isneg.c for my_isneg in /home/mar_b/rendu/Piscine-C-Jour_03
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Wed Mar  5 10:20:32 2014 Fabien Martinez
** Last update Thu Mar  6 08:52:12 2014 Fabien Martinez
*/

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return (0);
}
