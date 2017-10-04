/*
** my_options.c for options in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Apr 24 15:39:56 2014 Fabien Martinez
** Last update Fri May  2 19:16:25 2014 Fabien Martinez
*/

#include <stdlib.h>
#include <grp.h>
#include <dirent.h>
#include <pwd.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "my_ls.h"
#include "my_file.h"
#include "my_display_l.h"
#include "my_check.h"
#include "my_printf.h"

/*
** Option -l (add permission, date user etc)
*/
char		*my_opt_l(char *str, char *opt)
{
  struct stat	*buf;
  int		len;
  char		*link;

  if ((buf = malloc(sizeof(*buf))) == NULL ||
      (link = malloc(256 * sizeof(char))) == NULL)
    my_puterror();
  if ((lstat(str, buf) == -1))
    my_puterrno(str, errno);
  my_putopt_l(buf, ctime(&buf->st_atime), opt);
  if (S_ISLNK(buf->st_mode))
    {
      if ((len = readlink(str, link, 256 * sizeof(char))) < 0)
        my_puterrno(str, errno);
      else
	link[len] = '\0';
      free(buf);
      return (link);
    }
  free(buf);
  return (NULL);
}

/*
** This function Will check if the current t_my_file contains a direct
** to call him and print files
*/
void		my_opt_R(t_my_file *files, char *opt)
{
  t_my_file	*tmp;

  tmp = files;
  while (tmp != NULL)
    {
      if ((opt[ALL] && !my_check_dir(tmp->name) || tmp->name[0] != '.')
	  && tmp->type == DT_DIR)
	{
	  my_printf("\n");
	  my_read_dir(my_pathfile(tmp->path, tmp->name, '/'), opt);
	}
      tmp = tmp->next;
    }
  free(tmp);
}

/*
** This function will append a char at the end of each special type
*/
void	my_option_F(int i)
{
  char	optF[8];

  optF[0] = '/';
  optF[1] = '\0';
  optF[2] = '\0';
  optF[3] = '|';
  optF[4] = '=';
  optF[5] = '@';
  optF[6] = '*';
  if (i < 7)
    my_printf("%c", optF[i]);
}
