/*
** my_list2.h for my_list2.h in /home/mar_b/rendu/PSU_2013_minishell1
**
** Made by mar_b mar_b
** Login   <mar_b@epitech.net>
**
** Started on  Thu Jun 19 11:39:38 2014 mar_b mar_b
** Last update Thu Jun 19 13:34:43 2014 mar_b mar_b
*/

#ifndef MY_LIST2_H_
# define MY_LIST2_H_

# include "my_list.h"

char	*my_find_element(t_list *lst, char *value);
void	my_setenv_lst(t_list *lst, char *var, char *value);

#endif /* !MY_LIST2_H_ */
