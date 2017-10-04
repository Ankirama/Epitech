/*
** my_sort.c for my_sort in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed May 28 15:19:22 2014 mar_b mar_b
** Last update Sun Jun  8 19:11:36 2014 mar_b mar_b
*/

#include <unistd.h>
#include "my_fun.h"
#include "my_sort.h"
#include "my_sort_la.h"
#include "my_sort_lb.h"
#include "my_list.h"
#include "my_swap.h"
#include "my_changelist.h"
#include "my_rotate.h"

char		is_it_sort_la(t_list *l_a)
{
  t_list	*tmp;

  tmp = l_a->next;
  while (tmp->next != l_a && tmp->data < tmp->next->data)
    tmp = tmp->next;
  return (tmp->next == l_a);
}

char		is_it_sort_lb(t_list *l_b)
{
  t_list	*tmp;

  tmp = l_b->prec;
  while (tmp->prec != l_b && tmp->data < tmp->prec->data)
    tmp = tmp->prec;
  return (tmp->prec == l_b);
}

int     my_sort(t_list *l_a, t_list *l_b, char verbose)
{
  char	moved;

  moved = 0;
  while (!is_it_sort_la(l_a))
    {
      moved += my_sort_la(l_a, l_b, verbose);
      moved += my_sort_lb(l_a, l_b, verbose);
      moved = moved > 1 ? 1 : moved;
      if (is_it_sort_la(l_a) && is_it_sort_lb(l_b))
	my_empty_lb(&l_a, &l_b);
    }
  if (!verbose && moved != 0)
    {
      (void)write(1, "\b", 1);
      (void)write(1, "\n", 1);
    }
  else if (verbose && moved == 0)
    {
      my_display_list(l_a);
      (void)write(1, "\n", 1);
    }
  return (0);
}
