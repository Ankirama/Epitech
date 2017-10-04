/*
** my_sort_list.c for day 12 in /home/mar_b/rendu/Piscine-C-Jour_12/ex_10
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Tue Mar 25 22:50:41 2014 Fabien Martinez
** Last update Tue Mar 25 22:50:44 2014 Fabien Martinez
*/

#include <stdlib.h>
#include "mylist.h"

int		my_sort_list(t_list **begin, int (*cmp)())
{
  t_list	*head;
  char		done;
  void		*tmp;

  if(begin == NULL || (*begin) == NULL)
    return (1);
  done = 1;
  while (done)
    {
      head = (*begin);
      done = 0;
      while (head != NULL && head->next != NULL)
	{
	  if (cmp(head->data, (head->next)->data) > 0)
	    {
	      tmp = head->data;
	      head->data = (head->next)->data;
	      (head->next)->data = tmp;
	      done = 1;
	    }
	  head = head->next;
	}
    }
}
