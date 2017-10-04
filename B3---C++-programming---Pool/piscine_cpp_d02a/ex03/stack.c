/*
** stack.c for stack in /home/mar_b/rendu/piscine_cpp_d02a/ex03
**
** Made by Fabien Martinez
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jan  8 20:53:48 2015 Fabien Martinez
** Last update Fri Jan  9 09:02:36 2015 Fabien Martinez
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "stack.h"

unsigned int stack_get_size(t_stack stack)
{
  if (stack == NULL)
    return (0);
  else
    return (1 + stack_get_size(stack->next));
}

t_bool stack_is_empty(t_stack stack)
{
  if (stack == NULL)
    return (TRUE);
  else
    return (FALSE);
}

t_bool stack_push(t_stack *stack_ptr, void *elem)
{
  t_stack tmp;

  if ((tmp = malloc(sizeof(tmp))) == NULL)
    return (FALSE);
  tmp->next = (*stack_ptr);
  tmp->value = elem;
  (*stack_ptr) = tmp;
  return (TRUE);
}

t_bool stack_pop(t_stack *stack_ptr)
{
  if (*stack_ptr)
    return (FALSE);
  *stack_ptr = (*stack_ptr)->next;
  return (TRUE);
}

void *stack_top(t_stack stack)
{
  if (stack == NULL)
    return (NULL);
  return (stack->value);
}
