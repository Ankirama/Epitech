/*
** my_putstr.c for my_putstr in /home/mar_b/rendu/Piscine-C-Jour_04
** 
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
** 
** Started on  Thu Mar  6 09:49:57 2014 Fabien Martinez
** Last update Thu Mar  6 10:03:26 2014 Fabien Martinez
*/

int	my_putstr(char *str)
{
  int	n;

  n = 0;
  while (*(str + n) != '\0')
    {
      my_putchar(*(str + n));
      n += 1;
    }
}
