/*
** my_display_l.c for my_display_l in /home/mar_b/rendu/PSU_2013_my_ls
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Apr 24 11:28:30 2014 Fabien Martinez
** Last update Fri May  2 19:02:46 2014 Fabien Martinez
*/

#include "my_path.h"
#include "my_display.h"
#include "my_date.h"
#include "my_ls.h"

/*
** print uid name and grp name (thx captain ovbious)
*/
static void	my_putuid_grp(struct passwd *my_uid,
			      struct group *my_gid, char *opt)
{
  if (!opt[OWNER])
    my_printf(g_fd, "%s ", my_uid->pw_name);
  if (!opt[GROUP] && !opt[INFGRP])
    my_printf(g_fd, "%s ", my_gid->gr_name);
}

/*
** I'm so crazy with binary operations <3
*/
static void	my_putpermission(struct stat *buf)
{
  if (S_ISDIR(buf->st_mode))
    my_printf(g_fd, "d");
  else if (S_ISLNK(buf->st_mode))
    my_printf(g_fd, "l");
  else if (S_ISCHR(buf->st_mode))
    my_printf(g_fd, "c");
  else if (S_ISBLK(buf->st_mode))
    my_printf(g_fd, "b");
  else if (S_ISFIFO(buf->st_mode))
    my_printf(g_fd, "p");
  else if (S_ISSOCK(buf->st_mode))
    my_printf(g_fd, "s");
  else
    my_printf(g_fd, "-");
  my_printf(g_fd, (buf->st_mode & S_IRUSR) ? "r" : "-");
  my_printf(g_fd, (buf->st_mode & S_IWUSR) ? "w" : "-");
  my_printf(g_fd, (buf->st_mode & S_IXUSR) ? "x" : "-");
  my_printf(g_fd, (buf->st_mode & S_IRGRP) ? "r" : "-");
  my_printf(g_fd, (buf->st_mode & S_IWGRP) ? "w" : "-");
  my_printf(g_fd, (buf->st_mode & S_IXGRP) ? "x" : "-");
  my_printf(g_fd, (buf->st_mode & S_IROTH) ? "r" : "-");
  my_printf(g_fd, (buf->st_mode & S_IWOTH) ? "w" : "-");
  my_printf(g_fd, (buf->st_mode & S_IXOTH) ? "x " : "- ");
}

/*
** Will call function to print long format (like group, owner, permissions...
*/
void	my_putopt_l(struct stat *buf, char *date, char *opt)
{
  (void)date;
  my_putpermission(buf);
  my_printf(g_fd, "%d ", (int)buf->st_nlink);
  my_putuid_grp(getpwuid(buf->st_uid), getgrgid(buf->st_gid), opt);
  if (S_ISCHR(buf->st_mode) || S_ISBLK(buf->st_mode))
    my_printf(g_fd, "%u, %u ", major(buf->st_rdev), minor(buf->st_rdev));
  else
    my_printf(g_fd, "%ld ", buf->st_size);
  if (my_putdate(ctime(&buf->st_mtime), current_year(NULL)))
    my_puterror();
}

/*
** Will print the number of block of 1024B
*/
void		my_puttotal_l(char *str, char *path, int *count)
{
  struct stat	*buf;

  if (str[0] != '.')
    {
      if ((buf = malloc(sizeof(*buf))) == NULL)
	my_puterror();
      if ((lstat(my_pathfile(path, str, '\0'), buf)) == -1)
	(void)my_puterrno(my_pathfile(path, str, '\0'), errno);
      else
	*count += (buf->st_blocks / 2);
      free(buf);
    }
}
