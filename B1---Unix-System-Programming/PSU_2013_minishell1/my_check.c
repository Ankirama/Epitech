/*
** my_check.c for my_check in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 16 15:45:21 2014 mar_b mar_b
** Last update Sun Jun 22 19:40:45 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_error.h"
#include "minishell1.h"
#include "my_fun.h"
#include "my_builtin.h"
#include "my_set_var.h"
#include "my_str.h"
#include "my_list.h"
#include "my_list2.h"
#include "my_pwd.h"
#include "my_str_to_wordtab.h"
#include "my_exec.h"
#include "my_free.h"

/*
** brief: we will try to find the good command
** @env: our env list
** @arr: contain the command and values
** return: 1 if we found our cmd but it's not cd, 0 if the cmd is not found
** and 2 if we have change the dir and 43 if exit
*/
static int	_my_builtin_fun(char **arr, t_list *env)
{
  char		*pwd;

  if (my_strcmp(arr[0], "exit", 0))
    return (my_exit(env, arr));
  else if (my_strcmp(arr[0], "env", 0))
    my_env(env, arr);
  else if (my_strcmp(arr[0], "cd", 0))
    return (my_cd(arr) + 1);
  else if (my_strcmp(arr[0], "pwd", 0))
    {
      pwd = my_find_element(env, "PWD");
      write(1, pwd, my_strlen(pwd));
      write(1, "\n", 1);
      return (1);
    }
  else if (my_strcmp(arr[0], "setenv", 0))
    my_setenv(env, arr);
  else if (my_strcmp(arr[0], "unsetenv", 0))
    my_unsetenv(env, arr);
  else
    return (0);
  return (1);
}

/*
** brief: main function to find the cmd
** @str: the str with the cmd and options like env -i ls -l
** @env: our env list
** BRIEF: this function will try to find our builtin cmd else it'll use execve
** return: return 0 if it's ok, 1 if chdir and 42 if exit used
*/
int	my_check_fun(char *str, t_list *env)
{
  char	**arr;
  char	res;

  arr = my_str_to_wordtab(str, ' ', '\t');
  if (arr == NULL || arr[0] == NULL)
    return (0);
  if ((res = _my_builtin_fun(arr, env)) != 0)
    {
      if (res != 43)
	my_free_arr(arr);
      return (res - 1);
    }
  else
    (void)my_exec(env, arr, my_find_element(env, "PATH"));
  my_free_arr(arr);
  return (0);
}
