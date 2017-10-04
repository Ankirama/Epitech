/*
** my_mulopel.c for multi operation in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Sun May 18 00:05:19 2014 mar_b mar_b
** Last update Sun May 18 01:06:34 2014 mar_b mar_b
*/

#include <stdlib.h>
#include "my_list.h"
#include "my_swap.h"
#include "my_rotate.h"

char	*ss(t_list **l_a, t_list **l_b)
{
  (void)sa(l_a, NULL);
  (void)sb(NULL, l_b);
  return ("ss");
}

char	*rr(t_list **l_a, t_list **l_b)
{
  (void)ra(l_a, NULL);
  (void)rb(NULL, l_b);
  return ("rr");
}

char	*rrr(t_list **l_a, t_list **l_b)
{
  (void)rra(l_a, NULL);
  (void)rrb(NULL, l_b);
  return ("rrr");
}
