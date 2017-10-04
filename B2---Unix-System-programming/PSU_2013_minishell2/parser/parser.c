/*
** my_parser.c for my_parser in /home/mar_b/minishell/parser
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Mon Jun 23 16:34:32 2014 mar_b mar_b
** Last update Sun Aug  3 19:57:48 2014 mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "utils.h"
#include "list.h"
#include "minishell2.h"

/*
** brief: it will call our main fun to find the cmd
** @parser: our parser struct
** @env: our env list
** return: return our function
*/
static char	_check_fun(t_parser **par, t_list *env)
{
  return (my_check_fun((*par)->array, env));
}

static void	_call_fun(t_parser **par, t_list *env)
{
  char		(*fun[NBR_OPT + 1])(t_parser **par, t_list *env);

  fun[ID_ADD_FERR] = &dup_stdout_err;
  fun[ID_ADD_FOUT] = &dup_stdout;
  fun[ID_FLUX_ERR] = &dup_stdout_err;
  fun[ID_FLUX_OUT] = &dup_stdout;
  fun[ID_ADD_FIN] = &dup_stdin_sim;
  fun[ID_FLUX_IN] = &dup_stdin_sim; //a changer
  fun[ID_PIPE] = &pipe_cmd; // a changer
  fun[ID_WAIT] = &_check_fun;
  fun[NBR_OPT] = &_check_fun;
  (void)fun[(*par)->option](par, env);
}

static void	_travel_parser(t_parser *lst, t_list *env)
{
  t_parser	*tmp;

  tmp = lst;
  while (tmp != NULL)
    {
      _call_fun(&tmp, env);
      if (tmp != NULL)
	tmp = tmp->next;
    }
}

void		my_parser(char *str, t_list *env)
{
  t_parser	*lst;

  lst = my_pre_parser(str);
  if (lst == NULL)
    {
      free_lst(env);
      exit(EXIT_FAILURE);
    }
  _travel_parser(lst, env);
  free_parser(lst);
}
