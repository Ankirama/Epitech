/*
** main.c for main lol mdr in /home/mar_b/rendu/CPE_2013_getnextline
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Apr 22 23:40:37 2014 Fabien Martinez
** Last update Wed May  7 20:24:55 2014 mar_b mar_b
*/

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "my_str_to_wordtab.h"
#include "my_tab.h"

int	my_strlen(char *str)
{
  if (str == NULL || !str[0])
    return (0);
  else
    return (1 + my_strlen(&str[1]));
}

int	my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}

int		main(int argc, char **argv)
{
  char		*s;
  int		i;
  int		fd;
  t_my_tab	*tab;

  tab = NULL;
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    my_puterror(1, errno);
  while (s = get_next_line(fd))
    {
      tab = my_append_elt(tab, my_str_to_wordtab(s));
      free(s);
    }
  while (tab != NULL)
    {
      i = 0;
      while (tab->data[i] != 0)
	{
	  my_putstr(tab->data[i++]);
	  write(1, " ", 1);
	}
      write(1, "\n", 1);
      tab = tab->next;
    }
  if (close(fd) == -1)
    my_puterror(1, errno);
  return (0);
}
