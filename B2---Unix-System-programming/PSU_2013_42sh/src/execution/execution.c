/*
** execution.c for execution in /home/mar_b/rendu/PSU_2013_42sh/src/execution
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  2 16:40:20 2014 mar_b mar_b
** Last update Thu Oct  2 23:36:05 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "lexer.h"
#include "list.h"
#include "utils.h"
#include "execution.h"

static t_ope	*my_ope_lst(int (**ope)(t_ast *left, char **arr,
						t_list *env, char trunc),
			    char trunc)
{
  t_ope		*lst;

  if ((lst = malloc(sizeof(*lst))) == NULL)
    my_puterror_null(ERR_MALLOC);
  lst->ope = ope;
  lst->trunc = trunc;
  return (lst);
}

char	my_exec_ast(t_ast *ast, t_list *env, t_ope *ope)
{
  t_ast	*tmp;
  char	**arr;
  int	id_ope;

  tmp = go_right(ast);
  if (tmp != NULL)
    {
      if (tmp->right != NULL)
	{
	  arr = dup_array(tmp->right->array);
	  id_ope = tmp->oper;
	  ope->trunc = IS_TRUNC(tmp->oper);
	  remove_right(&ast);
	  if (ope->ope[id_ope](tmp, arr, env, ope) == -1)
	    return (-1);
	  else
	    free_arr(arr);
	}
      else
	(void)tmp;
    }
}

char	execution(t_ast *ast, t_list *env)
{
  t_ast	*tmp;
  t_ope	*lst_ope;
  int	(**ope)(t_ast *left, char **arr, t_list *env, t_ope *op);

  if ((ope = malloc(sizeof(*ope) * NBR_OPT)) == NULL)
    return (my_puterror(ERR_MALLOC));
  ope[ID_ADD_FERR] = dup_stdout_err;
  ope[ID_ADD_FOUT] = dup_stdout;
  ope[ID_FLUX_ERR] = dup_stdout_err;
  ope[ID_FLUX_OUT] = dup_stdout;
  ope[ID_ADD_FIN] = dup_stdin_doub;
  ope[ID_FLUX_IN] = dup_stdout_sim;
  ope[ID_PIPE] = pipe_cmd;
  ope[ID_WAIT] = NULL;
  tmp = ast;
  lst_ope = my_ope_lst(ope, 0);
  while (tmp != NULL && tmp->oper == ID_WAIT)
    {
      my_exec_ast(tmp->left, env);
      tmp = tmp->right;
    }
  if (tmp != NULL)
    my_exec_ast(tmp, env, ope);
  return (0);
}
