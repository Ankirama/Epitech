/*
** lexer.c for lexer in /home/mar_b/rendu/PSU_2013_42sh/src/parser/binary_tree
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Sep 19 16:30:45 2014 mar_b mar_b
** Last update Thu Oct  2 21:51:41 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "utils.h"

static char	_error_ast(char *ope)
{
  (void)write(2, ERR_AST, my_strlen(ERR_AST));
  (void)write(2, ope, my_strlen(ope));
  (void)write(2, "'", 1);
  (void)write(2, "\n", 1);
  return (-1);
}

static char	_check_ast(t_ast *ast)
{
  if (ast != NULL)
    {
      if (ast->array != NULL && my_strlen(ast->array[0]) == 0)
	return (1);
      else
	{
	  if (ast->right == NULL && IS_NOT_WAIT(ast->oper))
	    return (_error_ast(ast->array[0]));
	  if (_check_ast(ast->left) == 1)
	    return (_error_ast(ast->array[0]));
	  if (_check_ast(ast->right) == 1)
	    return (_error_ast(ast->array[0]));
	}
    }
  return (0);
}

t_ast	*my_parser(t_ast *ast)
{
  t_ast	*tmp;

  if (ast == NULL)
    return (NULL);
  tmp = ast;
  if (_check_ast(tmp))
    {
      free_ast(ast);
      return (NULL);
    }
  else
    return (ast);
}
