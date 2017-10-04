/*
** my_error.c for my_error in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 16 03:08:09 2014 mar_b mar_b
** Last update Tue Jul 29 23:25:47 2014
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "parser.h"

/*
** brief: if there is any error this function will print a message and exit
** @error: it will display this message
*/
void	my_puterror(const char *error)
{
  (void)write(2, error, my_strlen(error));
  exit(EXIT_FAILURE);
}

/*
** brief: this function will display a message without exit
** @error: the message
** @var: the binary
*/
char	my_error(const char *error, const char *var)
{
  (void)write(2, var, my_strlen(var));
  (void)write(2, ": ", 3);
  (void)write(2, error, my_strlen(error));
  (void)write(2, "\n", 1);
  return (1);
}

/*
** brief: this function will display an error for the env.c
** @env: the problem
** @type: if type == 0 -> write the char * else we will display the char
** env[pos]
** @pos: this position is used to write the error
** return: just return -1
*/
char	my_env_error(char *env, char type, int pos)
{
  if (type == 0)
    {
      (void)write(2, "env: invalid option --'", 23);
      (void)write(2, env, my_strlen(env));
      (void)write(2, "'", 1);
    }
  else if (type == 1)
    {
      (void)write(2, "env: invalid option --'", 23);
      (void)write(2, &env[pos], 1);
      (void)write(2, "'", 1);
    }
  else if (type == 2)
    (void)write(2, "env: option requires an argument -- 'u'\n", 40);
  else
    (void)write(2, "env: cannot unset '': Invalid argument\n", 39);
  if (type != 3)
    (void)write(2, "\nTry 'env --help' for more information.\n", 41);
  return (-1);
}

/*
** brief: the command-not-found by bash
** @cmd: the command like toto etc...
** return: -1 everytime
*/
void	my_cnf(char *cmd, char **env)
{
  (void)write(2, "If '", 4);
  (void)write(2, cmd, my_strlen(cmd));
  (void)write(2, "' is not a typo you can use command-not-found to lookup", 55);
  (void)write(2, " the package that contains it, like this:\n\tcnf ", 47);
  (void)write(2, cmd, my_strlen(cmd));
  (void)write(2, "\n", 1);
  free_arr(env);
}

/*
** brief: it will try if quote = 0, else we will free it
** @str: our message
** @quote: count our "
** @lst: our parser list
** return: return NULL if problem, else our lst
*/
t_parser	*my_parserror(char *str, char quote, t_parser *lst)
{
  if (quote)
    {
      (void)write(2, str, my_strlen(str));
      free_parser(lst);
      return (NULL);
    }
  return (lst);
}
