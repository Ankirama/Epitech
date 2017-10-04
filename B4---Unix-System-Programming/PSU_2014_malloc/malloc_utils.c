/*
** malloc_utils.c for malloc_utils in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Tue Jan 27 10:43:14 2015 Fabien Martinez
** Last update Sun Feb 15 06:09:34 2015 Fabien martinez
*/

#include "malloc.h"

/*
** brief: we will try to find our first place where we can use to malloc
** @backup: equal to "curr->prev", used to keep a trace if we can't find any
** place
** @curr: our emplacement we will used to malloc
** @size: size reached
*/
t_list		*first_place(t_list **backup, t_list *breaker, size_t size)
{
  t_list	*tmp;

  tmp = breaker;
  while (tmp && !(tmp->is_free && tmp->size >= size))
    {
      *backup = tmp;
      tmp = tmp->next;
    }
  return (tmp);
}

/*
** brief: it will allow us to increase heap
** @list: a pointer to the last block in our list, or NULL
** @size: the size we will increase
** BRIEF: we will save the current position of program break
** and try to increase the size. If it works, then we will set our new elt
** and "add" it to our current list
** return: we return the new block
*/
t_list		*increase_heap(t_list *list, size_t size)
{
  t_list	*new;
  size_t	size_big;
  size_t	size_page;

  size_page = sysconf(_SC_PAGESIZE);
  size_big = (size / size_page + 1) * size_page;
  size_big = size_big >= size + SIZE_LIST ? size_big : size_big + size_page;
  new = sbrk(0);
  if (sbrk(size_big) == (void *) -1)
    return (NULL);
  new->is_free = 0;
  new->size = size_big - SIZE_LIST;
  new->prev = list;
  new->next = NULL;
  new->addr = new->end_meta_data;
  if (list)
    list->next = new;
  if (new->size - size >= SIZE_LIST + SIZE_T)
    split_size(new, size);
  return (new);
}

/*
** brief: this function will allow us to resize correctly our list
** @list: this list point to the element we want to resize
** @size: the size we need to change
** BRIEF: we will resize and create a new element in our list with the size
** unused. we need to aligned our list so we will use a pointer arithmetic
** with end_meta_data. Indeed, end_meta_data point to the end of our element
** We don't have to forget to "attach" our prev and next element with new
*/
void		split_size(t_list *list, size_t size)
{
  t_list	*new;

  new = (t_list *)(list->end_meta_data + size);
  new->is_free = 1;
  new->size = list->size - size - SIZE_LIST;
  new->prev = list;
  new->next = list->next;
  new->addr = new->end_meta_data;
  list->size = size;
  list->next = new;
  if (new->next)
    new->next->prev = new;
}
