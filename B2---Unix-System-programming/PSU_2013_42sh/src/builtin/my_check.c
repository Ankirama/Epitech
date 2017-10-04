/*
** my_check.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src/builtin
** 
** Made by mar_b mar_b
** Login   <teyssa_r@epitech.net>
** 
** Started on  Fri Oct  3 00:03:37 2014 teyssa_r teyssa_r
** Last update Fri Oct  3 00:04:09 2014 teyssa_r teyssa_r
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell2.h"
#include "builtin.h"
#include "utils.h"
#include "list.h"
#include "parser.h"

char	*my_path(char *path)
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
  char	(*tab[6])(t_list *, char **);
  char	**fun;
  int	i;

  if ((fun = malloc(sizeof(char *) * 6)) == NULL)
    my_puterror("error: problem to malloc in my_check.c!\n");
  fun[0] = "exit";
  fun[1] = "env";
  fun[2] = "cd";
  fun[3] = "setenv";
  fun[4] = "unsetenv";
  fun[5] = "echo";
  tab[0] = my_exit;
  tab[1] = my_env;
  tab[2] = my_cd;
  tab[3] = my_setenv;
  tab[4] = my_unsetenv;
  tab[5] = my_echo;
  i = -1;
  while (++i < 6 && !my_strcmp(arr[0], fun[i], 0));
  free(fun);
   if (i == 6)
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
  int	nbr;

  nbr = my_builtin_fun(arr, env);
  if (arr == NULL || arr[0] == NULL)
    return (0);
  if (nbr >= 0)
    return (nbr);
  else
    (void)my_exec(env, arr, my_path(my_find_element(env, "PATH")));
  return (0);
}
