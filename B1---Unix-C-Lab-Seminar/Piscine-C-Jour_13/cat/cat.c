/*
** cat.c for cat in /home/mar_b/rendu/Piscine-C-Jour_13/cat
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Mar 26 09:55:05 2014 Fabien Martinez
** Last update Thu Mar 27 21:37:34 2014 Fabien Martinez
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "my.h"
#include "my_perror.h"

void	my_init(char *str, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      str[i] = 0;
      i += 1;
    }
}

int	read_file(char *path)
{
  int	fd;
  int	bytes;
  char	buffer[30000];

  bytes = 1;
  fd = open(path, O_RDONLY);
  if (fd == -1)
    {
      my_print_error(errno, path);
      return (1);
    }
  while (bytes > 0)
    {
      my_init(&(buffer[0]), 30000);
      bytes = read(fd, buffer, 30000);
      if (bytes == -1)
	{
	  my_print_error(errno, path);
	  close(fd);
	  return (1);
	}
      my_putstr(buffer);
    }
  close(fd);
  return (0);
}

int	main(int argc, char **argv)
{
  int	i;
  int	count;
  char	buffer[30000];

  if (argc == 1)
    {
      count = 1;
      while (count != 0)
	{
	  my_init(&(buffer[0]), 30000);
	  count = read(0, buffer, 30000);
	  if (count == -1)
	    {
	      return (my_print_error(errno, "cat: "));
	    }
	  if (count > 0 && count < 30000)
	    my_putstr (buffer);
	}
    }
  i = 1;
  while (i < argc)
    {
      read_file(argv[i]);
      i += 1;
    }
}
