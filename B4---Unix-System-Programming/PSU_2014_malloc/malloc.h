/*
** malloc.h for malloc in /home/ankirama/rendu/PSU_2014_malloc
** 
** Made by Fabien Martinez
** Login   <ankirama@ubuntu>
** 
** Started on  Mon Jan 26 14:20:20 2015 Fabien Martinez
** Last update Sun Feb 15 19:13:23 2015 david tang
*/

#ifndef MALLOC_H_
# define MALLOC_H_
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>

/*
** We need to align data with a multiple of 4 (sizeof int)
** 32 bits -> 4 bytes that's why we use 4 to find nearest multiple
** this operation's like (x - 1) / 4 x 4 + 4, this formula allow us
** to have a result always nearest ge multiple of 4
** We'll use >> and << because it's faster than / and *
** example : we want to fill 42 bytes : 
** padding_int will return:
** 0010 1010 - 0000 0001 = 0010 1001 (41)
** 0010 1001 >> 2 = 0000 1010 (10)
** 0000 1010 << 2 = 0010 1000 (40)
** 0010 1000 + 0000 0100 = 0010 1100 (44) -> nearest multiple of 4 bytes for 42
*/
# define PADD(x)	((((x - 1) >> 3) << 3) + 8)
# define SIZE_T		(sizeof(size_t))

/*
** brief: this list will allow us to create meta data and give us some things
** @is_free: 1 if our block is free, else 0
** @size: the size in our block
** @prev: a pointer to the previous block
** @next: a pointer to the next block (null by default)
** @addr: the address of the current block
** @end_meta_data: end_meta_data point to the block just after meta_data
*/
typedef struct	s_list
{
  size_t	is_free;
  size_t	size;
  struct s_list	*prev;
  struct s_list	*next;
  void		*addr;
  char		end_meta_data[1];
}		t_list;

# define SIZE_LIST	(SIZE_T * 2 + sizeof(t_list *) * 2 + sizeof(void *))
# define SUB_SIZE(a, b)	(a < b ? b - a : a - b)

/*
** free_utils.c
*/
t_list	*get_meta_data(void *ptr);
char	is_valid_addr(void *ptr, const t_list *breaker);
t_list	*merge(t_list *list);

/*
** malloc_utils.c
*/
t_list	*first_place(t_list **backup, t_list *breaker, size_t size);
t_list	*increase_heap(t_list *list, size_t size);
void	split_size(t_list *list, size_t size);

/*
** realloc_utils.c
*/
void	copy_data(t_list *src, t_list *dest);
void	*create_new_block(t_list *list, void *old, size_t size_aligned);
void	merge_and_split(t_list *list, size_t size);

/*
** functions.c
*/
void	*malloc(size_t taille);
void	*realloc(void *ptr, size_t taille);
void	free(void *ptr);
void	show_alloc_mem(void);

#endif /* !MALLOC_H_ */
