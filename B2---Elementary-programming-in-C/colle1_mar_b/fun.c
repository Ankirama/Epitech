/*
** fun.c for let it go in /home/mar_b/rendu/colle1_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Aug 26 20:20:40 2014 mar_b mar_b
** Last update Tue Aug 26 22:30:59 2014 mar_b mar_b
*/

#include <stdlib.h>
#include <sys/types.h>
#include "utils.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	++i;
    }
  return (i);
}

void	my_puterror(const char *str)
{
  my_write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}

void	my_write(const int fd, const void *buf, size_t count)
{
  if (write(fd, buf, count) == -1)
    exit(EXIT_FAILURE);
}

void	my_putstr(const char *str, const int fd)
{
  my_write(fd, str, my_strlen(str));
}
