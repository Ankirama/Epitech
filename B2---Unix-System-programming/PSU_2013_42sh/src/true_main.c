/*
** new_main.c for  in /home/teyssa_r/rendu/PSU_2013_42sh/src
**
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
**
** Started on  Thu Oct  2 15:41:56 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 22:41:54 2014 charles viterbo
*/

#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <term.h>
#include "utils.h"
#include "bonus.h"
#include "mini.h"
#include "list.h"
#include "lexer.h"
#include "parser.h"

static char	*_set_parameter_term(struct termios terminal)
{
  if (tcgetattr(0, &terminal) == -1)
    return (my_puterror_tc(ERR_TCGETATTR, ERR_TC));
  terminal.c_lflag |= (ICANON | ECHO);
  if (tcsetattr(0, 0, &terminal) == -1)
    return (my_puterror_tc(ERR_TCSETATTR, ERR_TC));
  return ("\0");
}

static char	*_read_caps(int *len, t_hst *hst)
{
  (void)write(1, CLR_SHELL, my_strlen(CLR_SHELL));
  return (bonus(hst, len));
}

static char	_read(char *buff, int *len, t_list *lst_env,
		      struct termios terminal)
{
  _set_parameter_term(terminal);
  if ((*len) > 0)
    while (((*len) = read(0, buff, BUFF)) > 0)
      {
	buff[(*len) - 1] = '\0';
	(void)my_parser(my_lexer(buff));
	my_init(&buff[0], BUFF);
	(void)write(1, CLR_SHELL, my_strlen(CLR_SHELL));
	if (my_signal(lst_env) == -1)
	  return (EXIT_FAILURE);
      }
  else
    (void)write(1, "exit\n", 5);
  return (0);
}

int			main(int __attribute__((__unused__)) argc,
			     char __attribute__((__unused__)) **argv,
			     char **env)
{
  int			len;
  char			*str;
  char			buff[BUFF + 1];
  t_hst			*hst;
  t_list		*lst_env;
  struct termios	terminal;

  str = "\0";
  len = 1;
  if ((lst_env = my_create_list(env)) == NULL)
    return (EXIT_FAILURE);
  if (my_signal(lst_env) == -1)
    return (EXIT_FAILURE);
  hst = make_hst();
  my_init(&buff[0], BUFF);
  while (hst != NULL && _set_parameter_term(terminal) != NULL
	 && (str = _read_caps(&len, hst)) != NULL)
    (void)my_parser(my_lexer(str));
  if (str == NULL)
    return (_read(buff, &len, lst_env, terminal));
  if (len == ID_EOF && str == NULL)
    free_eof(lst_env);
  return (EXIT_SUCCESS);
}
