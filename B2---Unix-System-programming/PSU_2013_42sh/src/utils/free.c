/*
** my_free.c for my_free in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun Jun 22 02:00:54 2014 mar_b mar_b
** Last update Thu Oct  2 16:31:17 2014 mar_b mar_b
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "list.h"
#include "lexer.h"

/*
** brief: it will free our arr[][]
** @arr: our array
*/
void	free_arr(char **arr)
{
  int	i;

  i = -1;
  if (arr != NULL)
    {
      while (arr[++i] != NULL)
	free(arr[i]);
      free(arr);
    }
}

/*
** brief: it will free our list
** @list: our struct's list
*/
void		free_lst(t_list *list)
{
  t_list	*tmp;
  t_list	*next;

  if (list != NULL)
    {
      tmp = list->next;
      while (tmp != list)
	{
	  next = tmp->next;
	  free(tmp->data);
	  free(tmp);
	  tmp = next;
	}
      free(list);
    }
}

/*
** brief: it will free our binary tree
*/
void	free_ast(t_ast *ast)
{
  if (ast != NULL)
    {
      free_ast(ast->left);
      free_ast(ast->right);
      free_arr(ast->array);
      free(ast);
    }
}

void	free_eof(t_list *env)
{
  free_lst(env);
  (void)write(1, "exit\n", my_strlen("exit\n"));
}
