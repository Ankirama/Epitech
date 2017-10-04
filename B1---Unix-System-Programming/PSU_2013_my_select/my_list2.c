/*
** my_list2.c for my_list2 in /home/user/rendu/PSU_2013_my_select
**
** Made by 
** Login   
**
** Started on  Fri May 16 09:46:12 2014 
** Last update Tue May 27 10:51:53 2014 
*/

#include <stdlib.h>
#include "my_error.h"
#include "my_list.h"

/*
** It will remove the element at the position 'pos'
*/
void		my_remove_elt(t_list *lst, int pos)
{
  t_list	*tmp;

  tmp = lst->next;
  while (pos > 0)
    {
      tmp = tmp->next;
      pos -= 1;
    }
  lst->active -= tmp->active;
  tmp->prec->next = tmp->next;
  tmp->next->prec = tmp->prec;
  lst->size -= 1;
  free(tmp);
}
