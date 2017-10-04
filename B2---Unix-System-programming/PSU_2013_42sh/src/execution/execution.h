/*
** execution.h for execution in /home/mar_b/rendu/PSU_2013_42sh/src/execution
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  2 16:39:51 2014 mar_b mar_b
** Last update Thu Oct  2 23:29:58 2014 mar_b mar_b
*/

#ifndef EXECUTION_H_
# define EXECUTION_H_

# include "lexer.h"
# include "list.h"

typedef struct	s_ope
{
  int	(**ope)(t_ast *left, char **arr, t_list *env, char trunc);
  char	trunc;
}		t_ope;

/*
** EXECUTION_C_
*/
char	my_exec_ast(t_ast *ast, t_list *env, t_ope *ope);
void	execution(t_ast *ast, t_list *env);

/*
** FUN_C_
*/
t_ast	*go_right(t_ast *ast);

#endif /* !EXECUTION_H_ */
