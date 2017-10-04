/*
** fun.c<2> for fun in /home/mar_b/rendu/PSU_2013_42sh
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Oct  2 21:15:12 2014 mar_b mar_b
** Last update Thu Oct  2 22:33:22 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "lexer.h"

t_ast	*go_right(t_ast *ast)
{
  t_ast	*tmp;
  t_ast	*prev;

  tmp = ast;
  prev = ast;
  while (tmp != NULL && tmp->right != NULL)
    {
      prev = tmp;
      tmp = tmp->right;
    }
  return (prev);
}
