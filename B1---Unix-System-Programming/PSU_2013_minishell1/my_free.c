/*
** my_free.c for my_free in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun Jun 22 02:00:54 2014 mar_b mar_b
** Last update Sun Jun 22 19:48:38 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_list.h"

/*
** it will free our arr[][]
*/
void	my_free_arr(char **arr)
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
void		my_free_lst(t_list *list)
{
  t_list	*tmp;
  t_list	*next;

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
