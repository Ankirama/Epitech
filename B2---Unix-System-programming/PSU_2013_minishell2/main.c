/*
** main.c for main in /home/mar_b/minishell
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jun 24 08:59:27 2014 mar_b mar_b
** Last update Sun Aug  3 14:30:16 2014 mar_b
** Last update Mon Jul 21 02:16:15 2014
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "minishell2.h"
#include "utils.h"
#include "list.h"
#include "parser.h"

/*
** brief: This function will display our (simple) prompt
*/
static void	_my_prompt()
{
  my_write("$>", RED);
}

/*
** brief: it will write a \n and the promp
*/
static	void	_my_write_sig()
{
  (void)write(0, "\n", 1);
  _my_prompt();
}

/*
** brief: we will check our Ctrl-C, if any pb then we'll free and put AND ERROR!
** @env: could be free
*/
static void	_my_signal(t_list *env)
{
  if (signal(SIGINT, _my_write_sig) == SIG_ERR)
    {
      free_lst(env);
      my_puterror("error: problem with signal SIGINT in main.c\n");
    }
}

static void	_free_EOF(t_list *env)
{
  free_lst(env);
  (void)write(0, "exit\n", 6);
}

int		main(int __attribute__((__unused__)) argc,
		     char __attribute__((__unused__)) **argv, char **env)
{
  char		buff[BUFF + 1];
  t_list	*lst_env;
  int		len;

  lst_env = my_create_list(env);
  my_init(&buff[0]);
  _my_prompt();
  _my_signal(lst_env);
  while ((len = read(0, buff, BUFF)) > 0)
    {
      if (len == BUFF)
	my_puterror("error: command too big!\n");
      buff[len - 1] = '\0';
      my_parser(buff, lst_env);
      my_init(&buff[0]);
      _my_prompt();
      _my_signal(lst_env);
    }
  if (len == ID_EOF)
    _free_EOF(lst_env);
  return (0);
}
