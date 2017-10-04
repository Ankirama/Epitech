/*
** function_list.c for  in /home/teyssa_r/rendu/PSU_2013_minishell2
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Wed Jul 23 15:38:01 2014 teyssa_r teyssa_r
** Last update Thu Oct  2 22:19:48 2014 chenev_d chenev_d
*/

#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "bonus.h"

t_hst		*add_before(t_hst **hst, char *name)
{
  t_hst		*tmp;
  t_hst		*elem;

  tmp = *hst;
  elem = *hst;
  if ((elem = malloc(sizeof(*elem))) != NULL)
    {
      while (tmp->next->root != 1 && tmp != tmp->next)
	{
	  tmp = tmp->next;
	}
      elem->root = 0;
      elem->val = tmp->val + 1;
      elem->name = my_strdup(name);
      elem->next = tmp->next;
      elem->prev = tmp;
      tmp->next->prev = elem;
      tmp->next = elem;
    }
  else
    return (NULL);
  return (elem);
}

t_hst		*make_hst(void)
{
  t_hst		*root;

  if ((root = malloc(sizeof(*root))) != NULL)
    {
      root->root = 1;
      root->name = NULL;
      root->val = 0;
      root->prev = root;
      root->next = root;
    }
  else
    return (NULL);
  return (root);
}

void		delete_hst(t_hst **hst)
{
  t_hst		*it;
  t_hst		*next;

  it = (*hst)->next;
  while (it != *hst)
    {
      next = it->next;
      free(it);
      it = next;
    }
}
