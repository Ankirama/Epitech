/*
** my_check.c for my_check in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 16 15:45:21 2014 mar_b mar_b
** Last update Sun Aug  3 14:01:45 2014
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell2.h"
#include "builtin.h"
#include "utils.h"
#include "list.h"
#include "parser.h"

char *my_path(char *path)
{
  if (path == NULL)
    return (PATH);
  return (path);
}

/*
** brief: we will try to find the good command
** @env: our env list
** @arr: contain the command and values
** return: 1 if we found our cmd or 0 if the cmd is not found
*/
int	my_builtin_fun(char **arr, t_list *env)
{
  char	(*tab[5])(t_list *, char **);
  char	**fun;
  int	i;

  if ((fun = malloc(sizeof(char *) * 5)) == NULL)
    my_puterror("error: problem to malloc in my_check.c!\n");
  fun[0] = "exit";
  fun[1] = "env";
  fun[2] = "cd";
  fun[3] = "setenv";
  fun[4] = "unsetenv";
  tab[0] = my_exit;
  tab[1] = my_env;
  tab[2] = my_cd;
  tab[3] = my_setenv;
  tab[4] = my_unsetenv;
  i = -1;
  while (++i < 5 && !my_strcmp(arr[0], fun[i], 0));
  free(fun);
   if (i == 5)
    return (0);
  return (tab[i](env, arr));
}

/*
** brief: main function to find the cmd
** @str: the str with the cmd and options like env -i ls -l
** @env: our env list
** BRIEF: this function will try to find our builtin cmd else it'll use execve
** return: return 0 if it's ok, 1 if chdir and 42 if exit used
*/
char	my_check_fun(char **arr, t_list *env)
{
  if (arr == NULL || arr[0] == NULL)
    return (0);
  if (my_builtin_fun(arr, env) == 0)
    (void)my_exec(env, arr, my_path(my_find_element(env, "PATH")));
  return (0);
}
