/*
** my_sort_lb.c for my_sort_lb in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Jun  3 17:54:11 2014 mar_b mar_b
** Last update Fri Jun  6 18:09:29 2014 mar_b mar_b
*/

#include <unistd.h>
#include "my_fun.h"
#include "my_sort.h"
#include "my_verbose.h"
#include "my_list.h"
#include "my_swap.h"
#include "my_changelist.h"
#include "my_rotate.h"

static	void	my_disp_lb(t_list *l_a, t_list *l_b, char verbose)
{
  while (l_b->size != 0)
    {
      (void)write(1, pa(&l_a, &l_b), 2);
      if (verbose)
	(void)my_verbose(l_a, l_b);
      else
	(void)write(1, " ", 1);
    }
}

static char	my_check_lb(t_list *l_a, t_list *l_b, char verbose)
{
  if (l_b->size == 1 || is_it_sort_lb(l_b))
    my_disp_lb(l_a, l_b, verbose);
  else
    {
      if (l_b->size == 2 && MY_CURR(l_b) < MY_NEXT(l_b))
	(void)write(1, sb(&l_a, &l_b), 2);
      else if (l_b->size > 2)
	{
	  if (MY_PREC(l_b) > MY_NEXT(l_b) && MY_CURR(l_b) < MY_PREC(l_b))
	    (void)write(1, rrb(&l_a, &l_b), 3);
	  else if (MY_CURR(l_b) < MY_NEXT(l_b) && MY_CURR(l_b) < MY_PREC(l_b)
		   && MY_NEXT(l_b) > MY_PREC(l_b))
	    (void)write(1, rb(&l_a, &l_b), 2);
	  else if (MY_CURR(l_b) < MY_NEXT(l_b) && MY_CURR(l_b) < MY_PREC(l_b))
	    (void)write(1, sb(&l_a, &l_b), 2);
	  else
	    (void)write(1, pa(&l_a, &l_b), 2);
	}
      return (verbose ? my_verbose(l_a, l_b) : write(1, " ", 1));
    }
  return (0);
}

static char	my_check_la(t_list *l_a, t_list *l_b, char verbose)
{
  if (l_a->size == 2 && MY_CURR(l_a) > MY_NEXT(l_a))
    {
      (void)write(1, sa(&l_a, NULL), 2);
      return (verbose ? my_verbose(l_a, l_b) : write(1, " ", 1));
    }
  else if (l_a-> size > 2)
    {
      if (MY_CURR(l_a) > MY_PREC(l_a) && MY_PREC(l_a) < MY_NEXT(l_a))
	{
	  (void)write(1, rra(&l_a, NULL), 3);
	  return (verbose ? my_verbose(l_a, l_b) : write(1, " ", 1));
	}
      else if (MY_CURR(l_a) > MY_NEXT(l_a) && MY_NEXT(l_a) < MY_PREC(l_a))
	{
	  (void)write(1, sa(&l_a, NULL), 2);
	  return (verbose ? my_verbose(l_a, l_b) : write(1, " ", 1));
	}
      else if (MY_CURR(l_a) > MY_NEXT(l_a) && MY_CURR(l_a) > MY_PREC(l_a)
	       && MY_NEXT(l_a) < MY_PREC(l_a))
	{
	  (void)write(1, ra(&l_a, NULL), 2);
	  return (verbose ? my_verbose(l_a, l_b) : write(1, " ", 1));
	}
    }
  return (0);
}

char	my_sort_lb(t_list *l_a, t_list *l_b, char verbose)
{
  char	moved;

  moved = 0;
  while (l_b->size != 0)
    {
      moved += my_check_lb(l_a, l_b, verbose);
      moved += my_check_la(l_a, l_b, verbose);
      moved = moved > 1 ? 1 : moved;
    }
  return (moved);
}
