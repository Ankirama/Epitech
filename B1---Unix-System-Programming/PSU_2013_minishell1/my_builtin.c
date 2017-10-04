/*
** my_builtin.c for my_builtin in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jun 17 02:26:33 2014 mar_b mar_b
** Last update Sun Jun 22 19:36:29 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_env.h"
#include "my_error.h"
#include "my_str.h"
#include "my_list.h"
#include "my_list2.h"
#include "my_str_to_wordtab.h"
#include "my_free.h"

/*
** brief: used to exit our program, we will free too
** @env: our env list
** @arr: our array we will free
*/
char	my_exit(t_list *env, char **arr)
{
  my_free_arr(arr);
  my_free_lst(env);
  return (43);
}

/*
** brief: this function will change directory, it will check if the dir exist
** @arr: this arr contains our command (arr[0] = cd) and our directory (arr[1])
** return: if chdir is ok then we return 1 to change our PWD variable
*/
int	my_cd(const char **arr)
{
  if (arr[1] != NULL)
    {
      if (access(arr[1], F_OK) == -1)
	{
	  my_error("no such file or directory: ", "cd");
	  (void)write(2, arr[1], my_strlen(arr[1]));
	  (void)write(2, "\n", 1);
	  return (0);
	}
      if (access(arr[1], R_OK) == -1)
	{
	  my_error("permission denied: ", "cd");
	  (void)write(2, arr[1], my_strlen(arr[1]));
	  (void)write(2, "\n", 1);
	  return (0);
	}
      if (chdir(arr[1]) == -1)
	{
	  my_error("you cannot access to this directory\n", "cd");
	  return (0);
	}
      return (1);
    }
  my_error("usage: cd directory\n", "cd");
  return (0);
}

/*
** brief: used to set a new variable in the env list
** @env: our env list
** @arr: contain the command and values
** (arr[0] = cmd, arr[1] = var, arr[2] = val)
*/
void	my_setenv(t_list *env, char **arr)
{
  if (arr[1] != NULL && arr[2] != NULL)
    my_setenv_lst(env, arr[1], arr[2]);
  else
    my_error("usage: setenv VARIABLE VALUE\n", "setenv");
}

/*
** brief: used to remove a variable in our list
** @env: our env list
** @arr: contain the command and values
** (arr[0] = cmd, arr[1] = var)
*/
void	my_unsetenv(t_list *lst, char **arr)
{
  if (arr[1] != NULL)
    my_remove_elt(&lst, arr[1]);
  else
    my_error("usage: unsetenv VARIABLE\n", "unsetenv");
}

/*
** brief: call the env function
** @env: our env list
** @arr: contain the command and values
** (arr[0] = cmd, arr[X] = options)
*/
void	my_env(t_list *env, char **options)
{
  my_env_opt(env, options);
}
