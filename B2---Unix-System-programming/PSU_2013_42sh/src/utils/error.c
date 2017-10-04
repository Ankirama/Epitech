/*
** error.c for error in /home/mar_b/rendu/MUL_2013_rtv1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Jul 11 18:13:39 2014 mar_b mar_b
** Last update Thu Oct  2 16:12:03 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

/*
** brief: if there is any error this function will print a message and exit
** @error: it will display this message
** return: return -1
*/
char	my_puterror(char *error)
{
  (void)write(2, error, my_strlen(error));
  return (-1);
}

void	*my_puterror_tc(char *error, char *error2)
{
 (void)write(2, error, my_strlen(error));
 (void)write(2, error2, my_strlen(error2));
 return (NULL);
}

void	*my_puterror_null(char *error)
{
 (void)write(2, error, my_strlen(error));
 return (NULL);
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
