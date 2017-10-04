/*
** my_env.c for 42sh in /home/zighed_a/rendu/PSU_2013_42sh/src/builtin
** 
** Made by zighed_a zighed_a
** Login   <zighed_a@epitech.net>
** 
** Started on  Wed Sep 17 12:59:47 2014 zighed_a zighed_a
** Last update Wed Sep 17 12:59:49 2014 zighed_a zighed_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "builtin.h"
#include "list.h"
#include "minishell2.h"

/*
** brief: this function will display the help
** @type: if type == 0 we will display the help, else the version
** return: return -1 for error
*/
static int	_disp(char type)
{
  if (type == 0)
    {
      my_w("Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]\n");
      my_w("Set each NAME to VALUE in the environment and run COMMAND.\n");
      my_w("\nMandatory arguments to long options are mandatory for ");
      my_w("short options too.\n");
      my_w("  -i, --ignore-environment  start with an empty environment\n");
      my_w("  -0, --null           end each output line with 0 byte rather ");
      my_w("than newline\n");
      my_w("  -u, --unset=NAME     remove variable from the environment\n");
      my_w("      --help     display this help and exit\n");
      my_w("      --version  output version information and exit\n");
      my_w("\nA mere - implies -i.  If no COMMAND, print the resulting ");
      my_w("environment.\n\nReport env bugs to bug-coreutils@gnu.org\nGNU ");
      my_w("coreutils home page: <http://www.gnu.org/software/coreutils/>\n");
      my_w("General help using GNU software: <http://www.gnu.org/gethelp/>\nF");
      my_w("or complete documentation, run: info coreutils 'env invocation'\n");
      return (1);
    }
  my_w("env (GNU coreutils) 8.21\nLicense GPLv3+: GNU GPL version 3 or later");
  my_w(" <http://gnu.org/licenses/gpl.html>.\nThis is free software: ");
  my_w("you are free to change and redistribute it.\n");
  my_w("There is NO WARRANTY, to the extent permitted by law.\n\n");
  my_w("Written by Richard Mlynarik and David MacKenzie.\n");
  return (-1);
}

/*
** brief: check option with only 1 -
** @opt: our char[] with 0 or 1
** @str: we will try to find our options in this char *
** return: return 0 if it's ok or -1 if there is a pb
*/
static char	_my_little_opt(char *opt, char *str)
{
  char		little[3];
  int		i;
  int		j;

  opt[ID_UN] = 0;
  little[ID_IGNORE] = 'i';
  little[ID_NULL] = '0';
  little[ID_UN] = 'u';
  i = 0;
  while (str[++i] != '\0')
    {
      j = -1;
      while (++j < 3 && little[j] != str[i]);
      if (j == 3)
	return (my_env_error(str, 1, i));
      else
	opt[j] = 1;
    }
  return (0);
}

/*
** brief: check big option with 2 - (like --null)
** @opt: our char[] with 0 or 1
** @str: we will try to find our options in this char *
** return: return 0 if it's ok or -1 if there is a pb
*/
static char	_my_big_opt(char *opt, char *str)
{
  int		i;
  char		**big;

  if ((big = malloc(sizeof(char *) * 5)) == NULL)
    my_puterror("error: problem to malloc in my_env.c: l92\n");
  opt[ID_UN] = 0;
  big[ID_IGNORE] = "ignore-environment";
  big[ID_NULL] = "null";
  big[ID_UN] = "unset";
  big[ID_HELP] = "help";
  big[ID_VER] = "version";
  i = -1;
  while (++i < 5)
    {
      if ((i != 2 && my_strcmp(str, big[i], 0)) ||
	  (i == 2 && my_strcmp(str, big[i], 1)))
	{
	  opt[i] = 1;
	  i = 5;
	}
    }
  free(big);
  if (i == 5)
    return (my_env_error(str, 0, 0));
  return (0);
}

/*
** brief: will try to find our options and set it
** @env: our env list
** @var: our arguments (like -l --null -0u test...)
** @opt: or char * we will set
** @ret: used to stop the loop if there is a pb
** BRIEF: if pb return -1, if -u without other arg then error like -unset=
** return: the good position for the next cmd or 0 if no cmd or -1 if error
*/
static char	_my_check_opt_env(t_list *env, char **var, char *opt,
				  char ret)
{
  int		i;

  i = -1;
  while (ret == 0 && ++i >= 0 && var[i] != NULL)
    {
      if (var[i][0] == '-' && var[i][1] != '-' && var[i][1] != '\0')
	{
	  ret = _my_little_opt(&opt[0], var[i]);
	  if (opt[ID_UN] && ret == 0 && var[++i] != NULL)
	    my_remove_elt(&env, var[i++]);
	  else if (opt[ID_UN] && ret == 0 && var[i] == NULL)
	    return (my_env_error(NULL, 2, 0));
	}
      else if (var[i][0] == '-' && var[i][1] == '-' && var[i][2] != '\0')
	{
	  ret = _my_big_opt(&opt[0], &var[i][2]);
	  if (opt[ID_UN] && ret == 0 && UNSET(var[i][8]) && UNSET(var[i][9]))
	    my_remove_elt(&env, &var[i][my_strlen("--unset=")]);
	  else if (opt[ID_UN] && ret == 0)
	    return (my_env_error(NULL, 3, 0));
	}
      if (opt[ID_HELP] || opt[ID_VER] || (var[i] != NULL && var[i][0] != '-'))
	return ((var[i][0] != '-') ? ++i: _disp((opt[ID_HELP] == 1) ? 0 : 1));
    }
  return (ret);
}

/*
** brief: main function for env, call my_exec if cmd found or display etc..
** @env: our list env
** @var: our argument
*/
void	my_env_opt(t_list *env, char **arr)
{
  char	opt[5];
  int	i;
  int	out;

  i = -1;
  while (++i < 5)
    opt[i] = 0;
  out = _my_check_opt_env(env, &arr[1], &opt[0], 0);
  if (out > 0)
    my_check_fun(&arr[out], (opt[ID_IGNORE] == 1) ? NULL : env);
  else if (out != -1 && !opt[ID_IGNORE])
    my_display_lst(env, opt[ID_NULL]);
}
