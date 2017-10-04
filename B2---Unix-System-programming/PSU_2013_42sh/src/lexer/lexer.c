/*
** lexer.c for lexer in /home/mar_b/rendu/PSU_2013_42sh/src/parser/binary_tree
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Sep 19 16:30:45 2014 mar_b mar_b
** Last update Thu Oct  2 22:51:04 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "lexer.h"
#include "utils.h"

static char	*g_opt[NBR_OPT] =
  {">>&", ">>", ">&", ">", "<<", "<", "|", ";"};

static int	_remove_space(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
    ++i;
  return (i);
}

/*
** brief: normal operator like ; | & etc
** @ast: our binary tree
** @str: our current command
** @end: end of str
** @j: the operator id
** return: return 1 if operator is ; else 0
*/
static char	_normal(t_ast **ast, char *str, int end, int j)
{
  *ast = add_command(*ast, str, NULL, end);
  *ast = (j == ID_WAIT) ? add_wait_opera(*ast) :
    add_operator(*ast, g_opt[j], j);
  if (*ast == NULL)
    return (-1);
  else
    return (0);
}

static int	_inv_mode(t_ast **ast, char *str, int end, int *j)
{
  char		**arr;
  int		i;
  int		k;
  int		deb;

  arr = my_str_to_wordtab(str, end, 0, -1);
  if (arr != NULL && arr[0] == NULL)
    {
      deb = _remove_space(str) + my_strlen(g_opt[*j]);
      i = deb;
      while (str[i] != '\0' && (k = check_opt(&str[i], g_opt)) >= NBR_OPT)
	++i;
      if ((arr = my_str_to_wordtab(&str[deb], i - deb, 0, -1)) == NULL)
	return (-1);
      *ast = add_command(*ast, NULL, arr[0] == NULL ? NULL : &arr[1], 1);
      *ast = add_operator(*ast, g_opt[*j], *j);
      *ast = add_command(*ast, arr[0], NULL, my_strlen(arr[0]));
      *ast = (k == ID_WAIT) ? add_wait_opera(*ast) :
	add_operator(*ast, g_opt[k >= NBR_OPT ? 0 : k], k >= NBR_OPT ? -1 : k);
      *j = k;
      free_arr(arr);
    }
  else if (arr != NULL)
    return (_normal(ast, str, end, *j) == -1 ? -1 : my_strlen(g_opt[*j]) - 1);
  return (arr == NULL || *ast == NULL ? -1 : i);
}

static t_ast	*_my_travel_str(char *str, t_ast *ast, char ope, int i)
{
  int		deb;
  int		j;
  int		tmp;

  deb = 0;
  while (str[++i] != '\0')
    {
      if ((j = check_opt(&str[i], g_opt)) < NBR_OPT)
	{
	  tmp = my_strlen(g_opt[j]) - 1;
	  if ((!IS_FLUX(j) || !ope) &&
	      _normal(&ast, &str[deb], i - deb, j) == -1)
	    return (NULL);
	  else if (ope && IS_FLUX(j) &&
		   (tmp = _inv_mode(&ast, &str[deb], i - deb, &j)) == -1)
	    return (NULL);
	  i += tmp;
	  ope = (j == ID_WAIT) ? 1 : 0;
	  deb = i + 1;
	}
    }
  if (i - deb > 0)
    ast = add_command(ast, &str[deb], NULL, i - deb);
  return (ast);
}

t_ast	*my_lexer(char *str)
{
  t_ast	*ast;
  t_ast	*tmp;

  ast = NULL;
  ast = _my_travel_str(str, ast, 1, -1);
  tmp = ast;
  travel_ast(tmp);
  return (ast);
}
