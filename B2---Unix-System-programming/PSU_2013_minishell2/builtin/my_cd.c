/*
** my_cd.c for my_cd in /home/mar_b/minishell/builtin
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 23 19:29:54 2014 mar_b mar_b
** Last update Tue Jul 29 23:30:12 2014
*/

#include <unistd.h>
#include <stdlib.h>
#include "list.h"
#include "utils.h"
#include "builtin.h"

/*
** brief: this function will write on stderr a specific message
** @error: the message
** @dir: the directory
** return: return 0
*/
static void	_my_error_cd(const char *error, char *dir)
{
  (void)write(2, error, my_strlen(error));
  (void)write(2, dir, my_strlen(dir));
  (void)write(2, "\n", 1);
}

/*
** brief: this function will return the good path if there is a ~ like cd ~
** @env: our env list
** @path: our current path (like ~/rendu)
** return: return the good string
*/
static char	*_my_tilde(t_list *env, char *path)
{
  char		*dir;
  char		*home;
  char		*tmp;
  int		i;

  if ((tmp = my_find_element(env, "HOME")) == NULL || tmp[0] == '\0')
    {
      (void)my_error("cd: HOME not set", "minishel2");
      return (NULL);
    }
  if ((home = malloc(my_strlen(tmp) + 1)) == NULL)
    my_puterror("error: problem to malloc in my_cd.c\n");
  i = -1;
  while (tmp[++i] != '\0' && tmp[i] != '\\')
    home[i] = tmp[i];
  home[i] = '\0';
  if ((dir = malloc(my_strlen(path) + my_strlen(home) + 1)) == NULL)
    my_puterror("error: problem to malloc in my_cd.c\n");
  dir[0] = '\0';
  dir = my_strcat(dir, home);
  free(home);
  dir = my_strcat(dir, path);
  return (dir);
}

/*
** brief: will set the good path (like /home/mar_b)
** @env: our env list
** @path: our current path (like NULL, ~/rendu ...)
** return: return the good path (or NULL if any problem)
*/
static char	*_my_directory(t_list *env, char *path)
{
  char		*dir;

  if (path == NULL)
    {
      if ((dir = my_strdup(my_find_element(env, "HOME"))) == NULL)
	{
	  (void)my_error("cd: HOME not set", "minishel2");
	  return (NULL);
	}
    }
  else if (my_strcmp(path, "-", 0))
    {
      if ((dir = my_strdup(my_find_element(env, "OLDPWD"))) == NULL)
	{
	  free(dir);
	  dir = my_charpwd();
	  return (dir);
	}
    }
  else if (path[0] == '~')
    dir = _my_tilde(env, &path[1]);
  else
    dir = my_strdup(path);
  return (dir);
}

/*
** brief: this function will change directory, it will check if the dir exist
** @end: our env list
** @arr: this arr contains our command (arr[0] = cd) and our directory (arr[1])
** BRIEF: if cd (without arg) the we will try to find in env HOME variable,
** if cd - then we will try to find our OLDPWD
** return: if chdir is ok then we return 1 to change our PWD variable else 0
*/
char	my_cd(t_list *env, char **arr)
{
  char	*dir;

  if ((dir = _my_directory(env, arr[1])) == NULL)
    return (1);
  if (access(dir, F_OK) == -1)
    _my_error_cd("cd: no such file or directory: ", dir);
  else if (access(dir, R_OK) == -1)
    _my_error_cd("cd: permission denied: ", dir);
  else if (chdir(dir) == -1)
    _my_error_cd("cd: you cannot change the dir: ", dir);
  free(dir);
  return (1);
}
