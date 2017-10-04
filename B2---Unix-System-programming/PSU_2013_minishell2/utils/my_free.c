/*
** my_free.c for my_free in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun Jun 22 02:00:54 2014 mar_b mar_b
** Last update Mon Jul 21 04:28:47 2014
*/

#include <stdlib.h>
#include "list.h"
#include "parser.h"

/*
** it will free our arr[][]
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
** It will free our list
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
** brief: it will free our parser struct
*/
void		free_parser(t_parser *lst)
{
  t_parser	*tmp;

  while (lst != NULL)
    {
      tmp = lst;
      lst = lst->next;
      free_arr(tmp->array);
      free(tmp);
    }
}
