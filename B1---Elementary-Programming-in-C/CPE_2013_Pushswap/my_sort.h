/*
** my_sort.h for my_sort in /home/mar_b/rendu/CPE_2013_Pushswap
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Wed May 28 15:19:38 2014 mar_b mar_b
** Last update Fri Jun  6 17:38:14 2014 mar_b mar_b
*/

#ifndef MY_SORT_H_
# define MY_SORT_H_

# include "my_list.h"

# define MY_CURR(lst)	(lst->next->data)
# define MY_PREC(lst)	(lst->prec->data)
# define MY_NEXT(lst)	(lst->next->next->data)

char	is_it_sort_la(t_list *l_a);
char	is_it_sort_lb(t_list *l_b);
int     my_sort(t_list *l_a, t_list *l_b, char verbose);

#endif /* !MY_SORT_H_ */
