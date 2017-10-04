/*
** my_read.c for my_read in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Sun Apr 27 21:21:52 2014 Fabien Martinez
** Last update Sat Feb 21 22:47:19 2015 Fabien Martinez
*/

#include "my_ls.h"
#include "my_path.h"
#include "my_display.h"
#include "my_display_l.h"
#include "my_file.h"
#include "my_options.h"
#include "my_sort.h"
#include "my_fun.h"

/*
** This function will display the help
*/
char	my_help()
{
  my_printf(g_fd, "Usage : ./my_ls [-aBlRdrtFfgGoS] [FILES]\n\n");
  my_printf(g_fd, "-a: \tdo not ignore entries starting with .\n");
  my_printf(g_fd, "-B: \tdo not list implied entries ending with ~\n");
  my_printf(g_fd, "-d: \tlist directory entries instead of contents\n");
  my_printf(g_fd, "-f: \tdo not sort, enable -a and disable color\n");
  my_printf(g_fd, "-F: \tappend indicator (one of */=@|) to entries\n");
  my_printf(g_fd, "-g: \tlike -l, but do not list owner\n");
  my_printf(g_fd, "-G: \tin a long listing, don't print group names\n");
  my_printf(g_fd, "-l: \tuse a long listing format\n");
  my_printf(g_fd, "-o: \tlike -l, but do not list group information\n");
  my_printf(g_fd, "-r: \treverse order while sorting\n");
  my_printf(g_fd, "-R: \tlist subdirectories recursively\n");
  my_printf(g_fd, "-S: \tsort by file size\n");
  my_printf(g_fd, "-t: \tsort by modification time, newest first\n");
  return (1);
}

/*
** Used to read each repo/etc like a file (-d option)
*/
static char	my_read_optD(char *str, char *opt)
{
  t_my_file	*my_file;
  char		*file;

  my_file = NULL;
  file = my_separpathD(&str);
  if (file[0] == '\0')
    {
      write(2, "Error : unvalid file name\n", 26);
      exit(EXIT_FAILURE);
    }
  my_file = my_add_file(my_file, file, str, DT_REG);
  my_putfile(1, my_file, opt, 1);
  free(file);
  return (0);
}

static char	my_read_file(char *str, char *opt)
{
  t_my_file	*my_file;
  char		*file;

  my_file = NULL;
  file = my_separpath(&str);
  if (!opt[DIRC] && errno != ENOTDIR)
    return (my_puterrno(str, errno));
  else if (file[0] == '\0')
    {
      write(2, "Error : unvalid file name\n", 26);
      exit(EXIT_FAILURE);
    }
  my_file = my_add_file(my_file, file, str, DT_REG);
  my_putfile(1, my_file, opt, 1);
  free(file);
  return (0);
}

/*
** This function will check if it can open the dir, if not it will
** call my_read_file to try to read the file
*/
char		my_read_dir(char *str, char *opt, char multiple, char end)
{
  DIR		*rep;
  t_my_file	*my_files;
  struct dirent	*my_file;
  int		count;

  count = 0;
  my_files = NULL;
  if  ((opt[DIRC] && multiple) ||
       (!(rep = opendir(str)) && !(rep = opendir(my_pathfile(str, "\0", '/')))))
    return (my_read_file(str, opt));
  str = str[strlen(str) - 1] != '/' ? my_pathfile(str, "\0", '/') : str;
  while ((my_file = readdir(rep)))
    {
      if (opt[LONG])
	my_puttotal_l(my_file->d_name, str, &count);
      my_files = my_add_file(my_files, my_file->d_name, str, my_file->d_type);
    }
  if (errno != 0)
    return (my_puterrno(str, errno));
  my_printf(g_fd, (opt[RECURSIVE] || multiple ? "%s:\n" : ""), str);
  my_printf(g_fd, (opt[LONG] ? "total %d\n" : ""), count);
  my_putfile(my_sort_list(&my_files, opt[REVERSE], opt), my_files, opt, end);
  if (closedir(rep) == -1)
    return (my_puterrno(str, errno));
  return (0);
}

/*
** This function will choose if it has to call my_read_dir (without option d)
** or call the function for d option
*/
char	my_read_manage(char **str, char *opt)
{
  int	i;

  i = 0;
  str = my_sort_alpha(str, opt[REVERSE]);
  if (opt[DIRC])
    {
      if (str[0] == 0)
	return (my_read_optD("./", opt));
      while (str[i] != 0)
	{
	  errno = 0;
	  (void)my_read_optD(str[i], opt);
	  i += 1;
	}
      return (0);
    }
  while (str[i] != 0)
    {
      errno = 0;
      (void)my_read_dir(str[i], opt, str[1] != 0 ? 1 : 0,
			str[i + 1] != 0 ? 0 : 1);
      i += 1;
    }
  return (0);
}
