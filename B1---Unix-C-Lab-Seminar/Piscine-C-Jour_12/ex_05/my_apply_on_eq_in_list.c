/*
** my_apply_on_eq_in_list.c for day 12 in /home/mar_b/rendu/Piscine-C-Jour_12/ex_05
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 15:05:52 2014 Fabien Martinez
** Last update Tue Mar 25 15:34:37 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "mylist.h"

int	my_apply_on_eq_in_list(t_list *begin, int (*f)(), void *data_ref,
			       int (*cmp)())
{
  while (begin != NULL)
    {
      if ((*cmp)(begin->data, data_ref) == 0)
	  (*f)(begin->data);
      begin = begin->next;
    }
}
