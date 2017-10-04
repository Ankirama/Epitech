/*
** simple_list.c for list in /home/mar_b/rendu/piscine_cpp_d02a/ex00
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 15:53:42 2015 Fabien Martinez
** Last update Thu Jan  8 20:42:50 2015 Fabien Martinez
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "generic_list.h"

unsigned int list_get_size(t_list list)
{
  if (list == NULL)
    return (0);
  else
    return (1 + list_get_size(list->next));
}

t_bool list_is_empty(t_list list)
{
  return (list == NULL ? TRUE : FALSE);
}

void list_dump(t_list list, t_value_displayer val_disp)
{
  if (list != NULL)
    {
      val_disp(list->value);
      list_dump(list->next, val_disp);
    }
}

t_bool list_add_elem_at_front(t_list *front_ptr, void *elem)
{
  t_list tmp;

  if ((tmp = malloc(sizeof(tmp))) == NULL)
    return (FALSE);
  tmp->value = elem;
  tmp->next = *front_ptr;
  *front_ptr = tmp;
  return (TRUE);
}

t_bool list_add_elem_at_back(t_list *front_ptr, void *elem)
{
  t_list	tmp;
  t_list	head;

  head = *front_ptr;
  if ((tmp = malloc(sizeof(tmp))) == NULL)
    return (FALSE);
  tmp->value = elem;
  tmp->next = NULL;
  if (head == NULL)
    {
      *front_ptr = tmp;
      return (TRUE);
    }
  while (head != NULL && head->next != NULL)
    head = head->next;
  head->next = tmp;
  return (TRUE);
}

t_bool list_add_elem_at_position(t_list * front_ptr, void *elem, unsigned int position)
{
  unsigned int	i;
  t_list head;
  t_list prev;
  t_list tmp;

  i = -1;
  head = *front_ptr;
  prev = head;
  if (position == 0)
    return (list_add_elem_at_front(front_ptr, elem));
  while (head != NULL && ++i < position)
    {
      prev = head;
      head = head->next;
    }
  if (i < position && head == NULL)
    return (FALSE);
  if ((tmp = malloc(sizeof(tmp))) == NULL)
    return (FALSE);
  tmp->value = elem;
  tmp->next = head;
  prev->next = tmp;
  return (TRUE);
}

void	list_clear(t_list *front_ptr)
{
  t_list tmp;
  t_list next;

  tmp = (*front_ptr)->next;
  while (tmp != NULL)
    {
      next = tmp->next;
      free(tmp);
      tmp = next;
    }
  free(*front_ptr);
  *front_ptr = NULL;
}

t_bool list_del_elem_at_front(t_list *front_ptr)
{
  t_list tmp;

  if (*front_ptr == NULL)
    return (FALSE);
  tmp = *front_ptr;
  free(tmp);
  *front_ptr = (*front_ptr)->next;
  return (TRUE);
}

t_bool list_del_elem_at_back(t_list *front_ptr)
{
  t_list head;

  head = *front_ptr;
  if (head == NULL)
    return (FALSE);
  if (head->next == NULL)
    {
      free (head);
      *front_ptr = NULL;
     return (TRUE);
    }
  while (head != NULL && head->next != NULL && head->next->next != NULL)
    head = head->next;
  free(head->next);
  head->next = NULL;
  return (TRUE);
}

t_bool list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list head;
  t_list prev;
  unsigned int	i;

  head = *front_ptr;
  prev = head;
  i = -1;
  while (head != NULL && ++i < position)
    {
      prev = head;
      head = head->next;
    }
  if (head == NULL)
    return (FALSE);
  prev->next = head->next;
  free(head);
  return (TRUE);
}

void *list_get_elem_at_front(t_list list)
{
  return (list == NULL ? 0 : list->value);
}

void *list_get_elem_at_back(t_list list)
{
  if (list == NULL)
    return (0);
  else if (list->next == NULL)
    return (list->value);
  else
    return (list_get_elem_at_back(list->next));
}

void *list_get_elem_at_position(t_list list, unsigned int position)
{
  if (list == NULL)
    return (0);
  else
    {
      if (position == 0)
	return (list->value);
      else
	return (list_get_elem_at_position(list->next, --position));
    }
}

t_node *list_get_first_node_with_value(t_list list, void *value, t_value_comparator val_comp)
{
  if (list == NULL)
    return (NULL);
  if (val_comp(list->value, value) == 0)
    return (list);
  else
    return (list_get_first_node_with_value(list->next, value, val_comp));
}
