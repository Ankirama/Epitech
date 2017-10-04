/*
** my_display.c for my_display in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Wed Apr 23 20:32:01 2014 Fabien Martinez
** Last update Fri May  2 18:54:40 2014 Fabien Martinez
*/

#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_printf.h"
#include "my_display.h"
#include "my_file.h"
#include "my_path.h"
#include "my_ls.h"
#include "my_options.h"
#include "my_fun.h"

/*
** This function will count 1 + 1 if 42 = 13
** In fact it will add color that all :(
*/
static char	my_putcolor(char *file, char *path, char *link, char *opt)
{
  struct stat	*buf;

  if ((buf = malloc(sizeof(*buf))) == NULL)
    my_puterror();
  if ((lstat(my_pathfile(path, file, '\0'), buf)) == -1)
    return (my_puterrno(my_pathfile(path, file, '\0'), errno));
  my_printf(opt[QUOTE] ? "\"" : "\0");
  file = opt[DIRC] && !CURR_P(path) ? my_pathfile(path, file, '\0') : file;
  if (my_check_color(file, link, buf, opt) == 1)
    {
      my_printf("\033[1m\033[36m%s\033[0m", file);
      my_printf(opt[QUOTE] ? "\" -> " : " -> ");
      my_putcolor(link, link[0] == '/' ? "\0" : path, NULL, opt);
    }
  else
    my_printf(opt[QUOTE] ? "\"\n" : "\n");
  free(buf);
  return (0);
}

/*
** This functionn will print our file and description
*/
void		my_putfile(char file, t_my_file *files, char *opt, char end)
{
  char		*link;
  t_my_file	*tmp;

  link = NULL;
  tmp = files;
  while (files != NULL)
    {
      if (!(opt[BACKUP] && files->name[my_strlen(files->name) - 1] == '~') &&
	  (file || opt[ALL] || !(files->name[0] == '.')))
	{
	  if (opt[LONG])
	    link = my_opt_l(my_pathfile(files->path, files->name, '\0'), opt);
	  (void)my_putcolor(files->name, files->path, link, opt);
	}
      files = files->next;
    }
  if (!file && !end)
    my_printf("\n");
  if (opt[RECURSIVE] && !opt[DIRC])
    my_opt_R(tmp, opt);
  free(link);
  free(tmp);
}

void	my_puterror()
{
  write(2, "Error : Problem with malloc !\n", 30);
  exit(EXIT_FAILURE);
}

char	my_puterrno(char *str, int my_errno)
{
  errno = my_errno;
  my_printf("my_ls: cannot open %s: %m\n", str);
  return (EXIT_FAILURE);
}
