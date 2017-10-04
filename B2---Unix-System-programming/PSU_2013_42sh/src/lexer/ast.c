/*
** ast.c for ast in /home/mar_b/rendu/PSU_2013_42sh/src/parser/binary_tree
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Fri Sep 19 15:58:13 2014 mar_b mar_b
** Last update Thu Oct  2 21:01:09 2014 mar_b mar_b
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "lexer.h"

/*
** AST = Abstract Syntax Tree
*/

/*
** brief : it will create a node and return it
** @array: our array
** @left: the left tree
** @right: the right tree
** @oper: our operator id like ID_ADD_FERR etc... -1 if no oper
** return: return the new node
*/
t_ast	*create_element_ast(char **array, char oper)
{
  t_ast	*elt;
  int	i;

  if ((elt = malloc(sizeof(*elt))) == NULL)
    return (my_puterror_null(ERR_MALLOC));
  if (!(elt->array = malloc(sizeof(char *) * (my_arrlen(array) + 1))))
    return (my_puterror_null(ERR_MALLOC));
  i = -1;
  while (array[++i] != NULL)
    elt->array[i] = my_strdup(array[i]);
  elt->array[i] = NULL;
  elt->oper = oper;
  elt->left = NULL;
  elt->right = NULL;
  return (elt);
}

/*
** brief: used if the operator is ; -> travel while the intern node is ;
** @ast: the ast
** return: the entire tree
*/
t_ast	*add_wait_opera(t_ast *ast)
{
  t_ast	*tmp;
  t_ast	*prev;
  t_ast	*node;
  char	**arr;

  tmp = ast;
  prev = ast;
  if ((arr = my_str_to_wordtab(";", 1, 0, -1)) == NULL)
    return (NULL);
  while (tmp != NULL && tmp->oper == ID_WAIT)
    {
      prev = tmp;
      tmp = tmp->right;
    }
  if ((node = create_element_ast(arr, ID_WAIT)) == NULL)
    return (NULL);
  free_arr(arr);
  node->left = tmp;
  if (tmp == prev)
    ast = node;
  else
    prev->right = node;
  return (ast);
}

/*
** brief: it will add other operator like | ...
** we will add the new elt in the right son while the intern node is
** an operator
** @ast: our binary tree
** @oper: the operator like "|"
** @id_ope: the operator id like ID_PIPE
** return: return the new ast
*/
t_ast	*add_operator(t_ast *ast, char *oper, char id_ope)
{
  t_ast	*tmp;
  t_ast	*prev;
  t_ast	*node;
  char	**arr;

  if (id_ope == -1)
    return (ast);
  tmp = ast;
  prev = ast;
  if ((arr = my_str_to_wordtab(oper, my_strlen(oper), 0, -1)) == NULL)
    return (NULL);
  while (tmp != NULL && tmp->oper != -1)
    {
      prev = tmp;
      tmp = tmp->right;
    }
  if ((node = create_element_ast(arr, id_ope)) == NULL)
    return (NULL);
  free_arr(arr);
  node->left = tmp;
  if (tmp == prev)
    ast = node;
  else
    prev->right = node;
  return (ast);
}

/*
** brief: it will add our command in our ast
** to add it, we will travel our ast while we've a command
** after it, if the left son is empty we will add our command here,
** else we'll add in the right son
** @ast: the binary tree struct
** @cmd : the char * with the cmd
** end: then end string to stop the str_to_wordtab magueule
** return: return the new AST
*/
t_ast	*add_command(t_ast *ast, char *cmd, char **array, int end)
{
  t_ast	*tmp;
  t_ast	*prev;
  t_ast	*node;
  char	**arr;

  tmp = ast;
  prev = ast;
  arr = (cmd != NULL || array == NULL) ?
    (my_str_to_wordtab(cmd == NULL ? "" : cmd, cmd == NULL ? 1 : end, 0, -1))
    : NULL;
  while (tmp != NULL && tmp->oper != -1)
    {
      prev = tmp;
      tmp = tmp->right;
    }
  if (!(node = create_element_ast(arr == 0 ? array : arr, -1)))
    return (NULL);
  free_arr(arr);
  if (tmp == prev)
    ast = node;
  else if (prev->left == NULL)
    prev->left = node;
  else
    prev->right = node;
  return (ast);
}

void	remove_right(t_ast **ast)
{
  t_ast	*tmp;
  t_ast	*prev;

  tmp = *ast;
  prev = tmp;
  while (tmp != NULL && tmp->right != NULL && tmp->right->oper != -1)
    {
      prev = tmp;
      tmp = tmp->right;
    }
  if (tmp == prev && tmp != NULL)
    {
      free_ast(tmp->right);
      *ast = (*ast)->left;
    }
  else if (tmp != NULL)
    {
      prev->right = tmp->left;
      free_ast(tmp->right);
    }
}
