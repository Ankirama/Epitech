/*
** my_exec.c for my_exec in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat Jun 21 03:06:01 2014 mar_b mar_b
** Last update Sun Aug  3 14:02:39 2014
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parser.h"
#include "list.h"
#include "utils.h"

/*
** brief: it will concat our path with exec like /bin/ with ls (/bin/ls)
** @path: our path (like /bin/)
** @exec: our binary
** return the good one (/bin/ls)
*/
static char	*_my_pathfile(char *path, char *exec)
{
  char		*res;
  int		len;
  int		size;

  len = my_strlen(path);
  size = (path[len - 1] == '/') ? len : len + 1;
  if ((res = malloc(sizeof(char) * (size + my_strlen(exec) + 1))) == NULL)
    my_puterror("error: problem to malloc in my_exec.c: l56\n");
  res[0] = '\0';
  res = my_strcat(res, path);
  if (len != size)
    res[len] = '/';
  res[size] = '\0';
  res = my_strcat(res, exec);
  return (res);
}

/*
** brief: if we have already a paht then we will not use _my_pathfile
** @str: the char * we will try
** return: 0 if only binary, 1 else
*/
static char	_my_goodpath(char *str)
{
  int		i;
  char		path_bin;

  i = -1;
  path_bin = 0;
  while (str[++i] && path_bin == 0)
    if (str[i] == '/')
      path_bin = 1;
  return (path_bin);
}

/*
** brief: we will check with access
** @str: our binary
** @path: our path (/bin:/sbin...)
** return: return NULL if there is a pb or the good pathfile
*/
static char	*_my_access(char *str, char *path)
{
  char		**arr;
  int		i;
  char		*exec;

  if (_my_goodpath(str))
    return ((access(str, F_OK | X_OK) == -1) ? NULL : str);
  arr = my_str_to_wordtab(path, "::", -1);
  i = -1;
  while (arr[++i] != NULL)
    {
      exec = _my_pathfile(arr[i], str);
      if (access(exec, F_OK | X_OK) != -1)
	return (exec);
      free(exec);
    }
  return (NULL);
}

/*
** brief: we will execute our cmd
** @env: list env
** @exec_opt: our cmd + options etc...
** @path: our path variable (/bin:/sbin....)
** return: 0 if no problem else -1
*/
char	my_exec_pipe(t_list *env, char **exec_opt, char *path)
{
  char	**my_env;
  char	*exec;

  my_env = my_conv_lst(env);
  if ((exec = _my_access(exec_opt[0], path)) == NULL ||
      execve(exec, exec_opt, my_env) == -1)
    {
      my_cnf((exec == NULL) ? exec_opt[0] : exec, my_env);
      exit(EXIT_FAILURE);
    }
  else
    free_arr(my_env);
  return (0);
}

/*
** brief: we will execute our cmd
** @env: list env
** @exec_opt: our cmd + options etc...
** @path: our path variable (/bin:/sbin....)
** return: 0 if no problem else -1
*/
char	my_exec(t_list *env, char **exec_opt, char *path)
{
  pid_t	pid;
  int	statut;
  char	**my_env;
  char	*exec;

  pid = fork();
  if (pid == -1)
    return (my_error("impossible to find the son for fork!", "fork"));
  else if (pid == 0)
    {
      my_env = my_conv_lst(env);
      if ((exec = _my_access(exec_opt[0], path)) == NULL ||
	  execve(exec, exec_opt, my_env) == -1)
	{
	  my_cnf((exec == NULL) ? exec_opt[0] : exec, my_env);
	  exit(EXIT_FAILURE);
	}
      else
	free_arr(my_env);
      return (0);
    }
  else
    if (wait(&statut) == -1)
      my_puterror("error: unable to use wait!\n");
  return (0);
}
