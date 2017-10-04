/*
** my_list_size.c for day 12 in /home/user/rendu/Piscine-C-Jour_12/ex_02
**
** Made by 
** Login   
**
** Started on  Tue Mar 25 10:14:46 2014 
** Last update Tue Mar 25 10:21:51 2014 
*/

#include "mylist.h"
#include <stdlib.h>

int	my_rec_size(t_list *list)
{
  if (list == NULL)
    return (0);
  else
    return (1 + my_rec_size(list->next));
}

int		my_list_size(t_list *begin)
{
  t_list	*list;

  list = begin;
  return (my_rec_size(list));
}
