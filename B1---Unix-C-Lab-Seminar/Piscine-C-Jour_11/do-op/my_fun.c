/*
** my_fun.c for my_fun in /home/user/rendu/Piscine-C-Jour_11/do-op
**
** Made by 
** Login   
**
** Started on  Mon Mar 24 14:55:48 2014 
** Last update Mon Mar 24 16:36:04 2014 
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
