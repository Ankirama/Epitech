/*
** my_fun.c for my_fun in /home/mar_b/rendu/Piscine-C-Jour_11/ex_05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Mon Mar 24 14:55:48 2014 Fabien Martinez
** Last update Mon Mar 24 15:41:38 2014 Fabien Martinez
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i += 1;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i += 1;
  return (i);
}
