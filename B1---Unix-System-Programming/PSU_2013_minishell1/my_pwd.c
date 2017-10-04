/*
** pwd.c for my_pwd in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed Jun 18 12:38:45 2014 mar_b mar_b
** Last update Sun Jun 22 23:03:15 2014 mar_b mar_b
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "my_str.h"
#include "my_error.h"

/*
** brief: this function will try to find our direct with stat
** @dir: the DIR used
** @cur: the current directory
** return: return the name of the directory
*/
static char		*_my_find_dir(DIR *dir, struct stat *cur)
{
  struct dirent		*dirent;
  struct stat		tmp;
  int			found;
  char			*foundDir;

  found = 0;
  while (!found && (dirent = readdir(dir)) != NULL)
    {
      if (lstat(dirent->d_name, &tmp) != 0)
	my_puterror("error: unable to use lstat in my_pwd.c: l30!\n");
      if ((tmp.st_dev == cur->st_dev) && (tmp.st_ino == cur->st_ino))
	found = 1;
    }
  if ((foundDir = my_strdup(dirent->d_name)) == NULL)
    my_puterror("error: problem with strdup in my_pwd.c: l37!\n");
  if (closedir(dir) == -1)
    my_puterror("error: problem during closedir in my_pwd.c: l39!\n");
  if (!found)
    my_puterror("error: unable to find the current dir in my_pwd: l41!\n");
  return (foundDir);
}

/*
** brief: initialize our struct stat and return our DIR
** @cur: it will be the current dir
** @parent: the parent (used to search our current name dir)
** return: return the DIR
*/
static DIR	*_my_init(struct stat *cur, struct stat *parent)
{
  DIR		*dir;

  if (lstat(".", cur) != 0)
    my_puterror("error: problem with lstat in my_pwd.c: l50!\n");
  chdir("..");
  if (lstat(".", parent) != 0)
    my_puterror("error: problem with lstat in my_pwd.c: l53!\n");
  if (!(dir = opendir(".")))
    my_puterror("error: unable to open the cur dir in my_pwd: l55!\n");
  return (dir);
}

/*
** brief: we will cat our cur dir with the foundDir (ex home/mar_b)
** @foundDir: the founddir (like mar_b)
** @curDir: the current dir is like mar_b/rendu
** return: return the curDir with the new foundDir
*/
static char	*my_new_str(char *foundDir, char *curDir)
{
  int		len;
  int		len2;

  len = my_strlen(curDir);
  if (len != 1)
    curDir = my_strcat(curDir, "/");
  if (foundDir)
    {
      len2 = my_strlen(foundDir);
      if ((len + len2 + 1) > 256)
	my_puterror("error: the path's size is too big in my_pwd.c: l71!\n");
      curDir = my_strcat(curDir, foundDir);
      free(foundDir);
    }
  return (curDir);
}

/*
** brief: rec function used to found our directory
** return: return the good path
*/
static char	*my_return_pwd()
{
  struct stat	cur;
  struct stat	parent;
  DIR		*dir;
  char		*curDir;
  char		*foundDir;

  dir = _my_init(&cur, &parent);
  if ((cur.st_dev == parent.st_dev) && (cur.st_ino == parent.st_ino))
    {
      if ((curDir = malloc(sizeof(char) * 256)) == NULL)
	my_puterror("error: problem to malloc curDir in my_pwd.c: l92!\n");
      curDir[0] = '\0';
      foundDir = NULL;
    }
  else
    {
      foundDir = _my_find_dir(dir, &cur);
      curDir = my_return_pwd();
    }
  return (my_new_str(foundDir, curDir));
}

/*
** brief: main function to find our path, it will chdir after it
** return: return our path
*/
char	*my_pwd()
{
  char	*pwd;

  pwd = my_return_pwd();
  if (chdir(pwd) == -1)
    my_error("unable to find directory in my_pwd.c: l110\n", "error");
  return (pwd);
}
