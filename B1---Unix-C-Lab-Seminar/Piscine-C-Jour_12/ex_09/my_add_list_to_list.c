/*
** my_add_list_to_list.c for day 12 in /home/mar_b/rendu/Piscine-C-Jour_12/ex_09
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 22:51:07 2014 Fabien Martinez
** Last update Tue Mar 25 22:52:42 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "mylist.h"

int	my_add_list_to_list(t_list **begin1, t_list *begin2)
{
  if (begin1 == NULL)
    {
      begin1 = malloc(sizeof(*begin2));
      (*begin1) = begin2;
    }
  else if ((*begin1) == NULL)
    (*begin1) = begin2;
  else
    my_add_list_to_list(&(*begin1)->next, begin2);
}
