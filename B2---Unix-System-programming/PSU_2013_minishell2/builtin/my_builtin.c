/*
** my_builtin.c for my_builtin in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jun 17 02:26:33 2014 mar_b mar_b
** Last update Tue Jul 29 23:32:50 2014
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "builtin.h"
#include "utils.h"
#include "list.h"
#include "parser.h"

/*
** brief: used to exit our program, we will free too
** @env: our env list
** @arr: our array we will free
*/
char	my_exit(t_list *env, char **arr)
{
  int	nbr;

  nbr = my_get_nbr(arr[1]);
  free_arr(arr);
  free_lst(env);
  exit(nbr);
  return (43);
}

/*
** brief: it will display our pwd (try to find into our env else call charpwd)
** @env: our env
** @arr: useless
** return: 1 everytime
*/
char	my_pwd(t_list *env, char __attribute__((__unused__)) **arr)
{
  char	*pwd;

  if ((pwd = my_find_element(env, "PWD")) == NULL)
    {
      pwd = my_charpwd();
      (void)write(0, pwd, my_strlen(pwd));
      (void)write(0, "\n", 1);
      free(pwd);
    }
  else
    {
      (void)write(0, pwd, my_strlen(pwd));
      (void)write(0, "\n", 1);
    }
  return (1);
}

/*
** brief: used to set a new variable in the env list
** @env: our env list
** @arr: contain the command and values
** (arr[0] = cmd, arr[1] = var, arr[2] = val)
** BRIEF: we will remove our variable (if there is this var in the env),
** then we will add our new element
** return: return 1 everytime
*/
char	my_setenv(t_list *env, char **arr)
{
  if (arr[1] != NULL && arr[2] != NULL)
    {
      my_remove_elt(&env, arr[1]);
      my_add_elt(&env, arr[2], arr[1]);
    }
  else
    (void)my_error("usage: setenv VARIABLE VALUE", "setenv");
  return (1);
}

/*
** brief: used to remove a variable in our list
** @env: our env list
** @arr: contain the command and values
** (arr[0] = cmd, arr[1] = var)
** return: return 1 everytime
*/
char	my_unsetenv(t_list *lst, char **arr)
{
  if (arr[1] != NULL)
    my_remove_elt(&lst, arr[1]);
  else
    (void)my_error("usage: unsetenv VARIABLE", "unsetenv");
  return (1);
}

/*
** brief: call the env function
** @env: our env list
** @arr: contain the command and values
** (arr[0] = cmd, arr[X] = options)
** return: return 1 everytime
*/
char	my_env(t_list *env, char **arr)
{
  my_env_opt(env, arr);
  return (1);
}
