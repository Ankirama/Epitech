/*
** my_find_elm_eq_in_list.c for my_find_elm_eq_in_list in /home/mar_b/rendu/Piscine-C-Jour_12
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 15:36:27 2014 Fabien Martinez
** Last update Tue Mar 25 16:03:32 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "mylist.h"

void	*my_find_elm_eq_in_list(t_list *begin, void *data_ref, int (*cmp)())
{
  while (begin != NULL && (*cmp)(begin->data, data_ref) != 0)
    {
      begin = begin->next;
    }
  if (begin == NULL)
    return (NULL);
  return (begin->data);
}
