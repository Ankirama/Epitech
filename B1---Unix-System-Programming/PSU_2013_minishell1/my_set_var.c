/*
** my_set_var.c for set_var in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 16 19:00:24 2014 mar_b mar_b
** Last update Sun Jun 22 06:38:33 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "minishell1.h"
#include "my_fun.h"
#include "my_str.h"
#include "my_error.h"
#include "my_list.h"
#include "my_pwd.h"
#include "my_list2.h"

/*
** brief: will set each env variable
** @env: env variables
** @code: we will try to find this code variable like PATH, PWD...
** return: we will return the variable
*/
char	*set_my_var(t_list *env, char *code)
{
  char	*var;

  var = my_find_element(env, code);
  return (var);
}

char	*set_my_pwd(t_list *env)
{
  char	*pwd;

  pwd = my_pwd();
  my_setenv_lst(env, "PWD", pwd);
  return (pwd);
}

void	my_init_env(t_list *lst)
{
  char	*path;

  my_setenv_lst(lst, "_", ENV);
  path = set_my_var(lst, "PATH");
  if (path == NULL)
    {
      my_setenv_lst(lst, "PATH", PATH);
      path = PATH;
    }
}
