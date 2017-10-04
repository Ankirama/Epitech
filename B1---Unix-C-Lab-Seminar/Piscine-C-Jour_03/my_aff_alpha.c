/*
** my_aff_alpha.c for my_aff_alpha in /home/mar_b/rendu/Piscine-C-Jour_03
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Wed Mar  5 10:01:42 2014 Fabien Martinez
** Last update Thu Mar  6 08:49:11 2014 Fabien Martinez
*/

int	my_aff_alpha()
{
  char	i;

  i = 'a';
  while (i <= 'z')
    {
      my_putchar(i);
      i += 1;
    }
  return (0);
}
