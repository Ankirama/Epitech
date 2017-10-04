/*
** main.c<2> for main in /home/ankirama
**
** Made by Fabien Martinez
** Login   <fabien.martinez@epitech.eu>
**
** Started on  Thu Feb 19 21:38:01 2015 Fabien Martinez
** Last update Sat Jul  4 05:23:03 2015 Alexandre Chenevier
*/

/*
** @file list2.c
** @brief functions for list
** @authour ankirama
** @version 1.0
*/

#include "utils.h"

/*
** @brief remove an element from a list
**
** @bug useful only for string data type (because strcmp used)
**
** @param root our list we want to remove an element
** @param elt_data our element we want to remove
*/
void		remove_element(t_list **root, void *elt_data)
{
  t_list	*tmp;
  t_list	*elt;

  tmp = (*root);
  while (tmp->next != *root && (!tmp->next->data ||
				strcmp(tmp->next->data, elt_data) != 0))
    tmp = tmp->next;
  if (tmp->next != *root)
    {
      elt = tmp->next;
      tmp->next = elt->next;
      (*root)->size -= elt->size;
      free(elt->data);
      free(elt);
    }
}

/*
** @brief count number elements in list
**
** @param root our list we want to get the number elements
** @return number elements
*/
int		nb_elements(t_list *root)
{
  t_list	*tmp;
  int		nb;

  nb = 0;
  tmp = root->next;
  while (tmp != root)
    {
      ++nb;
      tmp = tmp->next;
    }
  return (nb);
}

/*
** @brief change and element in unique list
**
** Change first occurence found
**
** @bug useful only for string type (strcmp used to find data)
** @deprecated useless in this project
**
** @param root our list we want to change element
** @param old_data our old data we need to find
** @param new_data our data wich will replace old_data
*/
int		change_element(t_list **root, void *old_data, void *new_data)
{
  t_list	*tmp;

  tmp = (*root)->next;
  while (tmp != *root && (!tmp->data || strcmp(tmp->data, old_data) != 0))
    tmp = tmp->next;
  if (tmp != *root)
    {
      free(tmp->data);
      if ((tmp->data = my_strdup(new_data)) == NULL)
	return (1);
    }
  return (0);
}

/*
** @brief get sublist
**
** Return a sublist wich will start with data
**
** @bug useful only for string type (strcmp used to find data)
**
** @deprecated with new change_element, could be segfault
**
** @param root our list
** @param data data we need to find to get our sublist
** @return the sublist
*/
t_list		*get_list(t_list *root, void *data)
{
  t_list	*tmp;

  tmp = root->next;
  while (tmp != root && strcmp(data, tmp->data) != 0)
    tmp = tmp->next;
  return (tmp);
}

/*
** @brief free cmds list
**
** @param root our root element from our list
*/
void		free_cmds(t_list **root)
{
  t_list	*tmp;
  t_list	*elt;
  t_list	*to_free;

  if (*root != NULL)
    {
      tmp = (*root)->next;
      while (tmp != NULL && tmp != *root)
	{
	  elt = tmp;
	  tmp = tmp->next;
	  to_free = elt->data;
	  let_it_go(&to_free);
	  free(elt);
	}
      free(*root);
    }
}
