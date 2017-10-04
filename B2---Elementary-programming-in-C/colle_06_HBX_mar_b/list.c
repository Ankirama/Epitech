/*
** list.c for let it go in /home/mar_b/rendu/colle_06_HBX_mar_b
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Tue Sep 30 18:52:33 2014 mar_b mar_b
** Last update Tue Sep 30 22:37:11 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "utils.h"
#include "list.h"

void		add_element(t_list **lst, char carac, unsigned int nbr)
{
  t_list	*elt;
  t_list	*tmp;

  elt = my_malloc(sizeof(*elt));
  elt->carac = carac;
  elt->nbr = nbr;
  elt->next = NULL;
  elt->prec = NULL;
  tmp = *lst;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if (tmp != NULL)
    {
      elt->prec = tmp;
      tmp->next = elt;
    }
  else
    *lst = elt;
}

void		let_it_go(t_list *lst)
{
  t_list	*tmp;

  while (lst != NULL)
    {
      tmp = lst;
      lst = tmp->next;
      free(tmp);
    }
}

static t_list		*_travel_inv(t_list *lst)
{
  t_list		*tmp;

  tmp = lst;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  return (tmp);
}

void		travel_lst(t_list *lst, char rev)
{
  t_list	*tmp;

  tmp = rev == 0 ? lst : _travel_inv(lst);
  while (tmp != NULL)
    {
      my_putchar(tmp->carac);
      my_putchar(':');
      my_putnbr(tmp->nbr);
      my_putchar('\n');
      if (rev)
	tmp = tmp->prec;
      else
	tmp = tmp->next;
    }
}

void	travel_range(t_list *lst, char rev, unsigned int nbr)
{
  if (rev)
    my_sort_int(&lst, cmp_sup);
  else
    my_sort_int(&lst, cmp_inf);
  while (lst != NULL)
    {
      nbr = lst->nbr;
      my_putnbr(lst->nbr);
      my_putchar(':');
      while (lst != NULL && lst->nbr == nbr)
	{
	  my_putchar(lst->carac);
	  if (lst->next != NULL && lst->next->nbr == nbr)
	    my_putchar(',');
	  lst = lst->next;
	}
      my_putchar('\n');
    }
}
