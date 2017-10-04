/*
** my_put_elem_in_sort_list.c for day 12 in /home/mar_b/rendu/Piscine-C-Jour_12/ex_11
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 22:50:21 2014 Fabien Martinez
** Last update Tue Mar 25 22:50:27 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "mylist.h"

t_list		*my_rec_elem_sort(t_list *head, void *data, int (*cmp)())
{
  t_list	*tmp;

  if (head == NULL || (*cmp)(head->data, data) >= 0)
    {
      tmp = malloc(sizeof(*tmp));
      tmp->data = data;
      tmp->next = head;
      return (tmp);
    }
  else
    {
      head->next = my_rec_elem_sort(head->next, data, cmp);
      return (head);
    }
}

int		my_put_elem_in_sort_list(t_list **begin, void *data,
					 int (*cmp)())
{
  t_list	*list;

  if (begin == NULL)
    begin = malloc(sizeof(*begin));
  list = my_rec_elem_sort((*begin), data, cmp);
  (*begin) = list;
}
