/*
** main.c<2> for main in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Feb 21 19:30:29 2015 Fabien Martinez
*/

#include "utils.h"

void	my_close(int fd)
{
  if (close(fd) == -1)
    perror("close");
}

ssize_t	my_read(int fd, void *buf, size_t size)
{
  int	len;

  if ((len = read(fd, buf, size)) == -1)
    {
      perror("read");
      return (-1);
    }
  return (len);
}

ssize_t	my_write(int fd, const void *buf, size_t size)
{
  int	len;

  if ((len = write(fd, buf, size)) == -1)
    {
      perror("write");
      return (-1);
    }
  return (len);
}

void	*my_malloc(size_t size)
{
  void	*p;

  if (!(p = malloc(size)))
    {
      fprintf(stderr, "malloc: %s\n", ERR_MALLOC);
      exit(EXIT_FAILURE);
    }
  return (p);
}

void	*my_realloc(void *ptr, size_t size)
{
  void	*p;

  if (!(p = realloc(ptr, size)))
    fprintf(stderr, "./realloc: %s\n", ERR_MALLOC);
  return (p);
}
