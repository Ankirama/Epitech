/*
** my_rev_list.c for my_rev_list in /home/mar_b/rendu/Piscine-C-Jour_12/ex_03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 10:26:00 2014 Fabien Martinez
** Last update Tue Mar 25 13:14:58 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "mylist.h"

int		my_rev_list(t_list **begin)
{
  t_list	*previous;
  t_list	*next;

  if (begin == NULL)
    return (1);
  previous = NULL;
  next = NULL;
  while ((*begin) != NULL)
    {
      next = (*begin)->next;
      (*begin)->next = previous;
      previous = (*begin);
      (*begin) = next;
    }
  (*begin) = previous;
  return (0);
}
