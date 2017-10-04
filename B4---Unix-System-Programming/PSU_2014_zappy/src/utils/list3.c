/*
** list3.c for $ in /home/viterb_c/rendu/PSU_2014_zappy/src/utils
** 
** Made by CHARLES VITERBO
** Login   <viterb_c@epitech.net>
** 
** Started on  Fri Jun 26 18:07:46 2015 CHARLES VITERBO
** Last update Fri Jul  3 17:28:21 2015 CHARLES VITERBO
*/

/*
** @file list3.c
** @brief functions for list
** @autor viterb_c
** @version 1.0
*/

# include "utils.h"
# include "server.h"

/*
** @brief remove an element from a list
**
** @pram root our list we want to remove an element
** @param fd the client's fd we want to remove
*/
void		remove_client(t_list **root, int fd)
{
  t_list	*tmp;
  t_list	*elt;

  tmp = (*root);
  while (tmp->next != *root && (!tmp->next->data ||
				((t_client *)tmp->next->data)->fd != fd))
    tmp = tmp->next;
  if (tmp->next != *root)
    {
      elt = tmp->next;
      tmp->next = elt->next;
      (*root)->size -= elt->size;
      free(elt);
    }
}

/*
** @brief
**
** @param root
*/
void		free_link(t_list **root)
{
  t_list	*elt;
  t_list	*tmp;
  t_fork	*fork;

  if (*root != NULL)
    {
      tmp = (*root)->next;
      while (tmp != NULL && tmp != *root)
	{
	  elt = tmp;
	  fork = tmp->data;
	  free(fork->team);
	  tmp = tmp->next;
	  free(elt);
	}
      free(*root);
    }
}

/*
** @brief
**
** @param root
*/
void		free_list(t_list **root)
{
  t_list	*elt;
  t_list	*tmp;
  t_fork	*fork;

  if (*root != NULL)
    {
      tmp = (*root)->next;
      while (tmp != NULL && tmp != *root)
	{
	  elt = tmp;
	  fork = tmp->data;
	  free(fork->team);
	  tmp = tmp->next;
	  free(elt->data);
	  free(elt);
	}
      free(*root);
    }
}
