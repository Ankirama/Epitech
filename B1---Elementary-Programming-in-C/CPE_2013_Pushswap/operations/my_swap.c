/*
** my_swap.c for my_swap in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sat May 17 23:36:12 2014 mar_b mar_b
** Last update Sun May 18 00:36:45 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_list.h"

char	*sa(t_list **l_a, t_list **l_b)
{
  int	la1;

  (void)l_b;
  if ((*l_a)->next != NULL && (*l_a)->next->next != NULL)
    {
      la1 = (*l_a)->next->data;
      (*l_a)->next->data = (*l_a)->next->next->data;
      (*l_a)->next->next->data = la1;
    }
  return ("sa");
}

char	*sb(t_list **l_a, t_list **l_b)
{
  int	lb1;

  (void)l_a;
  if ((*l_b)->next != NULL && (*l_b)->next->next != NULL)
    {
      lb1 = (*l_b)->next->data;
      (*l_b)->next->data = (*l_b)->next->next->data;
      (*l_b)->next->next->data = lb1;
    }
  return ("sb");
}
