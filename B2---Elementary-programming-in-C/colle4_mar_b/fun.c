/*
** fun.c for let it go in /home/user/rendu/colle4_
**
** Made by 
** Login   
**
** Started on  Tue Sep 16 19:23:57 2014 
** Last update Tue Sep 16 19:27:41 2014 
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void	my_write(int fd, const void *buf, size_t count)
{
  if (write(fd, buf, count) < 0)
    exit(EXIT_FAILURE);
}

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

void	my_puterror(const char *str)
{
  my_write(2, str, my_strlen(str));
  exit(EXIT_FAILURE);
}
