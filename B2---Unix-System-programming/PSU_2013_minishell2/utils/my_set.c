/*
** my_set.c for my_set in /home/mar_b/minishell
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jun 26 12:12:20 2014 mar_b mar_b
** Last update Thu Jun 26 16:50:58 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "list.h"
#include "builtin.h"
#include "minishell2.h"

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

/*
** brief: it will set (into our env) the pwd variable
** @env: our env list
** return: return the pwd
*/
char	*set_my_pwd(t_list *env)
{
  char	*pwd;

  pwd = my_charpwd();
  my_remove_elt(&env, "PWD");
  my_add_elt(&env, pwd, "PWD");
  return (pwd);
}

/*
** brief: it will define our PATH and _ if they doesnt exist
** @env: our env list
*/
void	my_init_env(t_list *env)
{
  char	*path;
  char	*_env;

  if ((_env = my_find_element(env, "_")) == NULL)
    {
      my_remove_elt(&env, "_");
      my_add_elt(&env, ENV, "_");
    }
  path = set_my_var(env, "PATH");
  if (path == NULL)
    {
      my_remove_elt(&env, "PATH");
      my_add_elt(&env, PATH, "PATH");
      path = PATH;
    }
}
