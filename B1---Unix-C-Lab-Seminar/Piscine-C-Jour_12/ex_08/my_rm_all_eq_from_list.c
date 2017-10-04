/*
** my_rm_all_eq_from_list.c for day 12 in /home/mar_b/rendu/Piscine-C-Jour_12/ex_08
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 16:23:34 2014 Fabien Martinez
** Last update Tue Mar 25 18:51:37 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "mylist.h"

t_list		*my_rm_rec(t_list *head, void *data_ref,
				       int (*cmp)())
{
  t_list	*tmp;

  if (head == NULL)
    return (NULL);
  if ((*cmp)(head->data, data_ref) == 0)
    {
      tmp = head->next;
      free(head);
      tmp = my_rm_rec(tmp, data_ref, cmp);
      return (tmp);
    }
  else
    {
      head->next = my_rm_rec(head->next, data_ref, cmp);
      return (head);
    }
}

int		my_rm_all_eq_from_list(t_list **begin, void *data_ref,
				       int (*cmp)())
{
  t_list	*list;

  if (begin == NULL || (*begin) == NULL)
    return (1);
  else
    {
      list = my_rm_rec((*begin), data_ref, cmp);
      (*begin) = list;
    }
  return (0);
}
