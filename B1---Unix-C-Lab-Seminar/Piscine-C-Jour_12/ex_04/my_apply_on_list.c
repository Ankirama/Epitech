/*
** my_apply_on_list.c for my_apply_on_list in /home/user/rendu/Piscine-C-Jour_12/ex_04
**
** Made by 
** Login   
**
** Started on  Tue Mar 25 13:15:34 2014 
** Last update Tue Mar 25 15:17:14 2014 
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
