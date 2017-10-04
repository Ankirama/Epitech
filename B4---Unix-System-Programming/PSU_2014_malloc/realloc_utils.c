/*
** realloc_utils.c for realloc_utils in /home/ankirama
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Tue Jan 27 14:57:58 2015 Fabien Martinez
** Last update Sun Feb 15 19:28:41 2015 david tang
*/

#include "malloc.h"

/*
** brief: it will copy our block into our new position
** @src: our source position
** @dest: our destination position
** since we aligned block we could copy block by block with convert our position
** void* addr to size_t * and then copy faster than using memcpy for example.
** sizeof size_t = 8 then we have to copy
** while i * sizeof(size_t) < src->size or dest->size
*/
void		copy_data(t_list *src, t_list *dest)
{
  size_t	i;
  size_t	*src_data;
  size_t	*dest_data;

  i = 0;
  src_data = src->addr;
  dest_data = dest->addr;
  while (i * SIZE_T < src->size && i * SIZE_T < dest->size)
    {
      dest_data[i] = src_data[i];
      ++i;
    }
}

void		*create_new_block(t_list *list, void *old, size_t size_aligned)
{
  void		*ptr;
  t_list	*new;

  if (!(ptr = malloc(size_aligned)))
    return (NULL);
  new = get_meta_data(ptr);
  copy_data(list, new);
  free(old);
  return (ptr);
}

void	merge_and_split(t_list *list, size_t size)
{
  list = merge(list);
  if (SUB_SIZE(list->size, size) >= SIZE_LIST + SIZE_T)
    split_size(list, size);
}
