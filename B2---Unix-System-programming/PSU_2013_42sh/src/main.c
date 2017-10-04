/*
** main.c for  in /home/teyssa_r/rendu/PSU_2013_42sh
**
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
**
** Started on  Mon Sep  1 18:12:27 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 23:36:58 2014 mar_b mar_b
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <term.h>
#include "utils.h"
#include "mini.h"
#include "list.h"
#include "lexer.h"
#include "parser.h"

int		main(int __attribute__((__unused__)) argc,
		     char __attribute__((__unused__)) **argv, char **env)
{
  int		len;
  char		buff[BUFF + 1];
  t_list	*lst_env;

  if ((lst_env = my_create_list(env)) == NULL)
    return (EXIT_FAILURE);
  my_init(&buff[0], BUFF);
  if (my_signal(lst_env) == -1)
    return (EXIT_FAILURE);
  (void)write(1, CLR_SHELL, my_strlen(CLR_SHELL));
  while ((len = read(0, buff, BUFF)) > 0)
    {
      buff[len - 1] = '\0';
      (void)my_parser(my_lexer(buff));
      my_init(&buff[0], BUFF);
      (void)write(1, CLR_SHELL, my_strlen(CLR_SHELL));
      if (my_signal(lst_env) == -1)
	return (EXIT_FAILURE);
    }
  if (len == ID_EOF)
    free_eof(lst_env);
  return (EXIT_SUCCESS);
}
