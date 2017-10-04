/*
** my_apply_on_list.c for my_apply_on_list in /home/mar_b/rendu/Piscine-C-Jour_12/ex_04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 13:15:34 2014 Fabien Martinez
** Last update Tue Mar 25 15:17:14 2014 Fabien Martinez
*/

#include "mylist.h"
#include <stdlib.h>

int	my_apply_on_list(t_list *begin, int (*f)(void*))
{
  while (begin != NULL)
    {
      (*f)(begin->data);
      begin = begin->next;
    }
}
