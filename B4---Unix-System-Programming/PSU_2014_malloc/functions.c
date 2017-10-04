/*
** malloc.c for malloc in /home/ankirama/rendu/PSU_2014_malloc
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Mon Jan 26 14:52:04 2015 Fabien Martinez
** Last update Sun Feb 15 19:29:59 2015 david tang
*/

#include "malloc.h"

static void		*g_break = 0;
static pthread_mutex_t	g_lock = PTHREAD_MUTEX_INITIALIZER;

/*
** brief: this is our malloc owi owi
** @size: the size we want to allocate
** BRIEF: steps :
** step 1 : padd our size parameter to get the nearest multiple of 32 bits
** step 2 : check if we already allocate something (with get_break_pos)
** step 3 : if g_break isn't null (already allocate something) :
** step 3-1: save our break and init our list
** step 3-2: we will try to find our first available place where we can alloc'
** step 3-3-1: if we find a place (list != 0) -> if the size of our current elt
** is > metadata + 8 bytes then we can split it
** step 3-3-1: if we didnt find a place then we have to increase our heap size
** step 3-4: after that, we'll return our pointer of our list (0) if any pb
** step 4: if get_break_pos is null then we'll try to increase heap size
** step 5: if the increase failed then return 0
** step 6: after these steps, we'll set the new break position: we set it
** to our new list element
** step 7: return the pointer after our meta data block
** return: return the pointer newest allocated
*/
void		*malloc(size_t size)
{
  t_list	*list;
  t_list	*backup;
  size_t	sz;

  if ((int)size <= 0 || !(sz = PADD(size)) || pthread_mutex_lock(&g_lock) != 0)
    return (NULL);
  if (g_break)
    {
      backup = g_break;
      list = first_place(&backup, g_break, sz);
      if (list)
	{
	  if (SUB_SIZE(list->size, sz) >= SIZE_LIST + SIZE_T)
	    split_size(list, sz);
	  list->is_free = 0;
	}
      else
	list = increase_heap(backup, sz);
      return (pthread_mutex_unlock(&g_lock) != 0 || list == NULL ?
	      NULL : list->end_meta_data);
    }
  if (!(list = increase_heap(NULL, sz)))
    return (pthread_mutex_unlock(&g_lock) != 0 ? NULL : list);
  g_break = list;
  return (pthread_mutex_unlock(&g_lock) != 0 ? NULL : list->end_meta_data);
}

void		*realloc(void *ptr, size_t taille)
{
  size_t	size_aligned;
  t_list	*list;

  if (!(size_aligned = PADD(taille)) || pthread_mutex_lock(&g_lock) != 0)
    return (NULL);
  if (!ptr)
    return (pthread_mutex_unlock(&g_lock) != 0 ? NULL : malloc(taille));
  if (is_valid_addr(ptr, g_break) && (list = get_meta_data(ptr)))
    {
      if (list->size >= size_aligned &&
	  SUB_SIZE(list->size,size_aligned) >= SIZE_LIST + SIZE_T)
	split_size(list, size_aligned);
      else
	{
	  if (list->next && list->next->is_free && list->size + list->next->size
	      + SIZE_LIST >= size_aligned)
	    merge_and_split(list, size_aligned);
	  else
	    return (pthread_mutex_unlock(&g_lock) != 0 ? NULL :
		    create_new_block(list, ptr, size_aligned));
	}
      return (pthread_mutex_unlock(&g_lock) != 0 ? NULL : ptr);
    }
  return (pthread_mutex_unlock(&g_lock) != 0 ? NULL : NULL);
}

/*
** brief: it will set to 1 our current position to explain that it's free
** @ptr: the pointer we want to free
** BRIEF: if any problem then do nothing (except to set errno). Steps:
** step 1: check if the address is a valid allocate pointer by our functions
** step 2: set a tmp to the meta data pointer of our current pointer
** step 3: set to 1 is_free to specifie that is a free block
** step 4: try to merge free space (prev and next)
** step 5: if the next address isn't available then we are at the end
** then we change prev->next to null or set our g_break to 0 if it's our only
** block
** step 6: last step: reset the break position
** (ignore brk return since free return void)
*/
void		free(void *ptr)
{
  t_list	*tmp;

  if (pthread_mutex_lock(&g_lock) == 0)
    {
      if (is_valid_addr(ptr, g_break))
	{
	  tmp = get_meta_data(ptr);
	  tmp->is_free = 1;
	  if (tmp->prev && tmp->prev->is_free)
	    tmp = merge(tmp->prev);
	  if (tmp->next)
	    tmp = merge(tmp);
	  else
	    {
	      if (tmp->prev)
		tmp->prev->next = NULL;
	      else
		g_break = NULL;
	      brk(tmp);
	    }
	}
    }
  (void)pthread_mutex_unlock(&g_lock);
}

void		show_alloc_mem(void)
{
  t_list	*tmp;

  printf("break : %p\n", sbrk(0));
  tmp = g_break;
  while (tmp)
    {
      if (!tmp->is_free)
	{
	  printf("%p - %p : %zd bytes\n", tmp->addr,
	  	 tmp->addr + tmp->size, tmp->size);
	}
      tmp = tmp->next;
    }
}
