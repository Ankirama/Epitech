/*
** my_color.c for my_color in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu May  1 10:40:39 2014 Fabien Martinez
** Last update Fri May  2 15:36:28 2014 Fabien Martinez
*/

#include "my_display.h"
#include "my_ls.h"
#include "my_options.h"

static void	my_create_tab_color(int k, char *file)
{
  char		*color[8];

  color[0] = "\033[1;34m";
  color[1] = "\033[1;33m";
  color[2] = "\033[1;33m";
  color[3] = "\033[21;33m";
  color[4] = "\033[1;31m";
  color[5] = "\033[1;36m";
  color[6] = "\033[1;33m";
  color[7] = 0;
  my_printf(g_fd, "%s%s\033[0m", color[k], file);
}

static int	my_create_tab_opt_col(struct stat *buf)
{
  char		my_opt_col[8];
  int		i;

  my_opt_col[0] = S_ISDIR(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[1] = S_ISCHR(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[2] = S_ISBLK(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[3] = S_ISFIFO(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[4] = S_ISSOCK(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[5] = S_ISLNK(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[6] = ((buf->st_mode & S_IXGRP) || (buf->st_mode & S_IXUSR) ||
		   (buf->st_mode & S_IXOTH));
  my_opt_col[7] = S_ISREG(buf->st_mode) == 1 ? 1 : 0;
  i = 0;
  while (i < 8 && my_opt_col[i] != 1)
    ++i;
  return (i);
}

char	my_check_color(char *file, char *link, struct stat *buf, char *opt)
{
  int	i;

  i = my_create_tab_opt_col(buf);
  if (i == 7 || opt[NOTSORT])
    my_printf(g_fd, "%s", file);
  else if (i == 6)
    my_printf(g_fd, "\033[1;32m%s\033[0m", file);
  else if (i != 5)
    my_create_tab_color(i, file);
  else
    {
      if (!link)
	my_create_tab_color(i, file);
      else
  	return (1);
    }
  if (opt[INDICATOR])
    my_option_F(i);
  return (0);
}
