/*
** fun.c for fun in /home/mar_b/rendu/colle3_bob42
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep  9 19:27:26 2014 mar_b mar_b
** Last update Wed Sep 10 00:20:40 2014 lefebv_1 lefebv_1
** Last update Tue Sep  9 20:37:11 2014 mar_b mar_b
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "calc.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

void	my_write(int fd, const void *buf, size_t count)
{
  if (write(fd, buf, count) < 0)
    exit(EXIT_FAILURE);
}

char	*my_strncat(char *s1, char *s2 , int len)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (s2 == NULL || s1 == NULL)
    my_puterror(ERR_STRNCAT);
  while (s1[i] != '\0')
    i = i + 1;
  while (s2[j] != '\0' && j < len)
    {
      s1[i] = s2[j];
      i = i + 1;
      j = j + 1;
    }
  s1[i] = '\0';
  return (s1);
}

void	*my_malloc(size_t size)
{
  void	*data;

  if ((data = malloc(size)) == NULL)
    my_puterror(ERR_MALLOC);
return (data);
}

char	*my_put_in_str(int nbr)
{
  char	*str;
  int	size;

  size = size_nbr(nbr);
  if (nbr < 0)
    str = my_malloc(size + 2);
  else
    str = my_malloc(size + 1);
  str[size] = '\0';
  if (nbr < 0)
    str[0] = '_';
  size = (nbr < 0) ? size : size - 1;
  while (nbr != 0)
    {
      str[size] = (nbr < 0) ? (nbr % 10) * -1 + '0' : nbr % 10 + '0';
      nbr = nbr / 10;
      size = size - 1;
    }
  return (str);
}
