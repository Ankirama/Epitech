/*
** main.c for main in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 16 03:00:10 2014 mar_b mar_b
** Last update Sun Jun 22 19:31:59 2014 mar_b mar_b
*/

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "minishell1.h"
#include "my_error.h"
#include "my_check.h"
#include "my_fun.h"
#include "my_str_to_wordtab.h"
#include "my_set_var.h"
#include "my_pwd.h"
#include "my_list.h"
#include "my_list2.h"
#include "my_str.h"

/*
** brief: this function will init our buffer
** @str: this is our buffer
*/
static void	_my_init(char *str)
{
  int		i;

  i = -1;
  while (++i <= BUFF)
    str[i] = '\0';
}

/*
** brief: This function will display our prompt
** @env: used to find our user and pwd
** @change: if the pwd has changed the change = 1 else 0
*/
static void	_my_prompt(t_list *env, char change)
{
  char		*pwd;
  char		*user;

  user = set_my_var(env, "USER");
  if (change)
    pwd = set_my_pwd(env);
  else
    pwd = set_my_var(env, "PWD");
  if (user != NULL)
    {
      my_write(user, CYAN);
      my_write("@", BLUE);
    }
  my_write(pwd, GREEN);
  (void)write(0, "\n", 1);
  my_write("$>", RED);
}

/*
** brief: this function will print for signal
** @t: unused
*/
static void	_my_print(int t)
{
  (void)t;
  my_write("\n$>", RED);
}

/*
** brief: used to check signal
** return: 0 for the variable ret in main
*/
static char	_my_signal()
{
  if (signal(SIGINT, _my_print) == SIG_ERR)
    my_puterror("error with signal in main.c: l74\n");
  return (0);
}

/*
** brief: main function
** BRIEF: in this function we will read and display our prompt, we will
** check every function too
*/
int		main(int argc, char **argv, char **env)
{
  char		buff[BUFF + 1];
  t_list	*lst;
  int		len;
  int		ret;

  (void)argc;
  (void)argv;
  lst = my_create_list(env);
  my_init_env(lst);
  _my_prompt(lst, 1);
  _my_init(&buff[0]);
  ret = _my_signal();
  while ((len = read(0, buff, BUFF)) > 0)
    {
      if (len == BUFF)
	my_puterror("error: the command is too big!\n");
      buff[len != 0 ? len - 1 : len] = '\0';
      ret = my_check_fun(buff, lst);
      if (ret == 42)
	return (EXIT_SUCCESS);
      _my_prompt(lst, ret);
      (void)_my_signal();
      _my_init(&buff[0]);
    }
  return (len == -1 ? EXIT_FAILURE : EXIT_SUCCESS);
}
