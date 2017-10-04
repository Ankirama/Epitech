/*
** free_utils.c for free_utils in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Tue Jan 27 10:43:24 2015 Fabien Martinez
** Last update Sat Feb 14 10:00:17 2015 Fabien martinez
*/

#include "malloc.h"

/*
** brief: return the position of metadata
** @ptr: our current data
** BRIEF: ptr points to our current data, but we need to get meta data
** and data, so we just move to current position - size of our struct - 1
** (-1 because we ignore our end_meta_data since it's the end of our struct)
** return: return our meta_data position
*/
t_list	*get_meta_data(void *ptr)
{
  char	*tmp;

  tmp = ptr;
  tmp -= SIZE_LIST;
  return ((t_list *)tmp);
}

/*
** brief: boolean function to check if the address is valid or not
** @ptr: our address we want to check
** return: return 0 if not, else 1
*/
char	is_valid_addr(void *ptr, const t_list *breaker)
{
  if (breaker && (ptr > (void *)breaker && ptr < sbrk(0)))
      return (ptr == get_meta_data(ptr)->addr);
  return (0);
}

/*
** brief: it will merge our free space to better free
** @list: our current position where we want to merge free
** BRIEF: new size : current size + meta data size + next size
** don't forget to attach our list
** return: return the new list pointed to the same as the parameter
** PS : my english is really bad but that's funny hahaha...
*/
t_list	*merge(t_list *list)
{
  if (list->next && list->next->is_free)
    {
      list->size += SIZE_LIST + list->next->size;
      list->next = list->next->next;
      if (list->next)
	list->next->prev = list;
    }
  return (list);
}
