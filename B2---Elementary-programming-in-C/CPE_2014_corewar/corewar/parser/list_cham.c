/*
** list_cham.c for  in /home/teyssa_r/rendu/CPE_2014_corewar/corewar/parse_vm
** 
** Made by teyssa_r teyssa_r
** Login   <teyssa_r@epitech.net>
** 
** Started on  Mon Aug 11 19:05:15 2014 teyssa_r teyssa_r
** Last update Sun Aug 31 23:25:31 2014 chenev_d chenev_d
** Last update Sun Aug 31 17:00:27 2014 teyssa_r teyssa_r
*/

#include "utils.h"
#include "parse.h"
#include "op.h"
#include <stdlib.h>
#include <unistd.h>

/*
** brief: error for size to big
** @str: prog_name
*/
void	size_to_big(char *str)
{
  my_write(2, "Error : size of '", 15);
  my_write(2, str, PROG_NAME_LENGTH);
  my_puterror("' to big\n");
}

/*
** brief: add an element to list
** @list: our list
** @fd : file descriptor
** @my_cor : name of our .cor
** @i : number of your .cor
** return: no return
*/
void		add_before(t_list **list, int fd, int i, int number_chp)
{
  t_list	*elem;

  elem = my_malloc(sizeof(*elem));
  elem->root = i + 1;
  elem->init_pos = 0;
  elem->pc = 0;
  elem->nb_tour = 0;
  elem->carry = 0;
  elem->live = 0;
  elem->reg[0] = number_chp;
  elem->chpm = my_malloc(sizeof(header_t));
  elem->chpm->magic = header_or_not(fd);
  if (elem->chpm->magic != COREWAR_EXEC_MAGIC)
    my_puterror("Error : Doesn't .cor\n");
  my_read(fd, elem->chpm->prog_name, PROG_NAME_LENGTH);
  if ((elem->chpm->prog_size = header_or_not(fd)) > 1024)
    size_to_big(elem->chpm->prog_name);
  my_read(fd, elem->chpm->comment, COMMENT_LENGTH);
  elem->prev = (*list)->prev;
  elem->next = (*list);
  (*list)->prev->next = elem;
  (*list)->prev = elem;
}

/*
** brief: to make racine of list
** return: return list or NULL
*/
t_list	*make_list()
{
  t_list	*root;

  if ((root = malloc(sizeof(t_list))) != NULL)
    {
      root->root = 0;
      root->prev = root;
      root->next = root;
    }
  else
    return (NULL);
  return (root);
}

/*
** brief: to delete element of the list
** @list: our list
** return: no return
*/
void	delete_list(t_list **list)
{
  t_list	*it;
  t_list	*next;

  it = (*list)->next;
  while (it != *list)
    {
      next = it->next;
      free(it);
      it = next;
    }
}
