/*
** my_changelist.c for my_changelist in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun May 18 00:07:51 2014 mar_b mar_b
** Last update Wed May 28 15:27:20 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_list.h"
#include "my_fun.h"

char		*pa(t_list **l_a, t_list **l_b)
{
  t_list	*tmp;

  if ((*l_b)->size > 0)
    {
      if ((tmp = malloc(sizeof(*tmp))) == NULL)
	my_puterror("error: problem to malloc the t_list!\n", 37);
      tmp->data = (*l_b)->next->data;
      tmp->prec = (*l_a);
      tmp->next = (*l_a)->next;
      (*l_a)->next->prec = tmp;
      (*l_a)->next = tmp;
      (*l_a)->size += 1;
      my_remove_elt((*l_b), 0);
    }
  return ("pa");
}

char		*pb(t_list **l_a, t_list **l_b)
{
  t_list	*tmp;

  if ((*l_a)->next != NULL)
    {
      if ((tmp = malloc(sizeof(*tmp))) == NULL)
	my_puterror("error: problem to malloc the t_list!\n", 37);
      tmp->data = (*l_a)->next->data;
      tmp->prec = (*l_b);
      tmp->next = (*l_b)->next;
      (*l_b)->next->prec = tmp;
      (*l_b)->next = tmp;
      (*l_b)->size += 1;
      my_remove_elt((*l_a), 0);
    }
  return ("pb");
}
