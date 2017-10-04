/*
** fun.c for fun in /home/lefebv_1/colle_06_HBX_mar_b
**
** Made by lefebv_1 lefebv_1
** Login   <lefebv_1@epitech.net>
**
** Started on  Tue Sep 30 18:51:15 2014 lefebv_1 lefebv_1
** Last update Tue Sep 30 20:24:32 2014 lefebv_1 lefebv_1
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "utils.h"

void	my_putchar(char c)
{
  my_write(1, &c, 1);
}

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    ++i;
  return (i);
}

void	*my_malloc(size_t size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    my_puterror(ERR_MALLOC);
  return (ptr);
}

void	my_write(const int fd, const void *str, size_t size)
{
  if (write(fd, str, size) < 0)
    exit(EXIT_FAILURE);
}

void	my_puterror(char *str)
{
  my_write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}
