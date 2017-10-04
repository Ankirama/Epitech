/*
** my_ls.c for my_ls in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 23 01:43:40 2014 Fabien Martinez
** Last update Sat Feb 21 06:44:01 2015 Fabien Martinez
*/

#include "my_ls.h"
#include "my_display.h"
#include "my_read.h"
#include "utils.h"
#include "my_check.h"

int	g_fd;

/*
** This function looks like a main, but i'm not sure I pasted it... <3
*/
int	my_ls(char **argv, int fd, char *ignored)
{
  int	i;
  char	opt[8];

  errno = 0;
  i = 0;
  (void)argv;
  (void)ignored;
  my_printf(fd, "150 Opening ASCII mode data connection for file list\n");
  g_fd = fd;
  while (i < 8)
    opt[i++] = 0;
  (void)my_read_dir("./", opt, 0, 1);
  my_printf(fd, "226 Transfer complete\n");
  my_printf(fd, "%s\n", END_READ);
  free_wordtab(argv);
  return (0);
}
