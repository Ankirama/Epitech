/*
** my_rotate.c for my_rotate in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun May 18 00:32:05 2014 mar_b mar_b
** Last update Tue Jun  3 17:13:31 2014 mar_b mar_b
*/

#include "my_list.h"

char		*ra(t_list **l_a, t_list **l_b)
{
  int		ra1;
  t_list	*tmp;

  (void)l_b;
  tmp = (*l_a)->next;
  while (tmp->next != (*l_a))
    {
      ra1 = tmp->data;
      tmp->data = tmp->next->data;
      tmp->next->data = ra1;
      tmp = tmp->next;
    }
  return ("ra");
}

char		*rb(t_list **l_a, t_list **l_b)
{
  int		rb1;
  t_list	*tmp;

  (void)l_a;
  tmp = (*l_b)->next;
  while (tmp->next != (*l_b))
    {
      rb1 = tmp->data;
      tmp->data = tmp->next->data;
      tmp->next->data = rb1;
      tmp = tmp->next;
    }
  return ("rb");
}

char		*rra(t_list **l_a, t_list **l_b)
{
  int		ra1;
  t_list	*tmp;

  (void)l_b;
  tmp = (*l_a)->prec;
  while (tmp->prec != (*l_a))
    {
      ra1 = tmp->data;
      tmp->data = tmp->prec->data;
      tmp->prec->data = ra1;
      tmp = tmp->prec;
    }
  return ("rra");
}

char		*rrb(t_list **l_a, t_list **l_b)
{
  int		rb1;
  t_list	*tmp;

  (void)l_a;
  tmp = (*l_b)->prec;
  while (tmp->prec != (*l_b))
    {
      rb1 = tmp->data;
      tmp->data = tmp->prec->data;
      tmp->prec->data = rb1;
      tmp = tmp->prec;
    }
  return ("rrb");
}
