/*
** fun.c for fun in /home/lefebv_1/rendu/colle5_mar_b
** 
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
** 
** Started on  Tue Sep 23 19:08:12 2014 lefebv_1 lefebv_1
** Last update Tue Sep 23 21:53:56 2014 lefebv_1 lefebv_1
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "utils.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

void	my_write(const int fd, const char *str, size_t size)
{
  if (write(fd, str, size) == -1)
    exit(1);
}

void	my_putstr(const char *str, const int fd)
{
  my_write(fd, str, my_strlen(str));
}

void	my_puterror(const char *str)
{
  my_write(2, str, my_strlen(str));
  exit(1);
}
