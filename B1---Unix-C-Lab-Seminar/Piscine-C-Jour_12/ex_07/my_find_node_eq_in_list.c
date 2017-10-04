/*
** my_find_node_eq_in_list.c for day 12 in /home/mar_b/rendu/Piscine-C-Jour_12/ex_07
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 16:05:10 2014 Fabien Martinez
** Last update Tue Mar 25 16:18:54 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "mylist.h"

t_list	*my_find_node_eq_in_list(t_list *begin, void *data_ref, int (*cmp)())
{
  while (begin != NULL && (*cmp)(begin->data, data_ref) != 0)
    {
      begin = begin->next;
    }
  return (begin);
}
