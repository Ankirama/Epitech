/*
** queue.c for sexe de charles in /home/mar_b/rendu/piscine_cpp_d02a/ex04
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 21:14:32 2015 Fabien Martinez
** Last update Fri Jan  9 08:46:19 2015 Fabien Martinez
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

unsigned int queue_get_size(t_queue queue)
{
  if (queue == NULL)
    return (0);
  else
    return (1 + queue_get_size(queue->next));
}

t_bool queue_push(t_queue *queue_ptr, void *elem)
{
  t_queue	tmp;
  t_queue	head;

  if ((tmp = malloc(sizeof(tmp))) == NULL)
    return (FALSE);
  head = *queue_ptr;
  tmp->next = NULL;
  tmp->value = elem;
  if (head == NULL)
    {
      *queue_ptr = tmp;
      return (TRUE);
    }
  while (head != NULL && head->next != NULL)
    head = head->next;
  head->next = tmp;
  return (TRUE);
}

t_bool queue_pop(t_queue *queue_ptr)
{
  t_queue head;

  if (*queue_ptr == NULL)
    return (FALSE);
  head = (*queue_ptr)->next;
  free(*queue_ptr);
  *queue_ptr = head;
  return (TRUE);
}

void *queue_front(t_queue queue)
{
  if (queue == NULL)
    return (NULL);
  return (queue->value);
}
